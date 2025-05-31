#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        vector<int> freqA(26, 0), freqB(26, 0);
        for(char c: a)
            freqA[c - 'a']++;
        for(char c: b)
            freqB[c - 'a']++;

        string ans;
        for(int i = 0; i < 26; i++){
            int commonCount = min(freqA[i], freqB[i]);
            ans.append(commonCount, char(i + 'a'));
        }
        cout << ans << endl;
    }
    return 0;
}