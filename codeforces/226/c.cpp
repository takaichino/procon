#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int f[10000001] = {};
int cnt[1000000] = {};
int x[1000000] = {};

int main(){
	
	int n, x, m;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> x[i];
		cnt[x[i]]++;
	}
	
	int yatta = 0;
	int j = 2;
	while(yatta < n){
		if(cnt[j] > 0){
			yatta += cnt[j];
			int y = j;
			int z = 2;
			while(y > 1){
				if(y % z == 0){
					f[z] += cnt[j];
					while(y % z == 0){
						y = y / z;
					}
				}
				z++;
			}
		}
		j++;
	}
	
	for(int k = 1; k <= 10000000;k++){
		f[k] = f[k] + f[k-1];
	}
	
	cin >> m;
	int l,r;
	
	for(int v = 0; v< m; v++){
		cin >> l >> r;
		if(l > 10000000){
			l = 10000000;
		}
		if(r > 10000000){
			r = 10000000;
		}
		int ans = f[r] - f[l-1];
		cout << ans << endl;
	}
	return 0;
}