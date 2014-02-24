#include <stdio.h>

int fib(int);
int count;

int main(){
	int n, input;
	scanf("%d", &n);
	while(n--){
		count = 0;
		scanf("%d", &input);
		printf("n = %-2d, call %-3d times. \n", input, fib(input));
	}
	return 0;
}

int fib(int n){
	count++;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}
