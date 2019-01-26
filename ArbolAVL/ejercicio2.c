#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Elem.h"
#include "ArbolAVL.h"

int main(){
	ArbolAVL nuevo=vacioAB();
	for (int i=1; i <=7; i++){
		nuevo=consAVL(i, nuevo);
	}
	printf("Altura del ArbolAVL:%d\n",AlturaAB(nuevo));
	printf("\n");
	ImprimirLvlByLvl(nuevo);
}