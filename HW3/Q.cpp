#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
long long infty = LONG_LONG_MAX;

int main() {
    long long n, k;
    cin >> n >> k;
    long long array[n+1];
    for (long long i = 1; i <= n; i++) {
        cin >> array[i];
    }

    sort(array + 1, array + n + 1);


    long long OPT [n];

    OPT [0] = 0;
    for (long long i = 1; i < k ; i++)
    {
        OPT [i] = infty;
    }
    OPT [k] = array[k] - array[1];


    for (long long num_objects = k + 1 ; num_objects <=n ; num_objects++){
        long long temp = infty;
        for (long long last_num = k ; last_num < 2*k; last_num++){
			if (num_objects-last_num + 1 < 0) break;
            temp = min(temp, max(OPT[num_objects - last_num], array[num_objects] - array[num_objects-last_num + 1]));
        }
        OPT[num_objects] = temp;
    }

    cout<<OPT[n];
    return 0;

}


