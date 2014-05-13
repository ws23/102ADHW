#include <stdio.h>
#include <string.h>

int total, weight, item; 
int w[500]; 

void sum(int i, int j, int t){
	if(i==1)
		t += w[j]; 
	if(t==weight)
		total++;
	if(t>=weight || j>=item)
		return; 
	
	j++; 

	sum(1, j, t); 
	sum(0, j, t); 
}

int main(){
	int t, i; 
	scanf("%d", &t); 

	while(t--){
		scanf("%d %d", &item, &weight); 
		total = 0;
		memset(w, 0, sizeof(w)); 

		for(i=1;i<=item;i++)
			scanf("%d", &w[i]); 
		sum(0, 0, 0); 

		printf("%05d\n", total%100000); 
	}
	return 0;
}
