#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	
	FILE *input, *output;
	
	if ((input = fopen("input.txt", "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}
	if ((output = fopen("output.txt", "w")) == NULL) {
		printf("cannot open\n");
		exit(EXIT_FAILURE);
 	}
 	
	while(1){ //write source code!
		
	}
	
	fclose(output);
	fclose(input);
	return 0;
}