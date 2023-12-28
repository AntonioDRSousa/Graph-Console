#include "matadj.h"
#include "gspec.h"
#include<stdio.h>

extern int n;
extern int M[10000][10000];
int T[10000][10000];
int v;//numero de vertices do momento
int x,w;//x e' o numero cromatico, w e' a clique maxima

void initT(){
    int i,j;
    for(i=0;i<10000;i++){
        for(j=0;j<10000;j++){
            T[i][j]=0;
            M[i][j]=0;
        }
    }
}

void input(){
	while(true){
		printf("x =  ");
		if(0>=scanf("%d",&x)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
			continue;
		}
	
		if(x<1){
			printf("Erro. X<1.\n");
			continue;
		}
		else if(x>10000){
			printf("Erro. X>10000\n");
			continue;
		}
		break;
	}
	while(true){
		printf("w =  ");
		if(0>=scanf("%d",&w)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
			continue;
		}

		if(x<w){
			printf("Erro. X<W\n");
			continue;
		}
	
		if(w<1){
			printf("Erro. W<1.\n");
			continue;
		}
		else if(w>10000){
			printf("Erro. W>10000\n");
			continue;
		}
		break;
	}
}

void GeraKN(int w){
	int i,j;
	for(i=0;i<w;i++){
		for(j=0;j<w;j++){
			if(i!=j){
				T[i][j]=1;
			}
		}
	}
}

void copiar(){
    int i,j;
    for(i=v;i<2*v;i++){
        for(j=0;j<v;j++){
            T[i][j]=T[i-v][j];
            T[i-v][j+v]=T[i][j];
        }
    }
}

void zerar(){
    int i,j;
    for(i=v;i<2*v;i++){
        for(j=v;j<2*v;j++){
            T[i][j]=0;
        }
    }
}

void finaliza(){
    int i;
    for(i=v;i<2*v;i++){
        T[i][2*v]=1;
        T[2*v][i]=1;
    }
}
        
void GeraMy(int x,int w){
    if(x==w){
        GeraKN(w); 
    }
    else{
        GeraMy(x-1,w);
        copiar();
        zerar();
        finaliza();
        v=2*v+1;
    }
}

void transposta(){
	int i,j;
	n=v;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			M[i][j]=T[v-i-1][v-j-1];
		}
	}
}

void criaMy(){
    initT();
    input();
    v=w;
    GeraMy(x,w);
    transposta();
}

void imprMy(){
    int i,j;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}

void My(){
    criaMy();
    imprMy();
}
