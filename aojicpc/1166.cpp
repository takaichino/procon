#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

int lr[32][32], ud[32][32], d[32][32];

struct hoge{
	int x, y;
};

queue<hoge> qu;

void search(hoge a){
	//cout << a.x << " " << a.y << " " << d[a.x][a.y] << endl;
	hoge b;
	if((!(lr[a.x][a.y]&2))&&(!d[a.x][a.y-1])){
		b.x = a.x;
		b.y = a.y-1;
		d[a.x][a.y-1] = d[a.x][a.y] + 1;
		qu.push(b);
	}
	if((!(lr[a.x][a.y]&1))&&(!d[a.x][a.y+1])){
		b.x = a.x;
		b.y = a.y+1;
		d[a.x][a.y+1] = d[a.x][a.y] + 1;
		qu.push(b);
	}
	if((!(ud[a.x][a.y]&2))&&(!d[a.x-1][a.y])){
		b.x = a.x-1;
		b.y = a.y;
		d[a.x-1][a.y] = d[a.x][a.y] + 1;
		qu.push(b);
	}
	if((!(ud[a.x][a.y]&1))&&(!d[a.x+1][a.y])){
		b.x = a.x+1;
		b.y = a.y;
		d[a.x+1][a.y] = d[a.x][a.y] + 1;
		qu.push(b);
	}
	qu.pop();
	if(!qu.empty()) search(qu.front());
}

int main(){
	int i, j, w, h, ins;
	hoge s;
	while(1){
		cin >> w >> h;
		if(!w)break;
		for(i=0;i<=h+1;i++){
			for(j=0;j<=w+1;j++){
				ud[i][j] = 0;
				lr[i][j] = 0;
				d[i][j] = 0;
				if(i==0) d[i][j] = 1;
				else if(i==1) ud[i][j] = 2;
				else if(i==h) ud[i][j] = 1;
				else if(i==h+1) d[i][j] = 1;
				if(j==0) d[i][j] = 1;
				else if(j==1) lr[i][j] = 2;
				else if(j==w) lr[i][j] = 1;
				else if(i==w+1) d[i][j] = 1;
			}
		}
		
		for(i=1;i<=h-1;i++){
			for(j=1;j<=w-1;j++){
				cin >> ins;
				if(ins){
					lr[i][j]+=1;
					lr[i][j+1]+=2;
				}
			}
			for(j=1;j<=w;j++){
				cin >> ins;
				if(ins){
					ud[i][j]+=1;
					ud[i+1][j]+=2;
				}
			}
		}
		for(j=1;j<=w-1;j++){
			cin >> ins;
			if(ins){
				lr[i][j]+=1;
				lr[i][j+1]+=2;
			}
		}
		//cout << "OK" << endl;
		s.x = 1;
		s.y = 1;
		d[1][1] = 1;
		qu.push(s);
		search(s);
		cout << d[h][w] << endl;
	}
	return 0;
}