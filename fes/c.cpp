#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

long long int f[10001];

int main(){
	long long int in;
	cin >> in;
	char c[6];
	
	for(int i = 0; i <= 10000;i++){
		f[i]=0;
		if(i>=10){
			sprintf(c, "%d", i);
			for(int j=0; c[j]!='\0'; j++){
				f[i] = f[i] * (long long int)i;
				f[i] += (c[j] - '0');
			}
		}
	}
	
	int head = 0,tail = 10000,now;
	while(head != tail){
		now = (head + tail)/2;
		//cout << x << "-L:" << head << " " << tail << " " << now << " " << r.query(now,x) << endl;//
		if(in <= f[now])tail=now;
		else head=now+1;
	}
	if(f[head] == in) cout << head << endl;
	else cout << -1 << endl;
	return 0;
}