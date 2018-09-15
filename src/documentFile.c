/*
 * Postivo is website which you must upload files.
 * This section prepare files to send.
 */
#include "documentFile.h"
#include "base64/base64.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>//strlen

#define STRING_SIZE 255
//fgets(s_fileTitle, STRING_SIZE - 1, stdin);//buffer must be less than STRING_SIZE
/// <summary>
/// Gets path to a file and title named by user.
/// </summary>
/// <param name = "filePath"> Pointer to a file path </param>
/// <param name = "fileTitle"> Pointer to a file title named by user </param>
void inputFilePath(char ** filePath, char ** fileTitle)
{
  char * s_filePath = malloc(sizeof(char) * STRING_SIZE);
  char * s_fileTitle = malloc(sizeof(char) * STRING_SIZE);
  printf("Enter the file path:");
  scanf("%s", s_filePath);
  printf("Enter the file title:");
  scanf("%s", s_fileTitle);

  (*filePath) = s_filePath;
  (*fileTitle) = s_fileTitle;
}

/// <summary>
/// Opens a document file and loads it to
/// the struct which stores buffer with the file.
/// </summary>
/// <param name = "fileLocation"> Contain a location to file. <param>
/// <param name = "document"> Pointer to object which contains a file stream and a title. <param>
void loadDocumentFile(const char * fileLocation,char * fileTitle, struct ns1__DocumentFile * document)
{
  FILE * m_file;
  struct ns1__DocumentFile m_document;
  long l_lenght;//lenght in file

  m_document.file_USCOREname = fileTitle;//title

  m_file = fopen(fileLocation,"rb");
  if(m_file)
  {
    fseek (m_file, 0, SEEK_END);//check end of file
    l_lenght = ftell(m_file);//assign this variable lenght of the file
    fseek(m_file, 0, SEEK_SET);

    m_document.file_USCOREstream = malloc(sizeof(char) * l_lenght);
    fread(m_document.file_USCOREstream, sizeof(char), l_lenght, m_file);//read binary in to the file
    char * s_encodedStream = base64encode(m_document.file_USCOREstream, l_lenght);//encode the file
    free(m_document.file_USCOREstream);

    m_document.file_USCOREstream = malloc(sizeof(char) * strlen(s_encodedStream) + 1);//allocating the place in the memory
    m_document.file_USCOREstream = s_encodedStream;

    fclose(m_file);//close the file
  }
  else
  {
    printf("-------------\n");
    printf("Cannot reads this file:%s\n", fileLocation);
    exit(1);
  }
  (*document) = m_document;
}

/// <summary>
/// Releases memory after sent a file.
/// </summary>
void freeDocumentFile(struct ns1__DocumentFile * document)
{
   free(document->file_USCOREstream);//release the file buffor
}
