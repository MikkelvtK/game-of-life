//
// Created by Michiel van 't Klooster on 28/02/2025.
//

#include "menu.h"
#include <raylib.h>
#include <stdlib.h>

struct menu_s {
    int width;
    int height;
    Vector2 pos;
    char *text;
};

static const int font_size = 18;
static const Color font_color = LIGHTGRAY;

menu_t* menu_create(int width, int height, Vector2 pos) {
    menu_t *menu = malloc(sizeof(struct menu_s));
    if (menu == NULL) {
        return NULL;
    }

    char *text = "<SPACE> Pause";
    menu->width = width;
    menu->height = height;
    menu->pos = pos;
    menu->text = text;
    return menu;
}

void menu_draw(menu_t *menu) {
    const Vector2 text_pos = {
        .x = (float) menu->width / 5 + menu->pos.x,
        .y = (float) menu->height / 2 + menu->pos.y,
    };
    DrawText(menu->text, (int) text_pos.x, (int) text_pos.y, font_size, font_color);
}

void menu_destroy(menu_t **menu) {
    free(*menu);
    *menu = NULL;
}
