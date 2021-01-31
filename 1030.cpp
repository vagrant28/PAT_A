#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1e9;

int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
vector<int> tempPath, path;
vector<int> pre[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1){
			return;
		}
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v == st){
		tempPath.push_back(st);	
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		} 
		if(tempCost < minCost){
			path = tempPath;
			minCost = tempCost;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}


int main(){
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	fill(G[0], G[0] + MAXV * MAXV, INF);
//	fill(cost[0], cost[0] + MAXV * MAXV, INF);
	for(int i = 0; i < m; i++){
		int u, v, d, c;
		scanf("%d%d%d%d", &u, &v, &d, &c);
		G[u][v] = G[v][u] = d;
		cost[u][v] = cost[v][u] = c;
	}
	Dijkstra(st);
	DFS(ed);
	for(int i = path.size() - 1; i >= 0; i--){
		printf("%d ", path[i]);
	}
	printf("%d %d\n", d[ed], minCost);
	return 0;
}
















//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//const int MAXV = 510;
//const int INF = (1 << 30) - 1;
//
//int N, M, S, D;
//int G[MAXV][MAXV], d[MAXV], cost[MAXV][MAXV], c[MAXV], pre[MAXV]; 
//bool vis[MAXV];
//
//void Dijkstra(int s){
//	for(int i = 0; i < N; i++){
//		int u = -1, MIN = INF;
//		for(int j = 0; j < N; j++){
//			if(vis[j] == false && d[j] < MIN){
//				u = j;
//				MIN = d[j];
//			}
//		}
//		if(u == -1){
//			return;
//		}
//		vis[u] = true;
//		for(int v = 0; v < N; v++){
//			if(vis[v] == false && G[u][v] != INF){
//				if(d[u] + G[u][v] < d[v]){
//					d[v] = d[u] + G[u][v];
//					c[v] = c[u] + cost[u][v];
//					pre[v] = u;
//				}
//				else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
//					c[v] = c[u] + cost[u][v];
//					pre[v] = u;
//				}
//			}
//		}
//	}
//}
//
//void DFS(int v, int &distance, int &ans){
//	if(v == S){
//		printf("%d ", S);
//		return;
//	}
//	ans += cost[v][pre[v]];
//	distance += G[v][pre[v]];
//	DFS(pre[v], distance, ans);
//	printf("%d ", v);
//}
//
//int main(){
//	scanf("%d%d%d%d", &N, &M, &S, &D);
//	fill(G[0], G[0] + MAXV * MAXV, INF);
//	fill(d, d + MAXV, INF);
//	d[S] = 0;
//	fill(c, c + MAXV, INF);
//	c[S] = 0;
//	for(int i = 0; i < N - 1; i++){
//		pre[i] = i;
//	}
//	for(int i = 0; i < M; i++){
//		int a, b, dis, cot;
//		scanf("%d%d%d%d", &a, &b, &dis, &cot);
//		G[a][b] = G[b][a] = dis;
//		cost[a][b] = cost[b][a] = cot;
//	}
//	int expense = 0, distance = 0;
//	Dijkstra(S);
//	DFS(D, distance, expense);
//	printf("%d %d\n", distance, expense);
//	
//	return 0;
//}
