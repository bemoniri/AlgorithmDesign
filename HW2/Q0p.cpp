#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <stdio.h>
long long sum = 0;

using namespace std;

bool is_perfect_square(long long n) {
    if (n < 0)
        return false;
    long long root(round(sqrt(n)));
    return n == root * root;
}


void print_all_subset(long long *A, long long len, long long *B, long long len2, long long index)
{
	long long num = 1;
    if (index >= len)
    {
        for (long long i = 0; i < len2; ++i)
        {
            num = num * B [i];
        }
        if (is_perfect_square(num)) sum ++;
        
        return;
    }
    print_all_subset(A, len, B, len2, index+1);

    B[len2] = A[index];
    print_all_subset(A, len, B, len2+1, index+1);
}

int main()
{
	long long n;
	cin >> n;	
	
	long long array [31] = {0};
	long  long per_sq = 0;
	for(long long i = 0; i<n; i++){
		long long temp;
	
		cin >> temp;
		if (is_perfect_square(temp)){
			 per_sq ++;		
			 continue;
			 
		}
		
		array[temp] ++;
	}
	
	long long num_even = 0;
	
	for(long i = 1; i<=30; i++){
		num_even += array[i]/2; // Even
		array[i] = array[i]%2;  // Odd
	}
	
	long long t = 0;
	long  long A [30];
	for(int i = 1; i<=30; i++){
		if (array [i] != 0){
			A[t] = i;
			t ++;
		}
	}
	long long res = 0;

	if (t==0) {
		res = ((pow(2, num_even)) * (pow(2, per_sq) ) - 1);
		long long num = pow(10,9) + 7;
		cout << res % num;
		return 0;
	};
	
	if (t>30) return 0;
	long long B[t] = {0};
    long long num = pow(10,9) + 7;

	
    print_all_subset(A, t, B, 0, 0);
    
    if (per_sq == 0 && num_even == 0 && sum != 1) res = (sum - 1)%num;
    
    if (per_sq == 0 && num_even != 0 && sum != 1) res =  (sum * (pow(2, 2*num_even-1)) - 1)%num;
    
    if (per_sq != 0 && num_even != 0 && sum != 1) res =  (sum * (pow(2, 2*num_even-1)) * (pow(2, per_sq)) - 1)%num;
    
    if (per_sq == 0 && num_even != 0 && sum == 1) res =  (pow(2, 2*num_even-1) - 1)%num;
     
    if (per_sq != 0 && num_even != 0 && sum == 1) res =  (pow(2, 2*num_even-1) * pow(2, per_sq) - 1)%num;
    
    if (per_sq != 0 && num_even == 0 && sum != 1) res =  (sum * (pow(2, per_sq)) - 1)%num;
    
    if (per_sq != 0 && num_even == 0 && sum == 1) res =  (pow(2, per_sq) - 1)%num;
    
	cout << res;
    return 0;
}
