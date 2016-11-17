#include <stdio.h>
#define STRLEN 14
int main(void)
{
	char word[STRLEN];

	puts("Enter a string:");
	fgets(word, STRLEN, stdin);
	printf("Your string twice (puts(), then fputs()):\n");
	puts(word);
	fputs(word, stdout);
	puts("Enter another string:");
	fgets(word, STRLEN, stdin);
	printf("Your string twice (puts(), then fputs()):\n");
	puts(word);
	fputs(word, stdout);
	puts("Done.");

	return 0;
}
