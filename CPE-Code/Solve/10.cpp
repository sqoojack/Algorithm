#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Node {
    map<string, Node*> children;
};

void InsertNode(Node& root, vector<string>& dirs){
    Node* address = &root;
    for(auto& dir: dirs){
        if(address->children.find(dir) == address->children.end()){
            address->children[dir] = new Node();
        }
        address = address->children[dir];
    }
}

void PrintTree(Node &root, int depth){
    for(auto& child: root.children){
        for(int i = 0; i < depth; i++){
            cout << " ";
        }
        cout << child.first << endl;
        PrintTree(*child.second, depth+1);
    }
}

int main(){
    int num_disk;
    while(cin >> num_disk){
        Node root;
        for(int i = 0; i < num_disk; i++){
            string path;
            cin >> path;
            stringstream ss(path);

            vector<string> dirs;
            string token;
            while(getline(ss, token, '\\')){
                dirs.push_back(token);
            }
            InsertNode(root, dirs);
        }
        PrintTree(root, 0);
        cout << endl;
    }
}