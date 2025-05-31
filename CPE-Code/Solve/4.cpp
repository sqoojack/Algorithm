#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int ans = 0;
        vector<string> instr_list;

        int num_instr;
        cin >> num_instr;
        cin.ignore();

        for(int j = 0; j < num_instr; j++){
            string line;
            getline(cin, line);

            if(line == "LEFT"){
                instr_list.push_back("LEFT");
                ans--;
            }
            else if(line == "RIGHT"){
                instr_list.push_back("RIGHT");
                ans++;
            }
            else{
                stringstream ss(line);
                string dummy1, dummy2;
                int x;
                ss >> dummy1 >> dummy2 >> x;

                string real_instr = instr_list[x-1];
                if(real_instr == "LEFT"){
                    instr_list.push_back("LEFT");
                    ans--;
                }
                else{
                    instr_list.push_back("RIGHT");
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}