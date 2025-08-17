#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    const double EPS = 1e-9;
    for (int i = 0; i < t; i++){
        int a[2],k[2],q[2];
        for (int j = 0; j < 2; j++) cin >> a[j];
        for (int j = 0; j < 2; j++) cin >> k[j];
        for (int j = 0; j < 2; j++) cin >> q[j];
        int cx = (k[0]+q[0])/2;
        int cy = (k[1]+q[1])/2;
        double radius, dist;
        radius = sqrt((cx-k[0])*(cx-k[0]) + (cy-k[1])*(cy-k[1]));
        dist = sqrt((cx-a[0])*(cx-a[0]) + (cy-a[1])*(cy-a[1]));
        if (fabs(radius - dist) < EPS ){
            if(cx == a[0] || cy == a[1]){
                cout << "2\n";
            }
            else cout << "1\n";
        }
        else if (dist < radius)
            cout << "2\n";
        else
            cout << "0\n";
        // if(radius == dist) cout << "1\n";
        // if(radius > dist) cout << "2\n";
        // if(radius < dist) cout << "0\n";
    }
    return 0;
}