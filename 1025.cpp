#include <stdio.h>
#include <algorithm>
using namespace std;

struct testee{
	long long reg_num;	// 考号 
	int grade;	//成绩 
	int loc_num;	// 考场号 
	int lrank;	// 考场排名 
	int trank;	// 总排名 
}a[30005];

bool cmp(testee a, testee b){
	if(a.grade == b.grade)
		return a.reg_num < b.reg_num;
	else
		return a.grade > b.grade;
}

int main(){
	int N, K;
	scanf("%d", &N);
//	printf("N = %d\n", N);
	int num = 0;
	for(int i = 1; i <= N; i++){
		int s = num;
		scanf("%d", &K);
//		printf("K = %d\n", K);
		for(int j = 1; j <= K; j++){
			scanf("%lld%d", &a[num].reg_num, &a[num].grade);
			a[num].loc_num = i;
			num++;
		}
		sort(&a[s], &a[num], cmp);
		a[s].lrank = 1;
		for(int j = 2; j <= K; j++){
			if(a[s+j-1].grade == a[s+j-2].grade){
				a[s+j-1].lrank = a[s+j-2].lrank;
			}
			else{
				a[s+j-1].lrank = j;
			}
		}
	}
	sort(&a[0], &a[num], cmp);
	a[0].trank = 1;
	for(int j = 2; j <= num; j++){
		if(a[j-1].grade == a[j-2].grade){
			a[j-1].trank = a[j-2].trank;
		}
		else{
			a[j-1].trank = j;
		}
	}
	printf("%d\n", num);
	for(int i = 0; i < num; i++){
		printf("%013lld %d %d %d\n", a[i].reg_num, a[i].trank, a[i].loc_num, a[i].lrank);
	}
	return 0;
}
