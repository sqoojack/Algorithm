#include <iostream>
#include <string>
using namespace std;

int main(){
    int num_act;
    while(cin >> num_act && num_act != 0){      // input continuously until read 0 
        int top = 1, north = 2, west = 3, bottom = 6, south = 5, east = 4;

        while(num_act--){
            int temp;
            string act;
            cin >> act;

            if(act == "north"){
                temp = top;
                top = south;
                south = bottom;
                bottom = north;
                north = temp;
            }
            if(act == "south"){
                temp = top;
                top = north;
                north = bottom;
                bottom = south;
                south = temp;
            }

            if(act == "east"){
                temp = top;
                top = west;
                west = bottom;
                bottom = east;
                east = temp;
            }

            if(act == "west"){
                temp = top;
                top = east;
                east = bottom;
                bottom = west;
                west = temp;
            }
        }
        cout << top << endl;
    }
    return 0;
}