#include <iostream>
#include <algorithm>
#include <math.h>

typedef long long llong;
using namespace std;

llong  num2code (llong temp) {	 // It is meaningful in binary! We assign a vector in {0, 1}^10 to each number. 
	//Our vector space is over the field {0, 1}. addition = xor   mult = and
	if (temp == 1)	return 0;
    if (temp == 2)  return 1;
    if (temp == 3)  return 2;
    if (temp == 4)  return 0;
    if (temp == 5)	return 4;
    if (temp == 6)	return 3;
    if (temp == 7)  return 8;
    if (temp == 8)  return 1;
    if (temp == 9)  return 0;
    if (temp == 10) return 5;
    if (temp == 11) return 16;
    if (temp == 12) return 2;
    if (temp == 13) return 32;
    if (temp == 14) return 9;
    if (temp == 15) return 6;
    if (temp == 16) return 0;
    if (temp == 17) return 64;
    if (temp == 18) return 1;
    if (temp == 19) return 128;
    if (temp == 20) return 4;
    if (temp == 21) return 10;
    if (temp == 22) return 17;
    if (temp == 23) return 256;
    if (temp == 24) return 3;
    if (temp == 25) return 0;
    if (temp == 26) return 33;
    if (temp == 27) return 2;
    if (temp == 28) return 8;
    if (temp == 29) return 512;	 
    return 0; 	 	
}

int main() {
	
	llong mod = 1000000007;
	llong primeVector [2][1024] = {0};
	llong n = 0;
	llong number = 0;
	llong numCode = 0;
	llong result = 0;

	cin >> n;
	int m = 0;
	
	for(llong i = 0; i < n; i++){
		cin >> number;
				
		numCode = num2code(number);
		
		for(llong j = 0; j < 1024; j++){
		    llong xxor = j^numCode;
		    // cout << xxor
			primeVector[m][j] = primeVector[!m][j] % mod + primeVector[!m][xxor] % mod;
		}
		primeVector[m][numCode] =  (primeVector[m][numCode]) % mod + 1;
		result = primeVector[m][0];
		m = (m + 1)%2;

   }  
   cout << result % mod;
}
