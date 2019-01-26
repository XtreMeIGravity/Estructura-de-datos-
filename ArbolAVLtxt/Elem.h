/*
typedef char*pal;
typedef struct NodoPalabras{
	pal palabra;
	int index;
}
pal DamePalabra(Elem temp){
	return temp->palabra;
}
int indexElem(Elem temp){
	return temp->index;
}
void ImpElem(Elem e){
	printf("\t%s",e->palabra);
}
int EsMenor(Elem e1, Elem e2){
	return strcmp(strlwr(e1),strlwr(e2))<0;
}
int sonIgual(Elem e1,Elem e2){
	return strlwr(e1)==strlwr(e2);
}*/
typedef char*Elem;
void ImpElem(Elem e){
	printf("%s\t",e);
}
int EsMenor(Elem e1, Elem e2){
	return strcmp(strlwr(e1),strlwr(e2))<0;
}
int sonIgual(Elem e1,Elem e2){
	return strlwr(e1)==strlwr(e2);
}

int maximo(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}