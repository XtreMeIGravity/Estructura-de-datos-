
#include "ArbolBin.h"
typedef Arbin DicBin;
DicBin InsOrd(Elem e, DicBin a){
	if (esVacioAB(a)){
		return consAB(e,vacioAB(),vacioAB());
	}else if(EsMenor(e,raiz(a))){
		return consAB(raiz(a),InsOrd(e,izqAB(a)),derAB(a));
	}else{
		return consAB(raiz(a),izqAB(a),InsOrd(e,derAB(a)));
	}
}

  