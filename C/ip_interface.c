#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "ip.h"

void calculateIP(GtkWidget *widget, gpointer data){
	GtkWidget* ip = GTK_WIDGET(data);
	GtkWidget* mask = GTK_WIDGET(g_object_get_data(G_OBJECT(widget),"masc"));
	GtkWidget* host = GTK_WIDGET(g_object_get_data(G_OBJECT(widget),"host"));
	GtkWidget* result = GTK_WIDGET(g_object_get_data(G_OBJECT(widget),"result"));
	
	const gchar* ip_str = gtk_entry_get_text(GTK_ENTRY(ip));
	const gchar* mask_str = gtk_entry_get_text(GTK_ENTRY(mask));
	const gchar* host_str = gtk_entry_get_text(GTK_ENTRY(host));
	
	int test=0;
    test = testons(ip_str);

    if(test==0 || test==1 || test==2){
	   	 ip_str = asiana_point(ip_str);
    }
    
    else if(test==3 || test==4){
    	test = if_ip(ip_str);
    	if(test==1) printf("IPV4 trouve\n");
    	else if(test==0){
    		printf("erreur, ce n'est pas une adresse ip\n");
    	}
    }
    
    /// Masque de sous reseau
    int pow_two[8] = {128,64,32,16,8,4,2,1};
    const char* subnet = malloc(50);
    if(strcmp(host_str,"")!=0){
		subnet = msr(ip_str,host_str,pow_two);
	}else if(strcmp(mask_str,"")!=0){
		subnet = strdup(mask_str);
	}
		
	/// Hosts
	if (strcmp(host_str,"")==0 || strcmp(mask_str,"")!=0){
		host_str = bits(mask_str,pow_two);
	}
	printf("Hosts : %f\n",power(host_str)-2);
		
  /// Adresse reseau
   const char* reseau =malloc(50);
   const char* first_h = malloc(50);
    reseau = search_reseau(ip_str,host_str,pow_two);
    first_h = first(reseau);
    
   /// Adresse broadcast
   const char* broadcast = search_broadcast(ip_str,host_str,pow_two);
   const char* last_h = malloc(50);
    last_h = last(broadcast);
    
    subnet = finish(subnet);
    reseau = finish(reseau);
    broadcast = finish(broadcast);
	
	gchar result_text[256];
	snprintf(result_text, sizeof(result_text),
			"IP Address       :  %s/%s\n"
             "Subnet Address  :  %s\n"
             "Host Bits       :  %f\n"
             "Network Address :  %s\n"
             "First IP        :  %s\n"
             "Last IP         :  %s\n"
             "Broadcast Address: %s\n",
             ip_str,host_str,
             subnet,power(host_str)-2,
             reseau,first_h,
             last_h,broadcast
             );

	
	gtk_label_set_text(GTK_LABEL(result),result_text);
}

int main(int argc,char** argv){
/// Creation window
	gtk_init(&argc,&argv);
	
	GtkWidget* fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(fenetre),"IP Calculator");
	gtk_container_set_border_width(GTK_CONTAINER(fenetre),10);
	gtk_widget_set_size_request(fenetre, 400,200);
	
///quit window 
	g_signal_connect(fenetre,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
///ao anatiny
	GtkWidget* grille = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(fenetre),grille);

	GtkWidget* label= gtk_label_new("IP Adress : ");
	gtk_grid_attach(GTK_GRID(grille),label, 0, 0, 1, 1);
	
	GtkWidget *label_mask = gtk_label_new("Subnet Mask:");
    gtk_grid_attach(GTK_GRID(grille), label_mask, 0, 1, 1, 1);
    
    GtkWidget *slash = gtk_label_new("/");
    gtk_grid_attach(GTK_GRID(grille), slash, 2, 0, 1, 1);
	// Entree de donnee
	GtkWidget* ip= gtk_entry_new();
	 gtk_entry_set_placeholder_text(GTK_ENTRY(ip), "192.168.2.73");
	 gtk_grid_attach(GTK_GRID(grille), ip, 1, 0, 1, 1);
    
    GtkWidget *masc = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(masc), "255.255.255.192");
    gtk_grid_attach(GTK_GRID(grille), masc, 1, 1, 1, 1);
    
    GtkWidget *host = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(host), "26");
    gtk_grid_attach(GTK_GRID(grille), host, 3, 0, 1, 1);
    
    GtkWidget* result = gtk_label_new(NULL);
    gtk_grid_attach(GTK_GRID(grille), result, 0, 5, 1, 1);
    
    //Calculate
    GtkWidget* calc_button= gtk_button_new_with_label("Calculate");
    gtk_grid_attach(GTK_GRID(grille), calc_button, 0, 2, 6, 1);
    
    //Recuperer les valeurs
    g_signal_connect(calc_button, "clicked", G_CALLBACK(calculateIP), ip);
	
	g_object_set_data(G_OBJECT(calc_button),"masc",masc);
	
	g_object_set_data(G_OBJECT(calc_button),"host",host);
	
	g_object_set_data(G_OBJECT(calc_button),"result",result);
	
	gtk_widget_show_all(fenetre);
	
	gtk_main();

	return 0;
}
