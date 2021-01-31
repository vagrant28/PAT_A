#include <stdio.h>
#include <vector>
using namespace std;

struct node{
	int data;
	node *lchild, *rchild;
};

vector<int> seq;
vector<int> preSeq, mirSeq;
bool flag;

void insert(node *&root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(x >= root->data){
		insert(root->rchild, x);
	}
	else{
		insert(root->lchild, x);
	}
}

node *create(vector<int> v){
	node *root = NULL;
	for(int i = 0; i < v.size(); i++){
		insert(root, v[i]);
	}
	return root;
}

void preOrder(node *root){
	if(root == NULL){
		return;
	}
	preSeq.push_back(root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void mirOrder(node *root){
	if(root == NULL){
		return;
	}
	mirSeq.push_back(root->data);
	mirOrder(root->rchild);
	mirOrder(root->lchild);
}

void print(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

void postOrder(node *root){
	if(root == NULL){
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(flag){
		printf(" ");
	}
	flag = true;
	printf("%d", root->data);
}

void mirPostOrder(node *root){
	if(root == NULL){
		return;
	}
	mirPostOrder(root->rchild);
	mirPostOrder(root->lchild);
	if(flag){
		printf(" ");
	}
	flag = true;
	printf("%d", root->data);
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		seq.clear();
		int t;
		while(n--){
			scanf("%d", &t);
			seq.push_back(t);
		}
		node *root = create(seq);
		preSeq.clear();
		mirSeq.clear();
		preOrder(root);
		mirOrder(root);
//		printf("preSeq:\t");
//		print(preSeq);
//		printf("mirSeq:\t");
//		print(mirSeq);
		if(preSeq == seq){
			printf("YES\n");
			flag = false;
			postOrder(root);
			printf("\n");
		}
		else if(mirSeq == seq){
			printf("YES\n");
			flag = false;
			mirPostOrder(root);
			printf("\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
