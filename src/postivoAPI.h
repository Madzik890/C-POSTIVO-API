#ifndef POSTIVO_API_H
#define POSTIVO_API_H

#include "soap/soapH.h"

/// <global instances>
extern struct soap * g_soap;
char * s_endAction;
char * s_soapAction;
/// </global instances>

/// <functions>
void initPostivoAPI();
void closePostivoAPI();

void postDispatch(char * login, char * password);
void postGetDispatchStatus(char * login, char * password);
void postGetBalance(char * login, char * password);
void postGetPrice(char * login, char * password);
void postGetConfigProfiles(char * login, char * password);
void postGetSenders();
void postGetCertificate();
void postAddSender();
void postVerifySender();
void postVerifySenderID();
/// </functions>

#endif
