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
#include<string.h>
#include<stdlib.h>

void strrev(char *str, int len) {
	int i;
	char temp;
	for (i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return;
}

void number_to_str(float number, char *str, int afterdecimal){
	int n, i = 0, ng = 0;
	for (; i < afterdecimal; i++) {
		number *= 10;
	}
	if (number < 0) {
		number = -number;
		ng = 1;
	}
	n = (int)number;
	for (i = 0; n > 0; i++) {
		if (afterdecimal != 0 && i == afterdecimal) {
			str[i] = '.';
			continue;
		}
		str[i] = '0' + n % 10;
		n /= 10;
	}
	if (ng) {
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	strrev(str, i);
	return;
}
