#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int pr[200];

int main(){
	long long int C, N, M;
	cin >> C;
	for(int i = 0; i < C; i++){
		cin >> N >> M;
		if(N * M % 8 == 0 && N * M >= 16 && min(N,M) >= 2){
			cout << "Possible" << endl;
		}
		else{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}