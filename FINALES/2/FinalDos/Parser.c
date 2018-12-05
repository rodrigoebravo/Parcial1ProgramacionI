#include "parser.h"
/** \brief Guarda en la lista el contenido del archivo como Usuario
 * \param fileName *char
 * \param LinkedList* pLista
 * \return int
 */

int parser_GuardarUsuariosDesdeArchivo(FILE* pFile , LinkedList* pLista)
{
    char idAux[1024];
    char nickAux[1024];
    char popularidadAux[1024];

    int retorno=ERROR;
    int flagOnce=TRUE;
    Usuario* pEntidad;

    if(pFile != NULL && pLista!=NULL)
    {
        retorno=TODOOK;
        printf("Procesando archivo...\n");

        while(!feof(pFile))
        {

            if(flagOnce)
            {

                flagOnce=FALSE;
                fscanf(pFile, "%[^,],%[^,],%[^\n]\n", idAux, nickAux, popularidadAux);
            }
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", idAux, nickAux, popularidadAux);
            pEntidad=Usuario_newConParametros(idAux, nickAux, popularidadAux);
            if(pEntidad!=NULL)
                ll_add(pLista, pEntidad);
        }
        printf("Archivo cargado exitosamente.\nTotal de registros ingresados: %d\n", ll_len(pLista));
    }
    return retorno;
}


/** \brief Guarda en la lista el contenido del archivo como Publicacion
 * \param fileName *char
 * \param LinkedList* pLista
 * \return int
 */

int parser_GuardarPublicacionesDesdeArchivo(FILE* pFile , LinkedList* pLista)
{
    char idAux[1024];
    char msgAux[4092];
    char popularidadAux[1024];
    char idUsuarioAux[1024];

    int retorno=ERROR;
    int flagOnce=TRUE;
    Publicacion* pEntidad;

    if(pFile != NULL && pLista!=NULL)
    {
        retorno=TODOOK;
        printf("Procesando archivo...\n");
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, idUsuarioAux, popularidadAux, msgAux);
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, idUsuarioAux, popularidadAux, msgAux);

            pEntidad=Publicacion_newConParametros(idAux, msgAux, popularidadAux, idUsuarioAux);
            if(pEntidad!=NULL)
                ll_add(pLista, pEntidad);
        }
        printf("Archivo cargado exitosamente.\nTotal de registros ingresados: %d\n", ll_len(pLista));
    }
    return retorno;
}



int parser_GuardarFeed(FILE* pFile, Usuario* pUsuario, Publicacion* pPublicacion)
{
    int retorno=ERROR;
    int idPublicacionAux;
    char nickAux[50];
    int popularidadPublicacionAux;
    int idUsuarioAux;
    char msgAux[1024];
    int popularidadUsuarioAux;

    if(pFile != NULL && pUsuario!=NULL && pPublicacion!=NULL)
    {
        retorno=TODOOK;

        if( Publicacion_getId(pPublicacion, &idPublicacionAux)==TODOOK&&
            Publicacion_getMsg(pPublicacion, msgAux)==TODOOK&&
            Publicacion_getPopularidad(pPublicacion, &popularidadPublicacionAux)==TODOOK&&
            Usuario_getId(pUsuario, &idUsuarioAux)==TODOOK&&
            Usuario_getNick(pUsuario, nickAux)==TODOOK&&
            Usuario_getPopularidad(pUsuario, &popularidadUsuarioAux)==TODOOK)
        {
            fprintf(pFile, "ID_MENSAJE: %d MENSAJE: %s POPULARIDAD_MENSAJE: %d ID_USUARIO: %d NICK: %s POPULARIDAD_USUARIO: %d", idPublicacionAux, msgAux, popularidadPublicacionAux, idUsuarioAux, nickAux, popularidadUsuarioAux);
        }
    }
    return retorno;
}
