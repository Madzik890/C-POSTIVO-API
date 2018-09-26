#include "shipments.h"

/// <summary>
/// Gets a shipment ID, from the user inputs.
/// </summary>
/// <param name = "shipmentID"> Pointer to a string which filled with an id. </param>
void getShipmentID(char ** shipmentID)
{
  char * s_shipment = malloc(sizeof(char) * 255);
  printf("Enter the shipment ID:");
  scanf("%s", s_shipment);//waits for user input
  (*shipmentID) = s_shipment;
}

/// <summary>
/// Prints information about shipments.
/// </summary>
/// <param name = "arrayOfShipments"> Results from the API </param>
void printfShipments(struct ArrayOfShipments * arrayOfShipments)
{
  for(int i = 0; i < arrayOfShipments->__size; i++)
  {
    printf("------------- \n");
    printf("Shipment %d'th\n", i);
    printf("Shipment id:%s\n", (*arrayOfShipments->__ptr[i]).id);
    printf("Shipment the recipient name:%s\n", (*arrayOfShipments->__ptr[i]).recipient_USCOREname);
    printf("Shipment the recipient address:%s\n",(*arrayOfShipments->__ptr[i]).recipient_USCOREaddress);
    printf("Shipment the recipient home number:%s\n",(*arrayOfShipments->__ptr[i]).recipient_USCOREhome_USCOREnumber);
    printf("Shipment the recipient flat number:%s\n",(*arrayOfShipments->__ptr[i]).recipient_USCOREhome_USCOREnumber);
    printf("Shipment the recipient post number:%s\n",(*arrayOfShipments->__ptr[i]).recipient_USCOREpost_USCOREcode);
    printf("Shipment the recipient city:%s\n",(*arrayOfShipments->__ptr[i]).recipient_USCOREcity);
    printf("Dispatch carrier:%s\n",(*arrayOfShipments->__ptr[i]).dispatch_USCOREcarrier);
    printf("Dispatch type:%s\n",(*arrayOfShipments->__ptr[i]).dispatch_USCOREtype);
    printf("Count of shipment page:%d\n",(*arrayOfShipments->__ptr[i]->page_USCOREnumber));
    printf("The price of dispatch:%0.2f\n",(*arrayOfShipments->__ptr[i]->price));
    printf("Shipment status:%s\n",(*arrayOfShipments->__ptr[i]).status);
  }
}
