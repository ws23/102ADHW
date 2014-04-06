#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int *a, *b, *c;
	int t, n, i, j, print;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = (int*)malloc(sizeof(int)*n);
		b = (int*)malloc(sizeof(int)*n);
		c = (int*)malloc(sizeof(int)*n*n);
		memset(c, 0, sizeof(c));

		for(i=n-1;i>=0;i--)
			scanf("%1d", &a[i]);
		for(i=n-1;i>=0;i--)
			scanf("%1d", &b[i]);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				c[i+j] += a[i]*b[j];
				while(c[i+j]>9){
					c[i+j+1]++;
					c[i+j] -= 10;
				}
			}
		}
		n = i+j;
		print = 0;
		for(i=n;i>=0;i--){
			if(print==0){
				if(c[i]==0)
					continue;
				print = 1;
			}
			printf("%d", c[i]);
		}
		printf("\n");
	}

	return 0;
}
