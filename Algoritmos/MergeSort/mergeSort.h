
void mezcla(int a[], int n)
{
	int m = n / 2 + n % 2;
	int i, j, k;
	int l[500], r[500];
	for (i = 0; i < m; i++)
		l[i] = a[i];

	/* printf("Izquierda=========\n");
	printArray(l, i); */

	for (j = 0; j < (n - m); j++)
		r[j] = a[i++];

	/*printf("Derecha=========\n");
	printArray(r, j);*/

	i = 0, j = 0, k = 0;
	/* printf("m=%d  , n=%d ,  n-m=%d\n",m,n,(n - m)); */
	while (k < n){
		/* printf("i=%d  , j=%d ,  k=%d\n",i,j,k); */
		if ((i < m) && (j < (n - m))){
			/* printf("l %d   r %d\n",l[i] , r[j]); */
			if (l[i] < r[j])
				a[k++] = l[i++];
			else
				a[k++] = r[j++];
		}else{
			if (i < m){
				for (j = i; i < m; i++)
					a[k++] = l[i];
			}else{
				for (i = j; i < (n - m);i++)
					a[k++] = r[i];
			}
		}	
	}
	//printArray(a,n);
}
void mergeSort(int a[], int n){
	if (n > 1){
		int m = n / 2 + n % 2;
		/*printArray(a, m);
		printArray(a + m, n - m);
		printf("N=%d-------------------\n", n);*/
		mergeSort(a, m);
		mergeSort(a + m, n - m);
		mezcla(a,n);
	}else
		return;
}