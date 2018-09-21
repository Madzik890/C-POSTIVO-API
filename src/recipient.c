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
  assingSource(l_sourceAnswer, &m_recipient.source);

  /// <assing the id>
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
  }
  /// </assing the id>

  if(l_sourceAnswer == 3)
  {
    char * s_eliminateFreeLine;            //when using is "scanf" and "fgets" occurs
    assingString("", &s_eliminateFreeLine);//a free line, this elminate this problem
    free(s_eliminateFreeLine);

  /// <assing the recipient name>
    assingString("Enter the recipient's name:", &m_recipient.recipient_USCOREname);
  /// </assing the recipient name>

  /// <assing the post code>
    assingString("Enter the post code:", &m_recipient.recipient_USCOREpost_USCOREcode);
  /// </assing the post code>

  /// <assing the city>
    assingString("Enter the city:", &m_recipient.recipient_USCOREcity);
  /// </assing the city>

  /// <assing the address prefix>
    assingString("Enter the adress prefix:", &m_recipient.recipient_USCOREaddress_USCOREprefix);
  /// </assing the address prefix>

  /// <assing the address>
    assingString("Enter the address:", &m_recipient.recipient_USCOREaddress);
  /// </assing the address>

  /// <assing the home number>
    assingString("Enter the home number:", &m_recipient.recipient_USCOREhome_USCOREnumber);
  /// </assing the home number>

  /// <assing the float number>
    assingString("Enter the flat number:", &m_recipient.recipient_USCOREflat_USCOREnumber);
  /// <assing the float number>

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
  free(recipient->recipient_USCOREname);//release name
  free(recipient->recipient_USCOREpost_USCOREcode);//release code
  free(recipient->recipient_USCOREcity);//release code
  free(recipient->recipient_USCOREaddress_USCOREprefix);//release addres prefix
  free(recipient->recipient_USCOREaddress);//release address
  free(recipient->recipient_USCOREhome_USCOREnumber);//release home number
  free(recipient->recipient_USCOREflat_USCOREnumber);//release flat number
  free(recipient->recipient_USCOREcountry);//release country
  free(recipient->recipient_USCOREfax_USCOREnumber);//release fax number
}
