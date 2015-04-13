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

int str_int(string v){
	int a=0;
	REP(i, v.size()){
		if(v[0]=='-'){
			if(!i)continue;
			else a = a*10 - (v[i]-'0');
		}
		else a = a*10 + (v[i]-'0');
	}
	return a;
}

int main(){
	int n, a, b, fx;
	string ins, sta;
	int ans, head, tail;
	while(1){
		cin >> n;
		if(!n) break;
		head = 2000000000;
		tail = -2000000000;
		b = 2000000001;
		fx = 0;
		sta = "ambiguous";
		REP(i,n){
			cin >> ins;
			if(!fx){
				if(ins[0] == 'x'){
					fx = 1;
					if(i%2==0){
						if(b-1<head)head = b-1;
						b = head;
					}
					else if(i%2==1){
						if(b+1>tail) tail = b+1;
						b = tail;
					}
				}
				else{
					fx=0;
					a = str_int(ins);
					if(i%2==0&&a>=b) sta = "none";
					if(i%2==1&&a<=b) sta = "none";
					b = a;
				}
			}
			else{
				if(ins[0] == 'x'){
					fx=1;
					sta = "none";
				}
				else{
					fx=0;
					a = str_int(ins);
					if(i%2==0&&a>=tail) tail = a+1;
					if(i%2==1&&a<=head) head = a-1;
					b = a;
				}
			}
			//cout << head << "~" << tail  << ":" << sta << endl;
		}
		//cout << head << " " << tail << " ";
		if(sta == "none") cout << sta << endl;
		else{
			if(head == tail) cout << head << endl;
			else if(head < tail) cout << "none" << endl;
			else cout << sta << endl;
		}
	}
	return 0;
}