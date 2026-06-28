#include "asder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void fill_framebuffer_for_canvas(int buffer_size, int height, int width, char framebuffer[height][width], char ascii_character) 
{
    memset(framebuffer, ascii_character, buffer_size);
}

static void show_framebuffer_from_canvas(int height, int width, char framebuffer[height][width]) 
{
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            putchar(framebuffer[h][w]);
        }
        putchar('\n');
    }
}

static void draw_ascii_pixel_to_buffer(int position_y, int position_x, int height, int width, char framebuffer[height][width], char pixel)
{
    framebuffer[position_y][position_x] = pixel;
}

int main(void) 
{
    char canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
    int canvas_size = sizeof(canvas);

    VecScreen_center screen_center = {
        .cx = CANVAS_WIDTH / 2,
        .cy = CANVAS_HEIGHT / 2
    };

    fill_framebuffer_for_canvas(canvas_size, CANVAS_HEIGHT, CANVAS_WIDTH, canvas, '.');
    draw_ascii_pixel_to_buffer(screen_center.cy, screen_center.cx, CANVAS_HEIGHT, CANVAS_WIDTH, canvas, '#');
    show_framebuffer_from_canvas(CANVAS_HEIGHT, CANVAS_WIDTH, canvas);

    return EXIT_SUCCESS;
}