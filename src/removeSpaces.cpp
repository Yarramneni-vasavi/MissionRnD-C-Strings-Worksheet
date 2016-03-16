/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

void SpaceShift(char *, int);

char removeSpaces(char *str)
{
	if (str != 0)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == ' ')
			{
				SpaceShift(str, i);
				if (str[i] == ' ')
					i--;
			}
		}
		return *str;
	}
	return '\0';
}

void SpaceShift(char *str, int index)
{
	int i = index;
	while (str[i + 1] != '\0')
	{
		str[i] = str[i + 1];	i++;
	}
	str[i] = '\0';
}