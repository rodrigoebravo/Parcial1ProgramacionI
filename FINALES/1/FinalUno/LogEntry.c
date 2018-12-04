#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LogEntry.h"
#include "utn.h"

static int isValidDate(LogEntry* this,char* date);
static int isValidTime(LogEntry* this,char* time);
static int isValidServiceId(LogEntry* this,char* serviceId);
static int isValidGravedad(LogEntry* this,char* gravedad);
static int isValidMsg(LogEntry* this,char* msg);
LogEntry* LogEntry_new()
{
    LogEntry* this;
    this=malloc(sizeof(LogEntry));
    return this;
}

void LogEntry_delete(LogEntry* this)
{
    free(this);
}

LogEntry* LogEntry_newConParametros(char* date,char* time,char* serviceId,char* gravedad,char* msg)
{
    LogEntry* this;

    this=LogEntry_new();

    if(
    isValidDate(this, date)&&
    isValidTime(this, time)&&
    isValidServiceId(this, serviceId)&&
    isValidGravedad(this, gravedad)&&
    isValidMsg(this, msg)&&
    !LogEntry_setDate(this,date)&&
    !LogEntry_setTime(this,time)&&
    !LogEntry_setServiceId(this,atoi(serviceId))&&
    !LogEntry_setGravedad(this,atoi(gravedad))&&
    !LogEntry_setMsg(this,msg))
        return this;

    LogEntry_delete(this);
    return NULL;
}

int LogEntry_setDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(this->date,date);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(date,this->date);
        retorno=0;
    }
    return retorno;
}

static int isValidDate(LogEntry* this,char* date)
{
	int retorno=TRUE;
	return retorno;
}

int LogEntry_setTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(this->time,time);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(time,this->time);
        retorno=0;
    }
    return retorno;
}

static int isValidTime(LogEntry* this,char* time)
{
	int retorno=TRUE;
	return retorno;
}

int LogEntry_setServiceId(LogEntry* this,int serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->serviceId=serviceId;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getServiceId(LogEntry* this,int* serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *serviceId=this->serviceId;
        retorno=0;
    }
    return retorno;
}

static int isValidServiceId(LogEntry* this,char* serviceId)
{
	int retorno=TRUE;
	return retorno;
}
int LogEntry_setGravedad(LogEntry* this,int gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getGravedad(LogEntry* this,int* gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;
}

static int isValidGravedad(LogEntry* this,char* gravedad)
{
	int retorno=TRUE;
	return retorno;
}

int LogEntry_setMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

static int isValidMsg(LogEntry* this,char* msg)
{
	int retorno=TRUE;
	return retorno;
}


int LogEntry_printLog(LogEntry* this)
{
    int retorno=ERROR;
    char dateAux[11];
    char timeAux[6];
    int serviceIdAux;
    int gravedadAux;
    char msgAux[65];
    if(this!=NULL&&
       LogEntry_getDate(this, dateAux)==TODOOK&&
       LogEntry_getTime(this, timeAux)==TODOOK&&
       LogEntry_getServiceId(this, &serviceIdAux)==TODOOK&&
       LogEntry_getGravedad(this, &gravedadAux)==TODOOK&&
       LogEntry_getMsg(this, msgAux)==TODOOK)
    {
        retorno=TODOOK;
        printf("date: %s - time: %s - idServ: %d - gravedad: %d - mensaje: %s\n",dateAux,timeAux,serviceIdAux,gravedadAux,msgAux);
    }

    return retorno;
}
