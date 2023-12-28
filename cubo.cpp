#include "matadj.h"
#include<stdio.h>
#include<math.h>

extern int n;
extern int M[10000][10000];

void leN(){
	while(true){
		printf("n =  ");
		if(0>=scanf("%d",&n)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
			continue;
		}
	
		if(n<0){
			printf("Erro. N negativo.\n");
			continue;
		}
		else if(pow(2,n)>10000){
			printf("Erro. Numero de Vertices maior que 10000\n");
			continue;
		}
		break;
	}
	n=pow(2,n);
}

void espelho(int n){
	register int i,j;
	for(i=n/2;i<n;i++){
		for(j=n/2;j<n;j++){
			M[i][j]=M[i-(n/2)][j-(n/2)];
		}
	}
}

void geraIdentidade(int n){
	register int i,j;
	for(i=0;i<n;i++){
		M[i][n-i-1]=1;
	}
}

void geraNCubo(int n){//por divisão e conquista
	if(n==2){
		M[1][0]=1;
		M[0][1]=1;
	}
	else{
		geraNCubo(n/2);
		espelho(n);
		geraIdentidade(n);
	}
} 

void NCuboGrafo(){
	initMat();
	leN(); 
	geraNCubo(n);
}
