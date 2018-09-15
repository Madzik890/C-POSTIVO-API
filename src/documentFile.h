#ifndef DOCUMENT_FIlE_H
#define DOCUMENT_FILE_H

#include "soap/soapH.h"

void inputFilePath(char ** filePath, char ** fileTitle);
void loadDocumentFile(const char * fileLocation, char * fileTitle, struct ns1__DocumentFile * document);
void freeDocumentFile(struct ns1__DocumentFile * document);

#endif
