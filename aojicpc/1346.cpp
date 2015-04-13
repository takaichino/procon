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

int main(){
	int m, l, a, mins, lins, sta;
	string eq;
	cin >> eq;
	eq += "+";
	cin >> a;
	sta = 0;
	m = 0;
	l = 0;
	for(int i=0;i<eq.size();i++){
		if(i%2==0){
			if(!sta){
				m += eq[i]-'0';
				lins = eq[i]-'0';
			}
			else{
				m = m * (eq[i]-'0');
				lins *= eq[i]-'0';
			}
		}
		else{
			if(eq[i]=='+'){
				sta = 0;
				l += lins;
			}
			else {
				sta = 1;
			}
		}
		//cout << m << " " << l << endl;
	}
	if(a==l&&a==m)cout << "U" << endl;
	else if(a==l)cout << "M" << endl;
	else if(a==m)cout << "L" << endl;
	else cout << "I" << endl;
	return 0;
}