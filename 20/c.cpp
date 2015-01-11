#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;

#define INF 99999999

int main(){
	char in[3], out[5];
	out[0] = 'a';
	out[1] = 'a';
	out[2] = 'a';
	out[3] = 'b';
	out[4] = '\0';
	int mem[27] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0};
	
	while(1){
		if(out[1]!='z') out[1]++;
		else if(out[1]!='z') out[2]++;

		printf("?%s\n",out); fflush(stdout);
		scanf("%s", in);
		
		if( in[0] !='b' ){
			cout << "!OUT" << endl;
			break;
		}
		if( in[1] == '\0'){
			mem[26]++;
			out[0]='b';
			if(mem[26] > 1){
				cout << "!OUT" << endl;
				break;
			}
		}
		else{
			mem[in[1]-'a']++;
			out[0] = in[1];
			if(mem[in[1]-'a'] > 1){
				cout << "!OUT" << endl;
				break;
			}
		}
	}
	
	return 0;
}