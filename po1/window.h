#pragma once
#include "allegro_includes.h"
#include "config.h"

namespace window {
    void render_frame();
    void clear();
    void get_event(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT* event);
}