#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10000;

int main(){
    // create prime list
    vector<int> prime_list;
    vector<bool> is_prime(maxn, true);

    for(int i = 2; i < maxn; i++){
        if(is_prime[i]){
            for(int j = i + i; j < maxn; j += i){
                is_prime[j] = false;
            }
            prime_list.push_back(i);
        }
    }

    // start sliding window part
    int num;
    while(cin >> num){
        if(num == 0)
            break;
        int left = 0, right = 0, sum = 0, ans = 0;
        while(true){
            if(sum < num && right < (int)prime_list.size()){
                sum += prime_list[right];
                right++;
            }
            else if(sum > num){
                sum -= prime_list[left];
                left++;
            }
            else{
                if(sum == num){
                    ans++;
                    sum -= prime_list[left];
                    left++;
                }
                if(right >= (int)prime_list.size())
                    break;
            }
        }
        cout << ans << endl;
    } 
    return 0;
}