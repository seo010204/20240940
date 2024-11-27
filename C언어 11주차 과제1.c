#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pInt;
	char* pChar;
	int count;

	scanf("%d", &count);
	pInt = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++) pInt[i] = rand() % 100;
	for (int i = 0; i < count; i++) printf("%d ", pInt[i]);

	while (getchar() != '\n');

	pChar = (char*)pInt;

	gets(pChar);
	puts(pChar);

	free(pInt);

	return 0;
}