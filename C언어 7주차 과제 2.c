#include <stdio.h>

typedef struct point
{
	int x;
	int y;
}POINT;

int main()
{
	POINT p1 = { 10, 10 };
	struct point p2;
	p2.x = 20; 
	p2.y = 20;
	struct point* p3 = &p2;

	printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
	printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);
	printf("p3->x = %d, p3->y = %d\n", p3->x, p3->y);

	printf("p3.x = %d, p3.y = %d\n", (*p3).x, (*p3).x);


	return 0;
}