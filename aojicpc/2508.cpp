#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int char_int(char c){
	if(c >= 'a' && c <= 'z') return c - 'a';
	if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
}

char int_char(int i){
	if(i < 0) i += 52;
	if(i > 51) i -= 52;
	if(i >= 0 && i <= 25) return i + 'a';
	if(i >= 26 && i <= 51) return i + 'A' - 26;
}

int main(){
	int i, j, n, k[100];
	string s;
	while(1){
		cin >> n;
		if(!n)break;
		for(i=0;i<n;i++) cin >> k[i];
		for(i=n;i<100;i++) k[i] = k[i-n];
		cin >> s;
		for(i=0;i<s.size();i++){
			cout << int_char(char_int(s[i]) - k[i]);
		}
		cout << endl;
	}
	
	return 0;
}