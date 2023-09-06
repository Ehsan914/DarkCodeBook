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
bool vis[N] = {0}, found = false;
vector<int> v[N], p, cycle;
int n, e, s;
int par[N], level[N], state[N];

//MAXIMUM EFFORT

void dfs(int start) {
    if (vis[start]) return;
    p.pb(start);
    cout << start << " ";
    vis[start] = 1;
    for (auto i:v[start]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int32_t main() {
    fastio;
    memset(level, -1, N);
    cin >> n >> e;
    int cnt = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        v[x].pb(y);
        //v[y].pb(x); // for undirected graph
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i].size() << " ";
        for (auto j:v[i]) {
            cout << j << " ";
        }
        nl;
    }
    return 0;
}
