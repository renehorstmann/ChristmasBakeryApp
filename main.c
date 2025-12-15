/**
 * Welcome to Mia :)
 * This will be the starting point of the app
 *      (at the end of this file is the main function)
 * Feel free to tinker around.
 * Or start the Examples App; Tea App or Mia Paint.
 *
 * Also have a look at the examples which act as a tutorial for coding in Mia ;)
 */

/** Only for the file containing the real main() function, before importing anything else */
#define MIA_MAIN

/**
 * Includes most of Mia
 * This header is located under "./include/mia.h";
 * The include directory "./include" may be used for your user code ( as well as this "./src" dir)
 */
#include "mia.h"



/**
 * Context Data for the hello world AView
 */
struct context {
    vec4 bg_color;
};


/**
 * Called once at start of this AView
 * @param view AView object
 */
static void setup(oobj view)
{
    /** Get user context */
    struct context *C = o_user_new0(view, *C, 1);

    /** Logs an info string, works with formatting like printf */
    o_log("hello world");

    /** Setting some values in the context */
    C->bg_color = R_GRAY_X(0.33);
}

/**
 * Called every frame before rendering to handle simulation, events, etc.
 * @param view AView object
 * @param tex RTex to render to (or NULL for the backbuffer...)
 *            Even if available, please render in the render function
 * @param dt delta time in seconds (time between this and the last frame)
 */
static void update(oobj view, oobj tex, float dt)
{
    struct context *C = o_user(view);

    /** nothing to do here... */

}

/**
 * Called every frame to render
 */
static void render(oobj view, oobj tex, float dt)
{
    struct context *C = o_user(view);

    /** clear the screen with the background color */
    RTex_clear_full(tex, C->bg_color);

    /** Renders the render object hello onto tex */
    RTex_text(tex, "HELLO WORLD", 0, 0, RTex_font35_shadow, R_WHITE);
}



/**
 * Starting point of the mia app with all systems initialized
 * @param root OObj to allocate on, acts as root parent for all objects
 */
static void app_main(oobj root)
{
    /**
     * AScene with the AView of this main.c hello world file
     */
    oobj view = AView_new(root, setup, update, render);
    oobj scene = AScene_new(root, view, true, AScene_SAFE);
    AScene_opaque_set(scene, false);
}


/**
 * Actual c main entry point.
 * This file needs "#define MIA_MAIN" before the includes...
 */
int main(int argc, char **argv)
{
    struct a_app_run_options options = a_app_run_options_default();
    options.mic_enable = true;
    // options.log_level = O_LOG_TRACE;

    a_app_run(app_main, &options);
    return 0;
}