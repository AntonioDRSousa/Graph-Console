#include<stdio.h>
#include "matadj.h"

extern int n;
extern int M[10000][10000];
int n1,n2;

void KnGrafo(){
	register int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				M[i][j]=1;
			}
		}
	}
}

void PnGrafo(){
	for(register int i=1;i<n;i++){
		if(i!=n){
			M[i-1][i]=1;
			M[i][i-1]=1;
		}
	}
}

void CnGrafo(){
	PnGrafo();
	M[0][n-1]=1;
	M[n-1][0]=1;
}

void WnGrafo(){
	CnGrafo();
	for(register int i=1;i<=n;i++){
		M[n][i-1]=1;
		M[i-1][n]=1;
	}
	n++;
}

void le2Vertices(){
    leVertices();
    n1=n;
    leVertices();
    n2=n;
    n=n1+n2;
}

void Kn1n2Grafo(){
    register int i,j;
	initMat();
	le2Vertices();
	for(i=0;i<n1;i++){
		for(j=n1;j<n1+n2;j++){
			M[i][j]=1;
			M[j][i]=1;
		}
	}
}

void Kn(){
	initMat();
	leVertices();
	KnGrafo();
}

void Pn(){
	initMat();
	leVertices();
	PnGrafo();
}

void Cn(){
	initMat();
	leVertices(2);
	CnGrafo();
}

void Wn(){
	initMat();
	leVertices(2);
	WnGrafo();
}	

void Kn1n2(){
	initMat();
	le2Vertices();
	Kn1n2Grafo();
}
		
