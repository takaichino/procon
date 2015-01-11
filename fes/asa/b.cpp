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

struct like{int min; int max;};
vector <like> G;
vector <int> pilo;

bool ask(const like& x, const like& y) { return x.max < y.max;}

int main(){
	int ans=0, n, m, i,a,b;
	cin >> n >> m;
	for(i=0; i<n;i++){
		cin >> a >> b;
		like c = {a, b};
		G.push_back(c);
	}
	for(i=0; i<m;i++){
		cin >> a;
		pilo.push_back(a);
	}
	
	sort(G.begin(),G.end(),ask);
	sort(pilo.begin(),pilo.end());
	
	int g=0,h=0;
	while(g < n && h < m){
		//cout << g << " " << h << endl;
		if(G[g].min <= pilo[h] && G[g].max >= pilo[h]){
			ans++;
			g++;
			h++;
		}
		else if(G[g].min > pilo[h]){
			h++;
		}
		else if(G[g].min < pilo[h]){
			g++;
		}
	}
	
	cout << ans << endl;
	return 0;
}