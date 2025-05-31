
/* Use the sweep line method to find closest pair */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <limits>
#include <climits>
using namespace std;

struct Point{
    double x, y;
};

/* The function to caculate the distance between two points */
double distance(const Point &a, const Point &b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;   // read n points
        vector<Point> pts(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
        }
        // sort it by x-coordinate
        sort(pts.begin(), pts.end(), [](const Point &a, const Point &b){
            return a.x < b.x;   // If point a has a smaller x-coordinate than point b, then a is considered to come before b
        });

        // Use a set sorted by y-coordinate to efficiency find points with nearby y-values
        set<pair<double, int>> active;  // The first element in pair is y-coordinate, second is the index of the point in the original point set
        double minDist = numeric_limits<double>::infinity();    // Get the positive infinity value of type double so that any computed distance will be smaller during the minimum distance calculation
        int left = 0;

        // Remove all points whose x-coordinate difference from points[i] is greater than minDist
        for(int i = 0; i < (int)pts.size(); i++){
            while(pts[i].x - pts[left].x > minDist){
                active.erase({pts[left].y, left});
                left++;
            }
            // In the set, we only need to check points whose y-coordinate differs from points[i].y by no more than minDist
            set<pair<double, int>>::iterator lower = active.lower_bound({pts[i].y - minDist, 1});
            set<pair<double, int>>::iterator upper = active.upper_bound({pts[i].y + minDist, INT_MAX});

            for(set<pair<double, int>>::iterator it = lower; it != upper; ++it){
                int idx = it->second;   // Get the corresponding point index from the set
                double d = distance(pts[i], pts[idx]);
                if(d < minDist)
                    minDist = d;
            }
            active.insert({pts[i].y, i});
        }
        // Specify six digits after the decimal point when outputting
        cout << fixed << setprecision(6) << minDist << endl;
    }
    return 0;
}