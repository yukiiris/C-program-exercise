#include <stdio.h>
#define STRLEN 81
int main(void)
{
	char word[STRLEN];

	puts("Enter a string, please");
	gets(word);
	printf("Your string twice:\n");
	printf("%s", word);
	puts(word);
	puts("Done.");

	return 0;
}
