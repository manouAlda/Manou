#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

static void button_clicked (GtkWidget* widget,gpointer user_data){
	gtk_label_set_text(GTK_LABEL(user_data),"Cliqué");
}
static void menu_response(GtkWidget* menu_items,GtkWidget* fenetre,gpointer data){
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_items)),"New")==0){
		g_print("New\n");
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_items)),"Exit")==0){
		gtk_main_quit();
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_items)),"About")==0){
		g_print("man gtk\n");
	}
}

int main(int argc,char** argv){

	gtk_init(&argc,&argv);
	
	GtkWidget *fenetre,*menu_bar,*menu_items,*file_menu,*help,*vbox,*button;
	
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect (fenetre, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_set_size_request(fenetre,800,500);
	gtk_window_set_title(GTK_WINDOW(fenetre),"Manou");
	
	
//	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),(gpointer)label);
	
	menu_bar = gtk_menu_bar_new();
	
	file_menu = gtk_menu_new();
	help = gtk_menu_new();
	
	menu_items = gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_items),file_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_items);
	
	menu_items = gtk_menu_item_new_with_label("Help");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_items),help);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_items);
	
	menu_items = gtk_menu_item_new_with_label("New");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_items);
	g_signal_connect(menu_items,"activate",G_CALLBACK(menu_response),NULL);
	
	menu_items = gtk_menu_item_new_with_label("Exit");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_items);
	g_signal_connect(menu_items,"activate",G_CALLBACK(menu_response),NULL);
	
	menu_items = gtk_menu_item_new_with_label("About");
	gtk_menu_shell_append(GTK_MENU_SHELL(help),menu_items);
	g_signal_connect(menu_items,"activate",G_CALLBACK(menu_response),NULL);
	
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	button = gtk_button_new_with_label("Hello!");
	gtk_box_pack_start(GTK_BOX(vbox),menu_bar,0,0,0);
	gtk_box_pack_start(GTK_BOX(vbox),button,0,0,0);
	
	
	gtk_container_add(GTK_CONTAINER(fenetre),vbox);
	gtk_widget_show_all (fenetre);
	
	gtk_main ();

	return 0;
}
