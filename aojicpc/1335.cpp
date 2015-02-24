#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int nks[21][11][156];

void br(){
	int s, t;
	for(int i=1; i<=20; i++){
		for(int j=0; j < (1<<i);j++){
			s = 0;
			t = 0;
			for(int k=0; k < i;k++){
				if(j&(1<<k)){
					s+=(k+1);
					t++;
				}
			}
			if(s<=155 && t<=10) nks[i][t][s]++;
		}
	}
}

int main(){
	int i, j, n, k, s;
	br();
	while(1){
		cin >> n >> k >> s;
		if(!n)break;
		cout << nks[n][k][s] << endl;
	}
	return 0;
}