#include "senders.h"

void printfSingleSender(struct ns1__Sender * sender);

/// <summary>
/// Prints sender received from a WebService.
/// </summary>
/// <param name = arrayOfSenders> An Array of senders </param>
void printfSenders(struct ArrayOfSenders * arrayOfSenders)
{
  if(arrayOfSenders->__ptr != NULL)//if all done successful 
  {
    for(int i = 0; i <= arrayOfSenders->__size; i++)
    {
      printfSingleSender(arrayOfSenders->__ptr[i]);//print all information about a sender
    }
  }
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