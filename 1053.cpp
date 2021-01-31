#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 110;

struct node{
	int data;
	vector<int> child;
	node(){}
}tree[maxn];

int N, M, S;
vector<int> w, path;

void dfs(int index, int sum){
//	printf("hello\n");
//	printf("index = %d, sum = %d\n", index, sum);
	node root = tree[index];
	if(sum == S && root.child.size() == 0){
//		printf("success\n");
		bool flag = false;
		for(int i = 0; i < path.size(); i++){
			if(flag){
				printf(" ");
			}
			flag = true;
			printf("%d", tree[path[i]].data);
		}
		printf("\n");
		return;
	}
	if(sum > S){
		return;
	}
	for(int i = 0; i < root.child.size(); i++){
		int child = root.child[i];
//		printf("pre = %d, now = %d, data = %d\n", index, child, tree[child].data);
		path.push_back(child);
		dfs(child, sum + tree[child].data);
		path.pop_back();
	}
	return;
}

int main(){
	scanf("%d%d%d", &N, &M, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &tree[i].data);
	}
	while(M--){
		int id, k, t;
		scanf("%d%d", &id, &k);
		while(k--){
			scanf("%d", &t);
			tree[id].child.push_back(t);
		}
		for(int i = 0; i < tree[id].child.size() - 1; i++){
			for(int j = 0; j < tree[id].child.size() - i - 1; j++){
				if(tree[tree[id].child[j]].data < tree[tree[id].child[j + 1]].data){
					swap(tree[id].child[j], tree[id].child[j + 1]);
				}
			}
		}
//		printf("====father: %d\n", id);
//		for(int i = 0; i < tree[id].child.size(); i++){
//			printf("%d ", tree[tree[id].child[i]].data);
//		}
//		printf("\n======\n");
	}
	path.push_back(0);
	dfs(0, tree[0].data);
	return 0;
}
