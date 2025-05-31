#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    vector<string> v;
    while(getline(cin, s) && s != "0"){
        s += "\n";
        string temp = "";
        int num = 0;

        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i]))
                temp += s[i];
            else if (isdigit(s[i])){
                num * 10;
                num += int(s[i] - '0');
            }
            else{
                if(num != 0){
                    auto target_position = v.end() - num;
                    auto target = *target_position;  // 解引用
                    cout << target;
                    v.erase(target_position);
                    v.push_back(target);
                    num = 0;
                }

                auto target_position = find(v.begin(), v.end(), temp);  // 在向量 v 中搜尋是否有與 temp 相同的單字 如果找到了，it 就會指向該單詞在容器中的位置；若找不到，it 會等於 v.end()
                if(temp != "" && target_position == v.end())// 檢查 it == v.end()，表示 temp 這個單字還沒有出現過，才會將它加入向量 
                    v.push_back(temp);
                cout << temp << s[i];
                temp = "";
            }
        }

    }
    return 0;
}