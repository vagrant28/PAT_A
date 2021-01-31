#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 1010;

struct node{
	int id;
	int layer;
	node(){}
	node(int _id, int _layer): id(_id), layer(_layer){}
};

int N, L, K, num;
vector<int> Adj[maxn];
bool inQue[maxn] = {false};

void print(node t){
	printf("id=%d, layer=%d\n", t.id, t.layer);
}

void bfs(int s){
	queue<node> q;
	node start = node(s, 0);
	q.push(start);
	inQue[s] = true;
	while(!q.empty()){
		node top = q.front();
//		print(top);
		q.pop();
		int u = top.id;
		for(int i = 0; i < Adj[u].size(); i++){
			node next = node(Adj[u][i], top.layer + 1);
			if(inQue[next.id] == false && next.layer <= L){
				q.push(next);
				inQue[next.id] = true;
				num++;
			}
		}
	}
}


int main(){
	int M, id;
	cin >> N >> L;
	for(int i = 1; i <= N; i++){
		cin >> M;
		while(M--){
			cin >> id;
			Adj[id].push_back(i);
		}
	}
//	for(int i = 1; i <= N; i++){
//		printf("i=%d: ", i);
//		for(int j = 0; j < Adj[i].size(); j++){
//			printf("%d ", Adj[i][j]);
//		}
//		printf("\n");
//	}
	cin >> K;
	while(K--){
		cin >> id;
		num = 0;
		memset(inQue, 0, sizeof(inQue));
		bfs(id);
		printf("%d\n", num);
	}
	return 0;
}
