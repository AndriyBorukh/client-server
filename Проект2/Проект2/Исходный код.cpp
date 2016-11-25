#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "atalkwsh.h"
#include <stdlib.h>
#include <Windows.h>
#pragma comment (lib, "Ws2_32.lib")
using namespace std;
#define MY_ZONE  "*"
#define MY_TYPE "Winsock-Test-App" 
#define MY_OBJECT "AppleTalk-Server"
 
char szZone[MAX_ENTITY],szType[MAX_ENTITY],szObject [MAX_ENTITY];
BOOL bFindName =false,bListZones =false, bListMyZone =false ;

void usage ()
{
  printf ("usage: atlookup [options] \n " );
  printf ("             Name lookup: \n " );
  printf ("             -z:ZONE-NAME \n " );
  printf ("             -t:TYPE-NAME \n " );
  printf ("             -o:OBJECT-NAME \n " );
  printf ("             List All Zones: \n " );
  printf ("             -lz \n " );
  printf ("             List my: Zone \n " );
  printf ("             -lm \n " );
  ExitProcess(1);
}



int main ()
{
	//int s= socket (AF_APPLETALK);
	


return 0;
}