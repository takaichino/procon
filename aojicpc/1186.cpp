#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

struct lec{
	int w, h, t;
	bool operator <(const lec& a) const{
		if(t!=a.t) return t < a.t;
		if(h!=a.h) return h < a.h;
	}
};

int main(){
	int i, j, a, b;
	vector<lec> mat;
	lec s;
	for(i=1;i<=150;i++){
		for(j=1;j<i;j++){
			s.w = i;
			s.h = j;
			s.t = i*i + j*j;
			mat.push_back(s);
		}
	}
	sort(mat.begin(), mat.begin()+mat.size());
	while(1){
		cin >> a >> b;
		if(!a) break;
		i = 0;
		while(1){
			if(mat[i].w==b && mat[i].h==a){
				cout << mat[i+1].h << " " << mat[i+1].w << endl;
				break;
			}
			i++;
		}
	}
	return 0;
}