#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

char s[2][100001];
int d[2];

long long int combi(long long int n, long long int r){
	if (r < 0 || n < r) return 0;
	r = min(r, n - r);
	long long int ret = 1;
	for (int i = 1; i <= r; i++) {
		ret = ret * (n - i + 1) / i;
	}
	return ret;
}

int main(){
	cin >> s[0] >> d[0] >> s[1] >> d[1];
	int sa=0, di=0;
	for(int v = 0; s[0][v] == '1' || s[0][v] == '0'; v++){
		if(s[0][v] == s[1][v]) sa++;
		else di++;
	}
	if((d[0] + d[1] - di) % 2 != 0){
		cout << "0" << endl;
		return 0;
	}
	int c = (d[0] + d[1] - di) / 2;
	long long int ans = combi((long long int)sa, (long long int)c) % 1000000007;
	ans = (ans * combi( (long long int)di ,(long long int)(d[0] - c))) % 1000000007;
	
	cout << ans << endl;
	return 0;
}