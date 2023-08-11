#include <stdio.h>
#include <gtk/gtk.h>

static void button_clicked (GtkWidget* widget,gpointer user_data){
	//gtk_label_set_text(GTK_LABEL(user_data),"Cliqué");
	g_print("%s\n",gtk_entry_get_text(GTK_ENTRY(user_data)));
	//gtk_entry_set_text(GTK_ENTRY(user_data),"Text printed");
	gtk_editable_select_region(GTK_EDITABLE(user_data),0,-1);
	gtk_editable_copy_clipboard(GTK_EDITABLE(user_data)); /// copier ,asan'ny ctrl+c'
}

int main(int argc,char** argv){

	gtk_init(&argc,&argv);
	
	GtkWidget *fenetre,*entry,*button,*hbox;
	
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect (fenetre, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_set_size_request(fenetre,800,500);
	gtk_window_set_title(GTK_WINDOW(fenetre),"Manou");
	
	entry= gtk_entry_new();
	button = gtk_button_new_with_mnemonic("_Write text");
	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),entry);
	g_signal_connect(button,"activate",G_CALLBACK(button_clicked),entry);
	hbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_box_pack_start(GTK_BOX(hbox),entry,0,0,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,0,0,0);
	
	gtk_container_add(GTK_CONTAINER(fenetre),hbox);
	
	gtk_widget_show_all (fenetre);
	
	gtk_main ();

	return 0;
}
