#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
int main()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);

	printf("%d ", STTop(&s));
	STPop(&s);

	STPush(&s, 3);
	STPush(&s, 4);

	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}

	STDestroy(&s);

	return 0;
}