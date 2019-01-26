
typedef char Elem;
void ImpElem(Elem e){
	printf("%c \t",e);
}
/*
int EsMenor(Elem e1, Elem e2){
	return strcmp(e1,e2)<0;
}*/
int EsMenor(Elem e1, Elem e2){
	return e1<e2;
}
int sonIgual(Elem e1,Elem e2){
	return e1==e2;
}
void flag(int n){
	printf("\nFlag:%d\n",n);
}
