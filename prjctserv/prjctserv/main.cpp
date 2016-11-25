#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

#define DefaultPort 6767
#define Printusers if (nclients)\
  printf("%d user on-line\n",nclients);\
  else printf("No User on line\n");

int nclients=0;
/*
int  initial ()
{
  

	return 0;
}
*/
/*
int  initsock (SOCKET *sock)
{
	*sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	struct sockaddr_in addr; 
	addr.sin_family= AF_INET;
	addr.sin_port= htons (6767);
	addr.sin_addr.s_addr = htonl (INADDR_ANY);
	bind (*sock ,(SOCKADDR *) &addr , sizeof (addr));



	return 0;
}
*/



/*
 //	variables
	struct addrinfo *result = NULL , *ptr=NULL ,  hints;


//creating sock{

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_addr

//creating sock}

//init winsock{
WSADATA wsadata;
	int errorr = WSAStartup (MAKEWORD (2,2),&wsadata);
	if (errorr !=0)
	{
	 cout<< "winsock not loaded";
	return 1;
	}
//initwinsock}




	string szdesc=wsadata.szDescription;
	cout<< wsadata.wVersion <<' '  ;
	cout<< szdesc <<' '  ;
	 szdesc=wsadata.szSystemStatus;
	cout<< szdesc <<' '  ;
	cout<< wsadata.iMaxUdpDg<<' '  ;



	SOCKET sock ;
	initsock ( & sock);
	//WSASocket (AF_INET,SOCK_DGRAM,IPPROTO_UDP,);
	listen(sock,3);
	//cout<< errcode <<' '  ;
		string u;
	cin >> u;*/




int main() {

	struct sockaddr_in local;
	int s;
	int s1;
    int rc;
	char buf [4];
	char com [4]="beg";
	int i=0;
	
WSADATA wsadata;

while  (com!="ext") 
{
	int errorr = WSAStartup (MAKEWORD (2,2),&wsadata);
	if (errorr !=0)
	{
	 cout<< "winsock not loaded;"<< '\n';

	return -1;
	}
cout<< " wsastartup ok err code: " <<errorr<< '\n';
local.sin_family= AF_INET;
local.sin_port = htons (7500);
local.sin_addr.s_addr= htonl ( INADDR_ANY )  ;

s= socket (AF_INET, SOCK_STREAM, 0);
cout << " socket status: "<< s;
  if (s==INVALID_SOCKET)
 {
	cout<<  (" invalid socket initialization; ")<< '\n';
	 exit (1);
 }
    else
 {
   cout<< (" valid socket initialization; ")<< '\n' ;
 }
 
  rc = bind (s, (struct sockaddr *)&local, sizeof (local) );
  cout << " binding status: "<< rc;
  if (rc==SOCKET_ERROR)
 {
	cout<<  (" invalid socket binding; ")<< '\n';
	 exit (1);
 }
    else
 {
   cout<< (" valid socket binding; ")<< '\n' ;
 }

  rc = listen (s, 5 );
  cout << " listening status: "<< rc;
  if (rc==SOCKET_ERROR)
 {
	cout<<  (" invalid socket listening; ")<< '\n';
	 exit (1);
 }
    else
 {
   cout<< (" valid socket listening; ")<< '\n' ;
 }

  s1= accept (s, NULL, NULL );
 cout << " accept status: "<< s1;
 if (s1== INVALID_SOCKET)
 {
	cout<<  (" invalid socket accept ; ")<< '\n';
	 exit (1);
 }
    else
 {
   cout<< (" valid socket accept; ")<< '\n' ;
 }


 rc= recv (s1,buf,5,0 );
cout<< " receiving status:" << rc;
 if (rc<0)
 {
	 cout<< (" invalid receiving; ")<< '\n';
	 exit (1);
 }
 else
 {
  cout<< (" valid receiving ")<< '\n';
 i=0;
 
 {
  cout<< buf;

 }

 }

rc= send (s1,"yoba",5,0 );
cout<< " sending status:" << rc;
 if (rc<0)
 {
	 cout<< (" invalid sending; ")<< '\n';
	 exit (1);
 }
 else
 {

  cout<< (" valid sending ")<< '\n';
 }




int wsacl= WSACleanup ();
cout<< " wsacleanup status " << wsacl;

cin >> com;
}
	return 0;
}