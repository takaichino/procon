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

int bi(int v){
	int r = 0;
	REP(i,20){
		if((1 << i) & v) r++;
	}
	//cout << r << endl;
	return r;
}

int main(){
	int n, m;
	double lab[20][3];
	double ans=0, now;
	cin >> n >> m;
	REP(i,n){
		cin >> lab[i][0] >> lab[i][1] >> lab[i][2];
	}
	if(m==1){
		cout << "0" <<endl;
		return 0;
	}
	REP(i,1<<n){
		if(bi(i) != m) continue;
		now = 0;
		REP(j,n){
			for(int k=j+1;k<n;k++){
				if((i&1<<j)&&(i&1<<k)){
					now += pow((lab[j][0] - lab[k][0]),2);
					now += pow((lab[j][1] - lab[k][1]),2);
					now += pow((lab[j][2] - lab[k][2]),2);
				}
			}
		}
		if(now > ans) ans = now;
	}
	printf("%.13f\n",ans);
	return 0;
}