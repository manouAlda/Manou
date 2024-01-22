#include <stdio.h>
#include <gtk/gtk.h>

static void check_state(GtkWidget* widget,gpointer data){
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
		g_print("THE toggle button activated");
	}else {
		g_print("The toggle is unactived");
	}
}

int main(int argc,char** argv){

	gtk_init(&argc,&argv);
	
	GtkWidget *fenetre,*toggle,*vbox;
	
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect (fenetre, "destroy", G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_set_size_request(fenetre,800,500);
	gtk_window_set_title(GTK_WINDOW(fenetre),"Manou");
	
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	//toggle = gtk_toggle_button_new_with_mnemonic("_Toggle 1");
	toggle = gtk_check_button_new_with_mnemonic("_Toggle 1");
	gtk_box_pack_start(GTK_BOX(vbox),toggle,0,0,0);
	g_signal_connect(toggle,"toggle",G_CALLBACK(check_state),NULL);
	
	//toggle = gtk_toggle_button_new_with_mnemonic("_Toggle 2");
	toggle = gtk_check_button_new_with_mnemonic("_Toggle 2");
	gtk_box_pack_start(GTK_BOX(vbox),toggle,0,0,0);
	g_signal_connect(toggle,"toggle",G_CALLBACK(check_state),NULL);
	
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle),TRUE); ///activer le ttoggle
	
	gtk_container_add(GTK_CONTAINER(fenetre),vbox);
	
	gtk_widget_show_all (fenetre);
	
	gtk_main ();

	return 0;
}
