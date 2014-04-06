#include <stdio.h>

typedef struct _point{
	int x, y;
}point;

int distance(point, point);

int main(){
	int t, n, i, j, dis, tmp;
	point p[10000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%d %d", &p[0].x, &p[0].y);
		scanf("%d %d", &p[1].x, &p[1].y);
		dis = distance(p[0], p[1]);
		for(i=2;i<n;i++){
			scanf("%d %d", &p[i].x, &p[i].y);
			for(j=0;j<i;j++){
				tmp = distance(p[i], p[j]);
				dis = dis<tmp?dis:tmp;
			}
		}
		printf("%d\n", dis);
	}
	return 0;
}

int distance(point a, point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
