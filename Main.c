#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	int x;
	int y;
} Point;

typedef struct
{
	Point point;
	int l;
} MovingPoint;

typedef struct
{
	Point center;
	int innerRadius;
	int outerRadius;
} Ring;

void print(MovingPoint mp) {
	printf("Point: {X: %i, Y: %i}, L: %i", mp.point.x, mp.point.y, mp.l);
}


Point square = { 10, -10 };
int squareSideLength = 10;

bool in_square(Point p) {
	if (p.x > square.x + squareSideLength / 2)
		return false;

	if (p.y > square.y + squareSideLength / 2)
		return false;

	if (p.x < square.x - squareSideLength / 2)
		return false;

	if (p.y < square.y - squareSideLength / 2)
		return false;

	return true;
}


int min(int a, int b) {
	return a > b ? b : a;
}


int max(int a, int b) {
	return a < b ? b : a;
}


int sign(int a) {
	if (a > 0)
		return 1;

	if (a < 0)
		return -1;

	return 0;
}

int abs(int a) {
	return a >= 0 ? a : -a;
}


int main()
{
	Point point = { 24, -14 };

	MovingPoint pointActor;
	pointActor.point = point;
	pointActor.l = 9;


	for (int k = 1; k <= 50; k++)
	{
		int i = pointActor.point.x;
		int j = pointActor.point.y;
		int l = pointActor.l;

		print(pointActor);
		printf("\n");

		MovingPoint newPoint;
		newPoint.point.x = (i + k) * (j - k) * (l + k) % 25;
		newPoint.point.y = min(i + k, max(j - k, l - k)) % 30;
		newPoint.l = abs(j - l) * sign(i) - abs(i - l) * sign(j);

		pointActor = newPoint;

		if (in_square(newPoint.point)) {
			printf("Successful: ");
			print(pointActor);
			printf("\n");
			return 0;
		}
	}

	printf("Not found\n");
	print(pointActor);
	return 0;
}
