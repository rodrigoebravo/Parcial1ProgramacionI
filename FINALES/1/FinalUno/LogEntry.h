#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED

typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
}LogEntry;


LogEntry* LogEntry_new();
void LogEntry_delete();
LogEntry* LogEntry_newConParametros(char* date,char* time,char* serviceId,char* gravedad,char* msg);

int LogEntry_setDate(LogEntry* this,char* date);
int LogEntry_getDate(LogEntry* this,char* date);

int LogEntry_setTime(LogEntry* this,char* time);
int LogEntry_getTime(LogEntry* this,char* time);

int LogEntry_setServiceId(LogEntry* this,int serviceId);
int LogEntry_getServiceId(LogEntry* this,int* serviceId);

int LogEntry_setGravedad(LogEntry* this,int gravedad);
int LogEntry_getGravedad(LogEntry* this,int* gravedad);

int LogEntry_setMsg(LogEntry* this,char* msg);
int LogEntry_getMsg(LogEntry* this,char* msg);

int LogEntry_printLog(LogEntry* this);
#endif // LOGENTRY_H_INCLUDED
