#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 9999999

int ans(int x, int y, int z){
	if(y < 0) return 0;
	if(x==1){
		if(y>=0 && y <= 9 && (z & (int)pow(2,y)) == 0 ) return 1;
		else return 0;
	}
	else 
	{
		int poyo=0;
		for(int p = 0;p<=9;p++){
			if( (z & (int)pow(2,p)) == 0){
				poyo += ans(x-1, y - x * p, z + (int)pow(2,p));
			}
		}
		return poyo;
	}
}

int main(){
	int n,s;
	
	while(1){
		cin >> n >> s;
		if ( cin.eof() ) break;
		cout << ans(n,s,0) << endl;
	}
	return 0;
}