#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_CHECK(p) if(!(p)) printf("Greska pri alokaciji.", stderr), exit(1)

int main(void)
{
	char **a=malloc(sizeof(char*));
	ALLOC_CHECK(a);

	int i, j;

	int ps[26];
	for (i = 0; i < 26; i++) ps[i] = 0;

	char c, s[20];
	i = 0;
	while ((s[0] =getc(stdin))!='\n')
	{
		for (j = 1; (s[j] = getc(stdin)) != '\n'; j++);
		s[j] = '\0';

		*(a + i) = malloc(strlen(s) * sizeof(char));
		ALLOC_CHECK(a + i);
		
		strcpy(*(a + i), s);
		for (j=0; s[j] != '\0'; j++) 
		{
			if (s[j] < 'a') s[j] = s[j]+'a'-'A';
			ps[s[j] - 'a']++;
		}

		i++;
		a = realloc(a, i*sizeof(char*));
	}

	for (i = 0; i<26; i++)
	{
		printf("%c %d\n", 'a'+i, ps[i]);
	}

	system("PAUSE");

	return 0;
}