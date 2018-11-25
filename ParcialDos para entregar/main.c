#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"

int main()
{
    LinkedList* Lista=ll_newLinkedList();
    //Venta* venta=Venta_newConParametros("1","10/10/2010","ARG_123","1","23.3","23-335976287-9");
    //ll_add(Lista, venta);
    //Venta_print(ll_get(Lista, 0));
    parser_parseVentas("data.csv", Lista);
    return 0;
}
