#include <stdio.h>

int main()
{
	int a[3][2] = { 1, 2, 3, 4, 5, 6 };
	int b[2][3];
	int i,j;

	b = ((int **)a);

	for (i=0; i<2; i++) {
		for (j=0; j<3; j++) {
			printf(" %d", b[i][j]);
		}
	}


}
