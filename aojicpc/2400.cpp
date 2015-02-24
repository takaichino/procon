#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

struct team{
	int id, ac, pe;
	
	bool operator<(const team& a) const{
		if(ac != a.ac) return ac > a.ac;
		if(pe != a.pe) return pe < a.pe;
		if(id != a.id) return id < a.id;
	}
};

int main(){
	int i, j, t, p, r, tid, pid, time, wa[51][11];
	string ma;
	vector<team> set(51);
	while(1){
		cin >> t >> p >> r;
		if(!t) break;
		for(i=0;i<=t;i++){
			set[i].id = i;
			set[i].pe = 0;
			set[i].ac = 0;
			for(j=0;j<=p;j++) wa[i][j] = 0;
		}
		for(i=0;i<r;i++){
			cin >> tid >> pid >> time >> ma;
			if(ma == "WRONG") wa[tid][pid]++;
			else{
				set[tid].ac++;
				set[tid].pe += wa[tid][pid]*1200 + time;
			}
		}
		sort(set.begin()+1, set.begin()+t+1);
		for(i=1;i<=t;i++){
			cout << set[i].id << " " << set[i].ac << " " << set[i].pe << endl;
		}
	}
	return 0;
}