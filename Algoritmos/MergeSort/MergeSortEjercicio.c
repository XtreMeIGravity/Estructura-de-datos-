#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Utilidad.h"
#include "mergeSort.h"

int main(){

	int numElem = 50;
	// 75, 65, 42, 55, 32, 76, 11, 37, 24, 49
	int array2[] = {47, 30, 22, 5, 85, 84, 72, 25, 36, 10, 57,
	82, 41, 28, 20, 24, 71, 70, 14, 66, 78, 97, 55, 18, 8, 93,
	64, 7, 99, 46, 31, 63, 95, 49, 96, 65, 52, 1, 59, 86, 53,
	35, 6, 98, 74, 54, 21, 76, 92, 81};
	// 11, 24, 32, 37, 42, 49 55, 65, 75, 76
	printf("Antes de mandaros:\n");
	printArray(array2, numElem);
	//printf("Ordenando:\n");
	mergeSort(array2, numElem);
	printf("Ordenados :) de mandaros:\n");
	printArray(array2, numElem);
}