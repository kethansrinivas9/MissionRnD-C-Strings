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

void strcp(char *source, int start, int end, char **d) {
	int i; char *dest;
	dest = (char *)malloc(sizeof(char)* (end - start + 2));
	for (i = start; i <= end; i++) {
		dest[i - start] = source[i];
	}
	dest[i - start] = '\0';
	*d = dest;
	return;
}

int strfind(char *key, int kstart, int kend, char *source) {
	int i = 0, j = kstart;
	while (source[i] != '\0') {
		if (j > kend) {
			if (source[i] == ' ' || source[i] == '\0') {
				return 1;
			}
			j = kstart;
		}
		else if (source[i] == key[j]) {
			j++;
		}
		else {
			j = kstart;
		}
		i++;
	}
	if (j > kend) return 1;
	return 0;
}

char ** commonWords(char *str1, char *str2) {
	int i = 0, prev = 0, size = 1;
	char **cw = NULL; char *cp = NULL;
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	while (str1[i] != '\0') {
		if (str1[i] == ' ' && i && str1[i - 1] != ' ') {
			if (strfind(str1, prev, i - 1, str2)) {
				strcp(str1, prev, i - 1, &cp);
				cw = (char **)realloc(cw, sizeof(char *) * size);
				cw[size - 1] = cp;
				size++;
			}
			prev = i + 1;
		}
		i++;
	}
	if (prev != 0) {
		if (strfind(str1, prev, i - 1, str2)) {
			strcp(str1, prev, i - 1, &cp);
			cw = (char **)realloc(cw, sizeof(char *)* size);
			cw[size - 1] = cp;
		}
	}
	return cw;
}