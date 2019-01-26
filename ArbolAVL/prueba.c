#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Elem.h"
#include "ArbolAVL.h"

int main(){
	ArbolAVL a=vacioAB();
	int e=0;
	do{
		printf("e?");
		scanf("%d",&e);
		if(e){
			a=consAVL(e,a);
			ImprimirAB(a);

		}
	}while(e);
	existeEn(10,a)?printf("SI EXISTE\n"):printf("NO EXISTE\n");
	printf("Borrando el 10\n");
	a=Elimina(10,a);
	ImprimirAB(a);
	existeEn(10,a)?printf("SI EXISTE\n"):printf("NO EXISTE\n");
}