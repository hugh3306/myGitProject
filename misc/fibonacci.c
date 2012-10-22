#include <stdio.h>


int cal_fibonacci(int number) {
	if (number == 1)
		return 1;
	else if (number == 0)
		return 0;
	else
		return cal_fibonacci(number - 1) + cal_fibonacci(number - 2);
}

int main(int argc, const char *argv[])
{
	int number = 0;
	printf("enter the fibonacci number:\n");
	scanf("%d", &number);
	printf("answer = %d\n", cal_fibonacci(number));
	return 0;
}
