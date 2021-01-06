#include <unistd.h>
#include <stdio.h>
int main()
{
	char buffer[1000];
	read(0,buffer,999);
	printf("%s",buffer);
	return 0;
}
