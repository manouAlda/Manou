int** allouer(int line,int cols){
	int **tab=NULL;
	tab=(int**)malloc(sizeof(int*)*line);
	for(int i=0;i<line;i++){
		*(tab+i)=(void*)calloc(cols,sizeof(int)*cols);
	}
	return tab;
}
int** print (int line,int cols,int** tab){
	for(int i=0;i<line;i++){
		for(int j=0;j<cols;j++){
			printf("%d\t",*(*(tab+i)+j));
		}
		printf("\n");
	}
	return tab;
}
int** enter (int line,int cols,int** tab){
	for(int i=0;i<line;i++){
		for(int j=0;j<cols;j++){
			scanf("%d",(*(tab+i)+j));
		}
		printf("\n");
	}
	return tab;
}
