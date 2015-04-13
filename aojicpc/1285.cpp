#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int main(){
	int i, j, n, w, b[100], hi;
	double ans;
	
	while(1){
		cin >> n >> w;
		if(!n) break;
		REP(i,100)b[i]=0;
		hi = 0;
		REP(i,n){
			int ins;
			cin >> ins;
			b[ins/w]++;
			if(hi < b[ins/w])hi = b[ins/w];
		}
		int d=0;
		REP(i,100) if(b[i]) d = i;
		ans = 0.01;
		REP(i,d){
			ans += (1-(double)i/(double)d)*((double)b[i]/(double)hi);
		}
		printf("%.13f\n",ans);
	}
	return 0;
}