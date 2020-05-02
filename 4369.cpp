//code by TheBeaverHunter

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector < vector <int> > graph(100001);
queue <int> que;
int edges,a,b,nodes;
long long visited[100001];
void bfs(){
	while (!que.empty()){
		int node=que.front();
		que.pop();
		for (int i=0;i<graph[node].size();i++){
			int t=graph[node][i];
			if (visited[t]==0){
				que.push(t);
				visited[t]=visited[node]+1;
			}
		}
	}
}

int main(){
	cin>>nodes>>edges;
	for (int i=0;i<edges;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin>>a;
	for (int i=0;i<a;i++){
		cin>>b;
		que.push(b);
		visited[b]=1;}
	bfs();
	int max=-1,max_index;
	for (int i=1;i<=nodes;i++){
		if (visited[i]>max){
			max=visited[i];
			max_index=i;
		}
	}
	cout<<max-1<<"\n"<<max_index;
	return 0;
}
