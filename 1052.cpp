#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxN = 1e5 + 10;

struct node{
	int key;
	int next;
	int add;
	bool flag = false;
}a[maxN];
 
bool cmp(node a, node b){
	if(a.flag == b.flag){
		return a.key < b.key;
	}
	else{
		return a.flag > b.flag;
	}
}
 
int main(){
	int N, h;
	scanf("%d%d", &N, &h);
	for(int i = 0; i < N; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].add = x;
		a[x].key = y;
		a[x].next = z;
	}
	int p = h, cnt = 0;
	while(p != -1){
		a[p].flag = true;
		cnt++;
		p = a[p].next;
	}
	if(cnt == 0){
		printf("0 -1\n");
	}
	else{
		sort(a, a + maxN, cmp);
		printf("%d %05d\n", cnt, a[0].add);
		for(int i = 0; i < cnt - 1; i++){
			printf("%05d %d %05d\n", a[i].add, a[i].key, a[i + 1].add);
		}
		printf("%05d %d -1\n", a[cnt - 1].add, a[cnt - 1].key);
	}
	return 0;
}
