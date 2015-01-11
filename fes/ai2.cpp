#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<time.h>

using namespace std;

#define INF 999999999

double ran(int a, int b){//0 to n-1
	srand((unsigned int)time(NULL)+(unsigned int)b);
	return rand()%a;
}

int main(){
	cout << "READY" << endl;
	int T, P, N, A[6], f[6];
	cin >> T >> P >> N;
	for(int i=0;i<6;i++)cin >> A[i];
	
	int ac = 0;
	for(int aa=6;aa>=3;aa--){
		for(int ab=0;ab<6;ab++){
			if(A[ab] == aa){
				f[ac] = ab;
				ac++;
			}
		}
	}
	
	int t, b[6][4][9], r[6], p[6], db[6][9], to[6][9], ra[6], ma[6], mi[6], risk, yoku;
	double po[6], now[2];
	string d;
	for(int j=0;j<T;j++){
		cin >> t >> d;
		for(int x=0;x<P;x++)for(int y=0;y<N;y++)cin >> b[x][y][t];
		for(int z=0;z<6;z++)cin >> r[z];
		if(d[0]=='W')for(int w=0;w<6;w++)cin >> p[w];
		
		if(d[0]=='H'){
			for(int ba=0;ba<6;ba++){
				db[ba][t] = 0;
				to[ba][t] = 0;
				ra[ba] = 1;
				ma[ba] = b[ba][0][t];
				mi[ba] = b[ba][0][t];
				for(int bb=0;bb<4;bb++){
					if(b[ba][bb][t] < b[ba][ db[ba][t] ][t])db[ba][t] = bb;
					if(b[ba][bb][t] > b[ba][ to[ba][t] ][t])to[ba][t] = bb;
					if(b[ba][0][t] < b[ba][bb][t])ra[ba]++;
					if(ma[ba] < b[ba][bb][t])ma[ba]=b[ba][bb][t];
					if(mi[ba] > b[ba][bb][t])mi[ba]=b[ba][bb][t];
				}
			}
		}
		if(d[0]=='H' && t>3){
			for(int ca=0;ca<6;ca++){
				risk += (db[ca][t] - db[ca][t-2]) * A[ca];
				yoku += (to[ca][t] - to[ca][t-2]) * A[ca];
			}
		}
		
		
		
		if(t==1){
			for(int xa=0;xa<5;xa++){
				if(xa>0)cout<< " ";
				cout << f[xa];
			}
			cout << endl;
		}
		else if(t==2) cout<< f[0] << " " << f[5] << endl;
		else if(t > 2 && d[0]=='W'){
			for(int ow=0;ow<5;ow++){
				for(int da=0;da<6;da++){
					if(ra[da] == 3) po[da] = 1.5 * (double)yoku * (double)A[da] / abs(((double)ma[da]+(double)mi[da])/2 - (double)r[da]);
					else if(ra[da] ==4)po[da] = 2.0 * (double)yoku *(double) A[da] / abs(((double)ma[da]+(double)mi[da])/2 - (double)r[da]);
					else if(ra[da] ==2)po[da] = (double)risk * (double) A[da] / abs((double)r[da] - ((double)ma[da]+(double)mi[da])/2);
					else if(ra[da] ==1)po[da] = (double)risk * (double) A[da] / abs((double)r[da] - ((double)ma[da]+(double)mi[da])/2);
				}
				now[0] = (int)f[0];
				now[1] = po[ f[0] ];
				for(int db=0;db<6;db++){
					if(now[1] < (int)po[ f[db] ]){
						now[0] = f[db];
					}
				}
				if(ow>0) cout << " ";
				cout << now[0];
				if(ra[(int)now[0]] % 2 == 1)r[(int)now[0]]-=1;
				else r[(int)now[0]]+=1;
			}
			cout << endl;
		}
		else if(t>2 && d[0]=='H'){
			for(int oh=0;oh<2;oh++){
				for(int dc=0;dc<6;dc++){
					if(ra[dc] == 3) po[dc] = 1.5 * (double)yoku * (double)A[dc] / abs(((double)ma[dc]+(double)mi[dc])/2 - (double)r[dc]);
					else if(ra[dc] ==4)po[dc] = 2.0 * (double)yoku *(double) A[dc] / abs(((double)ma[dc]+(double)mi[dc])/2 - (double)r[dc]);
					else if(ra[dc] ==2)po[dc] = (double)risk * (double) A[dc] / abs((double)r[dc] - ((double)ma[dc]+(double)mi[dc])/2);
					else if(ra[dc] ==1)po[dc] = (double)risk * (double) A[dc] / abs((double)r[dc] - ((double)ma[dc]+(double)mi[dc])/2);
				}
				now[0] = (int)f[0];
				now[1] = po[ f[0] ];
				for(int dd=0;dd<6;dd++){
					if(now[1] < po[ f[dd] ]){
						now[0] = (int)f[dd];
					}
				}
				if(oh>0) cout << " ";
				cout << now[0];
				if(ra[(int)now[0]] % 2 == 1)r[(int)now[0]]-=2;
				else r[(int)now[0]]+=2;
			}
			cout << endl;
		}
	}
		
	
	return 0;
}