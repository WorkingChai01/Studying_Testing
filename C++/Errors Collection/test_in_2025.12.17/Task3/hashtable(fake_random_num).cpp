#include <iostream>
#include <vector>
using namespace std;
//哈希表解法
int main(){
    int Z, I, M, L;
    int outCount = 1;
    while(cin >> Z >> I >> M >> L){
	    //判断终止条件
        if(Z == 0 && I == 0 && M == 0 && L == 0){
            break;
        }
	    //创建初始列表 用特殊值-1处理未被设定过的数据
	    //如果要防止tle 可以使用标0，初始counting值为1,使用数组的解法
        //最大值不会超过M 所以只需要考虑0-M的出现情况
        vector<int> arr(M, -1);
        int counting = 0;
        while(arr[L] == -1){
            arr[L] = counting;
            counting++;
            L = (Z * L + I) % M;
        }
        cout <<"Case " << outCount << ": " << counting - arr[L] << endl;
        outCount++;
    }
    return 0;
}