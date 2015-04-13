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

int main(){
	int i, j;
	long long int p, t, q, l, r;
	char c;
	//??? ans;
	cin >> q;
	r = 0;
	l = 0;
	REP(i,q){
		cin >> p >> c >> t;
		if(c=='(') l+=t;
		else r+=t;
		if(l==r)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}