#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct{
    int id;
    char nick[50];
    int popularidad;
}Usuario;

Usuario* Usuario_new();
void Usuario_delete();
Usuario* Usuario_newConParametros(char* id,char* nick,char* popularidad);

int Usuario_setId(Usuario* this,int id);
int Usuario_getId(Usuario* this,int* id);

int Usuario_setNick(Usuario* this,char* nick);
int Usuario_getNick(Usuario* this,char* nick);

int Usuario_setPopularidad(Usuario* this,int popularidad);
int Usuario_getPopularidad(Usuario* this,int* popularidad);

void Usuario_printUsuario(Usuario* pUsuario);

#endif // USUARIO_H_INCLUDED
