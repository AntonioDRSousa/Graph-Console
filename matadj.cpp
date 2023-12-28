#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int n;
extern int M[10000][10000];
extern FILE * fp;

void initMat(){
	int i,j;
	for(i=0;i<10000;i++){
		for(j=0;j<10000;j++){
			M[i][j]=0;
		}
	}
}

void saveGrafo(){
	int i,j;
	char s[30];
	printf("Digite o nome do grafo: ");
	scanf("%s",s);
	if((fp=fopen(strcat(s,".txt"),"w"))==NULL){
		printf("Erro ao abrir o arquivo.....\n");
		exit(1);
	}
	fprintf(fp,"%d\n",n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(fp,"%d ",M[i][j]);
		}
		fprintf(fp,"\n");
	}
	if(fflush(fp)==EOF){
		printf("Erro. fflush.....\n");
		exit(3);
	}
	if(fclose(fp)){
		printf("Erro ao fechar arquivo.....\n");
		exit(4);
	}
	printf("Salvo o Grafo\n");
}

void loadGrafo(){
	initMat();
	int i,j;
	char s[30];
	printf("Digite o nome do grafo: ");
	scanf("%s",s);
	if((fp=fopen(strcat(s,".txt"),"r"))==NULL){
		printf("Erro ao abrir o arquivo.....\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&M[i][j]);
		}
	}
	if(fflush(fp)==EOF){
		printf("Erro. fflush.....\n");
		exit(3);
	}
	printf("Carregado Grafo: %s\n",s);
	if(fclose(fp)){
		printf("Erro ao fechar arquivo.....\n");
		exit(4);
	}
}

void leArestas(){
	int v1,v2;
	printf("Digite as arestas do grafo(digite 0 0 para parar)\n");
	printf("EX: 1 2(vertice 1 com vertice 2)\n");
	while(true){
		if(0>=scanf("%d %d",&v1,&v2)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
			continue;
		}
		if(v1==0 && v2==0){
			break;
		}
		else if(v1>n || v2>n){
			printf("Erro. Aresta Invalida\n");
			continue;
		}
		M[v1-1][v2-1]=1;
		M[v2-1][v1-1]=1;
	}	
}

void leVertices(int min=0){
	while(true){
		printf("Digite o numero de vertices do grafo(maximo 10000 vertices): ");
		if(0>=scanf("%d",&n)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
			continue;
		}
	
		if(n<=min){
			printf("Erro. Numero de Vertices menor que %d.\n",min+1);
			continue;
		}
		else if(n>10000){
			printf("Erro. Numero de Vertices maior que 10000\n");
			continue;
		}
		break;
	}
}

void leGrafo(){
	initMat();
	leVertices();
    leArestas();
}

void imprMat(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
}
