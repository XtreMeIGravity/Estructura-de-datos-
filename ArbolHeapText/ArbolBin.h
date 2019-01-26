
typedef struct nodoP{
	struct nodoP*izq;
	Elem r;
	struct nodoP*der;
}*Arbin;
Arbin vacioAB(){	return NULL;}
Arbin consAB(Elem r,Arbin izq,Arbin der){
	Arbin t=(Arbin)malloc(sizeof(struct nodoP));
	t->r=r;
	t->der=der;
	t->izq=izq;
	return t;
}	
int esVacioAB(Arbin ab){	return ab==NULL;}
Elem raiz(Arbin t){	return t->r;}
Arbin izqAB(Arbin t){	return t->izq;}
Arbin derAB(Arbin t){	return t->der;}
int NumElemAB(Arbin t){
	if (esVacioAB(t)){
		return 0;
	}else{
		return 1+NumElemAB(izqAB(t))+NumElemAB(derAB(t));
	}
}
void InOrderAB(Arbin a){
	if (!esVacioAB(a)){
		InOrderAB(izqAB(a));
		ImpElem(raiz(a));
		InOrderAB(derAB(a));
	}
}
void PreOrderAB(Arbin a){
	if (!esVacioAB(a)){
		ImpElem(raiz(a));
		PreOrderAB(izqAB(a));
		PreOrderAB(derAB(a));
	}
}
void PostOrderAB(Arbin a){
	if (!esVacioAB(a)){
		PostOrderAB(izqAB(a));
		PostOrderAB(derAB(a));
		ImpElem(raiz(a));
	}
}
int maximo(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}
int AlturaAB(Arbin a){
	if (!esVacioAB(a)){
		return 1+maximo(AlturaAB(izqAB(a)),AlturaAB(derAB(a)));
	}else{
		return 0;
	}
}
int esHoja(Arbin a){	return (esVacioAB(izqAB(a))&&esVacioAB(derAB(a)));}
int esInterno(Arbin a){	return !esHoja(a);}
int nivelAB(Arbin a){	return AlturaAB(a)-1;}

/* Print nodes at a given level */
void ImprimirPorLVL(Arbin root, int level){ 
    if (esVacioAB(root)){
    	printf("\tN");
        return;
    }
    if (level == 1){
        printf("\t");ImpElem(raiz(root));
    }else if (level > 1) { 
        ImprimirPorLVL(izqAB(root), level-1); 
        ImprimirPorLVL(derAB(root), level-1); 
    } 
} 
/* Function to line by line print level order traversal a tree*/
void ImprimirAB(Arbin root){ 
    int h = AlturaAB(root);
    int h2=pow(2,AlturaAB(root)-1);
    int i , espacios; 
    for (i=1; i<=h; i++){
        ImprimirPorLVL(root, i); 
        printf("\n"); 
    } 
} 
/* FILE */
void ImprimirPorLVLFILE(Arbin root, int level, FILE*nuevo){ 
    if (esVacioAB(root)){
    	fprintf(nuevo,"\tN");
        return;
    }
    if (level == 1){
        fprintf(nuevo,"\t%s",raiz(root));
    }else if (level > 1) { 
        ImprimirPorLVLFILE(izqAB(root), level-1, nuevo); 
        ImprimirPorLVLFILE(derAB(root), level-1, nuevo); 
    } 
} 
/* FILE*/
void ImprimirABFILE(Arbin root, FILE*nuevo){ 
    int h = AlturaAB(root);
    int h2=pow(2,AlturaAB(root)-1);
    int i , espacios; 
    for (i=1; i<=h; i++){
        ImprimirPorLVLFILE(root, i, nuevo); 
        fprintf(nuevo,"\n");
    } 
} 
int esCompleto(Arbin a){
    if(AlturaAB(izqAB(a))-AlturaAB(derAB(a))<=1 && esCompleto(izqAB(a)) && esCompleto(derAB(a)))
		return 1;
	else
		return 0;
}
//falto caso
int esLLeno(Arbin a){
	if (esVacioAB(a))
		return 0;
	else if(AlturaAB(izqAB(a))==AlturaAB(derAB(a)) && esLLeno(izqAB(a))&& esLLeno(derAB(a)))
		return 1;
	else
		return 0;
}

Arbin hazCompleto(Elem e, Arbin a){
	if(esVacioAB(a))
		return consAB(e,vacioAB(),vacioAB());
	else if((AlturaAB(izqAB(a)) == (AlturaAB(derAB(a))+1) &&  esLLeno(izqAB(a))) || (AlturaAB(izqAB(a))==AlturaAB(derAB(a)) && !esLLeno(derAB(a))))
		return consAB(raiz(a),hazCompleto(e,izqAB(a)),derAB(a));
	else
		return consAB(raiz(a),izqAB(a),hazCompleto(e,derAB(a)));
}