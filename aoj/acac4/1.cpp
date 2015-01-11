#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 9999999999

void print(int A[3][9]){
	cout << "A";
	for(int j = 0; j < A[0][0]; j++){
		cout << " " << A[0][j+1];
	}
	cout << endl;
	cout << "B";
	for(int j = 0; j < A[1][0]; j++){
		cout << " " << A[1][j+1];
	}
	cout << endl;
	cout << "C";
	for(int j = 0; j < A[2][0]; j++){
		cout << " " << A[2][j+1];
	}
	cout << endl << endl;
}

void suwa(int A[3][9], int m, int x, int y, int z){ //m‚Ü‚¢x‚©‚çy‚Ö
	if (m == 1){
		A[y][ A[y][0] + 1 ] = A[x][ A[x][0] ];
		A[x][ A[x][0] ] = 0;
		A[x][0]--;
		A[y][0]++;
		print(A);
	}
	else{
		suwa(A, m-1, x, z, y);
		suwa(A, 1, x, y, z);
		suwa(A, m-1, z, y, x);
	}
}

int main(){
	int han[3][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0 },{0, 0, 0, 0, 0, 0, 0, 0, 0 },{0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int n;
	cin >> n;
	han[0][0] = n;
	for(int i=0; i<n; i++){
		han[0][i+1] = n-i;
	}
	print(han);
	suwa(han, n, 0, 2, 1);
	
	return 0;
}