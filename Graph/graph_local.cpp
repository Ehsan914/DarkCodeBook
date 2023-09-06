//darkhorse226

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fill(a) memset(a, 0, sizeof (a))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nl cout << '\n'

const ll N = 1e6+7;

//MAXIMUM EFFORT

bool possible = true;
int n, e;

void bfs (int start, vector<vector<int>> &v, vector<bool> &vis, vector<int> &level, vector<int> &p) { //bfs with queue
    queue<int> q;
    q.push(start);
    //p.pb(start);
    level[start] = 0;
    vis[start] = 1;
    while (!(q.empty())) {
        int vertex = q.front();
        p.pb(vertex);
        q.pop();
        for (auto i:v[vertex]) {
            if (vis[i] == 0) {
                level[i] = level[vertex] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    for (auto i:p) {
        cout << i << " ";
    }
}

void dfs(int start, bool c, vector<vector<int>> &v, vector<bool> &vis, vector<bool> &col) {
    if (vis[start]) return;
    vis[start] = 1;
    col[start] = c;
    for (auto i:v[start]) {
        if (!vis[i]) {
            dfs(i, c^1, v, vis, col);
        } else {
            if (col[i] == c) {
                possible = 0;
            }
        }
    }
}

int32_t main() {
    fastio;
    cin >> n >> e;
    vector<vector<int>> v(n + 10);
    vector<int> level(n + 10), p;
    vector<bool> vis(n + 10, 0), col(n + 10);
    possible = 1;
    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) bfs(i, v, vis, level, p);
        p.clear();
    }
    return 0;
}
