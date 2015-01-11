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

int ya[100001];

int main(){
	int ans=0, n, m, i, j, ins, now =0;
	ya[0] = 0;
	cin >> n >> m;
	for(i=0;i<n-1;i++){
		cin >> ins;
		ya[i+1] = ya[i] + ins;
	}
	for(j=0;j<m;j++){
		cin >> ins;
		ans += abs(ya[now+ins] - ya[now]);
		ans = ans % 100000;
		now += ins;
	}
	cout << ans << endl;
	return 0;
}