#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // for LLONG_MAX
using namespace std;
using ll = long long;

struct Node{
    int key;
    Node *left, *right;
    Node(int k): key(k), left(nullptr), right(nullptr){}
};

// Caculate root[i][j]
vector<vector<int>> optimal_BST(const vector<int>& freq){
    // freq: frequency of each node
    int n = freq.size() - 1;
    // create prefix array (prefix[i] = freq[1] + ... + freq[i])
    vector<ll> prefix(n+1, 0);  // index from 0 to n
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + freq[i];
    }

    // create dp[i][j] and root[i][j]
    vector<vector<ll>> dp(n+2, vector<ll>(n+2, 0));     // want to access index of n+1
    vector<vector<int>> root(n+2, vector<int>(n+2, 0));

    // initialize it
    for(int i = 1; i <= n+1; i++){
        dp[i][i-1] = 0;     // when i > j in dp[i][j], it means empty interval
        root[i][i-1] = i;
    }

    // initialize the condition with length 1
    for(int i = 1; i <= n; i++){
        dp[i][i] = freq[i];
        root[i][i] = i;
    }

    // caculate every interval with length 2 to n
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            ll weight = prefix[j] - prefix[i-1];
            dp[i][j] = LLONG_MAX;

            // Knuth optimize: search the root from root[i][j-1] to root[i+1][j]
            int start = root[i][j-1];
            int end = root[i+1][j];
            if(start > end)
                end = start;

            for(int r = start; r <= end; r++){
                ll cost = dp[i][r-1] + dp[r+1][j] + weight;
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }
    return root;
}

Node* build_tree(int i, int j, const vector<vector<int>>& root, const vector<int>& keys){
    if(i > j)
        return nullptr;
    int r = root[i][j];
    Node* node = new Node(keys[r]);
    node->left = build_tree(i, r-1, root, keys);    // create left subtree
    node->right = build_tree(r+1, j, root, keys);    // create right subtree
    return node;
}

vector<int> level_order(Node* root){
    vector<int> result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node){
            result.push_back(node->key);
            q.push(node->left);
            q.push(node->right);
        }
        else
            result.push_back(-1);
    }
    // remove all trailing 1
    while(!result.empty() && result.back() == -1)
        result.pop_back();

    return result;
}

int main(){
    int test_case;
    if(!(cin >> test_case))
        return 0;

    while(test_case--){
        int n;
        cin >> n;
        vector<int> keys(n+1), freq(n+1);

        for(int i = 1; i <= n; i++)
            cin >> keys[i];
        for(int i = 1; i <= n; i++)
            cin >> freq[i];
        
        auto root = optimal_BST(freq);
        Node* tree = build_tree(1, n, root, keys);  // define root of tree

        // output by level order
        auto output = level_order(tree);
        for(int x: output)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}