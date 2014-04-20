#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Min(int a, int b){
	if(a>b)
		return b;
	return a;
}

void show(int dp[][300], int n, int m){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%3d", dp[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

int main(){
	char a[301], b[301];
	int dp[300][300];
	int m, n, gap, miss;
	int t, i, j, tmp;

	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &m, &n, &miss, &gap);
		scanf("%s %s", a, b);	
	
		memset(dp, 0, sizeof(dp));

		dp[0][0] = miss;
		for(i=1;i<n;i++){
			dp[i][0] = i*gap+miss;
			if(a[0]==b[i])
				dp[i][0] -= miss;
		}
		for(i=1;i<m;i++){
			dp[0][i] = i*gap+miss;
			if(a[i]==b[0])
				dp[0][i] -= miss;
		}

//		show(dp, n, m);

		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				tmp = 2147483647;
				if(a[j]==b[i])
					tmp = Min(tmp, dp[i-1][j-1]);		
				else
					tmp = Min(tmp, dp[i-1][j-1]+miss);
				tmp = Min(tmp, dp[i-1][j]+gap);
				tmp = Min(tmp, dp[i][j-1]+gap);
				dp[i][j] = tmp;	
			}
		}

//		show(dp, n, m);

		printf("%d\n", dp[n-1][m-1]);
	}


	return 0;		
}
