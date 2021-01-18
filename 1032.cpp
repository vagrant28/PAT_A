#include <stdio.h>
const int maxN = 1e5 + 10;

struct node{
	char v;
	int next;
	int flag = 0;
}w[maxN];

int main(){
	int h1, h2, N;
	scanf("%d%d%d", &h1, &h2, &N);
	w[h1].next = -1;
	w[h2].next = -1;
	while(N--){
		int a, b;
		char c;
		scanf("%d %c %d", &a, &c, &b);
		w[a].v = c;
		w[a].next = b;
	}
	int p = h1;
	while(p != -1){
		w[p].flag = 1; 
		p = w[p].next;
	}
	p = h2;
	while(p != -1){
		if(w[p].flag == 1){
			break;
		}
		p = w[p].next;
	}
	if(p == -1){
		printf("-1\n");
	} 
	else{
		printf("%05d\n", p);
	}
	return 0;
}
