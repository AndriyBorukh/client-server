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


	struct sockaddr_in peer;
	int s;
    int rc;
	char buf [5];
	char * sb ="obba";
	char  ip [30] ;

	cout<< "enter server ip";
	gets (ip);
WSADATA wsadata;
	int errorr = WSAStartup (MAKEWORD (2,2),&wsadata);
	if (errorr !=0)
	{
	 cout<< "winsock not loaded;"<< '\n';

	return -1;
	}
cout<< " wsastartup ok err code: " <<errorr<< '\n';

peer.sin_family=AF_INET;
peer.sin_port=htons(7500);

// peer.sin_addr.s_addr= inet_addr ("127.0.0.1");
peer.sin_addr.s_addr= inet_addr (ip);
s= socket (AF_INET,SOCK_STREAM,0);
//s=INVALID_SOCKET;
cout<< " sock status: " << s;
 if (s==INVALID_SOCKET)
 {
	cout<<  (" invalid socket initialization; ")<< '\n';
	 exit (1);
 }
    else
 {
   cout<< (" valid socket initialization; ")<< '\n' ;
 }



 rc= connect (s, (struct sockaddr *)&peer, sizeof (peer) );
cout<< " connection status: " << rc;
 if (rc<0)
 {
	 cout<< (" invalid connection; ")<< '\n';
	 exit (1);
 }
  else
 {
   cout<< (" valid connection; ")<< '\n';
 }


 rc= send (s,sb,5,0 );
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




 rc= recv (s,buf,5,0 );
cout<< " receiving status:" << rc;
 if (rc<0)
 {
	 cout<< (" invalid receiving; ")<< '\n';
	 exit (1);
 }
 else
 {
  cout<< (" valid receiving ")<< '\n';
  cout<< buf;
 }



int wsacl= WSACleanup ();
cout<< " wsacleanup status " << wsacl;

cin>> wsacl;
	return 0;
}