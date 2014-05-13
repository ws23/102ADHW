#include <cstdio>
#include <algorithm>
typedef struct _Act{
	int start, end; 
} Act; 

int comp(Act a, Act b){
	if(a.end==b.end)
		return a.start<b.start;
	return a.end<b.end;
}

int main(){
	int t, n, i, count, end;
	Act act[1000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d", &act[i].start);
		for(i=0;i<n;i++)
			scanf("%d", &act[i].end);
		std::sort(act, act+n, comp);
		count = end = 0;
		for(i=0;i<n;i++){
			if(act[i].start>=end){
				count++;
				end = act[i].end;
			}
		}		
		printf("%d\n", count);
	}


	return 0;
}
