#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class GooseTattarrattatDiv2 {
	public:
	int getmin(string S)
	{
		int cnt[26];
		int most=0;
		vector<int> ary(26, 0);
		for(int i=0; i< (int)S.size(); i++)
		{
			if( S[i] == 'a'){ cnt[0]++; if(cnt[0] > most) most++;}
			if( S[i] == 'b'){ cnt[1]++; if(cnt[1] > most) most++;}
			if( S[i] == 'c'){ cnt[2]++; if(cnt[2] > most) most++;}
			if( S[i] == 'd'){ cnt[3]++; if(cnt[3] > most) most++;}
			if( S[i] == 'e'){ cnt[4]++; if(cnt[4] > most) most++;}
			if( S[i] == 'f'){ cnt[5]++; if(cnt[5] > most) most++;}
			if( S[i] == 'g'){ cnt[6]++; if(cnt[6] > most) most++;}
			if( S[i] == 'h'){ cnt[7]++; if(cnt[7] > most) most++;}
			if( S[i] == 'i'){ cnt[8]++; if(cnt[8] > most) most++;}
			if( S[i] == 'j'){ cnt[9]++; if(cnt[9] > most) most++;}
			if( S[i] == 'k'){ cnt[10]++; if(cnt[10] > most) most++;}
			if( S[i] == 'l'){ cnt[11]++; if(cnt[11] > most) most++;}
			if( S[i] == 'm'){ cnt[12]++; if(cnt[12] > most) most++;}
			if( S[i] == 'n'){ cnt[13]++; if(cnt[13] > most) most++;}
			if( S[i] == 'o'){ cnt[14]++; if(cnt[14] > most) most++;}
			if( S[i] == 'p'){ cnt[15]++; if(cnt[15] > most) most++;}
			if( S[i] == 'q'){ cnt[16]++; if(cnt[16] > most) most++;}
			if( S[i] == 'r'){ cnt[17]++; if(cnt[17] > most) most++;}
			if( S[i] == 's'){ cnt[18]++; if(cnt[18] > most) most++;}
			if( S[i] == 't'){ cnt[19]++; if(cnt[19] > most) most++;}
			if( S[i] == 'u'){ cnt[20]++; if(cnt[20] > most) most++;}
			if( S[i] == 'v'){ cnt[21]++; if(cnt[21] > most) most++;}
			if( S[i] == 'w'){ cnt[22]++; if(cnt[22] > most) most++;}
			if( S[i] == 'x'){ cnt[23]++; if(cnt[23] > most) most++;}
			if( S[i] == 'y'){ cnt[24]++; if(cnt[24] > most) most++;}
			if( S[i] == 'z'){ cnt[25]++; if(cnt[25] > most) most++;}
		}
		return ((int)S.size() - most);
	}
};

int main() {
  GooseTattarrattatDiv2 ___test;
  ___test.run_test(-1);
}