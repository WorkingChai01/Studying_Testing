//#include <bits/stdc++.h>
//in order to standardize
#include <iostream>
using namespace std;

void hannoi(int n,char a,char b,char c){
    if(n==1){
        cout << "disk:" << n << " " << a << "-->" << c << endl;
    }else{
        hannoi(n-1,a,c,b);
        cout << "disk:" << n << " " << a << "-->" << c << endl;
        hannoi(n-1,b,a,c);
    }
}
int main(){
    int n;
    cin >> n;
    hannoi(n,'A','B','C');
    system("pause");
    return 0;
}
