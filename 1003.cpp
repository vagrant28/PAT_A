#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = (1 << 30) - 1;

struct node{
	int v, dis;
	node(int _v, int _dis): v(_v), dis(_dis){}
};

int N, M, C1, C2;
vector<node> Adj[MAXV];
int d[MAXV], weight[MAXV], w[MAXV], num[MAXV];
set<int> pre[MAXV];

bool Bellman(int s){
	fill(d, d + MAXV, INF);
	fill(w, w + MAXV, 0);
	fill(num, num + MAXV, 0);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	
	for(int i = 0; i < N - 1; i++){
		for(int u = 0; u < M; u++){
			for(int j = 0; j < Adj[u].size(); j++){
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]){
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				if(d[u] + dis == d[v]){
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					set<int>::iterator it;
					for(it = pre[v].begin(); it != pre[v].end(); it++){
						num[v] += num[*it];
					}
				}
			}
		}
	}
	for(int u = 0; u < M; u++){
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for(int i = 0; i < N; i++){
		scanf("%d", &weight[i]);
	}
	for(int i = 0; i < M; i++){
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		Adj[u].push_back(node(v, d));
		Adj[v].push_back(node(u, d));
	}
	Bellman(C1);
	printf("%d %d\n", num[C2], w[C2]);
	return 0;
}









//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//const int MAXV = 510;
//const int INF = (1 << 30) - 1;
//
//int N, M, C1, C2;
//int G[MAXV][MAXV], d[MAXV], weight[MAXV], w[MAXV], num[MAXV];
//bool vis[MAXV] = {false};
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
//					num[v] = num[u];
//					w[v] = w[u] + weight[v];
//				}
//				else if(d[u] + G[u][v] == d[v]){
//					num[v] += num[u];
//					if(w[u] + weight[v] > w[v]){
//						w[v] = w[u] + weight[v];
//					}
//				}
//			}
//		}
//	}
//}
//
//int main(){
//	fill(G[0], G[0] + MAXV * MAXV, INF);
//	fill(d, d + MAXV, INF);
//	fill(w, w + MAXV, 0);
//	fill(num, num + MAXV, 0);
//	scanf("%d%d%d%d", &N, &M, &C1, &C2);
//	d[C1] = 0;
//	num[C1] = 1;
//	for(int i = 0; i < N; i++){
//		scanf("%d", &weight[i]);
//	}
//	w[C1] = weight[C1];
//	for(int i = 0; i < M; i++){
//		int a, b, len;
//		scanf("%d%d%d", &a, &b, &len);
//		G[a][b] = G[b][a] = len;
//	}
//	Dijkstra(C1);
//	printf("%d %d\n", num[C2], w[C2]);
//	return 0;
//}
