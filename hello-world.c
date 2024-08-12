/**
*gcc `pkg-config --cflags gtk+-3.0` hello-world.c -o helloWorldEXE `pkg-config --libs gtk+-3.0`
*./helloWorldEXE
*Victor Manuel Fragoso Barrera
**/

#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World-VictorFB\n");
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    g_print("Delete event occurred\n");
    return TRUE;
}

void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    // Crear la ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Conectar señales de "delete_event" y "destroy"
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

    // Establecer el borde de la ventana
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Crear un botón con la etiqueta "Hello World-VictorFB"
    button = gtk_button_new_with_label("Hello World-VictorFB");

    // Conectar la señal "clicked" del botón para imprimir "Hello World-VictorFB"
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(hello), NULL);

    // Conectar la señal "clicked" para destruir la ventana cuando se haga clic en el botón
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

    // Agregar el botón a la ventana
    gtk_container_add(GTK_CONTAINER(window), button);

    // Mostrar el botón y la ventana
    gtk_widget_show(button);
    gtk_widget_show(window);

    // Entrar en el bucle principal de GTK
    gtk_main();

    return 0;
}
