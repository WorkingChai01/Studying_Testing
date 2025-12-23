#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp解法
int main(){
    //初始化
    string str1;
    string str2;
    string output;
    //每次处理两个字符串
    while(getline(cin, str1) && getline(cin, str2)){
        vector<int> resultlistX; //记录最长字串末尾处索引
        vector<string> result; //存储所有满足最长字串的字符串
        int counter;
        int max = 0;
        //提前排除长度为0的情况
        if(str1.size() == 0 || str2.size() == 0){
            cout << "" << endl;
            continue;
        }
        /*
        dp部分正式开始
        因为每出现一组相同的字符，要去判断其之前x++，y++一直到他这里经过了多少个相等的字符情况
        于是通过
        dp[i][j] = dp[i - 1][j - 1] + 1;
        实现前后对角线（i，j减数相等）的联动，同时也能保证从开始出现重复计数到当前项
        举个例子
        "aaab" "aaaa"
        列表写为
                0   1   2   3   4
                   'a' 'a' 'a' 'a'
        0       0   0   0   0   0
        1   'a' 0   1   1   1   1
        2   'a' 0   1   2   2   2
        3   'a' 0   1   2   3   3
        4   'b' 0   0   0   0   0
        可以看出，若能连续构成子字符串,一定是处于对角状态的，并且可以动态累加计算到某一格时的长度
        */
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        for(int i = 1; i < str1.size() + 1; i++){
            for(int j = 1; j < str2.size() + 1; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if(dp[i][j] > max){
                        max = dp[i][j];
                        resultlistX.clear();
                        resultlistX.push_back(i - 1);
                    }else if(dp[i][j] == max){
                        resultlistX.push_back(i - 1);
                    }
                }
            }
        }
        counter = resultlistX.size();
        //排除无相同子集情况
        if(resultlistX.size() == 0){
            cout << "" << endl;
            continue;
        }
        //同等长字串，取字典序最小
        while(counter--){
            result.push_back(str1.substr(resultlistX[counter] - max + 1, max));
        }
        output = result[0];
        for(int i = 1; i < result.size(); i++){
            if(output > result[i]){
                output = result[i];
            }
        }
        cout << output << endl;
    }
    return 0;
}