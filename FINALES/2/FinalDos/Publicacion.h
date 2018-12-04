#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct{
    int id;
    char msg[1024];
    int popularidad;
    int idUsuario;
}Publicacion;

#endif // PUBLICACION_H_INCLUDED
