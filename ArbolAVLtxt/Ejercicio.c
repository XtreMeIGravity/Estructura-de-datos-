#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Elem.h"
#include "ArbolAVL.h"

int main(int argc,char *argv[]){
	char pal[80],*pal2;
	FILE *body,*nuevo;
	ArbolAVL guardapal=vacioAB();

	body=fopen(argv[1],"r");
	nuevo=fopen(argv[2],"w+");

	if (body==NULL) {fputs ("File error",stderr); printf("\nEjercicio.exe <InputText.txt> <OutputText.txt>\n"); exit (1);}
	if (nuevo==NULL) {fputs ("File error",stderr); printf("\nEjercicio.exe <InputText.txt> <OutputText.txt>\n"); exit (1);}

	while (fscanf(body,"%s",pal)!=EOF){
		pal2=(char*)malloc(80);
		strcpy(pal2,pal);
		guardapal=consAVL(pal2,guardapal);
	}
	//ImprimirLvlByLvl(guardapal);
	ImprimirLvlByLvlFILE(guardapal,nuevo);
	printf("%d",AlturaAB(guardapal));
	fclose(body);
	fclose(nuevo);
	return 0;
	return 0;
}