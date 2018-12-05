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

    Controller_cargarUsuarios("usuarios.csv", listaUsuarios);
    Controller_cargarPublicaciones("mensajes.csv", listaPublicaciones);
    Controller_procesarListas(listaUsuarios, listaPublicaciones);

    return 0;
}
