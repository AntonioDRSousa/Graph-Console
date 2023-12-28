#include<stdio.h>
#include "bipart.h"

extern int n;
extern int M[10000][10000];
int A[10000][10000]; //arvore geradora

void imprArvGeradora(){
	register int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}

void initArvore(){
	register int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
}

int teste(int * c){
	for(register int i=0;i<n;i++){
		if(c[i]!=0){
			return 1;
		}
	}
	return 0;
}

void arvoreGeradora(){
	register int i,j;
	int t;
	int c[10000];

	initArvore();
	for(i=0;i<n;i++){
		c[i]=i;
	}
	while(true){
	    t=teste(c);
	    if(t==0){
	        break;
	    }
		for(i=0;i<n;i++){
			if(c[i]==0){
				for(j=0;j<n;j++){
					if((c[j]!=0) && M[i][j]==1){
						A[i][j]=1;
						A[j][i]=1;
						c[j]=0;
					}
				}
			}
		}
	}		
}

void Conexidade(){
	if(conexo()){
		arvoreGeradora();
	    imprArvGeradora();
	}
	else{
	     printf("Nao e' conexo\n");
	}
}
