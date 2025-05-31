#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int nums;
    cin >> nums;
    vector<int> dp(nums + 1, 1);
    vector<int> nums_list(nums + 1, 0);

    for(int i = 1; i <= nums; i++){
        cin >> nums_list[i];
    }
    for(int i = 1; i <= nums; i++){
        for(int j = 1; j <= i - 1; j++){
            if(nums_list[i] > nums_list[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= nums; i++){
        ans = max(ans, dp[i]);        
    }
    cout << ans << endl;
    return 0;
}