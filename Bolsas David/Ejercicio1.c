#include <stdio.h>
#include <stdlib.h>

#include "Elem.h"
#include "Bolsa.h"

int main(int argc, char const *argv[])
{

    Bolsa a=InsertaB('a',InsertaB('e',InsertaB('i',InsertaB('o',InsertaB('e',InsertaB('i',InsertaB('u',vacioB())))))));
    Bolsa b=InsertaB('a',InsertaB('b',InsertaB('c',InsertaB('d',InsertaB('e',InsertaB('b',InsertaB('e',InsertaB('d',vacioB()))))))));
    Bolsa c=InsertaB('b',InsertaB('d',InsertaB('f',InsertaB('g',InsertaB('b',InsertaB('b',InsertaB('d',InsertaB('a',InsertaB('i',vacioB())))))))));
    printf("\n");
    ImpBolsa(interseccionB(unionB(a,b),c));
    printf("\n");
    ImpBolsa(diferenciaB(a,b));
    printf("\n");
    ImpBolsa(diferenciaB(b,a));
    printf("\n");
    return 0;
}
