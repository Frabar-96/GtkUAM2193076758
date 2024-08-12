/**
* gcc hello-world-gtk.c $(pkg-config --cflags --libs gtk+-3.0) -o hello-world-gtk
*./hello-button-gtk
*Victor Manuel Fragoso Barrera
*
**/


#include <gtk/gtk.h>

static void activate_cb(GtkApplication *app, gpointer user_data) {
    GtkWindow *window;
    GtkWidget *label;

    window = GTK_WINDOW(gtk_application_window_new(app));
    gtk_window_set_title(window, "Hello World!-VictorFB");
    gtk_window_set_default_size(window, 400, 300);

    label = gtk_label_new("Hello World!");
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show(label);

    gtk_window_present(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.sadiqpk.example", 0);
    g_signal_connect(app, "activate", G_CALLBACK(activate_cb), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
