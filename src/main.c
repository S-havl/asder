#include "../include/asder.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

void set_terminal_mode(int enable) {
    static struct termios oldt;
    if (enable) {
        struct termios newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        
        newt.c_cc[VMIN] = 0;
        newt.c_cc[VTIME] = 0;
        
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

int main(void) {
    Canvas* screen = init_canvas(100, 40);
    if (!screen) return EXIT_FAILURE;

    int player_x = 50;
    int player_y = 20;
    char input;

    printf("\033[2J");
    set_terminal_mode(1);

    while (1) {
        memset(screen->buffer, '.', screen->width * screen->height);

        draw_line(screen, 10, 10, 90, 30, '=');
        draw_pixel(screen, player_x, player_y, '#');

        render_canvas(screen);

        if (read(STDIN_FILENO, &input, 1) == 1) {
            if (input == 'q') break;
            
            if (input == 'w' && player_y > 0) player_y--;
            if (input == 's' && player_y < screen->height - 1) player_y++;
            if (input == 'a' && player_x > 0) player_x--;
            if (input == 'd' && player_x < screen->width - 1) player_x++;
        }
        
        usleep(30000);
    }

    set_terminal_mode(0);
    free_canvas(screen);
    printf("\033[2J\033[HEngine off.\n");

    return EXIT_SUCCESS;
}
