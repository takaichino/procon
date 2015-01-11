#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int ans;
	string s;	 //a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
	int key[26] = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,2,1,1,1,2,1};
	while(1){
		cin >> s;
		if(s[0] == '#')break;
		int now = 0;
		ans = -1;
		for(int i =0; i < s.size();i++){
			if(key[(s[i]-'a')] != now){
				ans++;
				now = key[(s[i]-'a')];
			}
		}
		cout << ans << endl;
	}
	return 0;
}