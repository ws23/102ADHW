#include <stdio.h>

int w[50][50], s[100][100]; 
int times, range; 

void ini(){
	int i; 
	for(i=1;i<=range;i++)
		s[0][i] = 1; 
}

void copy(int level){
	int i; 
	for(i=1;i<=range;i++)
		s[level+1][i] = s[level][i]; 
}

int getAll(int level){
	int i; 
	for(i=1;i<=range;i++)
		if(s[level][i]==1)
			return 0;
   return 1; 	
}

void hum(int item, int level){
	int i; 

	copy(level); 
	s[level+1][item] = 0; 
	if(getAll(level+1)==1)
		times++; 

	for(i=1;i<=range;i++)
		if(w[item][i]==1)
			if(s[level+1][i]==1)
				hum(i, level+1); 
}

int main(){
	int t, i, j;
	scanf("%d", &t); 

	while(t--){
		scanf("%d", &range); 
		for(i=1;i<=range;i++)
			for(j=1;j<=range;j++)
				scanf("%1d", &w[i][j]); 

		times = 0; 

		for(i=1;i<=range;i++){
			ini(); 
			hum(i, 0); 
		}

		printf("%d\n", times/2);
	}
	return 0; 
}
