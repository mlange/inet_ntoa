#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/tcp.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <unistd.h>
# include <netdb.h>

int main(int argc, char *argv[])
{
    long status;

    char *ipaddress;

    struct hostent *hp;

    status = inet_addr(argv[1]);
    if (status != -1)
    {
	strcpy(ipaddress, argv[1]);
    }
    else
    {
	hp = gethostbyname(argv[1]);
	strcpy(ipaddress, inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
    }

    printf("IP Address: %s\n", ipaddress);

    exit(0);
}

