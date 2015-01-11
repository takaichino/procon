#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int n, m;
	cin >> n >> m;
	if(min(n,m) % 2 == 1) cout << "Akshat" <<endl;
	else cout << "Malvika" <<endl;
	return 0;
}