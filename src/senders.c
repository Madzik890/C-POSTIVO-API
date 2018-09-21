#include "senders.h"
#include "stringMan.h"

void printfSingleSender(struct ns1__Sender * sender);

/// <summary>
/// Prints sender received from a WebService.
/// </summary>
/// <param name = arrayOfSenders> An Array of senders </param>
void printfSenders(struct ArrayOfSenders * arrayOfSenders)
{
  if(arrayOfSenders->__ptr != NULL)//if all done successful 
  {
    for(int i = 0; i < arrayOfSenders->__size; i++)
    {
      printfSingleSender(arrayOfSenders->__ptr[i]);//print all information about a sender
    }
  }
}

/// <summary>
/// Creates the sender via user parameters.
/// </summary>
/// <param name = "sender"> Pointer to the user object </param>
void createSender(struct ns1__SenderData * sender)
{
  struct ns1__SenderData m_sender;

  /// <assign the recipient name>
  assignString("Enter the sender name:", &m_sender.sender_USCOREname);
  /// </assign the recipient name>

  /// <assign the post code>
  assignString("Enter the post code:", &m_sender.sender_USCOREpost_USCOREcode);
  /// </assign the post code>

  /// <assign the city>
  assignString("Enter the city:", &m_sender.sender_USCOREcity);
  /// </assign the city>

  /// <assign the address prefix>
  assignString("Enter the adress prefix:", &m_sender.sender_USCOREaddress_USCOREprefix);
  /// </assign the address prefix>

  /// <assign the address>
  assignString("Enter the address:", &m_sender.sender_USCOREaddress);
  /// </assign the address>

  /// <assign the home number>
  assignString("Enter the home number:", &m_sender.sender_USCOREhome_USCOREnumber);
  /// </assign the home number>

  /// <assign the float number>
  assignString("Enter the flat number:", &m_sender.sender_USCOREflat_USCOREnumber);
  /// <assign the float number>

  m_sender.sender_USCOREcountry = NULL;
  m_sender.sender_USCOREfax_USCOREnumber = NULL;

  (*sender) = m_sender;
}

/// <summary>
/// Prints a single sender.
/// </summary>
/// <param name = "sender"> Pointer to a sender </param>
void printfSingleSender(struct ns1__Sender * sender)
{
  printf("The sender ID:%s \n", *sender->sender_USCOREid);
  printf("The sender name:%s \n", *sender->sender_USCOREname);
  printf("The sender address:%s \n", *sender->sender_USCOREaddress);
  printf("The sender home number:%s \n", *sender->sender_USCOREhome_USCOREnumber);
  printf("The sender flat number:%s \n", *sender->sender_USCOREflat_USCOREnumber);
  printf("The sender post code:%s \n", *sender->sender_USCOREpost_USCOREcode);
  printf("The sender city:%s \n", *sender->sender_USCOREcity);
  printf("The sender country:%s \n", *sender->sender_USCOREcountry);
  printf("The sender fax number:%s \n", *sender->sender_USCOREfax_USCOREnumber);
  printf("Is the sender default?:%s \n", *sender->default_);
  printf("Is the sender verified:%s \n", *sender->active);
}
