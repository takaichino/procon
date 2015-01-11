#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	float b,h,ans;
	cin >> h >> b;
	h = h / 100.0;
	ans = b * h * h;
	cout << ans << endl;
	
	return 0;
}