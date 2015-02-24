#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int frac[2];

void dir(string s){
	//cout << s << endl;
	if(s == "north"){
		frac[0] = 0;
		frac[1] = 1;
	}
	else if(s == "west"){
		frac[0] = 90;
		frac[1] = 1;
	}
	else if(s[0] == 'n'){
		dir(s.substr(5));
		frac[0] = frac[0] * 2 - 90;
		frac[1] = frac[1] * 2;
	}
	else if(s[0] == 'w'){
		dir(s.substr(4));
		frac[0] = frac[0] * 2 + 90;
		frac[1] = frac[1] * 2;
	}
}

int main(){
	int i, j;
	string s;
	while(1){
		cin >> s;
		if(s=="#") break;
		dir(s);
		while(!(frac[0]%2)&&!(frac[1]%2)){
			frac[0] /= 2;
			frac[1] /= 2;
		}
		if(frac[1] == 1)cout << frac[0] << endl;
		else cout << frac[0] << "/" << frac[1] << endl;
	}
	return 0;
}