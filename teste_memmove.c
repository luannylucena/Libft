#include <string.h>
#include <stdio.h>

int main()
{
	char d[] = "Lo";
	char s[] = "Amor";

	printf("%s\n", memmove(d, s, -5));
}
