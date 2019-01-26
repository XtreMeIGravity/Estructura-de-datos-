#include <stdio.h>
#include <stdlib.h>
#include "ColaCircular.h"

int main(){
	Circular newq=nuevaC();
	int i=1 ;
	for (i= 1; i <=10; ++i){
		newq=formarC(newq,i);
	}
	while(1){
		ImpElem(primerC(newq));
		newq=rotar(newq);
		getchar();
	}

	return 0;
}
