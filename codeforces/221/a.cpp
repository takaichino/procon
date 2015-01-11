#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	char str[1000001];
	cin >> str;
	
	long long int bar[2] ={};
	int center=0;

	for (int i=0; str[i] != '\0'; i++){
		if(str[i] == '^')center = i;
	}
	for (int j=0; j <center; j++){
		if(str[j] != '='){
			bar[0] += (long long int)(center - j) * (long long int)(str[j] - '0');
		}
	}
	for (int k=center+1;  str[k] != '\0'; k++){
		if(str[k] != '='){
			bar[1] += (long long int)(k - center) * (long long int)(str[k] - '0');
		}
	}
	
	if(bar[0] == bar[1]){
		cout << "balance" << endl;
	}
	else if (bar[0] > bar[1]){
		cout << "left" << endl;
	}
	else {
		cout << "right" << endl;
	}
		
	return 0;
}