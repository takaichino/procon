#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int main(){
	int i, j, t;
	string in;
	int ans, sum, now, cut;
	while(1){
		cin >> t >> in;
		if(!t) break;
		ans = 1000000;
		for(i=1;i<(1<<in.size());i+=2){
			sum = 0;
			now = 0;
			REP(j,in.size()){
				if(!(i&1<<(in.size()-j-1))){
					now *= 10;
					now += in[j] - '0';
				}
				else{
					now *= 10;
					now += in[j] - '0';
					sum += now;
					now = 0;
				}
			}
			if(sum == abs(ans)) ans = -abs(sum);
			else if(sum<=t&&abs(sum-t)<=abs(abs(ans)-t)){
				ans = sum;
				cut = i;
			}
		}
		if(ans < 0) cout << "rejected" << endl;
		else if(ans == 1000000) cout << "error" << endl;
		else{
			//cout << cut << " ";
			cout << ans << " ";
			for(j=in.size()-1;j>=0;j--){
				cout << in[in.size()-j-1];
				if(j>=1&&(cut&1<<j)) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}