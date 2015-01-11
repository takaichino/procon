#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 9999999

int bf[108][64];

int main(){
	int m, n, d, cak[6], run;
	string pla[2];
	int a[256][3]; //[place][place][dis]
	
	while(cin >> m >> n >> run >> d, d){
		for(int u= 0;u<m;u++){
			cin >> cak[u];
		}
		for(int x1=0;x1<2+m+n;x1++){
			for(int x2=0;x2<pow(2,m);x2++){
				bf[x1][x2] = INF;
			}
		}
		bf[0][0]=0;
		
		for(int j=0; j<d;j++){
			cin >> pla[0] >> pla[1] >> a[j][2];
			for(int y= 0; y<2; y++){
				if(pla[y][0] == 'H') a[j][y] = 0;
				if(pla[y][0] == 'D') a[j][y] = 1;
				if(pla[y][0] == 'C') a[j][y] = (p[y][1] - '0') + 1;
				if(pla[y][0] == 'L'){
					a[j][y]=0;
					for(int z=0;z<(int)pla[y].size()-1;z++){
						a[j][y] = a[j][y]*10;
						a[j][y] += (pla[y][ pla[y].size() - 1 - z] -'0');
					}
					a[j][y] += 1 + m;
				}
			}
		}
		
		for(int r=0;r<pow(2,m);r++){
			for(int p=0;p<2+m+n;p++){
				for(int q=0;q<d;q++){
					for(int s =0;s<2;s++){
						int bit = pow(2, a[q][s]-2);
						if(a[q][s] >= 2 && a[q][s] < 2+m && (bit & r)== 0){
							bf[ a[q][s] ][r + bit] = bf[ a[q][s] ][r] - cak[a[q][s]-2];
						}
						else bf[ a[q][1-s] ][r] = min(bf[ a[q][1-s] ][r], bf[ a[q][s] ][r] + a[q][2] * run);
					}
				}
			}
		}
		int ans=INF;
		/*debug
		for(int xy=0; xy < pow(2,m); xy++){
			for(int xx=0; xx < 2+m+n; xx++){
				cout << bf[xx][xy] << " ";
			}
			cout << endl;
		}
		*/
		
		for(int t = 0; t<pow(2, m);t++){
			if(ans > bf[1][t]) ans = bf[1][t];
		}
		cout << ans << endl;
	}
	return 0;
}