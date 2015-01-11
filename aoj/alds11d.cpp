#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int in[200001], ma[200001], mi[200001];

int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> in[i];
	mi[0] = in[0];
	for(int j=1; j<n; j++) mi[j] = min(mi[j-1], in[j]);
	ma[n-1] = in[n-1];
	for(int k=n-2; k>=0; k--) ma[k] = max(ma[k+1], in[k]);
	int ans=-1000000000;
	for(int x=1; x<n;x++) if(ans < ma[x] - mi[x-1]) ans = ma[x] - mi[x-1];
	cout << ans << endl;
	
	return 0;
}