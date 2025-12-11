#include <bits/stdc++.h>
using namespace std;

int fasterPower(int A, int B){
    int result = 1;
    while(B){
        if(B % 2 == 1){
            result = (result * A) % 1000;
        }
        A = (A * A) % 1000;
        B = B / 2;
    }
    return result;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int A, B, result;
        cin >> A >> B;
        cout << fasterPower(A, B) << endl;
    }
    return 0;
}