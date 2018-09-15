#ifndef RECIPIENT_H
#define RECIPIENT_H

#include "soap/soapH.h"

void createRecipient(struct ns1__Recipient * recipient);
void freeRecipient(struct ns1__Recipient * recipient);

#endif
