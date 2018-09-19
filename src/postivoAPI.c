/*
 * Postivo API is aplication create for handling the web service "Postvio".
 * API creates via gSOAP and works with gSOAPSSL.
 * In each function is used prefix "post". It shortcut of postivo.
 */

#include "soap/Postivo_x002eplBinding.nsmap"

#include "postivoAPI.h"
#include "documentFile.h"//used in: postDispatch
#include "recipient.h"
#include "shipments.h"//used in: postGetDispatchStatus
#include "senders.h"
#include <string.h>//strcmp

/// <global instances>
struct soap * g_soap;
char * s_endAction = NULL;//prepare to using servers
char * s_soapAction = NULL;//prepare to using servers
/// </global instances>

/// <summary>
/// Prints the error code.
/// Created only for clean code.
/// </summary>
/// <param name = "errorCode"> Code of error. </param>
void printErrorMessage(const char * errorCode)
{
  printf("---------------------------------------------------\n");//for transparency
  printf("The request has been sent but something went wrong.\n");
  printf("[Error]: %s\n",errorCode);
}

/// <summary>
/// Prepare the "g_soap", to work with the Postivo API.
/// </summary>
void initPostivoAPI()
{
  g_soap = soap_new1(SOAP_C_UTFSTRING | SOAP_XML_INDENT | SOAP_ENC_SSL | SOAP_XML_TREE);//create soap
  soap_ssl_init();//init SSL
  soap_init(g_soap);//init soap lib

  soap_set_imode(g_soap, SOAP_C_UTFSTRING);//input
  soap_set_omode(g_soap, SOAP_C_UTFSTRING);//output

  if (soap_ssl_server_context(g_soap, SOAP_SSL_NO_AUTHENTICATION, NULL, NULL, NULL, NULL, NULL, NULL, NULL))//init SSL with no AUTHENTICATION
  {
    soap_print_fault(g_soap, stderr);//print error
    exit(1);//exit because without ssl, cannot connect to HTTPS
  }
}

/// <summary>
/// Releasing the memory.
/// </summary>
void closePostivoAPI()
{
  if(s_endAction != NULL)//if endAction is not empty 
    free(s_endAction);//release memory
  soap_end(g_soap);     //delete deserialized temp data
  soap_destroy(g_soap); //delete deserialized data
  soap_free(g_soap);    //free context
}

/// <summary>
/// Creates a request to send a letter.
/// Currently sents to webservice a only 1 file to only a 1 recipient.
/// In the future, will be possible to send to a more than 1 recipient and more than 1 file.
/// When gets any error, returns it code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postDispatch(char * login, char * password)
{
  struct ns1__DocumentFile m_file;
  char * s_filePath = NULL;
  char * s_fileTitle = NULL;
  inputFilePath(&s_filePath,&s_fileTitle);//prepare file
  loadDocumentFile(s_filePath, s_fileTitle, &m_file);//loading and encrypting a file

  struct ArrayOfDocumentFiles m_arrayDocuments;
  m_arrayDocuments.__ptr = calloc(1, sizeof(struct ns1__DocumentFile*));//allocating the memory to only file
  m_arrayDocuments.__size = 1;//set size the array to only one
  m_arrayDocuments.__ptr[0] = &m_file;

  struct ns1__Recipient m_recipient;
  createRecipient(&m_recipient);//create a recipient
  
  struct ArrayOfRecipients m_arrayRecipients;
  m_arrayRecipients.__ptr = calloc(1, sizeof(struct ns1__Recipient*));//allocating the memory to only a one recipient
  m_arrayRecipients.__size = 1;//set size the array to only one
  m_arrayRecipients.__ptr[0] = &m_recipient;

  struct ns2__dispatchResponse m_dispatchStatus;
  if(soap_call_ns2__dispatch(g_soap, s_endAction, s_soapAction, login, password, "1", &m_arrayDocuments, &m_arrayRecipients, 0, &m_dispatchStatus) == SOAP_OK)//try execute the soap method
  {
    if(!strcmp(m_dispatchStatus.return_->result, "OK"))//if is no error
    {
      printf("--------------------------\n");//for transparency
      printf("Successfull\n");
      printf("The request has been sent.\n");
      printfShipments(m_dispatchStatus.return_->shipments);
    }
    else
      printErrorMessage(m_dispatchStatus.return_->result_USCOREdescription);
  }
  else
    soap_print_fault(g_soap, stderr);//print error

  free(m_arrayRecipients.__ptr);
  free(m_arrayDocuments.__ptr);
  free(s_filePath);
  free(s_fileTitle);
  freeRecipient(&m_recipient);
  freeDocumentFile(&m_file);
}

/// <summary>
/// Receives a created request to send a letter.
/// Currently receives from webservice a only 1 file to only a 1 recipient.
/// In the future, will be possible to receives to a more than 1 recipient and more than a 1 file.
/// When gets any error, returns it code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postGetDispatchStatus(char * login, char * password)
{
  struct ArrayOfDispatchIds m_arrayDispatchIDs;
  m_arrayDispatchIDs.__ptr = calloc(1,sizeof(char *));
  m_arrayDispatchIDs.__size = 1;
  getShipmentID(&m_arrayDispatchIDs.__ptr[0]);


  struct ns2__getDispatchStatusResponse m_dispatchStatus;
  if(soap_call_ns2__getDispatchStatus(g_soap, s_endAction, s_soapAction, login, password, &m_arrayDispatchIDs, &m_dispatchStatus) == SOAP_OK)
  {
    if(!strcmp(m_dispatchStatus.return_->result, "OK"))//if is no error
    {
      printf("---------------------------\n");//for transparency
      printf("Successfull\n");
      printf("The status has been received.\n");
      printf("Result:\n");
      printfShipments(m_dispatchStatus.return_->shipments);
    }
    else
      printErrorMessage(m_dispatchStatus.return_->result_USCOREdescription);
  }
  else
    soap_print_fault(g_soap, stderr);//print error
}

/// <summary>
/// Connects to webservice and gets the default account info.
/// User must inputes a login and a password.
/// When gets any error, returns code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postGetBalance(char * login, char * password)
{
  struct ns2__getBalanceResponse m_balanceStatus;//object which is returning in the SOAP function

  if(soap_call_ns2__getBalance(g_soap, s_endAction, s_soapAction, login, password, &m_balanceStatus) == SOAP_OK)//try execute the soap method
  {
    if(!strcmp(m_balanceStatus.return_->result, "OK"))//if is no error
    {
      printf("------------------------\n");//for transparency
      printf("Account balance:%lf \n",m_balanceStatus.return_->balance);
      printf("Account limit:%lf\n",m_balanceStatus.return_->limit);
      if(m_balanceStatus.return_->postpaid == 0)
        printf("Account type: PREPAID\n");
      else
        printf("Account type: POST-PAID\n");
    }
    else
      printErrorMessage(m_balanceStatus.return_->result_USCOREdescription);
  }
  else
    soap_print_fault(g_soap, stderr);//print error
}

/// <summary>
/// Connects to webserivce and gets the price of dispatch.
/// User must inputes a login and a password.
/// When gets any error, returns code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postGetPrice(char * login, char * password)
{
  struct ns1__DocumentFile m_file;
  char * s_filePath = NULL;
  char * s_fileTitle = NULL;
  inputFilePath(&s_filePath,&s_fileTitle);//prepare file
  loadDocumentFile(s_filePath, s_fileTitle, &m_file);//loading and encrypting a file

  struct ArrayOfDocumentFiles m_arrayDocuments;
  m_arrayDocuments.__ptr = calloc(1,sizeof(struct ns1__DocumentFile*));//allocating the memory to only file
  m_arrayDocuments.__size = 1;//set size the array to only one
  m_arrayDocuments.__ptr[0] = &m_file;

  struct ns1__Recipient  m_recipient;
  createRecipient(&m_recipient);//create a recipient

  struct ArrayOfRecipients m_arrayRecipients;
  m_arrayRecipients.__ptr = calloc(1,sizeof(struct ns1__Recipient*));//allocating the memory to only a one recipient
  m_arrayRecipients.__size = 1;//set size the array to only one
  m_arrayRecipients.__ptr[1] = &m_recipient;


  struct ns2__getPriceResponse m_priceStatus;
  if(soap_call_ns2__getPrice(g_soap, NULL, NULL, login, password, "1", &m_arrayDocuments, &m_arrayRecipients, 0, &m_priceStatus) == SOAP_OK)
  {
    if(!strcmp(m_priceStatus.return_->result, "OK"))//if is no error
    {
      printf("--------------------------\n");//for transparency
      printf("Successfull\n");
      printf("The status has been received.\n");
    }
    else
      printErrorMessage(m_priceStatus.return_->result_USCOREdescription);
  }
  else
    soap_print_fault(g_soap, stderr);//print error
}

/// <summary>
/// Connects to service and gets config profiles.
/// User must inputes a login and a password.
/// When gets any error, returns code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postGetConfigProfiles(char * login, char * password)
{
  struct ns2__getConfigProfilesResponse m_configProfilesStatus;
  if(soap_call_ns2__getConfigProfiles(g_soap, s_endAction, s_soapAction, login, password, "1", &m_configProfilesStatus) == SOAP_OK)
  {
    if(!strcmp(m_configProfilesStatus.return_->result, "OK"))//if is no error
    {
      printf("--------------------------\n");//for transparency
      printf("Successfull\n");
      printf("The status has been received.\n");
    }
    else
      printErrorMessage(m_configProfilesStatus.return_->result_USCOREdescription);
  }
  soap_print_fault(g_soap, stderr);
}

/// <summary>
/// Connects to service and gets all senders.
/// User must inputes a login and a password.
/// When gets any error, returns code.
/// List of error codes: https://postivo.pl/docs/Dokumentacja_API_Postivo.pdf
/// </summary>
/// <param name = "login"> Login </param>
/// <param name = "password"> Password </param>
void postGetSenders(char * login, char * password)
{
  struct ns2__getSendersResponse m_sendersStatus;
  if(soap_call_ns2__getSenders(g_soap, s_endAction, s_soapAction, login, password, &m_sendersStatus) == SOAP_OK)
  {
    if(!strcmp(m_sendersStatus.return_->result, "OK"))//if is no error
    {
      printf("--------------------------\n");//for transparency
      printf("Successfull\n");
      printf("The status has been received.\n");
      printfSenders(m_sendersStatus.return_->senders);
    }
    else
      printErrorMessage(m_sendersStatus.return_->result_USCOREdescription);
  }
}

void postGetCertificate()
{

}

void postAddSender()
{

}

void postVerifySender()
{

}

void postVerifySenderID()
{

}
