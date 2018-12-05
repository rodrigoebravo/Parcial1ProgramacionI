#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED
#include "Publicacion.h"
#include "Usuario.h"
typedef struct
{
    Publicacion* publicacion;
    Usuario* usuario;
}Feed;

#endif // FEED_H_INCLUDED
