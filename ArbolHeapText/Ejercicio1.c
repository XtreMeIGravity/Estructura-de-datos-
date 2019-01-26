#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Elem.h"
#include "Lista.h"
#include "ArbolHeap.h"

int main(int argc,char *argv[]){
	char pal[80],*pal2;
	FILE *body,*nuevo;
	Arbin guardapal=vacioAB();
	Lista pals=vacia();

	body=fopen(argv[1],"r");
	nuevo=fopen(argv[2],"w+");

	if (body==NULL) {fputs ("File error",stderr); printf("\nEjercicio.exe <InputText.txt> <OutputText.txt>\n"); exit (1);}
	if (nuevo==NULL) {fputs ("File error",stderr); printf("\nEjercicio.exe <InputText.txt> <OutputText.txt>\n"); exit (1);}

	while (fscanf(body,"%s",pal)!=EOF){
		pal2=(char*)malloc(80);
		strcpy(pal2,pal);
		pals=cons(pal2,pals);
	}
    guardapal=InsertaElems(pals,guardapal);
    guardapal=ConsHeap(guardapal);

    ImprimirABFILE(guardapal,nuevo);
	fclose(body);
	fclose(nuevo);
	return 0;
}
