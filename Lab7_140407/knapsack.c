#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *cost, *weight;
int *dp;

int Max(int a, int b){
	if(b>a)
		return b;
	return a;
}

void knapsack(int n, int w){
	int i, j;
	memset(dp, 0, sizeof(int)*(w+1));

	for(i=0;i<n;i++)
		for(j=w;j-weight[i]>=0;j--)
			dp[j] = Max(dp[j], dp[j-weight[i]]+cost[i]);
}

int main(){
	int t, n, w, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &w);
		cost = (int*)malloc(sizeof(int)*n);
		weight = (int*)malloc(sizeof(int)*n);
		dp = (int*)malloc(sizeof(int)*(w+1));

		for(i=0;i<n;i++)
			scanf("%d", &cost[i]);
		for(i=0;i<n;i++)
			scanf("%d", &weight[i]);

		knapsack(n, w);		

		printf("%d\n", dp[w]);
		free(cost);
		free(weight);
		free(dp);
	}
	
	return 0;
}
