/**
*hellolabelEXE
* gcc hello-label-gtk.c $(pkg-config --cflags --libs gtk+-3.0) -o hellolabelEXE
*./hellolabelEXE
*VictorManuelFragosoBarrera
**/

#include <gtk/gtk.h>

static void activate_cb(GtkApplication *app, gpointer user_data) {
    GtkWindow *window;
    GtkWidget *label;

    // Crear una nueva ventana
    window = GTK_WINDOW(gtk_application_window_new(app));
    gtk_window_set_title(window, "Hello World Title!");
    gtk_window_set_default_size(window, 400, 300);

    // Crear y agregar la etiqueta a la ventana
    label = gtk_label_new("Hello World!-VictorFB");
    gtk_container_add(GTK_CONTAINER(window), label);

    // Mostrar la ventana y todos los widgets contenidos
    gtk_widget_show_all(GTK_WIDGET(window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // Crear la aplicación GTK
    app = gtk_application_new("uam.azc.ia.example", 0);
    g_signal_connect(app, "activate", G_CALLBACK(activate_cb), NULL);

    // Ejecutar la aplicación
    status = g_application_run(G_APPLICATION(app), argc, argv);

    // Liberar la memoria utilizada por la aplicación
    g_object_unref(app);

    return status;
}
