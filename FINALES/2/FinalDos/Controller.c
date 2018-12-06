#include "Controller.h"

int Controller_cargarLista(char* nombreArchivo, LinkedList* pLista, int fn(void*, void*))
{
    int retorno=ERROR;
    FILE* pFile;
    if(nombreArchivo!=NULL &&  pLista!=NULL)
    {
        pFile=fopen(nombreArchivo, "r");
        retorno=fn(pFile, pLista);
        fclose(pFile);
    }
    return retorno;
}

int Controller_procesarListas(LinkedList* listaUsuarios, LinkedList*  listaPublicaciones, LinkedList* listaFeed)
{
    int retorno=ERROR;
    ll_filterConValor(listaPublicaciones, buscarUsuario, listaUsuarios, listaFeed);
    ll_sort(listaFeed, criterioOrdenamientoLikes, 1);
    printListaEnArchivo("Feed.csv", listaFeed);
    return retorno;
}


void* buscarUsuario(Publicacion* pEntidad, LinkedList* listaUsuarios)
{
    int idEntidad=0;
    Usuario* pUsuario;
    Feed* pFeed;
    int idPublicacionAux;
    char msgAux[4092];
    int likesPublicacionAux;
    int idUsuarioAux;
    char nickAux[50];
    int likesUsuarioAux;
    if(pEntidad!=NULL && listaUsuarios!=NULL && Publicacion_getIdUsuario(pEntidad, &idEntidad)==TODOOK)
    {
        pUsuario=ll_BuscarValor(listaUsuarios, criterioPorID, &idEntidad);

        if(pUsuario!=NULL &&
           Publicacion_getId(pEntidad, &idPublicacionAux)==TODOOK&&
           Publicacion_getIdUsuario(pEntidad, &idUsuarioAux)==TODOOK&&
           Publicacion_getMsg(pEntidad, msgAux)==TODOOK&&
           Publicacion_getPopularidad(pEntidad, &likesPublicacionAux)==TODOOK&&
           Usuario_getPopularidad(pUsuario, &likesUsuarioAux)==TODOOK&&
           Usuario_getNick(pUsuario, nickAux)==TODOOK)
        {
            //HACER ALGO CON ESTE PUSUARIO
            //POR AHORA IMPRIMO
            //Usuario_printUsuario(pUsuario);
            //Publicacion_printPublicacion(pEntidad);
            pFeed=Feed_newConParametros(idPublicacionAux, msgAux, likesPublicacionAux, idUsuarioAux, nickAux, likesUsuarioAux);
            return pFeed;
        }
    }
    return NULL;
}

int criterioPorID(Usuario* pEntidad, void* id)
{

    int idEncontrado=0;
    int pId=*((int*)id);
    int retorno=FALSE;

    if(pEntidad!=NULL && id!=NULL && Usuario_getId(pEntidad, &idEncontrado)==TODOOK && idEncontrado==pId)
        retorno=TRUE;
    return retorno;
}

int criterioOrdenamientoLikes(void* pEntidadA, void* pEntidadB)
{
    int likesPublicacionA;
    int likesPublicacionB;
    int likesUsuarioA;
    int likesUsuarioB;


    if(pEntidadA!=NULL && pEntidadB!=NULL &&
       Feed_getLikesPublicacion(pEntidadA, &likesPublicacionA)==TODOOK &&
       Feed_getLikesPublicacion(pEntidadB, &likesPublicacionB)==TODOOK &&
       Feed_getLikesUsuario(pEntidadA, &likesUsuarioA)==TODOOK &&
       Feed_getLikesUsuario(pEntidadB, &likesUsuarioB)==TODOOK
        )
    {

        if(likesUsuarioB>likesUsuarioA)
            return 1;
        else if(likesUsuarioA==likesUsuarioB && likesPublicacionB>likesPublicacionA)
            return 1;
    }
    return 0;
}

int printListaEnArchivo(char* nombreArchivo, LinkedList* list)
{
    FILE* pFile=fopen(nombreArchivo, "w");
    ll_MapperConValor(list, printFeedEnArchivo, pFile);
    fclose(pFile);

}

void printFeedEnArchivo(void* pEntidad, FILE* file)
{
    int idPublicacionAux;
    char msgAux[4092];
    int likesPublicacionAux;
    int idUsuarioAux;
    char nickAux[50];
    int likesUsuarioAux;

    if(file!=NULL && pEntidad!=NULL &&
       Feed_getIdPublicacion(pEntidad, &idPublicacionAux)==TODOOK &&
       Feed_getIdUsuario(pEntidad, &idUsuarioAux)==TODOOK &&
       Feed_getLikesPublicacion(pEntidad, &likesPublicacionAux)==TODOOK &&
       Feed_getLikesUsuario(pEntidad, &likesUsuarioAux)==TODOOK &&
       Feed_getMsg(pEntidad, msgAux)==TODOOK &&
       Feed_getNick(pEntidad, nickAux)==TODOOK)
    {
        fprintf(file,"ID_MENSAJE: %d POPULARIDAD_MENSAJE: %d ID_USUARIO: %d NICK: %s POPULARIDAD_USUARIO: %d MENSAJE: %s\n",
               idPublicacionAux,likesPublicacionAux, idUsuarioAux, nickAux, likesUsuarioAux, msgAux);
    }
}
