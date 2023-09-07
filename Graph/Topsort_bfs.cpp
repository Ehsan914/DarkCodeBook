//darkhorse226

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fill(a) memset(a, 0, sizeof (a))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sqr(x) (1LL*(x)*(x))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (1LL*(a/gcd(a,b))*b)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define kase(x, y) cout << "Case " << x << ": " << y
#define nl cout << '\n'

typedef long long int ll;
typedef unsigned long long int llu;

const int N = 1e7;
const int mod = 1e9;
vector<ll> v[N];
ll indegrees[N], dp[N];
vector<ll> topsort;
ll n, m, cnt;
string s;

//MAXIMUM EFFORT

void top_sort() {
	priority_queue<ll> q;
	cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (indegrees[i] == 0) {
			q.push(i*-1);
		}
	}
	while (!q.empty()) {
		cnt++;
		ll x = -q.top();
		q.pop();
		topsort.pb(x);
		for (auto y:v[x]) {
			indegrees[y]--;
			if (indegrees[y] == 0) {
				q.push(-y);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y; cin >> x >> y;
		v[x].pb(y);
		++indegrees[y];
	}
	top_sort();
	if (cnt < n) {
		return 0;
	} 
	for (auto x:topsort) {
		cout << x << " ";
	}
	return 0;
}
