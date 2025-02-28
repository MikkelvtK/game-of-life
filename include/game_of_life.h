//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define CELL_SIZE 4
#define ALIVE 1
#define DEAD 0

static const int screen_width = 1200;
static const int screen_height = 800;
static const int fps = 8;

void    init(void);
void    update_draw_frame(void);
void    cleanup(void);

#endif //GAME_OF_LIFE_H
