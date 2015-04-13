#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

vector<pair<int, int> > pita[20000];
vector<int> yaku[20000];

void prep(){
	for(int i=1;i<20000;i++){
		for(int j=2;j*j<=i;j++){
			if(i%j==0)yaku[i].push_back(j);
		}
	}
	for(int k=0;k*k<20000;k++){
		for(int l=k;l*l+k*k<20000;l++){
			pair<int, int> m;
			m.first = k;
			m.second = l;
			pita[l*l+k*k].push_back(m);
		}
	}
}

int main(){
	int i, j, a, p, q;
	prep();
	cin >> a;
	REP(i,a){
		string ans = "P";
		cin >> p >> q;
		REP(j,yaku[p*p+q*q].size()){
			REP(k,pita[yaku[p*p+q*q][j]].size()){
				int m = pita[yaku[p*p+q*q][j]][k].first;
				int n = pita[yaku[p*p+q*q][j]][k].second;
				if((m*p+n*q)%(m*m+n*n)==0 && (abs(m*q-n*p))%(m*m+n*n)==0) ans = "C";
				if((n*p+m*q)%(m*m+n*n)==0 && (abs(n*q-m*p))%(m*m+n*n)==0) ans = "C";
			}
		}
		cout << ans << endl;
	}
	return 0;
}