#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n=1,st[30]={},ans=0;
	st[0]=1;
	st[1]=2;
	st[2]=4;
	cin >> n;
	while(n>0){
		for(int j=3;j<n;j++){
			st[j] = st[j-1] + st[j-2] + st[j-3];
		}
		if(st[n-1]%3650==0)ans = st[n-1] / 3650;
		else ans = (st[n-1] / 3650) + 1;
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}