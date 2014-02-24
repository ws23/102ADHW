#include <stdio.h>

int main(){
	int i, t, n,f[1001];
	f[0] = 0;
	f[1] = 1;
	for(i=2;i<=1000;i++)
		f[i] = (f[i-1]+f[i-2])%10000;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n>20)
			printf("%04d\n", f[n]);
		else
			printf("%d\n", f[n]);
	}
	return 0;       
}
