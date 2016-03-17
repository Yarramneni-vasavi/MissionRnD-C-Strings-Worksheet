/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char *StringCopy(char *, char *, int);

char **commonWords(char *str1, char *str2)
{
	if (str1 != NULL && str2 != NULL)
	{
		int index = 0, flag;
		char **temp = (char **)malloc(sizeof(char*)*SIZE);
		int start = 0, end;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			//identifying each word end index in str1 string
			if (str1[i] != ' ' && str1[i + 1] == ' ' || str1[i] != ' ' && str1[i + 1] == '\0')
			{
				end = i;
				temp[index] = (char *)malloc(sizeof(char)*(end - start));
				int start2 = 0, end2;
				for (int j = 0; str2[j] != '\0'; j++)
				{
					if (str2[j] != ' ' && str2[j + 1] == ' ' || str2[j] != ' ' && str2[j + 1] == '\0')
					{
						end2 = j;	flag = 0;

						int s1 = start, s2 = start2;
						while (s1 <= end || s2 <= end2)
						{

							if (str1[s1] != str2[s2])
							{
								flag = 1; break;
							}
							s1++;	s2++;
						}
						if (flag == 0)
						{
							//copying the matched word to temp 2D array
							StringCopy(temp[index], (str2 + start2), end2 - start2);
							index++;
							break;
						}
					}
					if (str2[j] == ' ' && str2[j + 1] != ' ')
					{
						start2 = j + 1;
					}
				}
			}
			//identifying each word start index in str1 string
			if (str1[i] == ' ' && str1[i + 1] != ' ')
			{
				start = i + 1;
			}
		}
		if (index == 0)
			return NULL;
		else
			return temp;
	}
	return NULL;
}

char *StringCopy(char *destination, char *source, int len)
{
	int i;
	char *temp1;
	temp1 = destination;
	for (i = 0; i <= len; i++)
	{
		*(temp1 + i) = *(source + i);
	}
	temp1[i] = '\0';
	return temp1;
}