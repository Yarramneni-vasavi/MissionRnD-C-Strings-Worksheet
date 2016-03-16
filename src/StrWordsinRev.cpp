/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void WordReverseStr(char *, int, int);
void str_words_in_rev(char *input, int len)
{
	int start = 0, end;
	for (int i = 0; i < len; i++)
	{
		if (input[i] == ' ')
		{
			end = i - 1;
			WordReverseStr(input, start, end);
			start = i + 1;
		}
		if (input[i + 1] == '\0')
		{
			end = i;
			WordReverseStr(input, start, end);
		}
	}
	WordReverseStr(input, 0, len - 1);
	printf("%s", input);
}
void WordReverseStr(char *input, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		++start;
		--end;
	}
}
