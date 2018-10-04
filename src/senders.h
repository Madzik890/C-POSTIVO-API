#ifndef SENDERS_H
#define SENDERS_H

#include "soap/soapH.h"

void createSender(struct ns1__SenderData * sender);
void printfSenders(struct ArrayOfSenders * arrayOfSenders);
void freeSender(struct ns1__SenderData * sender);

#endif