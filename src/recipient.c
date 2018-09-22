#include "recipient.h"
#include "stringMan.h"

/// <summary>
/// Creates the recipient from user inputs.
/// </summary>
/// <param name = "recipient"> Pointer to recipient object. </param>
void createRecipient(struct ns1__Recipient * recipient)
{
  struct ns1__Recipient m_recipient;
  int l_sourceAnswer = 0;
  printf("1)Group\n");
  printf("2)Book \n");
  printf("3)Inline \n");
  printf("Enter the source type:");
  scanf("%d", &l_sourceAnswer);//waits for user input
  assignSource(l_sourceAnswer, &m_recipient.source);

  /// <assign the id>
  int i_id;
  if(l_sourceAnswer != 3)
  {
    printf("Enter the recipient's id:");
    scanf("%d", &i_id);//waits for user input
    m_recipient.id = malloc(sizeof(int) * 1);
    m_recipient.id = &i_id;

    m_recipient.recipient_USCOREname = NULL;
    m_recipient.recipient_USCOREpost_USCOREcode = NULL;
    m_recipient.recipient_USCOREcity = NULL;
    m_recipient.recipient_USCOREaddress_USCOREprefix = NULL;
    m_recipient.recipient_USCOREaddress = NULL;
    m_recipient.recipient_USCOREhome_USCOREnumber = NULL;
    m_recipient.recipient_USCOREflat_USCOREnumber = NULL;
    m_recipient.recipient_USCOREcountry = NULL;
    m_recipient.recipient_USCOREfax_USCOREnumber = NULL;
  }
  /// </assign the id>

  if(l_sourceAnswer == 3)
  {
    char * s_eliminateFreeLine;            //when using is "scanf" and "fgets" occurs
   assignString("", &s_eliminateFreeLine);//a free line, this elminate this problem
    free(s_eliminateFreeLine);

  /// <assign the recipient name>
   assignString("Enter the recipient's name:", &m_recipient.recipient_USCOREname);
  /// </assign the recipient name>

  /// <assign the post code>
   assignString("Enter the post code:", &m_recipient.recipient_USCOREpost_USCOREcode);
  /// </assign the post code>

  /// <assign the city>
   assignString("Enter the city:", &m_recipient.recipient_USCOREcity);
  /// </assign the city>

  /// <assign the address prefix>
   assignString("Enter the adress prefix:", &m_recipient.recipient_USCOREaddress_USCOREprefix);
  /// </assign the address prefix>

  /// <assign the address>
   assignString("Enter the address:", &m_recipient.recipient_USCOREaddress);
  /// </assign the address>

  /// <assign the home number>
   assignString("Enter the home number:", &m_recipient.recipient_USCOREhome_USCOREnumber);
  /// </assign the home number>

  /// <assign the float number>
    assignString("Enter the flat number:", &m_recipient.recipient_USCOREflat_USCOREnumber);
  /// <assign the float number>

    m_recipient.recipient_USCOREcountry = NULL;
    m_recipient.recipient_USCOREfax_USCOREnumber = NULL;
  }
  (*recipient) = m_recipient;
}

/// <summary>
/// Releases memory from user data.
/// </summary>
/// <param name = "recipeint"> Pointer to recipient </param>
void freeRecipient(struct ns1__Recipient * recipient)
{
  if(recipient->id != NULL)//release type of recipient
    free(recipient->id);

  if(recipient->recipient_USCOREname != NULL)
    free(recipient->recipient_USCOREname);//release name

  if(recipient->recipient_USCOREpost_USCOREcode != NULL)
    free(recipient->recipient_USCOREpost_USCOREcode);//release code

  if(recipient->recipient_USCOREcity != NULL)
    free(recipient->recipient_USCOREcity);//release code

  if(recipient->recipient_USCOREaddress_USCOREprefix != NULL)
    free(recipient->recipient_USCOREaddress_USCOREprefix);//release addres prefix

  if(recipient->recipient_USCOREaddress != NULL)
    free(recipient->recipient_USCOREaddress);//release address

  if(recipient->recipient_USCOREhome_USCOREnumber != NULL)
    free(recipient->recipient_USCOREhome_USCOREnumber);//release home number

  if(recipient->recipient_USCOREflat_USCOREnumber != NULL)
    free(recipient->recipient_USCOREflat_USCOREnumber);//release flat number

  if(recipient->recipient_USCOREcountry != NULL)
    free(recipient->recipient_USCOREcountry);//release country

  if(recipient->recipient_USCOREfax_USCOREnumber != NULL)
    free(recipient->recipient_USCOREfax_USCOREnumber);//release fax number
}
