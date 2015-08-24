#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define PNG_DEBUG 3
#include <png.h>


/* some file local variable to save tmp image */
static int width = 0;
static int height = 0;
static int stride = 0;

static png_bytep *row_pointers;
static png_byte color_type;
static png_byte bit_depth;


/* prebuilt table */
uint32_t mul_299[] = {
        0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 48, 48, 48, 49, 49, 49, 49, 50, 50, 50, 51, 51, 51, 52, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 55, 56, 56, 56, 57, 57, 57, 58, 58, 58, 58, 59, 59, 59, 60, 60, 60, 60, 61, 61, 61, 62, 62, 62, 63, 63, 63, 63, 64, 64, 64, 65, 65, 65, 66, 66, 66, 66, 67, 67, 67, 68, 68, 68, 69, 69, 69, 69, 70, 70, 70, 71, 71, 71, 72, 72, 72, 72, 73, 73, 73, 74, 74, 74, 75, 75, 75, 75, 76,
};
uint32_t mul_587[] = {
        0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9, 10, 11, 11, 12, 12, 13, 14, 14, 15, 15, 16, 17, 17, 18, 18, 19, 19, 20, 21, 21, 22, 22, 23, 24, 24, 25, 25, 26, 27, 27, 28, 28, 29, 29, 30, 31, 31, 32, 32, 33, 34, 34, 35, 35, 36, 36, 37, 38, 38, 39, 39, 40, 41, 41, 42, 42, 43, 44, 44, 45, 45, 46, 46, 47, 48, 48, 49, 49, 50, 51, 51, 52, 52, 53, 54, 54, 55, 55, 56, 56, 57, 58, 58, 59, 59, 60, 61, 61, 62, 62, 63, 63, 64, 65, 65, 66, 66, 67, 68, 68, 69, 69, 70, 71, 71, 72, 72, 73, 73, 74, 75, 75, 76, 76, 77, 78, 78, 79, 79, 80, 81, 81, 82, 82, 83, 83, 84, 85, 85, 86, 86, 87, 88, 88, 89, 89, 90, 90, 91, 92, 92, 93, 93, 94, 95, 95, 96, 96, 97, 98, 98, 99, 99, 100, 100, 101, 102, 102, 103, 103, 104, 105, 105, 106, 106, 107, 108, 108, 109, 109, 110, 110, 111, 112, 112, 113, 113, 114, 115, 115, 116, 116, 117, 117, 118, 119, 119, 120, 120, 121, 122, 122, 123, 123, 124, 125, 125, 126, 126, 127, 127, 128, 129, 129, 130, 130, 131, 132, 132, 133, 133, 134, 135, 135, 136, 136, 137, 137, 138, 139, 139, 140, 140, 141, 142, 142, 143, 143, 144, 144, 145, 146, 146, 147, 147, 148, 149, 149,
};
uint32_t mul_144[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 29,
};

/* original version */
void rgba_to_bw(uint32_t *bitmap, int width, int height, long stride)
{
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = 0; row < height; row++) {
                for (col = 0; col < width; col++) {
                        pixel = bitmap[col + row * stride / 4];

                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
                        bitmap[col + row * stride / 4 ] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

/* optimize version v1
 *
 * change:
 *
 *  1. for i++   -> for i--
 */
void rgba_to_bw_v1(uint32_t *bitmap, int width, int height, long stride)
{
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = height - 1; row + 1 != 0; row--) {
                for (col = width - 1; col + 1 != 0; col--) {
                        pixel = bitmap[col + row * stride / 4];

                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
                        bitmap[col + row * stride / 4 ] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

/* optimize version v2
 *
 * change:
 *
 *  1. for i++   -> for i--
 *  2. int tmp = col + row * stride / 4;
 */
void rgba_to_bw_v2(uint32_t *bitmap, int width, int height, long stride)
{
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = height - 1; row + 1 != 0; row--) {
                for (col = width - 1; col + 1 != 0; col--) {
                        int tmp = col + row * stride / 4;
                        pixel = bitmap[tmp];
                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
                        bitmap[tmp] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

/* optimize version v3
 *
 * change:
 *
 *  1. for i++   -> for i--
 *  2. int tmp = col + row * stride / 4;
 *  3. use table for: bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
 */
void rgba_to_bw_v3(uint32_t *bitmap, int width, int height, long stride)
{
        int row, col;
        uint32_t pixel, r, g, b, a, bw;
        for (row = height - 1; row + 1 != 0; row--) {
                for (col = width - 1; col + 1 != 0; col--) {
                        int tmp = col + row * stride / 4;
                        pixel = bitmap[tmp];
                        a = (pixel >> 24) & 0xff;
                        r = (pixel >> 16) & 0xff;
                        g = (pixel >> 8) & 0xff;
                        b = pixel & 0xff;
                        bw = (uint32_t) mul_299[r] + (uint32_t) mul_587[g] + (uint32_t) mul_144[b];
                        bitmap[tmp] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
                }
        }
}

void read_image(const char* filename)
{
        FILE *fp = fopen(filename, "rb");
        if (!fp) {
                perror("open file");
                return;
        }

        png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if(!png) abort();

        png_infop info = png_create_info_struct(png);
        if(!info) abort();

        if(setjmp(png_jmpbuf(png))) abort();

        png_init_io(png, fp);

        png_read_info(png, info);

        width      = png_get_image_width(png, info);
        height     = png_get_image_height(png, info);
        color_type = png_get_color_type(png, info);
        bit_depth  = png_get_bit_depth(png, info);

        // Read any color_type into 8bit depth, RGBA format.
        // See http://www.libpng.org/pub/png/libpng-manual.txt

        if(bit_depth == 16)
                png_set_strip_16(png);

        if(color_type == PNG_COLOR_TYPE_PALETTE)
                png_set_palette_to_rgb(png);

        // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
        if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
                png_set_expand_gray_1_2_4_to_8(png);

        if(png_get_valid(png, info, PNG_INFO_tRNS))
                png_set_tRNS_to_alpha(png);

        // These color_type don't have an alpha channel then fill it with 0xff.
        if(color_type == PNG_COLOR_TYPE_RGB ||
           color_type == PNG_COLOR_TYPE_GRAY ||
           color_type == PNG_COLOR_TYPE_PALETTE)
                png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

        if(color_type == PNG_COLOR_TYPE_GRAY ||
           color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
                png_set_gray_to_rgb(png);

        png_read_update_info(png, info);

        stride = png_get_rowbytes(png, info);
        png_bytep pixels = (png_bytep) malloc(height * stride);

        row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
        for(int y = 0; y < height; y++) {
//                row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
                row_pointers[y] = pixels + stride * y;
        }

        png_read_image(png, row_pointers);

        fclose(fp);
}

void write_image(const char *filename)
{
        FILE *fp = fopen(filename, "wb");
        if (!fp) {
                perror("write file");
                exit(-1);
        }

        png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!png) abort();

        png_infop info = png_create_info_struct(png);
        if (!info) abort();

        if (setjmp(png_jmpbuf(png))) abort();

        png_init_io(png, fp);

        // Output is 8bit depth, RGBA format.
        png_set_IHDR (
                png,
                info,
                width, height,
                8,
                PNG_COLOR_TYPE_RGBA,
                PNG_INTERLACE_NONE,
                PNG_COMPRESSION_TYPE_DEFAULT,
                PNG_FILTER_TYPE_DEFAULT);
        png_write_info(png, info);


        png_write_image(png, row_pointers);

        png_write_end(png, NULL);

        // FIXME:
        // malloc: *** error for object 0x1066fe960: pointer being freed was not allocated
        // for(int y = 0; y < height; y++) {
        //         free(row_pointers[y]);
        // }
        free(row_pointers);

        fclose(fp);
}

void process_image()
{
#if defined(TOGRAY_V0)
#define OUTPUT "gray_v0.png"
        rgba_to_bw((uint32_t *) *row_pointers, width, height, stride);

#elif defined(TOGRAY_V1)
#define OUTPUT "gray_v1.png"
        rgba_to_bw_v1((uint32_t *) *row_pointers, width, height, stride);

#elif defined(TOGRAY_V2)
#define OUTPUT "gray_v2.png"
        rgba_to_bw_v2((uint32_t *) *row_pointers, width, height, stride);

#elif defined(TOGRAY_V3)
#define OUTPUT "gray_v3.png"
        rgba_to_bw_v3((uint32_t *) *row_pointers, width, height, stride);
#else
#error "See makefile"
#endif
}

int main(int argc, char *argv[])
{
        read_image("sample.png");

        clock_t begin = clock();
        process_image();
        printf("process image time elapsed: %f\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
        write_image(OUTPUT);

        // for generate table
#if 0
        int r = 0;
        for (int i = 0; i < 256; i++) {
                r = i * 0.587;
                //r = i * 0.114;
                //r = i * 0.114;
                printf("%d, ", r);
        }
        printf("\n");
#endif

        return 0;
}
