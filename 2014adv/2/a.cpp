#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int n, h, m, s, sum[86405], in[86405];
	char hoge[10];
	while(cin >> n ,n){
		memset(sum, 0, sizeof(sum) );
		memset(in, 0, sizeof(in) );
		
		for(int i=0; i<n; i++){
			cin >> hoge;
			h = (hoge[0]-'0') * 10 + (hoge[1]-'0');
			m = (hoge[3]-'0') * 10 + (hoge[4]-'0');
			s = (hoge[6]-'0') * 10 + (hoge[7]-'0');
			in[3600*h+60*m+s]++;
			cin >> hoge;
			h = (hoge[0]-'0') * 10 + (hoge[1]-'0');
			m = (hoge[3]-'0') * 10 + (hoge[4]-'0');
			s = (hoge[6]-'0') * 10 + (hoge[7]-'0');
			in[3600*h+60*m+s]--;
		}
		sum[0] = in[0];
		int ans = 0;
		for(int j=1; j<86400; j++){
			sum[j] = sum[j-1] + in[j];
			if(ans < sum[j] ) ans = sum[j];
		}
		
		cout << ans << endl;
	}
	
	
	return 0;
}