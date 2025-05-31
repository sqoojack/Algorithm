#include <iostream>
#include <vector>
using namespace std;

int main(){
    int M;
    cin >> M;
    while(M--){
        int N, K;
        cin >> N >> K;

        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        vector<vector<bool>> dp(N+1, vector<bool>(K, false));
        dp[0][0] = true;

        for(int i = 1; i <= N; i++){
            for(int r = 0; r < K; r++){
                if(dp[i-1][r] == true){
                    int add_num = (r + arr[i-1]) % K;
                    if(add_num < 0)
                        add_num += K;

                    int sub_num = (r - arr[i-1]) % K;
                    if(sub_num < 0)
                        sub_num += K;
                    
                    dp[i][add_num] = true;
                    dp[i][sub_num] = true;
                }
            }
        }
        if(dp[N][0] == true)
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
}