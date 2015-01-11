#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

char in[1001][1001];
char ta[1001][1001];
int q[16384][4];

int main(){
	int H, W, N, now=0,tail=1;
	cin >> H >> W >> N;
	int time = 0;
	for(int j=0; j<H; j++){
		cin >> in[j];
		for(int k=0; k<W; k++){
			if(in[j][k] == 'S'){
				q[0][0] = j;
				q[0][1] = k;
				q[0][2] = 0;//time
				q[0][3] = 0;//cheese
			}
		}
	}
	
	while(1){
		/*debug 
		cout << now << " " << q[now][0] << " " << q[now][1] << " " << q[now][2] << " " << q[now][3] << endl;
		*/
		if(time == q[now][2]){
			for(int j=0; j<H; j++){
				for(int k=0; k<W; k++){
					ta[j][k] = -1;
				}
			}
			time++;
		}
		
		if(in[ q[now][0] ][ q[now][1] ] - '1' == q[now][3]){
			q[now][3]++;
		}
		if(q[now][3] == N) break;
		if(q[now][0] > 0 && in[ q[now][0]-1 ][ q[now][1] ] != 'X'){
			if(ta[ q[now][0]-1 ][ q[now][1] ] < q[now][3]){
				ta[ q[now][0]-1 ][ q[now][1] ] = q[now][3];
				q[tail][0] = q[now][0]-1;
				q[tail][1] = q[now][1];
				q[tail][2] = q[now][2]+1;
				q[tail][3] = q[now][3];
				tail++;
				if(tail == 16384) tail=0;
			}
		}
		if(q[now][0] < H-1 && in[ q[now][0]+1 ][ q[now][1] ] != 'X'){
			if(ta[ q[now][0]+1 ][ q[now][1] ] < q[now][3]){
				ta[ q[now][0]+1 ][ q[now][1] ] = q[now][3];
				q[tail][0] = q[now][0]+1;
				q[tail][1] = q[now][1];
				q[tail][2] = q[now][2]+1;
				q[tail][3] = q[now][3];
				tail++;
				if(tail == 16384) tail=0;
			}
		}
		if(q[now][1] > 0 && in[ q[now][0] ][ q[now][1]-1 ] != 'X'){
			if(ta[ q[now][0] ][ q[now][1]-1 ] < q[now][3]){
				ta[ q[now][0] ][ q[now][1]-1 ] = q[now][3];
				q[tail][0] = q[now][0];
				q[tail][1] = q[now][1]-1;
				q[tail][2] = q[now][2]+1;
				q[tail][3] = q[now][3];
				tail++;
				if(tail == 16384) tail=0;
			}
		}
		if(q[now][1] < W-1 && in[ q[now][0] ][ q[now][1]+1 ] != 'X'){
			if(ta[ q[now][0] ][ q[now][1]+1 ] < q[now][3]){
				ta[ q[now][0] ][ q[now][1]+1 ] = q[now][3];
				q[tail][0] = q[now][0];
				q[tail][1] = q[now][1]+1;
				q[tail][2] = q[now][2]+1;
				q[tail][3] = q[now][3];
				tail++;
				if(tail == 16384) tail=0;
			}
		}
		now++;
		if(now == 16384) now =0;
	}
	cout << q[now][2] << endl;
	
	return 0;
}