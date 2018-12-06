#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Parser.h"
#include "utn.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaUsuarios=ll_newLinkedList();
    LinkedList* listaPublicaciones=ll_newLinkedList();
    LinkedList* listaFeed=ll_newLinkedList();
    Controller_cargarLista("usuarios.csv", listaUsuarios, parser_GuardarUsuariosDesdeArchivo);
    Controller_cargarLista("mensajes.csv", listaPublicaciones, parser_GuardarPublicacionesDesdeArchivo);
    Controller_procesarListas(listaUsuarios, listaPublicaciones, listaFeed);

    return 0;
}
