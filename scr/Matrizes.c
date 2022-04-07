#include <stdio.h>
#include <stdlib.h>
#define TAM 2
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

int total;				
int l,c;
int Matriz[TAM][TAM];
srand(time(NULL));
	
for(l=0;l<TAM;l++)
{		
	for(c=0;c<TAM;c++)
	{		
		Matriz[l][c] = rand() %100;
		printf("%d\t", Matriz[l][c]);
	}
	printf("\n");
}

l=0; c=0; total = Matriz[l][c];
int esquerda = 0, direita = 0, baixo = 0;


while((l!=(TAM-1))||(c!=(TAM-1)))
{
	if(c == (TAM - 1)) {
		direita = 0;
	} else {
		direita=Matriz[l][c+1];
	}
	
	if(c==0){
		esquerda=0;
	} else {
		esquerda=Matriz[l][c-1];
	}
	
	if(l==(TAM-1)){
		baixo=0;
		esquerda = 0;
	} else {
		baixo=Matriz[l][c + 1];
	}
	
	if(direita>esquerda&&direita>baixo){
		total+=direita;
		Matriz[l][c]=-1;
		c++;
	}
	
	if(esquerda>direita&&esquerda>baixo){
		total+=esquerda;
		Matriz[l][c]=-1;
		c--;
	}
	
	if(baixo>=direita&&baixo>=esquerda){
		total+=baixo;
		Matriz[l][c]=-1;
		l++;
	}	
}
	
	printf("%d", total);
	
	return 0;
}