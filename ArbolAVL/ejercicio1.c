#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Randoms.h"
#include "Elem.h"
#include "ArbolAVL.h"

int main(){
	ArbolAVL nuevo=vacioAB();
	int *numerosRandom;
	int cant,lim;
	printf("Cuantos Numeros deseas crear?\n");
	scanf("%d",&cant);
	printf("Establece el limite\n");
	scanf("%d",&lim);
	numerosRandom=arregloRandom(cant,lim);
	for (int i=1; i <=cant; i++){
		//printf("%d\t",numerosRandom[i]);
		nuevo=consAVL(numerosRandom[i], nuevo);
	}
	printf("Altura del ArbolAVL\n%d\n",AlturaAB(nuevo));
	InOrderAB(nuevo);
}