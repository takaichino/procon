#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int in[100001];

int main(){
	int n, head, tail, flag =0;
	cin >> n;
	head = 1;
	tail = n;
	for(int i=1; i<=n; i++){
		cin >> in[i];
	}
	for(int k=2; k<=n; k++){
		if(in[k-1] > in[k]){
			if(flag==0){
				head = k-1;
				flag++;
			}
		}
		if(in[k-1] < in[k]){
			if(flag==1){
				tail = k-1;
				break;
			}
		}
	}
	if(flag==0){
		cout << "yes" << endl << "1 1" << endl;
		return 0;
	}
	/*
	cout << head << " " << tail << endl;
	*/
	for(int j=0;head + j < tail - j; j++){
		/*
		cout << "swap" << j << endl;
		*/
		swap(in[head+j], in[tail-j]);
	}
	
	for(int x=2; x <=n; x++){
		if(in[x-1] >= in[x]){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl << head << " " << tail << endl;
	return 0;
}