#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, m;
	int hito[101] = {};
	int a, b, c;
	int answer = 0;
	
	cin >> n >> m;
	
	for(int i = 0; i<m; i++){
		cin >> a >> b >> c;
		hito[a] -= c;
		hito[b] += c;
	}
	for(int j = 1; j<=n; j++){
		if(hito[j] > 0){
			answer += hito[j];
		}
	}
	cout << answer << endl;
		
	return 0;
}