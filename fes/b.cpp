#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	string in;
	int ans = 0;
	cin >> in;
	for(int i=0;i<(int)in.size(); i++){
		if(i % 2 != 0) ans -= in[i] - '0';
		else ans += in[i] - '0';
	}
	cout << ans << endl;
	return 0;
}