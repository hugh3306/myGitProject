#include <stdio.h>

void hanoi(int n, char A, char B, char C) {
	if (n == 0) {
		printf("no plate\n");
		return;
	}
	else if (n == 1) {
		printf("move plate from \"%c\" to \"%c\" \n", A, C);
		return;
	}

	hanoi(n - 1, A, C, B);
	hanoi(1, A, B, C);
	hanoi(n - 1, B, A, C);
}

int main(int argc, const char *argv[])
{
	int number = 0;
	printf("input plat number\n");	
	scanf("%d", &number);
	hanoi(number, 'A', 'B', 'C');
	printf("done\n");
	return 0;
}
