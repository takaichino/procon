#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int combi(int n, int r){
	
}

int main(){
	int r, c, x, y, d, l, ans;
	cin >> r >> c >> x >> y >> d >> l;
	ans = combi(x * y, d) * combi(x * y - d, l) * (r - x + 1) * (c - y + 1);
	ans = ans % 1000000007;
	cout << ans << endl;
	return 0;
}