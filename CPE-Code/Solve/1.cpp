// Command line: g++ -std=c++17 -o output/p10041 practice/p10041.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int relative_num;
        cin >> relative_num;
        vector<int> home_list;

        for(int j = 0; j < relative_num; j++){
            int street_num;
            cin >> street_num;
            home_list.push_back(street_num);
        }
        // After added, sorted it and search the median value
        sort(home_list.begin(), home_list.end());
        int median_value;
        if(relative_num % 2 == 0)
            median_value = home_list[relative_num / 2 - 1]; 
        else
            median_value = home_list[relative_num / 2];
        // cout << median_value;

        int ans = 0;
        for(int j = 0; j < relative_num; j++){
            ans += abs(home_list[j] - median_value);
        }
        cout << ans << endl;
    }
    return 0;
}