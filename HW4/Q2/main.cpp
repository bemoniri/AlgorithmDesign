#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long m = 1e9+1;
long p = 47;

int main() {

    string str;
    cin >> str;

    long n = str.length();
    long long Hash_Forward [n];
    long long Hash_Backward [n];
    long long Mirror_Numbers [n];
    long long pow = 1;

    Hash_Forward[0]=str[0] % m;
    Hash_Backward[0] = str[0] % m;

    for(long i=1; i<n; i++){
        pow = (pow * p) % m;
        Hash_Forward[i] = (Hash_Forward[i-1] + str[i] * pow) % m;
        Hash_Backward[i] = (Hash_Backward[i-1] * p % m + str[i]) % m;
    }

    Mirror_Numbers[0] = 1;

    for(long i=1; i<n; i++){
        if(Hash_Forward[i] == Hash_Backward[i])
            Mirror_Numbers[i] = Mirror_Numbers[ int(floor((i+1)/2)) - 1] + 1;
        else
            Mirror_Numbers[i] = 0;
    }

    long long  output = 0;
    for (int i = 0; i<n; i++){
        //cout<<Mirror_Numbers[i];
        output += Mirror_Numbers[i];
    }
    cout << output;
    return 0;
}