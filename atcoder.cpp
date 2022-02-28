#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rng(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define per(i, b) gnr(i, 0, b)
#define all(obj) begin(obj), end(obj)
#define allr(obj) rbegin(obj), rend(obj)
#define sz(x) (int)(x).size()
#define cinv(a) rep(i, sz(a)) cin >> a[i]
#define debug(a) rep(i, sz(a)) cout << a[i] << " \n"[i == sz(a) - 1]
#define show(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ef emplace_front

typedef long long ll;
typedef pair<ll, ll> Pl;
typedef vector<Pl> vpl;
typedef vector<vpl> vvpl;
typedef pair<int, int> Pi;
typedef vector<Pi> vp;
typedef vector<vp> vvp;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;

template <typename T> bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T> bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int MOD = 1e9 + 7;
// const int MOD = 998244353;

struct mint
{
    ll x;
    mint(ll x = 0) : x((x % MOD + MOD) % MOD)
    {
    }
    mint operator-() const
    {
        return mint(-x);
    }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += MOD - a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const
    {
        return mint(*this) += a;
    }
    mint operator-(const mint a) const
    {
        return mint(*this) -= a;
    }
    mint operator*(const mint a) const
    {
        return mint(*this) *= a;
    }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    mint inv() const
    {
        return pow(MOD - 2);
    }
    mint &operator/=(const mint a)
    {
        return *this *= a.inv();
    }
    mint operator/(const mint a) const
    {
        return mint(*this) /= a;
    }
};
istream &operator>>(istream &is, mint &a)
{
    return is >> a.x;
}
ostream &operator<<(ostream &os, const mint &a)
{
    return os << a.x;
}

const int INF = 1e9 + 9;
const ll LINF = 1e18;
const long double eps = 1e-10;
const char nl = '\n';

ll power(ll a, ll b, int mod = MOD)
{
    return b ? power(a * a % mod, b / 2, mod) * (b % 2 ? a : 1) % mod : 1;
}

ll inv(ll a, int mod = MOD)
{
    return power(a, mod - 2);
}

ll nCk(int n, int k, int mod = MOD)
{
    ll x = 1, y = 1;
    for (int i = 1; i <= k; ++i)
    {
        x = x * (n - i + 1) % mod;
        y = y * i % mod;
    }
    return x * power(y, mod - 2, mod) % mod;
}

struct UF
{
    vi d;
    UF(int n = 0) : d(n, -1)
    {
    }
    int root(int x)
    {
        if (d[x] < 0)
            return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (d[x] > d[y])
            swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x)
    {
        return -d[root(x)];
    }
};

struct Edge
{
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost)
    {
    }
};

clock_t startTime;
void getCurrentTime()
{
    cout << (double)(clock() - startTime) / CLOCKS_PER_SEC << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    // startTime = clock();
    // getCurrentTime();
    int n;
    cin >> n;
    vvl dp(40, vl(n));
    rep(i, n) cin >> dp[0][i];

    rep(i, 39) rep(j, n) dp[i + 1][j] = dp[i][j] + dp[i][(j + dp[i][j]) % n];

    int q;
    cin >> q;
    while (q--)
    {
        ll k; cin >> k;
        ll ans = 0;
        rep(i, 40)
        {
            if (k & (1LL << i))
                ans += dp[i][ans % n];
        }
        cout << ans << nl;
    }
}
