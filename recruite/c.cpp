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
 	
	int T;
	int N;
	char now, state;
	int who;
	long long int score[100];
	
	fscanf(input, "%d\n", &T);
	for(int i= 0;i<T; i++){
		fscanf(input, "%d\n", &N);
		for(int j = 0;j<N;j++){
			score[j] = 0;
		}
		who = 0;
		while(1){
			now = fgetc(input);
			if(now == '\n' || now == EOF) break;
			
			if( (now - '0') <= 9 && (now - '0') >= 1){
				score[who] += (now - '0');
			}
			else{
				state = now;
				while(( (now - '0') > 9 || (now - '0') < 1) && now != EOF && now != '\n'){
					now = fgetc(input);
				}
				if( (now - '0') <= 9 && (now - '0') >= 1){
					if(state == 'X') score[who] = score[who] * ( now - '0');
					else if(state == 'D') score[who] = score[who] / ( now - '0');
					else if(state == 'S') score[who] = score[who] - ( now - '0');
				}
			}
			
			if(who==N-1) who = 0;
			else who++;
		}
		
		long long int ans = -99999999999;
		
		for(int j = 0;j<N;j++){
			if(ans < score[who]){
				ans = score[who];
			}
		}
		
		fprintf(output, "%lld\n", ans);
	}
		
	fclose(output);
	fclose(input);
	return 0;
}