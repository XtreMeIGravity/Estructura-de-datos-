#include <stdio.h>
#include <stdlib.h>

#include "Utilidad.h"
#include "quickSort.h"

int main()
{

	int numElem = 11;
	int array2[] = {47, 57, 82, 41, 28, 20, 24, 71, 70, 14, 66};
	printf("Antes de mandaros:\n");
	printArray(array2, numElem);
	//printf("Ordenando:\n");
	quick(array2, numElem);
	printf("Ordenados :) de mandaros:\n");
	printArray(array2, numElem);
}