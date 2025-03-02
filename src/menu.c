//
// Created by Michiel van 't Klooster on 28/02/2025.
//

#include "menu.h"

#include <game_of_life.h>
#include <raylib.h>
#include <stdlib.h>

struct menu_s {
    int width;
    int height;
    Vector2 pos;
    char *text;
};

static const int font_size = 14;
static const Color font_color = LIGHTGRAY;

menu_t* menu_create(int width, int height, Vector2 pos) {
    menu_t *menu = malloc(sizeof(struct menu_s));
    if (menu == NULL) {
        return NULL;
    }

    char *text = "<SPACE> Pause | <R> Restart";
    menu->width = width;
    menu->height = height;
    menu->pos = pos;
    menu->text = text;
    return menu;
}

void menu_draw(menu_t *menu) {
    const Vector2 text_pos = {
        .x = (float) menu->width / 16 + menu->pos.x,
        .y = (float) menu->height / 2 - (float) (font_size / 2) + menu->pos.y,
    };

    DrawLine(menu->pos.x, menu->pos.y, menu->width, menu->pos.y, font_color);
    DrawText(menu->text, (int) text_pos.x, (int) text_pos.y, font_size, font_color);
}

void menu_destroy(menu_t **menu) {
    free(*menu);
    *menu = NULL;
}
