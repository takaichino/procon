#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

bool mew(string s){
	//cout << "0:" << s <<endl;
	int m, e, w;
	if(s == "mew") return true;
	for(int i=1;i<s.size();i+=3){
		if(s[i]=='e'){
			if(i!=1){
				m=0; e=0; w=0;
				for(int j=1;j<i;j++){
					if(s[j]=='m') m++;
					else if(s[j]=='e') e++;
					else if(s[j]=='w') w++;
				}
				if(m!=e||e!=w||w!=m) continue;
			}
			if(i!=s.size()-2){
				m=0; e=0; w=0;
				for(int j=i+1;j<s.size()-1;j++){
					if(s[j]=='m') m++;
					else if(s[j]=='e') e++;
					else if(s[j]=='w') w++;
				}
				if(m!=e||e!=w||w!=m) continue;
			}
			if(i==1)return mew(s.substr(i+1,s.size()-3));
			else if(i==s.size()-2)return mew(s.substr(1,s.size()-3));
			else return mew(s.substr(1,i-1))&&mew(s.substr(i+1,s.size()-2-i));
		}
	}
	return false;
}

int main(){
	int i, j;
	string s;
	cin >> s;
	if(mew(s)) cout << "Cat" << endl;
	else  cout << "Rabbit" << endl;
	return 0;
}