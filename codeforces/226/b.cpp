#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	string s;
	int atai[5000] = {};
	cin >> s;
	int now=0;
	
	atai[0]=0;
	atai[1]=0;
	atai[2]=0;
	for(int i=3; i < (int)s.size();i++){
		if(s[i-3] == 'b' && s[i-2] == 'e' && s[i-1] == 'a' && s[i] == 'r'){
			atai[i-3] = now;
			atai[i-2] = now+1;
			atai[i-1] = now+1;
			atai[i] = now+2;
			now += 2;
		}
		else atai[i] = now;
	}
	int ans = 0;
	for(int j = 0; j<(int)s.size();j++){
		for(int k = j+1; k<(int)s.size();k++){
			if(atai[k] - atai[j] > 2){
				ans++;
			}
			else if (atai[k] - atai[j] == 2 && atai[k] % 2 == 0){
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}