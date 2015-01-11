#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n;
	vector<int> r(500001);
	cin >> n;
	for( int k =0; k< n; k++){
		cin >> r[k];
	}
	sort(&r[0], &r[n]);
	
	int head = 0;
	int tail = n/2;
	int now;
	
	while(head != tail){
		now = (head + tail+1) / 2;
		int z = 0;
		while(z < now){
			if(r[z] * 2 > r[n - now + z]){
				break;
			}
			else z++;
		}
		if(z == now){
			head = now;
		}
		else{
			tail = now - 1;
		}
	}
	
	cout << n - head << endl;
	
	return 0;
}