#include <stdio.h>
#include <queue>
using namespace std;
const int maxN = 40;

struct node{
	int data;
	node *lchild, *rchild;
	node(){}
	node(int _data){
		data = _data;
		lchild = rchild = NULL;
	}
};

int postSeq[maxN], inSeq[maxN];

node *create(int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;
	}
	node *root = new node;
	root->data = postSeq[postR];
	int k;
	for(k = inL; k <= inR; k++){
		if(inSeq[k] == postSeq[postR]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}

void LayerOrder(node *root){
	queue<node*> q;
	q.push(root);
	bool flag = false;
	while(!q.empty()){
		if(flag){
			printf(" ");
		}
		flag = true;
		node *now = q.front();
		q.pop();
		printf("%d", now->data);
		if(now->lchild != NULL){
			q.push(now->lchild);
		}
		if(now->rchild != NULL){
			q.push(now->rchild);
		}
	}
	printf("\n");
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &postSeq[i]);
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &inSeq[i]);
	}
	node *root = create(1, N, 1, N);
	LayerOrder(root);
	return 0;
}
