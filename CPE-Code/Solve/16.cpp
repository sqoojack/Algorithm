#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(a[i-1] == b[j-1])   // because string's index is start from 0
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}