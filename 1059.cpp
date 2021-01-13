#include <stdio.h>
#include <string.h>
#include <math.h>
const int maxn = 1e6 + 10;

int prime[maxn], pnum;
bool flag[maxn];

void findPrime(){
	pnum = 0;
	memset(prime, 0, sizeof(prime));
	memset(flag, 0, sizeof(flag));
	for(int i = 2; i < maxn; i++){
		if(!flag[i]){
			prime[pnum++] = i;
			for(int j = i + i; j < maxn; j += i){
				flag[j] = true;
			}
		}
	}
}

struct factor{
	int x, cnt;
}fac[10];

int main(){
	findPrime();
//	for(int i = 0; i < pnum; i++){
//		printf("%d ", prime[i]);
//	}
	int N;
	scanf("%d", &N);
	if(N == 1){
		printf("1=1");
		return 0;
	}
	int tmp = N;
	int h = (int)sqrt(1.0 * N);
	int fnum = 0;
	for(int i = 0; prime[i] <= h; i++){
		if(N % prime[i] == 0){
			fac[fnum].x = prime[i];
			fac[fnum].cnt = 0;
			while(N % prime[i] == 0){
				fac[fnum].cnt++;
				N /= prime[i];
			}
			fnum++;
		}
	}
	if(N != 1){
		fac[fnum].x = N;
		fac[fnum].cnt = 1;
		fnum++;
	}
	printf("%d=", tmp);
	int s = 0;
	for(int i = 0; i < fnum; i++){
		if(s){
			printf("*");
		}
		s = 1;
		printf("%d", fac[i].x);
		if(fac[i].cnt > 1){
			printf("^%d", fac[i].cnt);
		}
	}
	return 0;
}
