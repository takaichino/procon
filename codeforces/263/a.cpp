#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int n;
	char in[100][100];
	cin >> n;
	for(int i = 0;i<n;i++){
			cin >> in[i];
	}
	int cnt;
	for(int a= 0;a<n;a++){
		for(int b= 0;b<n;b++){
			cnt = 0;
			if(a>0 && in[a-1][b] == 'o') cnt++;
			if(a<n-1 && in[a+1][b] == 'o') cnt++;
			if(b>0 && in[a][b-1] == 'o') cnt++;
			if(b<n-1 && in[a][b+1] == 'o') cnt++;
			if(cnt % 2 == 1){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}