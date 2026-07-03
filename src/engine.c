#include "../include/asder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Canvas_t* init_canvas(int width, int height)
{
    Canvas_t* canvas = malloc(sizeof(Canvas_t));
    if (!canvas) return NULL;
    
    canvas->width = width;
    canvas->height = height;
    canvas->buffer = malloc(width * height * sizeof(char));
    
    if (canvas->buffer) {
        memset(canvas->buffer, '.', width * height);
    }
    return canvas;
}

void free_canvas(Canvas_t* canvas)
{
    if (canvas) {
        free(canvas->buffer);
        free(canvas);
    }
}

void draw_pixel(Canvas_t* canvas, int x, int y, char c)
{
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->buffer[y * canvas->width + x] = c;
    }
}

void draw_line(Canvas_t* canvas, int x0, int y0, int x1, int y1, char c)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        draw_pixel(canvas, x0, y0, c);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void render_canvas(Canvas_t* canvas)
{
    printf("\033[H");
    
    for (int y = 0; y < canvas->height; y++) {
        fwrite(&canvas->buffer[y * canvas->width], sizeof(char), canvas->width, stdout);
        putchar('\n');
    }
    fflush(stdout);
}
