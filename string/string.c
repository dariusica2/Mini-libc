// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *d = destination;

	while (*source != '\0') {
		*d = *source;
		d++;
		source++;
	}

	*d = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *d = destination;

	while (len && *source != '\0') {
		*d = *source;
		len--;
		d++;
		source++;
	}

	while (len) {
		*d = '\0';
		d++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *d = destination;

	while (*d != '\0') {
		d++;
	}

	while (*source != '\0') {
		*d = *source;
		d++;
		source++;
	}

	*d = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *d = destination;

	while (*d != '\0') {
		d++;
	}

	while (len && *source != '\0') {
		*d = *source;
		len--;
		d++;
		source++;
	}

	*d = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len && *str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
		len--;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		str++;
		if (*str == c) {
			return (char *)str;
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *last = NULL;

	while (*str != '\0') {
		if (*str == c) {
			last = (char *)str;
		}
		str++;
	}

	if (last) {
		return last;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	for (size_t i = 0 ; i < strlen(haystack) - strlen(needle) + 1 ; i++) {
		int ok = 1;
		for (size_t j = 0 ; j < strlen(needle) ; j++) {
			if (*(haystack + i + j) != *(needle + j)) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return (char *)(haystack + i);
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last = NULL;

	for (size_t i = 0 ; i < strlen(haystack) - strlen(needle) + 1 ; i++) {
		int ok = 1;
		for (size_t j = 0 ; j < strlen(needle) ; j++) {
			if (*(haystack + i + j) != *(needle + j)) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			last = (char *)(haystack + i);
		}
	}

	if (last) {
		return last;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;

	while (num) {
		*d = *(char *)source;
		d++;
		source++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *d = (char *)destination;

	while (num) {
		*d = *(char *)source;
		d++;
		source++;
		num--;
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	while (num) {
		if (*(char *)ptr1 != *(char *)ptr2) {
			return *(char *)ptr1 - *(char *)ptr2;
		}
		ptr1++;
		ptr2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	while (num) {
		*(char *)source = value;
		source++;
		num--;
	}

	return source;
}
