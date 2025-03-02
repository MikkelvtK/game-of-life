//
// Created by Michiel van 't Klooster on 02/03/2025.
//

#include "inputs.h"
#include "game_of_life.h"

state_t handle_space(state_t current_state) {
    if (current_state == RUNNING)
        return PAUSED;
    return RUNNING;
}

state_t handle_r(grid_t *grid) {
    grid_randomize(grid);
    return RUNNING;
}
