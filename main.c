// NumeralSystemsConverter.cpp
// Symple Numeral System convertion programm
// Author: Dinozor
// Mail: dinocrys@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "numerals.h"

int main(int argc, char* argv[])
{
	printf("Welcome to NumeralSystemsConverter by Dinozor!\n\nData is inputed like \"Number FromBase ToBase\"(spaces between),\nwhere:\n\n-Number\t\tyour Number to convert,\n-FromBase\tyour number radix (2-binary, 16-hex etc.)\n-ToBase\t\tradix to convert to (2-binary, 16-hex etc.)\n");
	char number[9];//don't forget about EOL (EndOfLine symbol '\0')
	int fromBase = 0, toBase = 0;
	scanf("%8s %d %d", number, &fromBase, &toBase); //we use %ns, where 'n' - number of symbols to read. It should be less than N-1, where N is total length of provided char array
	int dec=convertAnyToDec(number, fromBase);
	printf("Number in decimal: %d\n", dec);
	printf("Number in numeral %d: %s\n", toBase, convertDecToAny(dec, toBase));
	system("pause");
	return 0;
}
