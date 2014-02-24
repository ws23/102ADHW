#include <stdio.h>

int count, fib[2], matrix[][] = {{1, 1}, {1, 0}};
int fib(int);

int main(){
	int n, input;
	fib[0][1] = fib[0][0] = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &input);
		printf("n = %d, f(n) = %d, do %d times.\n", input, fib(input), count);
	}	
	return 0;
}

int fib(int n){
	int tmp[2];
	if(n<2)
		return 1;
	tmp[0] = fib[0];
	tmp[1] = fib[1];

	fib[0] = 
}
