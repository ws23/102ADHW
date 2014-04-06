#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

#define range 10

int** creatGraph(int pointNum){
    int i,j;
    srand (time(NULL));

    int **s;
    s = (int**)new int*[pointNum];
    for(i=0; i<pointNum; i++)
        s[i]=(int*)new int[pointNum];

    for(i=0; i<pointNum; i++){
        for(j=0; j<pointNum; j++){
            if(i==j)
                s[i][j]=0;
            else{
                if(rand()%13==12)
                    s[i][j]=999;
                else
                    s[i][j]=rand()%9+1;
            }
        }
    }
    return s;
}

void show(int **s,int pointNum){
    int i,j,k;

    printf("%4s"," ");
    for(i=0; i<pointNum; i++)
        printf("%4d",i+1);
    cout<<endl;

    for(i=0; i<pointNum; i++){
        printf("%4d",i+1);
        for(j=0; j<pointNum; j++)
            printf("%4d",s[i][j]);
        cout<<endl;
    }
}

int minPoint(int *List,int *visit,int pointNum){
    int i,j,point,small=999;
    for(i=0; i<pointNum; i++){
        if(visit[i]==0){
            if(List[i]<=small){
                point=i;
                small=List[i];
            }
        }
    }
    return point;
}

int *sPath(int **graph,int start,int pointNum){
    int i,j,v;
    int *visit;
    visit=(int*)new int[pointNum];
    for(i=0;i<pointNum;i++)
        visit[i]=0;

    visit[start]=1;

    int *List;
    List=(int*)new int[pointNum];

    for(i=0; i<pointNum; i++)
        List[i]=graph[start][i];

    for(i=0; i<pointNum-2; i++){
        v=minPoint(List,visit,pointNum);
        visit[v]=1;

        for(j=0; j<pointNum; j++)
            if(visit[j]==0 && List[v]+graph[v][j]<=List[j])
                List[j]=List[v]+graph[v][j];
	}
	return List;
}


int **shortList(int **graph,int pointNum){
	int **s;
	s = (int**)new int*[pointNum];

	int i;
	for(i=0; i<pointNum; i++)
		s[i]=sPath(graph,i,pointNum);

	return s;
}

int **floydWarshall(int **graph, int num){
	int **d = (int**)new int *[num];
	for(int i=0;i<num;i++)
		d[i] = (int*)new int[num];

	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			d[i][j] = graph[i][j];

	for(int i=0;i<num;i++)
		d[i][i] = 0;

	for(int k=0;k<num;k++)
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++)
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j] = d[i][k] + d[k][j]; 

	return d;
}

int main(){
    int **graph,**sList, **wList;

	cout << "Graph Create" << endl;
    graph=creatGraph(range);
    show(graph,range);
    cout<<endl;

	cout << "Dijkstra's Algorithm(array)" << endl;
    sList=shortList(graph,range);
    show(sList,range);
	cout << endl;

	cout << "Floyd-Warshall's Algorithm" << endl;
	wList = floydWarshall(graph, range);
	show(wList, range);
	cout << endl;

    return 0;
}
