#include <stdio.h>

int fib(int);
int count;


int main(){
	int n, in;
	scanf("%d", &n);
	while(n--){
		count = 0;
		scanf("%d", &in);
		fib(in);
		printf("%d\n", count);
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

