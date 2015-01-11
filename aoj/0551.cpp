#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

int in[100002];

int main(){
	long long int ans=0, ins=0;
	int N, L, i, j;
	cin >> N >> L;
	in[0] = 0;
	for(i=1;i<=N;i++)cin >> in[i];
	in[N+1] = 0;
	for(i=1;i<=N;i++){
		if(in[i-1] < in[i]) ins = L - in[i];
		else ins += L - in[i];
		if(ins > ans) ans = ins;
	}
	for(i=N;i>=1;i--){
		if(in[i] > in[i+1]) ins = L - in[i];
		else ins += L - in[i];
		if(ins > ans) ans = ins;
	}
	
	cout << ans << endl;
	return 0;
}