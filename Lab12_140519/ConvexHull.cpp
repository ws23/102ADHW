#include <cstdio>
#include <algorithm>

typedef struct _point{
	int x, y;
} point; 

int comp(point a, point b){
	if(a.x==b.x)
		return a.y<b.y; 
	return a.x<b.x; 
}

double cross(point o, point a, point b){
	return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x); 
}

int main(){
	int t, n, m, i, tmp; 
	point p[110], CH[220]; 
	scanf("%d", &t); 
	while(t--){
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d %d", &p[i].x, &p[i].y);
		std::sort(p, p+n, comp);
		
		if(n==3){
			if(cross(p[0], p[1], p[2])==0)
				m = 0; 
			else
				m = 3; 
			printf("%d\n", m);
			continue; 
		}

		m = 0; 

		for(i=0;i<n;i++){
			while(m>=2 && cross(CH[m-2], CH[m-1], p[i])<=0)
				m--; 
			CH[m++] = p[i]; 
		}	

		for(i=n-2, tmp=m+1;i>=-0;i--){
			while(m>=t && cross(CH[m-2], CH[m-1], p[i])<=0)
				m--; 
			CH[m++] = p[i]; 
		}
		
		m--; 

		printf("%d\n", m); 	
	}
	return 0; 
}

