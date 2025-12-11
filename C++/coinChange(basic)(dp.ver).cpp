#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T;
    int coinList[5] = {1, 5, 10, 25, 50};
    cin >> T;
    while(T--){
        int n, sum = 0;
        cin >> n;
        vector<vector<int>> dp(101, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < 5; i++){
            for(int j = 1; j <= 100; j++){
                for(int k = coinList[i]; k <= n; k++){
                    dp[j][k] += dp[j - 1][k - coinList[i]];
                }
            }
        }
        for(int i = 0; i <= 100; i++){
            sum += dp[i][n];
        }
        cout << sum << endl;
    }
    return 0;
}