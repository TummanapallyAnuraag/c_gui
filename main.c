/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: My first GTK application, in C 
 *
 *        Version:  1.0
 *        Created:  31/10/20 10:13:15 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anuraag Tummanapally, 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <gtk/gtk.h>

static int counter = 0;

void greet(GtkWidget* widget, gpointer data)
{
    // printf equivalent in GTK+
    g_print("Welcome to GTK\n");
    g_print("%s clicked %d times\n",
            (char*)data, ++counter);
}

void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char* argv[])
{

    GtkWidget* window;
    GtkWidget* button;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect(window, "destroy",
                     G_CALLBACK(destroy), NULL);
    /* Let's set the border width of the window to 20.
    * You may play with the value and see the
    * difference. */
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    button = gtk_button_new_with_label("Click Me!");

    g_signal_connect(GTK_OBJECT(button),
                     "clicked", G_CALLBACK(greet),
                     "button");

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
