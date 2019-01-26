#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Elem.h"
#include "ColaPeor.h"

int main()
{
    ColaPeor A=VaciaCP();
    Elem e;
    e=CreaElemP(1,"Miki");
    A=InsertarCP(e,A);
    e=CreaElemP(2,"David");
    A=InsertarCP(e,A);
    e=CreaElemP(0,"Paco");
    A=InsertarCP(e,A);
    e=CreaElemP(0,"Pedro");
    A=InsertarCP(e,A);
    ImpCP(A);
    printf("\n");
    printf("%d\n",NumElem(A));
    //Borramos estrictamente
    e=CreaElemP(0,"Paco");
    A=EliminarElemCPEstrict(e,A);
    ImpCP(A);
    return 0;
}
