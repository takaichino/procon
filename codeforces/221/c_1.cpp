#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int kazu[5]={0,1,6,8,9};
	int num;
	
	for(int i=1;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				for(int l=0;l<5;l++){
					for(int m=0;m<5;m++){
						for(int n=0;n<5;n++){
							num = kazu[i] * 100000;
							num += kazu[j] * 10000;
							num += kazu[k] * 1000;
							num += kazu[l] * 100;
							num += kazu[m] * 10;
							num += kazu[n] * 1;
							if(num % 7 == 0){
								cout << num << endl;
							}
						}
					}
				}
			}
		}
	}
	
		
	return 0;
}