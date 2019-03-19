#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    string a[n];
    string s;
    for (int i = 0; i<n; i++){
        cin>>s;
        string rev;
        unsigned long len = s.length();
        for (int i = 0; i < len / 2; i++)
            swap(s[i], s[len - i - 1]);
        a[i] = s;
    }
    for (int i = n-1; i>=0; i--){
        cout<<a[i]<<endl;
    }
    return 0;
}

