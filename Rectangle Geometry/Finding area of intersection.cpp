#include <bits/stdc++.h>
using namespace std;

struct point{
    int bl_x, bl_y, tr_x, tr_y; //bottom left = bl, top right = tr
    long long area() {return abs(tr_x - bl_x) * abs(tr_y - bl_y);}
};

long long inter_area(point a, point b) {
	int xOverlap = max(0, min(a.tr_x, b.tr_x) - max(a.bl_x, b.bl_x));
	int yOverlap = max(0, min(a.tr_y, b.tr_y) - max(a.bl_y, b.bl_y));
	return xOverlap * yOverlap; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    point a, b, c;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;
    cout << inter_area(a, b);
    return 0;
}
