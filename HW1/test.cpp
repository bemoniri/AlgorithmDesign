#include <iostream>
#include <array>


using namespace std;

string invrs(string a1){
    int l = a1.size();

    char a2[l];
    int i = 0;
    for (i ; i<l ; ++i){
        a2[l-1-i] = a1[i];}

    return a2;
}


int main() {
    cout << "?" << endl;
    int a;
    cin>>a;
    string str[a];
    string str2[a];
    int i = 0;
    for(i;i<a;++i){
        cin>>str[a-1-i];
        str2[a-1-i] = invrs(str[a-1-i]);

    }

    int k = 0;
    string str3;
    for ( k ; k<a ; ++k){



        cout<<str2[k]<<endl;
    }

    return 0;
}






