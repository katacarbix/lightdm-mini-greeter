/* lightdm-mini-greeter - A minimal GTK LightDM Greeter */
#include <sys/mman.h>

#include <gtk/gtk.h>

#include "app.h"
#include "utils.h"


int main(int argc, char **argv)
{
    mlockall(MCL_CURRENT | MCL_FUTURE);  // Keep data out of any swap devices

    App *app = initialize_app(argc, argv);

    connect_to_lightdm_daemon(app->greeter);
    begin_authentication_as_default_user(app);

    gtk_widget_show_all(GTK_WIDGET(APP_BACKGROUND_WINDOW(app)));
    gtk_widget_show_all(GTK_WIDGET(APP_MAIN_WINDOW(app)));
    gtk_window_present(APP_MAIN_WINDOW(app));
    gtk_main();

    destroy_app(app);
}
