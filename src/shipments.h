#ifndef SHIPMENTS_H
#define SHIPMENTS_H

#include "soap/soapH.h"

void getShipmentID(char ** shipmentID);
void printfShipments(struct ArrayOfShipments * arrayOfShipments);
void printfShipmentsPrices(struct ArrayOfShipmentsPrice * arrayOfShipments);

#endif
