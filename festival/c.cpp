#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

vector <string> s(3);

int main(){
	int part[3][26], cap[2]={0,0},flag = 1;
	cin >> s[0] >> s[1] >> s[2];
	
	for(int i=0;i<3;i++){
		for(int j=0; j<26;j++){
			part[i][j] =0;
		}
	}
	for(int k=0;k<3;k++){
		for(int m=0; m<(int)s[k].size();m++){
			part[k][ s[k][m]-'A' ]++;
		}
	}
	
	for(int n=0;n<26;n++){
		if(part[2][n] > (part[1][n] + part[0][n]) ){
			flag = 0;
			// cout << n << " ";
		}
		cap[0] += min(part[0][n], part[2][n]);
		cap[1] += min(part[1][n], part[2][n]);
	}
	if(cap[0] < (int)s[2].size()/2 || cap[1] < (int)s[2].size()/2){
		flag =0;
	}
	/*
	cout << s[0].size() << endl;
	for(int y=0;y<3;y++){
		for(int z=0; z<26;z++){
			cout << part[y][z] << " ";
		}
		cout << endl;
	}
	*/
	if(flag==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}