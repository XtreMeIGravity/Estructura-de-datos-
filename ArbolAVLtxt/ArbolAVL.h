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
			if (factBal(izqAB(a))>0){
				a=rotarDer(a);	
			}else{
				a=rotarDerIzq(a);
			}
		}else{
			if (factBal(derAB(a))<0){
				a=rotarIzq(a);
			}else{
				a=rotarIzqDer(a);
			}
		}
		return consAB(raiz(a),generaAVL(izqAB(a)),generaAVL(derAB(a)));
	}
}
ArbolAVL consAVL(Elem e, ArbolAVL a){
	return generaAVL(InsOrd(e,a));
}