#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;
    int row, col;
    for(int x = 0; x < test_case; x++){
        cin >> row >> col;
        vector<vector<int>> dp(col, vector<int>(row, 0));   // the columns have col, and each col has vevtor<int>(row, 0)
        vector<vector<int>> grid(col, vector<int>(row, 0));
        // Input the grid
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                cin >> grid[i][j];
            }
        }
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < col; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < col; i++){
            for(int j = 1; j < row; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        cout << dp[col - 1][row - 1] << endl;
    }
    return 0;
}