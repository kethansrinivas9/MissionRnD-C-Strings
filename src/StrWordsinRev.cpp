/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void strev(char *input, int start, int end) {
	char temp;
	while (start < end) {
		temp = input[end];
		input[end] = input[start];
		input[start] = temp;
		start++;
		end--;
	}
	return;
}

void str_words_in_rev(char *input, int len) {
	int i = 0, prev = 0;
	if (input == NULL) {
		return;
	}
	while (i < len) {
		if (input[i] == ' ') {
			strev(input, prev, i - 1);
			prev = i + 1;
		}
		i++;
	}
	strev(input, prev, len - 1);
	strev(input, 0, len - 1);
	return;
}