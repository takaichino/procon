#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

vector<int> py, od;
int pol[1000000], odd[1000000];

void tri(){
	for(int i=0;i*i*i<=6000000;i++){
		py.push_back(i*(i+1)*(i+2)/6);
		if((i*(i+1)*(i+2)/6)%2==1)od.push_back(i*(i+1)*(i+2)/6);
	}
	//cout << py.size() << " " << od.size() << endl;
}

void tab_pol(){
	pol[0] = 0;
	int ans, ins;
	for(int i=1;i<1000000;i++){
		ans = i;
		for(int j=1;py[j]<=i&&j<py.size();j++){
			ins = 1 + pol[i-py[j]];
			if(ins < ans) ans = ins;
		}
		pol[i] = ans;
	}
}


void tab_odd(){
	odd[0] = 0;
	int ans, ins;
	for(int i=1;i<1000000;i++){
		ans = i;
		for(int j=1;od[j]<=i&&j<od.size();j++){
			ins = 1 + odd[i-od[j]];
			if(ins < ans) ans = ins;
		}
		odd[i] = ans;
	}
}

int main(){
	tri();
	//cout << "tri" <<endl;
	tab_pol();
	//cout << "pol" <<endl;
	tab_odd();
	int n;
	
	while(1){
		cin >> n;
		if(!n) break;
		cout << pol[n] << " " << odd[n] << endl;
	}
	return 0;
}