#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int i, j, c, k[4], s, t, u, v, ans[4], mai=0;
	while(1){
		cin >> c;
		if(!c) break;
		if(mai)cout << "\n";
		mai = 10000;
		for(i=0;i<4;i++) cin >> k[i];
		for(s=0;s<=k[0];s++){
			for(t=0;t<=k[1];t++){
				for(u=0;u<=k[2];u++){
					for(v=0;v<=k[3];v++){
						int ch = (s*10+t*50+u*100+v*500) - c;
						if(ch < 0)continue;
						else{
							if((!((ch/500)&&v)) && (!(((ch/100)%5)&&u)) && (!(((ch/50)%2)&&t)) && (!(((ch/10)%5)&&s))){
								//cout << s << " " << t << " " << u << " " << v << " " << ch/500 << " " << (ch/100)%5 << " " << (ch/50)%2 << " " << (ch/10)%5 << "\n";
								int now = 1;
								now += ch/500 + (ch/100)%5 + (ch/50)%2 + (ch/10)%5;
								now += (k[0] - s) + (k[1] - t) + (k[2] - u) + (k[3] - v);
								if(now < mai){
									mai = now;
									ans[0] = s;
									ans[1] = t;
									ans[2] = u;
									ans[3] = v;
								}
							}
						}
					}
				}
			}
		}
		if(ans[0])cout << 10 << " " << ans[0] << "\n";
		if(ans[1])cout << 50 << " " << ans[1] << "\n";
		if(ans[2])cout << 100 << " " << ans[2] << "\n";
		if(ans[3])cout << 500 << " " << ans[3] << "\n";
	}
	return 0;
}