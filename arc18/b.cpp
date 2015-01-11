#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, xy[100][100], ans = 0;
	cin >> n;
	for( int i = 0; i < n ; i++){
		cin >> xy[i][0] >> xy[i][1];
	}
	int j,k,l,w,h;
	for(j=0;j<n-2;j++){
		for(k=j+1;k<n-1;k++){
			for(l=k+1;l<n;l++){
				w=abs(xy[j][0]-xy[k][0]);
				if(w < abs(xy[k][0]-xy[l][0]) )w = abs(xy[k][0]-xy[l][0]);
				if(w < abs(xy[l][0]-xy[j][0]) )w = abs(xy[l][0]-xy[j][0]);
				h=abs(xy[j][1]-xy[k][1]);
				if(h < abs(xy[k][1]-xy[l][1]) )h = abs(xy[k][1]-xy[l][1]);
				if(h < abs(xy[l][1]-xy[j][1]) )h = abs(xy[l][1]-xy[j][1]);
				
				int men = 2*w*h - abs(xy[k][0]-xy[l][0])*abs(xy[k][1]-xy[l][1]) - abs(xy[j][0]-xy[k][0])*abs(xy[j][1]-xy[k][1]) - abs(xy[l][0]-xy[j][0])*abs(xy[l][1]-xy[j][1]);
				if(men%2==0&&men >0){
					ans++;
					//
					cout << j << " " << k << " " << l  << " " << endl;
					//
				}
			}
		}
	}
	cout << ans << endl;
	
	
	return 0;
}