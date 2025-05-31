#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    while(true){
        int n;  // have n node
        cin >> n;
        if(n == 0)
            break;
        int l;
        cin >> l;
        vector<vector<int>> adj_list(n);
        for(int i = 0; i < l; i++){
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        vector<int> color(n, -1);
        bool IsBicolorable = true;

        for(int start = 0; start < n; start++){
            if(color[start] == -1){
                queue<int> q;
                color[start] = 0;
                q.push(start);

                while(!q.empty() && IsBicolorable){
                    int u = q.front();
                    q.pop();
                    for(auto v: adj_list[u]){
                        if(color[v] == -1){
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        if(color[v] == color[u]){
                            IsBicolorable = false;
                            break;
                        }
                    }
                }
            }
            if(IsBicolorable == false)
                break;
        }

        if(IsBicolorable)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }


}