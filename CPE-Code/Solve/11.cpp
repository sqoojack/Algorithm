#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    int PrevSum = 0;

    for(int j = 0; j < N; j++){
        int num;
        cin >> num;
        PrevSum += num;
    }

    for(int i = 1; i < M; i++){
        int CurSum = 0;
        for(int j = 0; j < N - i; j++){
            int num;
            cin >> num;
            CurSum += num;
        }
        int ans = PrevSum - CurSum;
        cout << ans << endl;
        PrevSum = CurSum;
    }
    return 0;
}
