#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Elem.h"
#include "DicBin.h"

int main(int argc,char *argv[]){
	char pal[80],*pal2;
	FILE *body,*nuevo;
	DicBin dicionarioBinario=vacioAB();

	body=fopen(argv[1],"r");
	nuevo=fopen(argv[2],"w+");

	if (body==NULL) {fputs ("File error",stderr); exit (1);}
	if (nuevo==NULL) {fputs ("File error",stderr); exit (1);}

	while (fscanf(body,"%s",pal)!=EOF){
		pal2=(char*)malloc(80);
		strcpy(pal2,pal);
		dicionarioBinario=InsOrd(pal2,dicionarioBinario);
	}

	printf("\n\n\n////////////////////////////////IN ORDER/////////////////////////////////\n");
	InOrderAB(dicionarioBinario);
	InOrderABFILE(dicionarioBinario,nuevo);
	
	fclose(body);
	fclose(nuevo);
	return 0;
}
