#include <bits/stdc++.h>
using namespace std;

struct point{
    int bl_x, bl_y, tr_x, tr_y; //bottom left = bl, top right = tr
    long long area() {return abs(tr_x - bl_x) * abs(tr_y - bl_y);}
};

bool intersect(point a, point b) {
	if (a.tr_y <= b.bl_y || a.bl_y >= b.tr_y || a.tr_x <= b.bl_x || a.bl_x >= b.tr_x) {
		return false;
	} else return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    point a, b;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;
    cout << (intersect(a, b) ? "YES" : "NO");
    return 0;
}
