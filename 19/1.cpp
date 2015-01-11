#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int N, p[100000];
	int minst[100000];
	
	cin >> N;
	for (int i=0;i<N;i++){
		cin >> p[i];
		minst[i] = INF;
	}
	
	minst[0] = 0;
	
	for(int i = 0; i<N-1; i++){
		if(p[i] == 0){
			for(int j = 1; j<=6 && i+j < N; j++){
				if(minst[i] + 1 < minst[i+j]){
					int x = i + j;
					minst[x] = minst[i] + 1;
					while(p[x] != 0 && minst[x + p[x] ] > minst[x]){
						minst[x + p[x] ] = minst[x];
						x = x + p[x];
					}
				}
			}
		}
	}
	
	cout << minst[ N - 1] << endl;
	
	return 0;
}