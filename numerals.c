#include "numerals.h"

const char N_symbols[]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', //Sorted array of digits and symbols that are used as digits in other numeral systems
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', //26 letters in alphabet
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};//26 more lowercase letters
const int N_maxBase = 26 + 26 + 10;

int convertAnyToDec(char *number, int base)
{
	int res=0;
	char c = number[0];
	int i = 0;

	while (c != '\0')
	{
		res = res * base + getSymbolAsDec(c);
		i++;
		c = number[i];
	}
	return res;
}
char* convertDecToAny(int number, int base)
{
	char res[80];
	res[0]='\0';
	int i=0;
	do
	{
		i++;
		res[i]=N_symbols[number%base];
		number=number/base;
	}
	while (number>0);
	int j=0, mid=(i+1)/2;
	int a=0;

	while (j<mid)
	{
		char c=res[j];
		res[j]=res[i-j];
		res[i-j]=c;
		j++;
	}
	return &res;
}
int getSymbolAsDec(char c)
{
	int i = 0;
	while (i < N_maxBase && c != N_symbols[i])
		i++;
	return i;
}
