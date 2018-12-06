#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED

typedef struct
{
    int idPublicacion;
    char msg[4092];
    int likesPublicacion;
    int idUsuario;
    char nick[50];
    int likesUsuario;
}Feed;

#endif // FEED_H_INCLUDED


Feed* Feed_new();
void Feed_delete();
Feed* Feed_newConParametros(int idPublicacion,char* msg,int likesPublicacion,int idUsuario,char* nick,int likesUsuario);

int Feed_setIdPublicacion(Feed* this,int idPublicacion);
int Feed_getIdPublicacion(Feed* this,int* idPublicacion);

int Feed_setMsg(Feed* this,char* msg);
int Feed_getMsg(Feed* this,char* msg);

int Feed_setLikesPublicacion(Feed* this,int likesPublicacion);
int Feed_getLikesPublicacion(Feed* this,int* likesPublicacion);

int Feed_setIdUsuario(Feed* this,int idUsuario);
int Feed_getIdUsuario(Feed* this,int* idUsuario);

int Feed_setNick(Feed* this,char* nick);
int Feed_getNick(Feed* this,char* nick);

int Feed_setLikesUsuario(Feed* this,int likesUsuario);
int Feed_getLikesUsuario(Feed* this,int* likesUsuario);

#endif // FEED_H_INCLUDED
