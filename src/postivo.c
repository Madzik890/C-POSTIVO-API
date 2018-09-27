#include "postivoAPI.h"
#include "userLog.h"
#include "clientOptions.h"
#include <string.h>//strcpy

void helpArgv();
void helpArgvServer();

int main(int argc, char ** argv)
{
  loadClientOptions();
  if(argc == 1)//zero arguments
  {
    if(i_loadedConfig == 0)
      helpArgv();
    else
      helpArgvServer();

    exit(1);//close
  }

  if(argc == 2 && (!strcmp( argv[ 1 ], "-h") || !strcmp( argv[ 1 ], "-help" ) || !strcmp( argv[ 1 ], "--help" )))
  {
    if(i_loadedConfig == 0)
      helpArgv();
    else
      helpArgvServer();

    exit(1);//close
  }
  else
  if(argc == 2 && (!strcmp( argv[ 1 ], "-ccf" ) || !strcmp( argv[ 1 ], "-gCF" ) || !strcmp( argv[ 1 ], "-createConfigFiles" )))//get price
  {
    createClientOptions();
    exit(1);
  } 

  struct userLog user = getUserLog();
  initPostivoAPI();

  for(int i = 1; i <= argc - 1;i++)
  {
    if(!strcmp( argv[ i ], "-d" ) || !strcmp( argv[ i ], "-dispatch" ))//dispatch
      postDispatch(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gd" ) || !strcmp( argv[ i ], "-gD" ) || !strcmp( argv[ i ], "-getDispatch" ))//get dispatch status
      postGetDispatchStatus(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gb" ) || !strcmp( argv[ i ], "-gB" ) || !strcmp( argv[ i ], "-getBalance" ))//get balance
      postGetBalance(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gp" ) || !strcmp( argv[ i ], "-gP" ) || !strcmp( argv[ i ], "-getPrice" ))//get price
      postGetPrice(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gcp" ) || !strcmp( argv[ i ], "-gCP" ) || !strcmp( argv[ i ], "-getConfigProfiles" ))//get config profiles
      postGetConfigProfiles(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gs" ) || !strcmp( argv[ i ], "-gS" ) || !strcmp( argv[ i ], "-getSenders" ))//get senders
      postGetSenders(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-gc" ) || !strcmp( argv[ i ], "-gC" ) || !strcmp( argv[ i ], "-setCertificate" ))//set certificate
      postGetCertificate(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-as" ) || !strcmp( argv[ i ], "-aS" ) || !strcmp( argv[ i ], "-addSender" ))//add sender
      postAddSender(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-vs" ) || !strcmp( argv[ i ], "-vS" ) || !strcmp( argv[ i ], "-verifySender" ))//verify sender
      postVerifySender(user.s_login, user.s_password);

    if(!strcmp( argv[ i ], "-rs" ) || !strcmp( argv[ i ], "-rS" ) || !strcmp( argv[ i ], "-removeSender" ))//remove sender
      postRemoveSender(user.s_login, user.s_password);
  }
  
  freeUser(&user);
  closePostivoAPI();

  return 0;
}

void helpArgv()
{
  printf("Usage Postivo [-d -dispatch] [-gd -gD -getdispatch] [-gb -gB -getbalance] [-gp -gP -getprice] [-gcp -gCP] -getConfigProfiles\n");

  printf("\nOptions: \n");
  printf("   -d               Dispatch shipment. \n");
  printf("   -gd              Get status of shipment. \n");
  printf("   -gb              Get accout balance. \n");
  printf("   -gp              Get price of shipment. \n");
  printf("   -gcp             Get config profiles. \n");
  printf("   -ccf             Create a config file to make connection with other servers. \n");
  printf("   -gs              Get list of senders. \n");
  printf("   -as              Add sender to contacts. \n");
  printf("   -vs              Verify a sender. \n");
  printf("   -rs              Remove a sender.  \n");
}

void helpArgvServer()
{
  printf("[WARNING] \n");
  printf("Config file to a server has been generated. Dedicated servers support less functions. \n");
  printf("To use with normal Web Service, delete the config file. \n");
  printf("Usage Postivo [-gb -gB -getbalance]\n");

  printf("\nOptions: \n");
  printf("   -d               Dispatch shipment. \n");
  printf("   -gb              Get accout balance. \n");
  printf("   -gp              Get price of shipment. \n");
  printf("   -ccf             Create a config file to make connection with other servers. \n");
  printf("   -as              Add sender to contacts. \n");
}

