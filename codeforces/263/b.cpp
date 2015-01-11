#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

char in[100000];

int main(){
	long long int n, k, cnt[26]={};
	cin >> n >> k;
	cin >> in;
	
	for(int i =0;i<n;i++){
		cnt[ in[i]-'A' ]++;
	}
	/*
	for(int v=0;v<26;v++){
		cout << cnt[v] << " ";
	}
	*/
	long long int rest = k;
	long long int ans = 0;
	sort( &cnt[0], &cnt[0]+26);
	for(int j =25; j>=0; j--){
		if(rest >= cnt[j]){
			ans += cnt[j] * cnt[j];
			rest -= cnt[j];
		}
		else if(rest < cnt[j]){
			ans += rest * rest;
			rest -= rest;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}