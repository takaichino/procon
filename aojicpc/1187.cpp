#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int wa[51][11];

struct team{
	int ac, pe, id;
	bool operator<(const team& a) const{
		if(ac != a.ac) return ac > a.ac;
		if(pe != a.pe) return pe < a.pe;
		if(id != a.id) return id > a.id;
	}
};

int main(){
	int i, j, M, T, P, R, m, t, p, ju;
	vector<team> set(51);
	while(1){
		cin >> M >> T >> P >> R;
		if(!M)break;
		for(i=0;i<=T;i++){
			set[i].ac = 0;
			set[i].pe = 0;
			set[i].id = i;
			for(j=1;j<=P;j++){
				wa[i][j] = 0;
			}
		}
		for(i=0;i<R;i++){
			cin >> m >> t >> p >> ju;
			if(!ju){
				set[t].ac++;
				set[t].pe += wa[t][p] * 20 + m;
			}
			else wa[t][p]++;
		}
		sort(set.begin()+1, set.begin()+1+T);
		for(i=1;i<=T;i++){
			if(i>1){
				if(set[i-1].ac==set[i].ac && set[i-1].pe==set[i].pe){
					cout << "=";
				}
				else cout << ",";
			}
			cout << set[i].id;
		}
		cout << endl;
	}
	return 0;
}