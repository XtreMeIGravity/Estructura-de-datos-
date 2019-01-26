typedef struct{
    int NumPeor;
    char*Cadena;
}Elem;
Elem CreaElemP(int NumPeor,char*Cadena){
    Elem t;
    t.NumPeor=NumPeor;
    t.Cadena=Cadena;
    return t;
}
void ImpElem(Elem e){
	printf("%d  %s\t", e.NumPeor ,e.Cadena);
}
int sonIgual(Elem e1, Elem e2){
	return  e1.NumPeor==e2.NumPeor;
}
int sonIgualEstricto(Elem e1, Elem e2){
	return  e1.NumPeor==e2.NumPeor && strcmp(e1.Cadena,e2.Cadena);
}
int EsMayorIgual(Elem e1, Elem e2){
	return  e1.NumPeor>=e2.NumPeor;
}
int EsMenor(Elem e1, Elem e2){
	return  e1.NumPeor<e2.NumPeor;
}
