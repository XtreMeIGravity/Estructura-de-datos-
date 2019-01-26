#include "DicBin.h"
typedef DicBin ArbolAVL;
ArbolAVL rotarDer(DicBin a){
	return consAB(raiz(izqAB(a)),izqAB(izqAB(a)),consAB(raiz(a),derAB(izqAB(a)),derAB(a)));
}
ArbolAVL rotarIzq(DicBin a){
	return consAB(raiz(derAB(a)),consAB(raiz(a),izqAB(a),izqAB(derAB(a))),derAB(derAB(a)));
}
ArbolAVL rotarDerIzq(DicBin a){
	return rotarDer(consAB(raiz(a),rotarIzq(izqAB(a)),derAB(a)));
}
ArbolAVL rotarIzqDer(DicBin a){
	return rotarIzq(consAB(raiz(a),izqAB(a),rotarDer(derAB(a))));
}
ArbolAVL ramaIzq(DicBin a){
	return consAB(raiz(a),rotarDer(izqAB(a)),derAB(a));
}
ArbolAVL ramaDer(DicBin a){
	return consAB(raiz(a),izqAB(a),rotarIzq(derAB(a)));
}
int esAVL(DicBin a){
	if (esVacioAB(a)){
		return 1;
	}else{
		return ((abs(AlturaAB(izqAB(a))-AlturaAB(derAB(a)))<=1)&&esAVL(izqAB(a))&&esAVL(derAB(a)));
	}
}
int factBal(DicBin a){
	if (esVacioAB(a)){
		return 0;
	}else{
		return (AlturaAB(izqAB(a))-AlturaAB(derAB(a)));
	}
}
ArbolAVL generaAVL(DicBin a){
	if (esAVL(a)){
		return a;
	}else{

		if (factBal(a)>0){
			if (factBal(izqAB(a))<1){
				a=ramaIzq(a);
			}else if(factBal(izqAB(a))<0){
				a=rotarDer(a);
			}else if(factBal(izqAB(a))>0){
				a=rotarIzqDer(a);
			}
		}else if (factBal(a)<0){
			if(factBal(derAB(a))<-1){
				a=ramaDer(a);
			}else if(factBal(derAB(a))<0){
				a=rotarIzq(a);
			}else if(factBal(derAB(a))>0){
				a=rotarDerIzq(a);
			}
		}
		return consAB(raiz(a),generaAVL(izqAB(a)),generaAVL(derAB(a)));
		/* ALFA
		if (factBal(a)>0){
			if (factBal(izqAB(a))<1){
				a=rotarDerIzq(a);
			}else if(factBal(izqAB(a))<0){
				a=rotarDer(a);
			}
		}else if (factBal(a)<0){
			if(factBal(derAB(a))<-1){
				a=rotarIzqDer(a);
			}else if(factBal(derAB(a))<0){
				a=rotarIzq(a);
			}
		}
		*/
		/* ORIGINAL
		if (factBal(a)>0){
			if (factBal(izqAB(a))>0){
				a=rotarDer(a);	
			}else if (factBal(izqAB(a))<0){
				a=rotarDerIzq(a);
			}
		}else if (factBal(a)<0){
			if (factBal(derAB(a))<0){
				a=rotarIzq(a);
			}else if(factBal(derAB(a))>0){
				a=rotarIzqDer(a);
			}
		}
		*/
	}
}
ArbolAVL consAVL(Elem e, ArbolAVL a){
	return generaAVL(InsOrd(e,a));
}
int existeEn(Elem e, DicBin a){
	if (esVacioAB(a)){
		return 0;
	}else if (sonIgual(e,raiz(a))){
		return 1;
	}else{
		return existeEn(e,izqAB(a))||existeEn(e,derAB(a));
	}
}

Elem minElem(DicBin a){
	if (esHoja(a)){
		return raiz(a);
	}else if (!esVacioAB(izqAB(a))){
		return minElem(izqAB(a));
	}else{
		return minElem(derAB(a));
	}
}
ArbolAVL Elimina(Elem e, DicBin a){
	if (esVacioAB(a)){
		return a;
	}else if (sonIgual(e,raiz(a))){
		if(esVacioAB(derAB(a))){
			return izqAB(a);
		}else if(esVacioAB(izqAB(a))){
			return derAB(a);
		}else{
			return generaAVL(consAB(minElem(derAB(a)),izqAB(a),Elimina(minElem(derAB(a)),derAB(a))));
		}
	}else{
		return consAB(raiz(a),Elimina(e,izqAB(a)),Elimina(e,derAB(a)));
	}
}