#include<stdio.h>

extern int n;
extern int M[10000][10000];//matriz adjacencia
int N[10050][10050]; //matriz de coloraçao, vertices por cores vizinhas
int f[10000];//coloracao

void initN(){
	register int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			N[i][j]=0;
		}
	}
}

void initColoracao(){
	for(register int i=0;i<=n;i++){
		f[i]=0;
	}
}

void Coloracao(){
	initN();
	initColoracao();
	for(register int i=0;i<n;i++){//percorre cada vertice
		for(register int j=0;j<n;j++){//percorre as vizinhancas
			if((M[i][j]==1) && (f[j]!=0)){//se o vertice e' vizinho e se o vertice esta' colorido
				N[i][f[j]]=1;//para o vertice i, temos que a cor f[j](cor do vertice j), a matriz atribui 1 para existencia de cor
			}
		}
		for(register int j=1;j<=n;j++){//percorre o vetor das cores para o vertice i, j representa uma cor
			if(N[i][j]==0){
				f[i]=j;
				break;
			}
		}
	}
}

void imprCol(){
	Coloracao();
	printf("\n\nf(v) = ");
	for(register int i=0;i<n;i++){
		printf("%d ",f[i]);
	}
	printf("\n\n");
}
		
	
