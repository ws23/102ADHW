#include <cstdio>
#include <algorithm>

struct site{
	int x, y;
};

int comp(site a, site b){
	if(a.x==b.x)
		return a.y>b.y;
	return a.x>b.x;
}

int main(){
	int t, n, i, h, count;
	site p[10001];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d %d", &p[i].x, &p[i].y);
		std::sort(p, p+n, comp);
		h = p[0].y;
		count = 1;
		for(i=1;i<n;i++){
			if(p[i].y>h){
				h = p[i].y;
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
