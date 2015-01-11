#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int n, w, h, t, s, x,y, ans, map[101][101], sum[100][100], i, j, per;
	while(1){
		cin >> n;
		if(!n) break;
		cin >> w >> h;
		for(i=0; i<=w; i++){
			for(j=0; j<=h; j++){
				map[i][j] = 0;
				sum[i][j] = 0;
			}
		}
		for(i=0; i<n; i++){
			cin >> x >> y;
			map[x][y]++;
		}
		/*for(j=0; j<=h; j++){
			for(i=0; i<=w; i++){
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		for(i=0; i<=w; i++){
			for(j=0; j<=h; j++){
				sum[i][j] = map[i][j];
				if(i>0)sum[i][j]+=sum[i-1][j];
				if(j>0)sum[i][j]+=sum[i][j-1];
				if(i>0 && j>0)sum[i][j]-=sum[i-1][j-1];
			}
		}
		/*for(j=0; j<=h; j++){
			for(i=0; i<=w; i++){
				cout << sum[i][j] << " ";
			}
			cout << endl;
		}*/
		cin >> s >> t;
		ans = -1;
		for(j=1; j+t-1<=h; j++){
			for(i=1; i+s-1<=w; i++){
				per=sum[i+s-1][j+t-1]-sum[i-1][j+t-1]-sum[i+s-1][j-1]+sum[i-1][j-1];
				//cout << i << " " << j << " " << sum[i+s-1][j+t-1] << "-" << sum[i+s-1][j-1] << "-" << sum[i-1][j+t-1] << "+" << sum[i-1][j-1] << "=" << per << endl;
				if(per > ans)ans = per;
			}
		}
		cout << ans << endl;
	}
	return 0;
}