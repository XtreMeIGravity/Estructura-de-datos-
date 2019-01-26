#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

int main(){
	Cola newq=nueva();
	int i=1 ;
	for (i= 1; i <=10; ++i){
		newq=formar(newq,i);
	}
	ImpCola(newq);
	return 0;
}
