#include <stdio.h>
#define STRLEN 10
int main(void)
{
	char word[STRLEN];

	puts("Enter a string (empty line to qiut):");
	while (fgets(word, STRLEN, stdin) != NULL && word[0] != '\n')
		fputs(word, stdout);
	puts("Done.");

	return 0;
}
