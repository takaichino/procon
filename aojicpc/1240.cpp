#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

string mej(string v){
	return v.substr(v.size()-1) + v.substr(0,v.size()-1);
}
string mec(string v){
	return v.substr(1) + v.substr(0,1);
}
string mee(string v){
	for(int i=0;i<v.size()/2;i++){
		swap(v[i], v[i + (v.size()+1)/2]);
	}
	return v;
}
string mea(string v){
	for(int i=0;i<v.size()/2;i++){
		swap(v[i], v[v.size()-1-i]);
	}
	return v;
}
string mep(string v){
	for(int i=0;i<v.size();i++){
		if(v[i] >= '1' && v[i] <= '9') v[i] -= 1;
		else if(v[i] == '0') v[i] = '9';
	}
	return v;
}
string mem(string v){
	for(int i=0;i<v.size();i++){
		if(v[i] >= '0' && v[i] <= '8') v[i] += 1;
		else if(v[i] == '9') v[i] = '0';
	}
	return v;
}

int main(){
	int i, j, n;
	string s, o;
	
	cin >> n;
	for(i=0;i<n;i++){
		cin >> o >> s;
		for(j=o.size()-1;j>=0;j--){
			if(o[j] == 'J') s = mej(s);
			if(o[j] == 'C') s = mec(s);
			if(o[j] == 'E') s = mee(s);
			if(o[j] == 'A') s = mea(s);
			if(o[j] == 'P') s = mep(s);
			if(o[j] == 'M') s = mem(s);
		}
		cout << s << endl;
	}
	
	
	return 0;
}