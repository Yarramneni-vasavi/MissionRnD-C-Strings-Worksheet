/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int ConvertTOstring(int integer_part, char *str, int i);
int power(int, int);
void reverse(char *str, int, int);

void number_to_str(float number, char *str,int afterdecimal)
{
	int index = 0, t = 0;
	if (number < 0)
	{
		number = -(number);
		str[index] = '-';
		index++;
		t = 1;
	}
	//separate integer part from given float number
	int integer_part = (int)number;
	//convert integral part to string
	index = ConvertTOstring(integer_part, str, index);
	//reverse the integral part string
	reverse(str, t, index - 1);
	if (afterdecimal != 0)
	{
		str[index] = '.';		//decimal for float number
		//separate float part
		int float_part = (number - (float)integer_part)*power(10, afterdecimal);
		//convert float part to string
		int end = ConvertTOstring(float_part, str, index + 1);
		//reverse the float part
		reverse(str, index + 1, end - 1);
		index = end;
	}
	str[index] = '\0';
	printf("%s", str);
}

int ConvertTOstring(int integer_part, char *str, int i)
{
	while (integer_part > 0)
	{
		str[i] = integer_part % 10 + '0';
		integer_part = integer_part / 10;
		i++;
	}
	return i;
}

int power(int base, int exponent)
{
	for (int j = 1; j < exponent; j++)
	{
		base = base * 10;
	}
	return base;
}

void reverse(char *str, int start, int end)
{
	int i = start, j = end;
	while (i<j)
	{
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}