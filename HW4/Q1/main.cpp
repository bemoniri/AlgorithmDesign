#include <iostream>
using namespace std;

long long get_hash(string const & s){
    int p = 31;
    int m = 1e9+9;
    long long hash = 0;
    long long pow = 1;
    for (char c : s){
        hash = (hash + (c-'a' + 1)*pow)%m;
        pow = (pow*p)%m;
    }
    return hash;
}
string reverseStr(string str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

int main() {
    cout << "Hello, World!" << std::endl;
    cout << reverseStr("behrad")<<endl;
    cout << get_hash("arshia")<<endl;
    cout << get_hash("moniri")<<endl;
    return 0;
}

