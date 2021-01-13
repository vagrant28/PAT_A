#include <stdio.h>
#include <string.h>
const int maxn = 1e5 + 10;
const int M = 1000000007;

int main(){
	int leftNumP[maxn] = {0};
	char str[maxn];
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] == 'P'){
			if(i == 0){
				leftNumP[i] = 1; 
			}else{
				leftNumP[i] = leftNumP[i - 1] + 1; 
			}
		}else{
			if(i == 0){
				leftNumP[i] = 0; 
			}else{
				leftNumP[i] = leftNumP[i - 1]; 
			}
		}
	}
//	for(int i = 0; i < len; i++){
//		printf("%d ", leftNumP[i]);
//	}
//	putchar('\n');
	int rightNumT = 0;
	int ans = 0;
	for(int i = len - 1; i >= 0; i--){
		if(str[i] == 'T'){
			rightNumT++;
		}
		else if(str[i] == 'A'){
			ans = (ans + leftNumP[i] * rightNumT) % M;
		}
	}
	printf("%d\n", ans);
	return 0;
}
