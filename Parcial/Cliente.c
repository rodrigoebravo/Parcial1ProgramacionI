#include "Cliente.h"
#include "Venta.h"
#include "utn.h"

static int cli_getAltaCliente(Cliente* pEntidad, int len, int index);
static int cli_BajaPorPosicion(Cliente* cli, int lenCli, int index, Venta* ven, int lenVen);
static int cli_obtenerPosicionVacia(Cliente* pEntidad, int len, int* indexVacio);
static int generarID(void);
static int cli_modificar(Cliente* pEntidad, int len, int index);
static int clientesTieneDatos(Cliente* pEntidad, int len);
static void cli_altas(Cliente* pEntidad, char* nombre, char* apellido, char* cuit, int i);
static void cli_forzarAltas(Cliente* pEntidad, int len);


int cli_inicializarListaClientes(Cliente* pEntidad, int len)
{
    int i;
    int retorno=ERROR;
    if(pEntidad !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            pEntidad[i].isEmpty=TRUE;
        }
        cli_forzarAltas(pEntidad, len);
        retorno=TODOOK;
    }
    return retorno;
}

int cli_darAltaCliente(Cliente* pEntidad, int len)
{
    int index;
    int retorno=ERROR;

    if(cli_validarParametros(pEntidad, len)==TODOOK && cli_obtenerPosicionVacia(pEntidad, len, &index)==TODOOK)
    {
        cli_getAltaCliente(pEntidad, len, index);
        retorno=index;
    }
    return retorno;
}

int cli_modificarClientePorID(Cliente* pEntidad, int len)
{
    int retorno=ERROR;
    int idModificar;
    int indexModificar;

    if(clientesTieneDatos(pEntidad, len))
    {
        cli_printClientes(pEntidad, len);
        if(utn_getEntero(&idModificar, 3, len, -1, "Ingrese ID a modificar:\n", "ID erroneo\n")==TODOOK &&
                cli_obtenerPosicionPorID(pEntidad, len, idModificar, &indexModificar)==TODOOK &&
                cli_posicionEstaVacia(pEntidad, len, indexModificar)==FALSE &&
                cli_modificar(pEntidad, len, indexModificar)==TODOOK)
        {
                retorno=TODOOK;
        }
        else
        {
                limpiarScreen();
                printf("No es posible modificar cliente.\n");
        }
    }
    else
    {
        limpiarScreen();
        printf("No es posible modificar clientes, no existen datos.\n");
    }
    return retorno;
}

int cli_bajaClientePorID(Cliente* pEntidad, int lenCli, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int idBaja;
    int indexBaja;
    if(clientesTieneDatos(pEntidad, lenCli))
    {
        cli_printClientes(pEntidad, lenCli);
        if(cli_validarParametros(pEntidad, lenCli)==TODOOK && ven!=NULL && lenVen>0
            && utn_getEntero(&idBaja, 3, lenCli, -1, "Ingrese ID del cliente a dar de baja\n", "Error al dar de baja el ID\n")==TODOOK
            && cli_obtenerPosicionPorID(pEntidad, lenCli, idBaja, &indexBaja)==TODOOK
            && cli_posicionEstaVacia(pEntidad, lenCli, indexBaja)==FALSE)
        {
            retorno=cli_BajaPorPosicion(pEntidad, lenCli, indexBaja, ven, lenVen);
        }
        else
        {
            limpiarScreen();
            printf("No es posible eliminar cliente.\n");
        }
    }
    else
    {
        limpiarScreen();
        printf("No es posible eliminar clientes, no existen datos.\n");
    }

    return retorno;
}

static int cli_getAltaCliente(Cliente* pEntidad, int len, int index)
{
    int retorno=ERROR;
    Cliente auxCli;

    limpiarScreen();
    if(cli_validarParametros(pEntidad, len)==TODOOK &&
            index>=0 &&
            index<len &&
            utn_getCadena(auxCli.nombre, 20, 3, "Ingrese nombre\n", "Nombre incorrecto\n")==TODOOK &&
            utn_getCadena(auxCli.apellido, 20, 3, "Ingrese apellido\n", "Apellido incorrecto\n")==TODOOK &&
            utn_getCadena(auxCli.cuit, 20, 3, "Ingrese cuit\n", "Cuit incorrecto\n")==TODOOK)
    {
        auxCli.id=generarID();
        auxCli.isEmpty=FALSE;
        pEntidad[index]=auxCli;
        retorno=TODOOK;
    }
    return retorno;
}

static int cli_modificar(Cliente* pEntidad, int len, int index)
{
    int retorno=ERROR;
    int opcionModificar;
    Cliente auxCli;

    if(cli_validarParametros(pEntidad, len)==TODOOK && index>=0 && index<len)
    {
        auxCli=pEntidad[index];

        limpiarScreen();
        if(utn_getEntero(&opcionModificar, 3, 5, 0, "1-Nombre\n2-Apellido\n3-CUIT\nIngrese Opcion a modificar:", "Opcion incorrecta")==TODOOK)
        {
            switch(opcionModificar)
            {
                case 1:
                    utn_getCadena(auxCli.nombre, 20, 3, "Ingrese nombre\n", "Nombre incorrecto\n");
                    break;
                case 2:
                    utn_getCadena(auxCli.apellido, 20, 3, "Ingrese apellido\n", "Apellido incorrecto\n");
                    break;
                case 3:
                    utn_getCadena(auxCli.cuit, 20, 3, "Ingrese cuit\n", "Cuit incorrecto\n");
                    break;
                case 4:
                    break;
            }
            pEntidad[index]=auxCli;
        }
        retorno=TODOOK;
    }
    return retorno;
}

static int cli_BajaPorPosicion(Cliente* cli, int lenCli, int index, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int i;
    if(cli_validarParametros(cli, lenCli)==TODOOK && ven!=NULL && lenVen>0 && index>=0 && index<lenCli)
    {
        cli[index].isEmpty=TRUE;

        for(i=0; i<lenVen; i++)
        {
            if(ven[i].idCliente==cli[index].id && ven[i].isEmpty==FALSE)
            {
                ven[i].isEmpty=TRUE;
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}

int cli_posicionEstaVacia(Cliente* pEntidad, int len, int index)
{
    int retorno=TRUE;

    if(pEntidad!=NULL && index>=0 && len>0 && index<len)
    {
        retorno=pEntidad[index].isEmpty;
    }
    return retorno;
}

static int cli_obtenerPosicionVacia(Cliente* pEntidad, int len, int* indexVacio)
{
    int i;
    int retorno=ERROR;

    if(cli_validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            if(pEntidad[i].isEmpty)
            {
                *indexVacio=i;
                retorno=TODOOK;
                break;
            }
        }
    }
    return retorno;
}

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}

int cli_obtenerPosicionPorID(Cliente* pEntidad, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=ERROR;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==id && !pEntidad[i].isEmpty)
        {
            *indexRetorno=i;
            retorno=TODOOK;
            break;
        }
    }
    return retorno;
}

int cli_printClientes(Cliente* pEntidad, int lenCli)
{
    int retorno=ERROR;
    int i;
    if(cli_validarParametros(pEntidad, lenCli)==TODOOK)
    {
        limpiarScreen();
        retorno=TODOOK;
        for(i=0; i<lenCli; i++)
        {
            if(!pEntidad[i].isEmpty)
            {
                cli_printCliente(pEntidad, i);
            }
        }
    }
    return retorno;
}

void cli_printCliente(Cliente* pEntidad, int index)
{
    printf("ID: %d Nombre: %s Apellido: %s Cuit: %s \n", pEntidad[index].id, pEntidad[index].nombre, pEntidad[index].apellido, pEntidad[index].cuit);
}

int cli_validarParametros(Cliente* pEntidad, int lenCli)
{
    int retorno=ERROR;
    if(pEntidad!=NULL && lenCli>0)
    {
        retorno=TODOOK;
    }
    return retorno;
}

static int clientesTieneDatos(Cliente* pEntidad, int len)
{
    int retorno=FALSE;
    int i;
    if(cli_validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            if(!pEntidad[i].isEmpty)
            {
                retorno=TRUE;
                break;
            }
        }
    }
    return retorno;
}


static void cli_forzarAltas(Cliente* pEntidad, int len)
{
    cli_altas(pEntidad, "Rodrigo", "Bravo", "20453164166", 0);
    cli_altas(pEntidad, "Sebastian", "Martinez", "23645168354", 1);
    cli_altas(pEntidad, "Maria", "Arange", "23845186798", 2);
    cli_altas(pEntidad, "Jose", "Morin", "23135416874", 3);
    cli_altas(pEntidad, "Brian", "Miria", "20835421687", 4);
    cli_altas(pEntidad, "Romina", "Zapiola", "20531687461", 5);
    cli_altas(pEntidad, "Ana", "Echeverria", "21168749684", 6);
    cli_altas(pEntidad, "Ayelen", "Ituzaingo", "21653196874", 7);
    cli_altas(pEntidad, "Daniel", "Mirin", "21845146879", 8);
    cli_altas(pEntidad, "Juan", "Isasia", "20459896874", 9);
    cli_altas(pEntidad, "Ramiro", "Birus", "23584168514", 10);
    cli_altas(pEntidad, "Lorenzo", "Abarin", "20851465841", 11);
    cli_altas(pEntidad, "Lorenzo", "Mulli", "22163446465", 12);
    cli_altas(pEntidad, "Lauriel", "Paoli", "22879774131", 13);
    cli_altas(pEntidad, "Gael", "Mique", "22465784698", 14);
    cli_altas(pEntidad, "David", "Lamel", "22623251648", 15);
    cli_altas(pEntidad, "Paula", "Ramirez", "20849469864", 16);
    cli_altas(pEntidad, "Alejandra", "Coria", "20684613351", 17);
    cli_altas(pEntidad, "Miguel", "Lev", "20746532168", 18);
    cli_altas(pEntidad, "Angel", "Yuri", "20873696387", 19);
    cli_altas(pEntidad, "Elio", "Pobli", "21258963214", 20);
    cli_altas(pEntidad, "XXXXXXX", "Bari", "21621478963", 21);
    cli_altas(pEntidad, "Maximiliano", "Vu", "21874541235", 22);
    cli_altas(pEntidad, "Ornela", "Wall", "21646584891", 23);
    cli_altas(pEntidad, "Wally", "Kor", "24654168468", 24);
    cli_altas(pEntidad, "Wol", "apl", "25346846384", 25);
    cli_altas(pEntidad, "Celeste", "Xur", "26385468768", 26);
    cli_altas(pEntidad, "Rosa", "Florencio", "23684634638", 27);
    cli_altas(pEntidad, "Blanca", "Troll", "23684124638", 28);
    cli_altas(pEntidad, "Gabriel", "Gabri", "23114634638", 28);
    cli_altas(pEntidad, "Julieta", "venegas", "23114631000", 29);
}

static void cli_altas(Cliente* pEntidad, char* nombre, char* apellido, char* cuit, int i)
{
    pEntidad[i].id=generarID();
    strcpy(pEntidad[i].nombre, nombre);
    strcpy(pEntidad[i].apellido, apellido);
    strcpy(pEntidad[i].cuit, cuit);
    pEntidad[i].isEmpty=FALSE;
}
