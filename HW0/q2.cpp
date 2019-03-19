#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a [n];

    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    for (int i = 0; i<m; i++){
        int op1, op2;
        cin>>op1;
        cin>>op2;
        op1 -= 1;
        op2 -= 1;
        for (int j = op1; j<=op2; j++) {
            for (int k = op1; k < op2; k++) {
                if (a[k + 1] < a[k]) {
                    int temp = a[k + 1];
                    a[k + 1] = a[k];
                    a[k] = temp;
                }
            }

        }
    }
    for (int i = 0; i<n; i++){
        cout<<a[i];
        cout<<" ";
    }
    return 0;
}
