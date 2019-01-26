#include <stdio.h>
#include <stdlib.h>

#include "Elem.h"
#include "DicBin.h"


int main(){
	int n;
	DicBin ABB=vacioAB();
	do{
		scanf("\t%d",&n);
		ABB=InsOrd(n,ABB);
	}while(n);
	
	InOrderAB(ABB);
	return 0;
}