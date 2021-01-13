#include <stdio.h>
const int maxn = 1e5 + 10;

int n;
int a[maxn];
int leftMax[maxn];
int rightMin[maxn];
int ans[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	leftMax[0] = a[0];
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > max){
			max = a[i];
			leftMax[i] = a[i];
		}else{
			leftMax[i] = leftMax[i - 1];
		}
	}
	rightMin[n - 1] = a[n - 1];
	int min = a[n -1];
	for(int i = n - 2; i >= 0; i--){
		if(a[i] < min){
			min = a[i];
			rightMin[i] = a[i];
		}else{
			rightMin[i] = rightMin[i + 1];
		}
	}
	int num = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == leftMax[i] && a[i] == rightMin[i]){
			ans[num++] = a[i];
		}
	}
	printf("%d\n", num);
	int i;
	for(i = 0; i < num; i++){
		printf("%d", ans[i]);
			if(i != num - 1){
			putchar(' ');
		}
	}
	putchar('\n');
	return 0;
}

