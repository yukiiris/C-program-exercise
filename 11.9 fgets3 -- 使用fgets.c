#include <stdio.h>
#define STRLEN 10
int main(void)
{
	char word[STRLEN];
	int i;

	puts("Enter a string (empty line to quit)");
	while (fgets(word, STRLEN, stdin) != NULL && word[0] != '\n')
	{
		i = 0;
		while (word[1] != '\n' && word[i] != '\0')
			i++;
		if (word[i] == '\n')
			word[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(word);
	}
	puts("Done.");
	return 0;
}
