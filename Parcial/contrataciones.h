#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int id;
    char video;
    float precio;
    int dias;
    int idPantalla;
    char cuit[20];
    int isEmpty;
}Contratacion;
#define FALSO 0
#define VERDADERO 1

#endif // CONTRATACIONES_H_INCLUDED
