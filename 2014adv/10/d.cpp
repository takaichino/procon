#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int w, h , n , xy[1000][2];
	cin >> w >> h >> n;
	for( int i=0; i< n; i++){
		cin >> xy[i][0] >> xy[i][1];
	}
	int ans = 0;
	for( int j = 1; j < n; j++){
		if( (xy[j][0]-xy[j-1][0]) * (xy[j][1]-xy[j-1][1]) < 0){
			ans += abs(xy[j][0]-xy[j-1][0]);
			ans += abs(xy[j][1]-xy[j-1][1]);
		}
		else ans += max( abs(xy[j][0]-xy[j-1][0]), abs(xy[j][1]-xy[j-1][1]) );
	}
	cout << ans << endl;
	return 0;
}