//
// Created by Michiel van 't Klooster on 28/02/2025.
//

#ifndef MENU_H
#define MENU_H

typedef struct menu_s menu_t;

menu_t  menu_create(int width, int height);
void    menu_draw(menu_t *menu);

#endif //MENU_H
