#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fill(a) memset(a, 0, sizeof (a))

typedef long long int ll;
typedef unsigned long long int llu;

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

const int N = 1e6 + 10000;
const int mod = 1e9 + 7;

vector<ll> primes;
vector<bool> is_prime(N+1, true);

void sieve() {
    int n = sqrt(N) + 1;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	  if (is_prime[i]) {
	     for (int j = i * i; j <= N; j += i) {
	        is_prime[j] = false;
	     }
	  }
	}
	for (ll i = 2; i <= N; i++) {
	  if (is_prime[i]) {
	     primes.pb(i);  
	  }
	}
}

int main() {
    fastio;
    sieve();
}
