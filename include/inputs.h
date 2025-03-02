//
// Created by Michiel van 't Klooster on 02/03/2025.
//

#ifndef INPUTS_H
#define INPUTS_H

#include "game_of_life.h"
#include "grid.h"

state_t handle_space(state_t current_state);
state_t handle_r(grid_t *grid);

#endif //INPUTS_H
