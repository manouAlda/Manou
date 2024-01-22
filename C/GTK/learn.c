#include <stdio.h>
#include <gtk/gtk.h>

static void button_clicked (GtkWidget* widget,gpointer user_data){
	gtk_label_set_text(GTK_LABEL(user_data),"Cliqué");
}

int main(int argc,char** argv){

	gtk_init(&argc,&argv);
	
	GtkWidget *fenetre,*label,*button,*hbox;
	
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect (fenetre, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_set_size_request(fenetre,800,500);
	gtk_window_set_title(GTK_WINDOW(fenetre),"Manou");
	
	label = gtk_label_new("Hello you!");
	button = gtk_button_new_with_label("Click me!");
	
	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),(gpointer)label);
	
	hbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_box_pack_start(GTK_BOX(hbox),label,0,0,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,0,0,0);
	
	gtk_container_add(GTK_CONTAINER(fenetre),hbox);
	
	gtk_widget_show_all (fenetre);
	
	gtk_main ();

	return 0;
}
