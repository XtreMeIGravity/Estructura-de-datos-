
typedef char*Elem;
void ImpElem(Elem e)
{
	printf("\t%s", e);
}

int esMenor(Elem e1, Elem e2){
	return strcmp(e1,e2)<0;
}
int esMayor(Elem e1, Elem e2){
	return strcmp(e1,e2)>0;
}
int esMayorIgual(Elem e1, Elem e2)
{
	return strcmp(e1,e2)>=0;
}
int sonIgual(Elem e1, Elem e2)
{
	return e1 == e2;
}

