#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int b[5];
int Max, Min;

void generate(int x){
	int tmp = x;
	for(int i = 3; i >= 0; i--){
		b[i] = tmp % 10;
		tmp /= 10;
	}
	sort(b, b + 4);
	int product = 1;
	Max = 0, Min = 0;
	for(int i = 0; i < 4; i++){
		Max += b[i] * product;
		Min += b[3 - i] * product;
		product *= 10;
	}
}

bool isSame(){
	return (Max == Min);
}


int main(){
	scanf("%d", &N);
	generate(N);
	if(isSame()){
		printf("%04d - %04d = %04d\n", N, N, 0);
	}else{
		do{
			N = Max - Min;
			printf("%04d - %04d = %04d\n", Max, Min, N);
			generate(N);
		}while(N != 6174); 
	}
	
	return 0;
}
