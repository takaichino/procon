#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	char in[500];
	cin >> in;
	int a=0, b=0, c=0, i=0;
	while(in[i] == '|'){
		a++;
		i++;
	}
	i++;
	while(in[i] == '|'){
		b++;
		i++;
	}
	i++;
	while(in[i] == '|'){
		c++;
		i++;
	}
	
	if(a+b == c){
	}
	else if(a+b-1 == c+1){
		if(a>1){
			a--;
			c++;
		}
		else if(b > 1){
			b--;
			c++;
		}
	}
	else if(a+b+1==c-1){
		c--;
		a++;
	}
	else{
		cout << "Impossible" << endl;
		return 0;
	}
	
	int j,k,l;
	for(j = 0; j < a; j++){
		cout << "|";
	}
	cout << "+";
	for(k = 0; k < b; k++){
		cout << "|";
	}
	cout << "=";
	for(l = 0; l < c; l++){
		cout << "|";
	}
	cout << endl;
	return 0;
}