#ifndef __SKEL_H__
#define __SKEL_H__
/* winsock*/
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
struct TimeZone
{
	long TZ_minuteswest;
	long TZ_dstime;

};

typedef  unsigned int u_int32_t;

#define EMSGSIZE WSAEMSGSIZE
#define INIT()   init (argv)
#define  EXIT(s)  do {wsacl= WSACleanup (); cout<< " wsacleanup status " << wsacl; exit ((s));} \
	                    while (0)
#define CLOSE(s)   if ( closesocket (s) ) \
	                 error (1,errno, "error close" )
#define errno        (GetLastError () )
#define  set_errno(e)  SetLastError ((e))
#define isvalidsock(s)  ( (s) !=SOCKET_ERROR  )
#define bzero(b,n)     memset ( ( b ) , 0, (n) )
#define WINDOWS


#endif // !__SKEL_H__





