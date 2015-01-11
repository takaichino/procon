#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

vector< vector<int> > in( 10 );

int main(){
	long long int ans=0;
	int N, K, C, G, i, j;
	cin >> N >> K;
	for(i=0;i<N;i++){
		cin >> C >> G;
		in[G-1].push_back(C);
	}
	for(j=0;j<10;j++){
		sort(in[j].begin(),in[j].end(),greater<int>());
	}
	for(j=0;j<10;j++){
		for(i=0;i<(int)in[j].size();i++){
			in[j][i] += 2*i;
			ans += in[j][i];
		}
	}
	for(i=0;i<N-K;i++){
		int ins = INF;
		int no = -1;
		for(j=0;j<10;j++){
			if(in[j].size()>0 && in[j][in[j].size()-1] < ins){
				no = j;
				ins = in[j][in[j].size()-1];
			}
			else if(in[j].size()>1 && in[j][in[j].size()-1] == ins && in[j][in[j].size()-2] < in[j][in[j].size()-1]){
				no = j;
				ins = in[j][in[j].size()-1];
			}
		}
		ans -= ins;
		in[no].pop_back();
	}
	
	cout << ans << endl;
	return 0;
}