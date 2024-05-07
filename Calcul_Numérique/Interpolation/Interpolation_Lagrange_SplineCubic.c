#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

void getData(char *filename,char *data,int *dim,float *xmin,float *xmax,float *ymin,float *ymax,float **xd,float **yd);
void plot(float xmin,float xmax,float ymin,float ymax, float *xd, float *yd, int dim,float *s,float *a,float *b);
float lagrange(float x,float *xd,float *yd,int dim);
void splineCubic(int dim,float *xd, float *yd, float **s, float **a, float **b) ;

int main(){
	printf("Inperpolation\n");
	
/// Données
	char *filename = "dataInterpolation.txt";
	char *data = "plotInterpolation.txt";
	int dim = 0;
	float	xmin =0,
			xmax = 0,
			ymin = 0,
			ymax = 0;
	float	*xd = NULL,
			*yd = NULL,
			*s = NULL, 
			*a = NULL, 
			*b = NULL;
	
	getData(filename, data, &dim,&xmin, &xmax, &ymin, &ymax, &xd, &yd);
	
	
/// Traitement
	splineCubic(dim, xd, yd, &s, &a, &b);
	
/// Plot
	plot(xmin, xmax, ymin, ymax, xd,yd, dim, s, a, b);
	
	free(xd);		free(yd);
	free(a);	free(b);	free(s);

	return 0;
}

void erreur(char * s){
	printf("%s\n",s);
}

float *newVect(int dim){
	float *v = NULL;
	v = (float*)calloc(dim,sizeof(float));
	if(v==NULL)	erreur("Impossible d'ouvrir le fichier\n");
	return v;
}

float lagrange(float x,float *xd,float *yd,int dim){
	/// Produit des termes 	L_i(x)
	float tmp = 0;
	float y = 0;
	
	for(int i=0; i<dim; i++){
		tmp=1;
		for(int j=0; j<dim; j++){
			if(i!=j){
				tmp *= (x-xd[j])/(xd[i]-xd[j]);
			}
		}
		y += yd[i]*tmp;
	}
	
	return y;
}

void calculateAjBj(int n, float* a, float* b, float *dx, float *yd, float *S) {
    for (int j = 0; j < n-1; j++) {
        a[j] = (yd[j]/dx[j]) - (S[j]*(dx[j]/6));
        b[j] = (yd[j+1] / (dx[j])) - (S[j+1] * (((dx[j])/6)));
    }
}

void tridiag(float *a, float *b, float *c,float *r, float *u, int n){
    int j;
    float bet, gam[n];

    if (b[0] == 0.0) erreur("Division par 0");
    u[0] = r[0] / (bet=b[0]);
    for (j = 1; j < n; j++) {
        gam[j] = c[j-1]/bet;
        bet = b[j] - a[j]*gam[j];
        if (bet == 0.0) erreur("Division par 0");
        u[j] = (r[j]-a[j]*u[j-1]) / bet;
    }
    for (j = n-2; j >= 0; j--)
        u[j] -= gam[j+1]*u[j+1];
}

void solveS2(float* lambda, float* rho, float *Y, float *s2, int dim){
    float *B=NULL, *C=NULL, *D=NULL;
    int j=0;

    B = newVect(dim);			// diagonale principale
    C = newVect(dim);			// première surdiagonale
    D = newVect(dim);			// première sous-diagonale
    for(j=0; j<dim; j++){
        B[j] = 2;
        C[j] = lambda[j];		// on ne suppose pas que les points sont équidistants
        D[j] = rho[j];
    }
    tridiag(D,B,C,Y,s2,dim);
    free(B);	free(C);	free(D);
 }
 
float** allouer (int dim){
    float** tab = NULL;
    tab = (float**)calloc(dim,sizeof(float*));
    for(int i=0;i<dim;i++){
        tab[i]=(float*)calloc(dim,sizeof(float));
    }
    return tab;
}
 
 void gauss(float **A,float *B,float *x,int dim, int *p){	
	float tmp=0;
	/// Triangularisation de la matrice
	float piv=0;
	int lpiv=0, t=0;
	
    for(int k=0; k< dim; k++){
		
		lpiv=k;
		piv=fabs(*(*(A+p[k])+k));      /// Zay valeur absolue any geza no atao pivot
		for(int i = k+1; i<dim; i++){	
			if(piv < fabs(*(*(A+p[i])+k))) {
				piv = fabs ( *(*(A+p[i])+k) );
				lpiv=i;
			}
		}
		
		t = p[k];
		p[k]=p[lpiv];				
		p[lpiv]=t;
		
        for(int i = k+1; i<dim; i++){
			
            for(int j=k+1; j<dim; j++){
				
				if(*(*(A+p[k])+k)!=0 || *(*(A+p[k])+j)!=0){
					*(*(A+p[i])+j) = *(*(A+p[i])+j) - *(*(A+p[i])+k) / *(*(A+p[k])+k) * *(*(A+p[k])+j) ;
				}
            }  
            if(*(*(A+p[k])+k)!=0 || *(B+p[k])!=0){ 
				*(B+p[i]) = *(B+p[i]) -  *(*(A+p[i])+k) / *(*(A+p[k])+k) * *(B+p[k]);
			}
            *(*(A+p[i])+k) = 0;
        }
    }

    /// Resolution de lA matrice triangularisee
    
	for(int i=dim-1; i>=0; i--){
		tmp=0;
		for(int j=i+1; j<dim; j++){
			tmp += *(*(A+p[i])+j) * (*(x+j)) ;
		}
		x[i]= (1/ *(*(A+p[i])+i) ) * ( *(B+p[i]) - tmp ) ; 
    }
}

void cholesky(float **A, float *B, float *x, int dim) {
        float **c = NULL;
    float **ct = NULL;
    float *y = NULL;
    
    c = allouer(dim);
    ct = allouer(dim); 
    y = newVect(dim);

    // Factorisation de A = B.Bt
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
			float tmp = 0;
			for (int k = 0; k < j; k++) {
				tmp += c[i][k] * c[j][k];
			}
            if (j < i) {
				if(c[j][j]!=0)	c[i][j] = (A[i][j] - tmp) / c[j][j];
            } else if (j > i) {
                c[i][j] = 0;
            } else if (i == j) {
                c[i][i] = sqrt(A[i][i] - tmp);
            }
        }
    }

	/// Resolution pour avoir le second membre y
    for (int i = 0; i < dim; i++) {
        float tmp = 0;
        for (int j = 0; j < i; j++) {
            tmp += c[i][j] * y[j];
        }
        if(c[i][i]!=0)	y[i] = (1 / c[i][i]) * (B[i] - tmp);
    }

    // Transposer la matrice c pour obtenir ct
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            ct[i][j] = c[j][i];
        }
    }

    for (int i = dim - 1; i >= 0; i--) {
        float tmp = 0;
        for (int j = i + 1; j < dim; j++) {
            tmp += ct[i][j] * x[j];
        }
        if(ct[i][i]!=0)		x[i] = (1 / ct[i][i]) * (y[i] - tmp);
    }

    for (int i = 0; i < dim; i++) {
        free(c[i]);
        free(ct[i]);
    }
    free(c);
    free(ct);
    free(y);
}

void splineCubic(int dim,float *xd, float *yd, float **s, float **a, float **b) {
    int n = dim;
	float	*dx = newVect(n),
			*l = newVect(n),
		 	*roh = newVect(n),
		 	*Y = newVect(n),
		 	*s2t = newVect(n),
		 	*at = newVect(n-1),
		 	*bt = newVect(n-1);
    
    /// Traitement
    for(int i=0;i<n-1;i++) dx[i] =xd[i+1] - xd[i];
    
    for(int j=1; j<n; j++){
		l[j] = dx[j]  / ( dx[j-1] + dx[j] );
	}
	for(int j=1; j<n-1; j++){
		roh[j-1] = 1 - l[j];
	}
	
	//Second membre du systeme tridiag. sym. pour le calcul de *s2
	Y = newVect(n);
	
	/// vecteur Y
	for(int j=1; j<n-1; j++){
		Y[j-1] = (6/ ( (dx[j-1]) + dx[j] ) )*( (yd[j+1]-yd[j]/ (dx[j]) )-(yd[j]-yd[j-1]/ dx[j-1]  ) ) ;	
	}
	
	// Calcul de S2
	s2t[0]=0;
	s2t[n-1]=0;
	
	float **M = allouer(n);
	int *p = (int*)calloc(dim,sizeof(int));
	for(int i=0; i<n; i++)	p[i]=i;
	
	/// Matrice S2
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			if(i==j)	M[i][j] = 2;
			else if(i==j+1)		M[i][j] = l[j];
			else if(j==i+1)		M[i][j] = roh[i];
			else M[i][j] = 0;
		}
	}
	
	float **A = allouer(n-2);
	for(int i=0; i<n-2; i++){
		for(int j=0; j<n-2; j++){
			A[i][j] = M[i+1][j+1];
		}
	}		
	
	s2t++;		// Les tableaux commencent à 1
	
	//solveS2(l, roh, Y, s2t, n-2);
	//gauss(A, Y, s2t, n-2, p);
	cholesky(A, Y, s2t, n-2);
	
	s2t--;
	
	at = newVect(n-1);
	bt = newVect(n-1);

	// Calcul de *a et *b
    calculateAjBj(n,at,bt,dx,yd,s2t);
    
    *s = s2t;
    *a = at;
    *b = bt;
    
    free(l);
    free(roh);
    free(Y);
	free(dx);
}

float cSpline(float x,float *xd,float *yd,float *s,float *a,float *b,int dim){
	float y = 0;
	float min =0, max = 0;
	int place = 0;
	
		for(int i=0; i<dim; i++){
			min = xd[i];
			max = xd[i+1];
			
			if(	x>=min && x<=max ){
				place = min;
				y = (  ( s[place]*pow(xd[place+1]-x,3) + s[place+1]*pow(x-xd[place],3) ) )/6*(xd[place+1]-xd[place]) +  ( a[place]*(xd[place+1]-x) ) + ( b[place]*(x-xd[place]) ) ;
		
				break;
			}
		}

	return  y;
}

void getData(char *filename,char *data,int *dim,float *xmin,float *xmax,float *ymin,float *ymax,float **xd,float **yd) {
	FILE *f = NULL;
	FILE *file = NULL;
	int number=0,col=0;
	float 	x = 1e-7,
			y = 1e-7;
	float	*xt = NULL,
			*yt = NULL;
	
	f = fopen(filename,"r");
	file = fopen(data,"w");
	
	if(f){
		fscanf(f, "%d", &number);
		fscanf(f, "%d", &col);
		
		xt = newVect(number);
		yt = newVect(number);
		
		if(file){
			for(int i=0; i<number; i++){
				fscanf(f, "%f %f", &x,&y);
				fprintf(file, "%f %f\n", x,y);
			
				if(*ymin > y)	*ymin = y;
				if(*ymax < y)	*ymax = y;
				
				if(*xmin > x)	*xmin = x;
				if(*xmax < x)	*xmax = x;
				
				xt[i] = x;
				yt[i] = y;
			}

			fclose(file);
		}
		else{
			erreur("Erreur d'ouverture du fichier plotInterpolation\n");
		}
		
		fclose(f);
	}
	else{
		erreur("Erreur d'ouverture du fichier dataInterpolation\n");
	}
	
	*dim = number;
	*xd = xt;
	*yd = yt;
}

void plot(float xmin,float xmax,float ymin,float ymax, float *xd, float *yd, int dim,float *s,float *a,float *b){
	printf("xmin = %f \nxmax = %f\nymin = %f\nymax = %f\n",xmin,xmax,ymin,ymax);
	
	FILE *gp=popen("gnuplot -presist", "w");
	if(gp){
		fprintf(gp, "set term qt size 800, 600\n");
		fprintf(gp, "set term qt title 'Interpolation'\n");
		fprintf(gp, "set xrange [%g:%g]\n", xmin, xmax);
		
		
		// Put data in reusable internal data blocks
		
/// Ajustement lineaire
		fprintf(gp, "$data1 << EOF\n");
		for(int i=0; i<dim; i++){
			fprintf(gp, "%f %f\n", xd[i], yd[i]);
		}
		fprintf(gp,"EOF\n");
		
/// Methode de Lagrange
		fprintf(gp, "$data2 << EOF\n");
		int np = 100;
		float x = xmin, dx =(xmax-xmin)/(np-1) ;
		x -=dx;
		float y = 0;
		for(int i=0; i<np; i++){
			x += dx;
			y = lagrange(x, xd, yd, dim);
			if(ymin > y)	ymin = y;
			if(ymax < y)	ymax = y;
			
			fprintf(gp , "%f %f\n", x, y);
			
		}
		fprintf(gp, "EOF\n");
		
		fprintf(gp,	"set yrange [%g:%g]\n", ymin-1, ymax+1);
		
///Spline Cubic
		fprintf(gp, "$data3 << EOF\n");
		np = 200;
		x = xmin, dx = (xmax-xmin)/(np-1);
		x -= dx;
		for(int i=0; i<np ; i++){
			x += dx;
			y = cSpline(x, xd,yd, s, a, b, dim);
			fprintf(gp , "%f %f\n", x,y);
			printf("X -> %g		Y -> %f\n", x,y);
		}
		fprintf(gp, "EOF\n");
		
		fprintf(gp, "plot $data1  w linespoints pt 2 ps 1, $data2 using 1:2 w linespoints , $data3 using 1:2 w l lw 3\n");
		fflush(gp);
		pclose(gp);
	}
}
