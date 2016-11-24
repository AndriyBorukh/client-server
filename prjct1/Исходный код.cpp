#include <iostream>
#include <string>
#include <WinSock2.h>
using namespace std;

int  initial ()
{
  WSADATA wsadata;
	int errorr = WSAStartup (MAKEWORD (2,0),&wsadata);
	if (errorr !=0)
	{
	 cout<< "winsock not loaded";
	return 1;
	}
	string szdesc=wsadata.szDescription;
	cout<< wsadata.wVersion <<' '  ;
	cout<< szdesc <<' '  ;
	 szdesc=wsadata.szSystemStatus;
	cout<< szdesc <<' '  ;
	cout<< wsadata.iMaxUdpDg<<' '  ;
	string u;
	cin >> u;

	return 0;
}


int main() {
	// your code goes here
    int errcode= initial();
	
	return 0;
}