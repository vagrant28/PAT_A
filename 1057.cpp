#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
using namespace std;
const int maxn = 1e5;
const int block_num = ceil(sqrt(maxn + 1));
const int block_cap = floor(sqrt(maxn + 1));

int n, key;
char op[20];
int table[maxn + 10] = {0};
int block[block_num + 10] = {0};
stack<int> st;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%s", op);
		if(strcmp(op, "Pop") == 0){
			if(st.size() == 0){
				printf("Invalid\n");
				continue;
			}
			int top = st.top();
			printf("%d\n", top);
			st.pop();
			table[top]--;
			block[top / block_cap]--;
		}
		else if(strcmp(op, "Push") == 0){
//			printf("enter push!!!\n");
			scanf("%d", &key);
			st.push(key);
			block[key / block_cap]++;
			table[key]++;
//			printf("finish!!\n");
		}
		else if(strcmp(op, "PeekMedian") == 0){
			if(st.size() == 0){
				printf("Invalid\n");
				continue;
			}
			int k;
			if(st.size() % 2 == 0){
				k = st.size() / 2; 
			}
			else{
				k = (st.size() + 1) / 2;
			}
			int sum = 0, id = 0;
			while(sum + block[id] < k){
				sum += block[id++];
			}
			int num = id * block_cap;
			while(sum + table[num] < k){
				sum += table[num++];
			}
			printf("%d\n", num);
		}
	}
	return 0;
}
