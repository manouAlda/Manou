#include <stdio.h>
#include <gtk/gtk.h>

static void toucher (GtkButton *button,gpointer user_data){
	const gchar *button_label;
	button_label = gtk_button_get_label(button);
	GtkWidget *label;
	label = GTK_WIDGET(user_data);
	gchar *message;
	message = g_strdup_printf("'%s'",button_label);
	gtk_label_set_text(GTK_LABEL(label),message);
	g_free(message);
}

static void activate (GtkApplication *app, gpointer user_data){
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *texte[10];
	GtkWidget *grid;
	GtkWidget *label;
	//gchar* sUtf8;
	
	window= gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window),"Test");
	gtk_window_set_default_size(GTK_WINDOW(window),800,500);
	
	texte[0] = gtk_button_new_with_label ( "Fichier" );
	texte[1] = gtk_button_new_with_label ( "Editer" );
	texte[2] = gtk_button_new_with_label ( "Rechercher" );
	texte[3] = gtk_button_new_with_label ( "Affichage" );
	texte[4] = gtk_button_new_with_label ( "Projet" );
	texte[5] = gtk_button_new_with_label ( "Construire" );
	texte[6] = gtk_button_new_with_label ( "Outils" );
	texte[7] = gtk_button_new_with_label ( "Manuel" );
	texte[8] = gtk_button_new_with_label ( "Aide" );
	texte[9] = gtk_button_new_with_label ( "" );
	
	grid = gtk_grid_new ();
	gtk_grid_set_row_spacing (GTK_GRID(grid),5);
	
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_container_set_border_width(GTK_CONTAINER(vbox),10);
	
	label= gtk_label_new ("Cliquez sur un boutton\n");
	gtk_label_set_yalign(GTK_LABEL(label),GTK_ALIGN_CENTER);
	
	g_signal_connect(G_OBJECT(texte[0]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[1]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[2]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[3]),"clicked",G_CALLBACK(toucher), label);
	
	//box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
	
	gtk_grid_attach(GTK_GRID(grid),texte[0],0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[1],1,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[2],2,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[3],3,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[4],4,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[5],5,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[6],6,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[7],7,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),texte[8],8,0,1,1);
	
	gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,0);
	
	//gtk_container_add(GTK_CONTAINER(window), box);
	gtk_container_add (GTK_CONTAINER(window),grid);
	
	
	g_signal_connect(G_OBJECT(texte[4]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[5]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[6]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[7]),"clicked",G_CALLBACK(toucher), label);
	g_signal_connect(G_OBJECT(texte[8]),"clicked",G_CALLBACK(toucher), label);
	
	//gtk_container_add (GTK_CONTAINER(window),label);
	
	gtk_widget_show_all(window);
	
}

int main(int argc,char** argv){

	GtkApplication *app;
	
	int ret;
	
	app = gtk_application_new("manou.l", G_APPLICATION_FLAGS_NONE);
	
	g_signal_connect (app, "activate", G_CALLBACK(activate),NULL);
	
	ret = g_application_run  (G_APPLICATION(app), argc, argv);

	g_object_unref (app);
	
	

	return ret;
}
