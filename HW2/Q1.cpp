#include <iostream>
#include <cmath>

using namespace std;
long A, B, k, n;
long* input_array_end;
long* input_array_start;

void merge(long array[], long l, long m, long r) 
{ 
    long i, j, k; 
    long n1 = m - l + 1; 
    long n2 =  r - m; 
 
    long L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = array[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = array[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            array[k] = L[i]; 
            i++; 
        } 
        else
        { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(long array[], long l, long r) 
{ 
    if (l < r) 
    { 
        long m = l+(r-l)/2; 
        mergeSort(array, l, m); 
        mergeSort(array, m+1, r); 
  
        merge(input_array_start, l, m, r); 
    } 
} 

long OPT(long start, long end, long pos, long num_sas) 
{
	if (end == start) {                           // if at base cases of recursion
		if (num_sas != 0) return B*num_sas;		  
		else              return A;				  
	}
	else {									      // at an intermediate step
		if (num_sas == 0) return A;              
		
		long left_num = 0;
		int i = 0;
		for(i = 0; i < k; i++){		     // only look in indexes of the input array where there is a chance of finding a tile related to the current stage
			if(input_array_start [i] <= (end + start - 1) / 2)    left_num++;  // increment if found a sas
			else break;
		}
		long right_cost = OPT((end + start + 1) / 2 , end, i , num_sas - left_num );   // split left (also pass the number of sas - no need to count!)
		long left_cost = OPT(start , (end + start - 1) / 2 , pos,  left_num );               // split right (also pass the number of sas)
		return min(left_cost + right_cost, (end - start + 1) * num_sas * B);                 // Decide what to do in the current stage
	}
}

int main()
{
	cin >> n >> k >> A >> B;
	input_array_start = new long[k];
	for (int i = 0; i < k; i++) {
		cin >> input_array_start[i] ;
	}
	input_array_end =  input_array_start + k - 1;   // Pointer to the end of input array
	if ( k == 0) return A;                          // If there is no sas
	else {
		mergeSort(input_array_start, 0,  k-1);		// Sorting the input array using mergesort
		long opt_res = OPT(1 , pow(2, n), 0,  k);   // Begin Recursion
		cout << opt_res;
		return 0;
	}
}
