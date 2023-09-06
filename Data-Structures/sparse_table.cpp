//darkhorse226

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fill(a) memset(a, 0, sizeof (a))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sqr(x) (1LL*(x)*(x))
#define sz(x) (int)(x).size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (1LL*(a/gcd(a,b))*b)
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define kase(x, y) cout << "Case " << x << ": " << y
#define nl cout << '\n'

typedef long long int ll;
typedef unsigned long long int llu;

const int N = 1e6 + 10000;
const int mod = 1e9 + 7;
//set<ll> st;
bool is_prime[N];
//MAXIMUM EFFORT

#define mx 500
#define K 21
ll Spt[mx][K];

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void build(ll v[], int n) {

	for (int i = 0; i < n; i++) Spt[0][i] = v[i];

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < n; j++) {
			if (j + (1 << i - 1) >= n) break;
			Spt[i][j] = min(Spt[i - 1][j], Spt[i - 1][j + (1 << (i - 1))]);
		}
	}
}

ll query(int l, int r) {
	int p = log2(r - l + 1);
	return min(Spt[p][l], Spt[p][r + 1 - (1 << p)]);
}

int main() {
	int n; cin >> n;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	build(ar, n);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l, r) << '\n';
	}
}
