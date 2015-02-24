#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define INF 999999999

int main(){
	int i, j;
	char s[101];
	stack<int> st;
	int flag;
	
	while(1){
		gets(s);
		if(s[0]=='.')break;
		flag = 1;
		while(!st.empty()) st.pop();
		
		for(i=0;s[i]!='\0';i++){
			if(s[i]=='(') st.push(1);
			else if(s[i]=='[') st.push(2);
			else if(s[i]==')'){
				if(!st.empty()&&st.top()==1){
					st.pop();
				}
				else {
					flag = 0;
					break;
				}
			}
			else if(s[i]==']'){
				if(!st.empty()&&st.top()==2){
					st.pop();
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		
		if(flag && st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}