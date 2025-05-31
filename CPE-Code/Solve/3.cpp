#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    // create key_word dictionary
    unordered_map<string, int> key_words;
    for(int i = 0; i < m; i++){
        string word;
        int value;
        cin >> word >> value;
        key_words[word] = value;
    }

    for(int j = 0; j < n; j++){
        long long score = 0;
        while(true){
            string line;
            getline(cin, line);
            if(line == ".")
                break;
            stringstream ss(line);
            string taken;
            while(ss >> taken){
                if(key_words.find(taken) != key_words.end())
                    score += key_words[taken]; 
            }
        }
        cout << score << endl;
    }
    return 0;
}