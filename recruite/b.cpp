#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	
	FILE *input, *output;
	
	if ((input = fopen("input (11).txt", "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}
	if ((output = fopen("output.txt", "w")) == NULL) {          // オープンに失敗した場合
		printf("cannot open\n");         // エラーメッセージを出して
		exit(EXIT_FAILURE);	// 異常終了
 	}
 	

	int T;
	int N;
	
	fscanf(input, "%d\n", &T);
	for(int i= 0;i<T; i++){
		
		char per[50][10];
		double smp, ave[50];
		double ans = 999.0;
		int hannin;
		char now;
		double sa;
		
		double moji = 0, spc = 1;
		
		while(1){
			now = fgetc(input);
			if(now =='\n') break;
			else if(now==' ')spc++;
			else moji++;
		}
		smp = moji / spc;
		
		fscanf(input, "%d\n", &N);
		for(int j = 0;j<N;j++){
			double moji = 0, spc = 0;
			int z = -1;
			while(1){
				z++;
				now = fgetc(input);
				if(now==':'){
					for(int y = z; y < 10; y++){
						per[j][y] = '\0';
					}
					break;
				}
				else per[j][z] = now;
			}
			
			while(1){
				now = fgetc(input);
				if(now =='\n' || now == EOF || now =='\0') break;
				else if(now==' ')spc++;
				else moji++;
			}
			
			ave[j] = moji / spc;
			
			if(ave[j] - smp > 0) sa = ave[j] - smp;
			else sa = - ave[j] + smp;
			
			if( sa < ans){
				hannin = j;
				ans = sa;
			}
		}
		
		fprintf(output, "%s\n", per[hannin]);
	}
	
	fclose(output);
	fclose(input);
	return 0;
}