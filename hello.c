/**
*gcc `pkg-config --cflags gtk+-3.0` hello.c -o helloEXE `pkg-config --libs gtk+-3.0`
*./helloEXE
*Victor Manuel Fragoso Barrera
*2193076758
**/

#include <gtk/gtk.h>

int main (int argc, char *argv[]){

	GtkWidget *window; 	//Se define un elemento visual: GTKWindget

	gtk_init(&argc, &argv);	//Se inicializa con el contexto de la linea de comando

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);	//Se crea la ventana a visualizar

	gtk_widget_show(window);	//Se muestra la ventana

	gtk_main();	//Se invoca el método main que procesa los eventos

	return 0;

}
