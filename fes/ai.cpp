#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<time.h>

using namespace std;

#define INF 999999999

double ran(int a, int b){//0`n-1‚ğ•Ô‚·
	srand((unsigned int)time(NULL)+(unsigned int)b);
	return rand()%a;
}

int main(){
	cout << "READY" << endl;
	int T, P, N, A[6];
	cin >> T >> P >> N;
	for(int i=0;i<6;i++)cin >> A[i];
	
	int t, b[6][4], r[6], p[6], tb[11], ins, m=0;
	string d;
	for(int j=0;j<T;j++){
		cin >> t >> d;
		for(int x=0;x<P;x++)for(int y=0;y<N;y++)cin >> b[x][y];
		for(int z=0;z<6;z++)cin >> r[z];
		if(d[0]=='W')for(int w=0;w<6;w++)cin >> p[w];
		
		if(t==1 || t==6){
			for(int r1=0;r1<6;r1++)tb[r1] = r1;
			ins = ran(6, m);
			for(int r2=6;r2<7;r2++)tb[r2] = ins;
			while(ins == tb[6]){
				m++;
				ins = ran(6, m);
			}
			for(int r3=7;r3<8;r3++)tb[r3] = ins;
		}
		else if(t==3 || t==8){
			while(ins == tb[6]){
				m++;
				ins = ran(6,m);
			}
			for(int r4=7;r4<8;r4++)tb[r4] = ins;
		}
		
		if(d[0]=='W'){
			for(int ow=0;ow<5;ow++){
				ins = ran(8,ow);
				if(ow>0) cout << " ";
				cout << tb[ins];
			}
			cout << endl;
		}
		
		if(d[0]=='H'){
			for(int oh=0;oh<2;oh++){
				ins = ran(8,oh);
				if(oh>0) cout << " ";
				cout << tb[ins];
			}
			cout << endl;
		}
	}
	
	return 0;
}