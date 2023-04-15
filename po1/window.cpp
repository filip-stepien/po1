#include "window.h"

namespace window {
    void render_frame() {
        al_flip_display();
    }

    void clear() {
        al_draw_filled_rectangle(0, 0, config.window_width, config.window_height, al_map_rgb(0, 0, 0));
    }

    void get_event(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT* event) {
        al_wait_for_event(queue, event);
    }
}