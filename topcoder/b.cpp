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

class ORSolitaireDiv2 {
public:
	int getMinimum(vector <int> numbers, int goal) {
	int result = 99, bit;
	for(int j = 0; j<32; j++){
		bit = 0;
		if( pow(2,j) & goal ){
			for(int i = 0; i< numbers.size(), i++){	
    			if(( pow(2,j) & numbers[i] ) && ( ( numbers[i] & (~goal) ) == 0 ) ){
    				bit++;
    			}
    		}
    		if(bit < result){
    			result = bit;
    		}
    	}
    }
    return result;
  }
};

