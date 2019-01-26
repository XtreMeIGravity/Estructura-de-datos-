int *arregloRandom(int n,int lim){
	int *array= malloc(n*4);
	int contador=1,Existe=0,temp;
	srand((int)time(NULL));
	do{
		//Reseteamos bandera
		Existe=0;
		//Generamos random
		temp=rand()+rand();
		//barrido de s
		for (int j = 0; j < contador; ++j){
			if (array[j]==temp || temp>lim){
				Existe =1;
				break;
			}
		}
		//Verificamos si no existe entonces insertamos
		if (!Existe){
			array[contador]=temp;
			contador++;
		}
	}while(contador<=n);
	return array;
}
