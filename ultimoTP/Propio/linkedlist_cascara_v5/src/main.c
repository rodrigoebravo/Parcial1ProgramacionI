/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
        //startTesting(1);  // ll_newLinkedList
        //startTesting(2);  // ll_len
        //startTesting(3);  // getNode - test_getNode
        //startTesting(4);  // addNode - test_addNode
        //startTesting(5);  // ll_add
        //startTesting(6);  // ll_get
        //startTesting(7);  // ll_set
        //startTesting(8);  // ll_remove
        //startTesting(9);  // ll_clear
        //startTesting(10); // ll_deleteLinkedList
        //startTesting(11); // ll_indexOf
        //startTesting(12); // ll_isEmpty
        //startTesting(13); // ll_push
        //startTesting(14); // ll_pop
        //startTesting(15); // ll_contains
        //startTesting(16); // ll_containsAll
        //startTesting(17); // ll_subList
        //startTesting(18); // ll_clone
        //startTesting(19); // ll_sort
        //strtok("hola-hola-hola", "-");
        //si pones null en el primer parametro agarra de donde se quedo
        //strstr("holamundoholamundoholamundo");
        //Hacer una entidad rapidamente con el builder!!!!

        //strstr(char* cadena, char palabraAbuscar)
        //Devuelve el puntero al char que se pidio que se busque, si busco Bravo en una cadena.
        char cadena[]="Rodrigo-Bravo-27\n";
        char needle[]="Bravo";
        //char* result=strstr(cadena, needle);
        //printf("%s\n", result);

        //strtok(char* cadena o NULL, char* separador);
        //devuelve el puntero al char hasta que encuentra el separador
        char separador[]="-";
        int cont=0;
        do{
            if(cont==0)
            {
                printf("%s\n", strtok(cadena, separador));
                printf("%s\n", strtok(NULL, separador));
                printf("%s\n", strtok(NULL, "\n"));
                cont++;
            }
            else
            {
                printf("%s\n", strtok(NULL, separador));
                printf("%s\n", strtok(NULL, separador));
                printf("%s\n", strtok(NULL, "\n"));
            }
        }
        while(cadena!=NULL);
        //printf("%s\n", strtok(cadena, "\n"));

        /*
        char separador[]="-";
        printf("%s\n", strtok(cadena, separador));
        printf("%s\n", strtok(NULL, separador));
        printf("%s", strtok(NULL, separador));
        printf("%s\n", strtok(cadena, separador));
        */

    return 0;
}


