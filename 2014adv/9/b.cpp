#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

bool state[1 << 16][31] ={};
int score[1 << 16][31] ={};

int main(){
	int n, c, a[31]={}, b[31]={},z,kari;
	while(cin >> n >> c, n){
		for(int g=0;g<31;g++){
			a[g]=0;
			b[g]=0;
			for(int h=0; h< 1 << 16; h++){
				state[h][g] = false;
				score[h][g] = 0;
			}
		}
		
		for(int v = 0;v<n; v++){
			for(int w=0; w<16; w++){
				cin >> z;
				a[v] = (a[v] << 1) + z;
			}
		}
		for(int x = 0;x<c; x++){
			for(int y=0; y<16; y++){
				cin >> z;
				b[x] = (b[x] << 1) + z;
			}
		}
		
		state[a[0]][0] = true;
		
		for(int i=0; i<n; i++){
			for(int j=0; j< 1 << 16; j++){
				if(state[j][i]){
					state[j|a[i+1]][i+1] = true;
					for(int k=0; k<c; k++){
						state[a[i+1]|(j & ~b[k])][i+1] = true;
						kari=0;
						for(int u=0; u<16; u++){
							if(1 << u & (j & b[k])) kari++;
						}
						score[a[i+1]|(j & ~b[k])][i+1] = max(score[a[i+1]|(j & ~b[k])][i+1], score[j][i] + kari);
					}
				}
			}
		}
		int ans = 0;
		for(int t=0; t< 1 << 16; t++){
			ans = max(ans, score[t][n]);
		}
		cout << ans << endl;
	}
	
	
	return 0;
}