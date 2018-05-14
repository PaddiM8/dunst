#ifndef DUNST_OUTPUT_H
#define DUNST_OUTPUT_H

#include <stdbool.h>
#include <glib.h>
#include <cairo.h>

typedef gpointer window;

struct dimensions {
        int x;
        int y;
        int w;
        int h;
};

struct output {
        void (*init)(void);
        void (*deinit)(void);

        window (*win_create)(void);
        void (*win_destroy)(window);

        void (*win_show)(window);
        void (*win_hide)(window);

        void (*display_surface)(cairo_surface_t *srf, window win, const struct dimensions*);

        bool (*win_visible)(window);
        cairo_t* (*win_get_context)(window);

        bool (*is_idle)(void);
        bool (*have_fullscreen_window)(void);
};

const struct output* output_create(void);

#endif
