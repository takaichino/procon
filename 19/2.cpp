#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, k, t, u, v, l, d[200], cal[10000], have=0, run=0;
	double ans = 0;
	cin >> n >> k >> t >> u >> v >> l;
	for(int i=0; i<l; i++){
		cal[i] = 0;
	}
	for(int i=0; i<n; i++){
		cin >> d[i];
		cal[ d[i]-1 ] = 1;
	}
	
	int running = 0, walking =0;
	
	for(int i=0; i<l; i++){
		if(have > 0 && run == 0){
			running++;
			have--;
			run = v * t - 1;
		}
		else if(run > 0){
			running++;
			run--;
		}
		else{
			walking++;
		}
		
		if(cal[i] == 1 && have < k){
			have++;
		}
		else if(cal[i] == 1 && have == k){
			run = v * t;
		}
	}
	
	ans = (double)running / (double)v + (double)walking / (double)u;
	
	printf("%.7f\n", ans);
	
	return 0;
}