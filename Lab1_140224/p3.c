#include <stdio.h>

int counting(int e){
	if(e==1)
		return 0;
	if(e%2==0)
		return counting(e/2)+1;
	return counting(e/2)+2;
}

void mul(int m[], int a[], int b[]){
	int i, tmp[4];

	tmp[0] = a[0]*b[0]+a[1]*b[2];
	tmp[1] = a[0]*b[1]+a[1]*b[3];
	tmp[2] = a[2]*b[0]+a[3]*b[2];
	tmp[3] = a[2]*b[1]+a[3]*b[3];
	for(i=0;i<4;i++)
		m[i] = tmp[i] %10000;
}

int main(){
	int t, n, i, j, bin, tmp, multi[32], count;
	int f[32][4], ans[4];

	f[0][0] = 0;
	for(i=1;i<=3;i++)
		f[0][i] = 1;

	for(i=1;i<=30;i++)
		mul(f[i], f[i-1], f[i-1]);

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		count = 0;
		for(i=0;i<31;i++)
			multi[i] = 0;
		ans[0] = ans[3] = 1;
		ans[1] = ans[2] = 0;
		for(i=0, bin=1;i<30;i++)
			bin *= 2;
		for(tmp=n-1,i=30;tmp>0;bin/=2, i--){
			if(tmp>=bin){
				tmp -= bin;
				multi[i] = 1;
			}
		}
		for(i=0;i<=30;i++)
			if(multi[i]==1)
				mul(ans, ans, f[i]);
		i = counting(n);
		i = counting(n-1)<i?counting(n-1):i;
		if(n<20)
			printf("%d %d\n", i, ans[3]);
		else
			printf("%d %04d\n", i, ans[3]);
	}
	return 0;
}

