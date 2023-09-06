//darkhorse226

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fill(a) memset(a, 0, sizeof (a))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sqr(x) (1LL*(x)*(x))
#define sz(x) (int)(x).size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (1LL*(a/gcd(a,b))*b)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define kase(x, y) cout << "Case " << x << ": " << y
#define nl cout << '\n'

const ll N = 1e6+7;

//MAXIMUM EFFORT

char graph[1000][1000];
bool vis[1000][1000];
int ans, R, C;

vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool is_valid(int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y < C && graph[x][y] != '#' && !vis[x][y]);
}

void dfs(int x,int y) {
    vis[x][y] = 1;
    if (is_valid(x + 1, y)) dfs(x + 1, y);
    if (is_valid(x - 1, y)) dfs(x - 1, y);
    if (is_valid(x, y + 1)) dfs(x, y + 1);
    if (is_valid(x, y - 1)) dfs(x, y - 1);
}

int32_t main() {
    fastio;
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    } 
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!vis[i][j] && graph[i][j] != '#') {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}
