#pragma once

typedef struct {
    int width;
    int height;
    char* buffer;
} Canvas_t;

Canvas_t* init_canvas(int width, int height);
void free_canvas(Canvas_t* canvas);
void draw_pixel(Canvas_t* canvas, int x, int y, char c);
void draw_line(Canvas_t* canvas, int x0, int y0, int x1, int y1, char c);
void render_canvas(Canvas_t* canvas);
