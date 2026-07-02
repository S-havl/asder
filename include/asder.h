#pragma once

typedef struct {
    int width;
    int height;
    char* buffer;
} Canvas;

Canvas* init_canvas(int width, int height);
void free_canvas(Canvas* canvas);
void draw_pixel(Canvas* canvas, int x, int y, char c);
void draw_line(Canvas* canvas, int x0, int y0, int x1, int y1, char c);
void render_canvas(Canvas* canvas);
