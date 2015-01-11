#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int keta(long long int n){
	if ((n / 10) == 0){
		return 1;
	}
	else return keta(n/10) + 1;
}

int main(){
	long long int w, m;
	int k;
	cin >> w >> m >> k;
	long long int ans = 0;
	w = w / (long long int)k;
	int s = keta(m);
	long long int p = pow(10,s);
	while( w - (p - m) * (long long int)s >= 0){
		ans += (p - m);
		w -= (p - m) * (long long int) s;
		m = p;
		s++;
	}
	ans += w / (long long int)s;
	cout << ans << endl;
	return 0;
}