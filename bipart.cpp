#include <queue>
#include<stdio.h>
#include "col.h"
using namespace std;

#define BRANCA 1
#define PRETA 2
#define CINZA 3

typedef struct biparticao{
	int v1[10000];
	int v2[10000];
	int n1;
	int n2;
	bool bip;//bipartido
	bool con;//conexo
}biparticao;

typedef struct vertice{
	short cor;
	int descoberta;
}vertice;

vertice V[10000];
extern int n;
extern int M[10000][10000];//matriz adjacencia

void initVer(){
	for(int i=1;i<=n;i++){
		vertice v;
		v.cor=1;
		v.descoberta=-1;
		V[i-1]=v;
	}
}

biparticao criaBiparticao(){
	biparticao bp;
	bp.n1=0;
	bp.n2=0;
	bp.con=true;
	return bp;
}

biparticao biparticiona(){
	int i;
	biparticao bp=criaBiparticao();
	
	for(i=0;i<n;i++){
		if(V[i].descoberta%2==0){
			bp.v1[bp.n1]=i+1;
			bp.n1++;
		}
		else{
			bp.v2[bp.n2]=i+1;
			bp.n2++;
		}
	}
	bp.bip=true;
	return bp;
}
		
biparticao BFG(){
	int comp=0;
	int i,j,k;
	queue<int> Q;
	biparticao bp;

	initVer();
	for(i=0;i<n;i++){
		if(V[i].cor==BRANCA){
			V[i].cor=CINZA;
			V[i].descoberta=0;
			Q.push(i);
			while(!Q.empty()){
				j=Q.front();
				Q.pop();
				for(k=0;k<n;k++){
					if(M[j][k]==1){
						if(V[k].cor==BRANCA){
							V[k].cor=CINZA;
							V[k].descoberta=V[j].descoberta+1;
							Q.push(k);
						}
						else{
							if((V[k].descoberta+V[j].descoberta)%2==0){
								bp=biparticiona();
								bp.bip=false;
								comp++;
								printf("\n\nPossui %d componentes conexas\n\n",comp);
								return bp;
							}
						}
					}
				}
				V[j].cor=PRETA;
			}
			comp++;
		}
	}
	bp=biparticiona();
	printf("\n\nPossui %d componentes conexas\n\n",comp);
	if(comp>1){
	    bp.con=false;
	}
	return bp;
}

void imprBiparticao(){
	int i;
	biparticao bp=BFG();
	if(bp.bip){
		printf("\nV1 = "); 
		for(i=0;i<bp.n1;i++){
			 printf("%d ",bp.v1[i]);
		}
		printf("\nV2 = ");
		for(i=0;i<bp.n2;i++){
			 printf("%d ",bp.v2[i]);
		}
		printf("\n\n");
	}
	else{
		printf("O Grafo nao e' bipartido\n\n");
	}
}

bool conexo(){
    biparticao b=BFG();
    return b.con;
}
		
							 
			
				
			
			
