#include <bits/stdc++.h>
using namespace std;

struct point{
    int bl_x, bl_y, tr_x, tr_y; //bottom left = bl, top right = tr
    long long area() {return abs(tr_x - bl_x) * abs(tr_y - bl_y);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    point a;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cout << a.area();

    return 0;
}
