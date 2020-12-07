#include <gtk/gtk.h>
#include <iostream>

using namespace std;

GtkApplication *mApp;

static void on_activate(GtkApplication *app) {
   // Create a new window
   GtkWidget *window = gtk_application_window_new(app);
   // Create a new button
   GtkWidget *button = gtk_button_new_with_label("Hello, World!");
   // When the button is clicked, close the window passed as an argument
   g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close),
                            window);
   gtk_container_add(GTK_CONTAINER(window), button);
   gtk_widget_show_all(window);
}

int main(int argc, char** argv) {
   mApp = gtk_application_new("com.example.GtkApplication",
                       G_APPLICATION_FLAGS_NONE);

   g_signal_connect(mApp, "activate", G_CALLBACK(on_activate), NULL);

   cout << "Hello There\n";
   return g_application_run(G_APPLICATION(mApp), argc, argv);
}