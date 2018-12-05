#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct{
    int id;
    char msg[1024];
    int popularidad;
    int idUsuario;
}Publicacion;

#endif // PUBLICACION_H_INCLUDED


Publicacion* Publicacion_new();
void Publicacion_delete();
Publicacion* Publicacion_newConParametros(int id,char* msg,int popularidad,int idUsuario);

int Publicacion_setId(Publicacion* this,int id);
int Publicacion_getId(Publicacion* this,int* id);

int Publicacion_setMsg(Publicacion* this,char* msg);
int Publicacion_getMsg(Publicacion* this,char* msg);

int Publicacion_setPopularidad(Publicacion* this,int popularidad);
int Publicacion_getPopularidad(Publicacion* this,int* popularidad);

int Publicacion_setIdUsuario(Publicacion* this,int idUsuario);
int Publicacion_getIdUsuario(Publicacion* this,int* idUsuario);

#endif // PUBLICACION_H_INCLUDED
