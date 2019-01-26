#include <stdio.h>
#include <stdlib.h>

#include "Elem.h"
#include "Arbolbin.h"
int main(){
	Arbin tree=consAB(4,consAB(1,vacioAB(),vacioAB()),consAB(6,consAB(5,vacioAB(),vacioAB()),consAB(7,vacioAB(),vacioAB())));
	printf("\t%d",NumElemAB(tree));
	printf("\t Numero elementos\n");
	InOrderAB(tree);
	printf("\tInOrderAB\n");
	PreOrderAB(tree);
	printf("\tPostOrderAB\n");
	PostOrderAB(tree);
	printf("\tPreOrderAB\n");
	printf("\t%d",AlturaAB(tree) );
	printf("\tAltura\n");
	esInterno(tree)?printf("Verdadero I\n"):printf("Falso I\n");
	Arbin tree2=consAB(5,vacioAB(),vacioAB());
	esHoja(tree2)?printf("Verdadero H\n"):printf("Falso H\n");
	printf("\t%d\tNivel",nivelAB(tree) );
	return 0;
}