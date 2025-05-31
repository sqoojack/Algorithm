#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        if(line.empty())
            continue;

        stringstream ss(line);
        int num_stone;
        ss >> num_stone;

        int num_takes;
        ss >> num_takes;
        vector<int> takes(num_takes);
        for(int i = 0; i < num_takes; i++){
            ss >> takes[i];
        }

        vector<bool> dp(num_stone + 1, false);

        for(int j = 1; j <= num_stone; j++){
            for(int take: takes){
                if((j - take) >= 0 && dp[j - take] == false){
                    dp[j] = true;
                    break;
                }
            }
        }
        if(dp[num_stone])
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
}