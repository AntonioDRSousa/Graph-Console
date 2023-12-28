#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "matadj.h"
#include "bipart.h"
#include "gspec.h"
#include "col.h"
#include "arvger.h"
#include "cubo.h"
#include "myc.h"

int n;
int M[10000][10000];//matriz adjacencia
FILE * fp;

void menu2(){
	int op;
	printf("1-Qn\n2-Kn\n3-Pn\n4-Cn\n5-Wn\n6-Kn1,n2\n7-Mycelsky\n8-Sair\n");
	while(true){
		if(0>=scanf("%d",&op)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
		}
		else if(op>=1 && op<=8){
			switch(op){
				case 1:
					NCuboGrafo();
					break;
				case 2:
					Kn();
					break;
				case 3:
					Pn();
					break;
				case 4:
					Cn();
					break;
				case 5:
					Wn();
					break;
				case 6:
					Kn1n2();
					break;
				case 7:
				    My();
					break;
				case 8:
					break;
			}
			break;
		}
		else{
			printf("Erro. Opcao invalida.....\n");
			fflush(stdin);
		}	
	}
}

void menu1(){
	int op;
	printf("1-Novo Grafo\n2-Novo Grafo Especial\n3-Carregar Grafo\n4-Salvar Grafo\n5-Imprimir Matriz Adjacencias\n6-Biparticao\n7-Arvore Geradora\n8-Coloracao\n9-Sair\n");
	while(true){
		if(0>=scanf("%d",&op)){
			printf("Erro Scanf.....\n");
			fflush(stdin);
		}
		else if(op>=1 && op<=9){
			switch(op){
				case 1:
					leGrafo();
					break;
				case 2:
					menu2();
					break;
				case 3:
					loadGrafo();
					break;
				case 4:
					saveGrafo();
					break;
				case 5:
					imprMat();
					break;
				case 6:
					imprMat();
					imprBiparticao();
					break;
				case 7:
				    imprMat();
				    Conexidade();
	                break;
	            case 8:
	                imprCol();
	                break;
				case 9:
					exit(1);
					break;
			}
			break;
		}
		else{
			printf("Erro. Opcao invalida.....\n");
			fflush(stdin);
		}	
	}
}

int main(void){
	while(true){
		menu1();
	}
	return 0;
}
