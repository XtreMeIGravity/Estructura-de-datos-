#include <stdio.h>
#include <stdlib.h>
#include "Cola2.h"
int main(){
	/*
	Cola q=nueva();
	formar(q,1);
	ImpElem(primero(q));
	esNueva(q)?printf("\nCierto"):printf("\nFalso");
	q=desformar(q);
	esNueva(q)?printf("\nCierto"):printf("\nFalso");*/


	printf("--------Metodo 1-------\n");
	Cola q3=nueva();
	formar(formar(formar(q3,5),6),7);
	ImpCola2(q3);
	printf("\n\tEsta vacia ?");
	esNueva(q3)?printf("\n\tCierto\n"):printf("\n\tFalso\n");
	ImpCola2(q3);
	//ImpElem(primero(q3));


	printf("\n\t:D\n");
	return 0;
}
