#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

int main(){
	int i, j, n;
	int ans;
	cin >> n;
	while(n > 1){
		ans ++;
		if(n%3==0)n = n/3;
		else n = n/3 + 1;
	}
	
	cout << ans << endl;
	return 0;
}