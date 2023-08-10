int test (int taille,int* tab){
	int n=0;
	for(int i=taille-1;i>0; i--){
		if(tab[i]>tab[i-1]){
			n=1;
		}
		else{
			break;
		}
	}
	return n;
}
int* del (int* tab,int taille,int pos){
	for(int j=pos;j<taille-1;j++){
		tab[j]=tab[j+1];		
	}
	return tab;
}
