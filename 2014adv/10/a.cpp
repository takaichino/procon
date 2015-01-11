#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int fi[200][2];
int st[1000][2];
long long int x[1000];

int main(){
	int m, n;
	while(cin >> m, m){
		for(int i=0; i<m; i++){
			cin >> fi[i][0] >> fi[i][1];
		}
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> st[j][0] >> st[j][1];
			x[j] = st[j][0] * 1000 + j;
		}
		sort(&x[0], &x[0]+n);
		
		int ans[2];
		for(int a=0; a<n; a++){
			int found = 0;
			ans[0] = st[a][0] - fi[0][0];
			ans[1] = st[a][1] - fi[0][1];
			for(int b=1; b<m; b++){
				int head = 0;
				int tail = n;
				int flag = 0;
				while(head != tail){
					int ch = (head + tail) / 2;
					if(x[ch]/1000 == fi[b][0] + ans[0]){
						head = ch;
						tail = ch;
						while(head > 0 && x[head] / 1000  == x[head-1]/1000){
							head--;
						}
						while(tail < n-1 && x[tail] / 1000  == x[tail+1]/1000){
							tail++;
						}
						flag = tail - head + 1;
						break;
					}
					else if(x[ch]/1000 > fi[b][0] + ans[0]){
						tail = ch;
					}
					else if(x[ch]/1000 < fi[b][0] + ans[0]){
						head = ch + 1;
					}
				}
				for(int c = 0; c<flag; c++){
					int num = x[head + c] % 1000;
					if(st[num][1] == fi[b][1] + ans[1]){
						found++;
						break;
					}
				}
				if(found < b) break;
			}
			if(found == m-1){
				cout << ans[0] << " " << ans[1] << endl;
			}
		}
	}
	
	return 0;
}