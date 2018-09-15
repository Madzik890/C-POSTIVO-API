CC = gcc
HTTPS = ./src/postivo.c ./src/postivoAPI.c ./src/userLog.c ./src/recipient.c ./src/documentFile.c ./src/base64/base64.c ./src/shipments.c ./src/soap/soapC.c ./src/soap/soapClient.c ./src/soap/stdsoap2.c 
PARAM = -o postivo -DWITH_OPENSSL -std=gnu99 -lrt -I./include -L./lib
LIBS = -lgsoapssl -lssl -lcrypto
	
all:	$(HTTPS)
	$(CC) $(PARAM) $(HTTPS) $(LIBS)
