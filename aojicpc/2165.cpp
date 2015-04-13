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

int main(){
	int n, o[256], in[256], x[256], s, a, c, r, ms, ma, mc;
	double ans, ins;
	while(1){
		cin >> n;
		if(!n) break;
		ans = 999;
		REP(i,n) cin >> in[i];
		REP(s,16){
			REP(a,16){
				REP(c,16){
					REP(i,256) x[i]=0;
					r=s;
					REP(i,n){
						r = (r*a+c) % 256;
						o[i] = (in[i]+r)%256;
						x[o[i]]++;
						//cout << o[i] << " ";
					}
					//cout << endl;
					ins = 0;
					REP(i,256)if(x[i]>0)ins += -((double)x[i]/(double)n) * log2((double)x[i]/(double)n);
					//cout << "H:" << ins << endl;
					if(ans>ins){
						ms = s;
						ma = a;
						mc = c;
						ans = ins;
					}
				}
			}
		}
		cout << ms << " " << ma << " " << mc << endl;
	}
	return 0;
}