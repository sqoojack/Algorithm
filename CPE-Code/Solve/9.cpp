#include <iostream>
using namespace std;

int main(){
    int cola;
    while(cin >> cola){
        int ans = cola, empty_nums = cola;
        while(empty_nums >= 3){
            int new_cola = empty_nums / 3;
            ans += new_cola;
            empty_nums = empty_nums % 3 + new_cola;
        }

        if(empty_nums == 2)
            ans++;
        cout << ans << endl;
    }
}