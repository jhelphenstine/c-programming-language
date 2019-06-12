/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
#include <stdio.h>
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) /2;
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else	/* found match */
			return mid;
	}
	return -1;
}

int main()
{
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int n = 10;
	int x = 5;

	int result = binsearch(x, array, n);
	printf("Result: %d\n", result);
	return 0;
}
