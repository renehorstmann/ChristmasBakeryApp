#define MIA_MAIN
#include "mia.h"

struct context {
    vec4 bg_color;
};


static void setup(oobj view)
{
    struct context *C = o_user_new0(view, *C, 1);
    o_log("hello world");
    C->bg_color = R_GRAY_X(0.33);
}

static void update(oobj view, oobj tex, float dt)
{
    struct context *C = o_user(view);

}

static void render(oobj view, oobj tex, float dt)
{
    struct context *C = o_user(view);
    RTex_clear_full(tex, C->bg_color);
    RTex_text(tex, "CHRISTMAS BAKERY", 0, 0, RTex_font35_shadow, R_WHITE);
}

static void app_main(oobj root)
{
    oobj view = AView_new(root, setup, update, render);
    oobj scene = AScene_new(root, view, true, AScene_SAFE);
    AScene_opaque_set(scene, false);
}

int main(int argc, char **argv)
{
    struct a_app_run_options options = a_app_run_options_default();
    options.mic_enable = true;
    // options.log_level = O_LOG_TRACE;

    a_app_run(app_main, &options);
    return 0;
}
