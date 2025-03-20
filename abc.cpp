#include <bits/stdc++.h>
using namespace std;

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

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef vector<vpl> vvpl;
typedef pair<int, int> pi;
typedef vector<pi> vp;
typedef vector<vp> vvp;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const int INF = 1e9 + 9;
const ll LINF = 3e18;
const long double eps = 1e-10;
const char nl = '\n';

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &it : v)
        is >> it;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<pair<T, T>> &v)
{
    for (auto &it : v)
        is >> it.first >> it.second;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < sz(v); ++i)
        os << v[i] << " \n"[i == sz(v) - 1];
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<pair<T, T>> &v)
{
    for (auto &it : v)
        os << it.first << " " << it.second << nl;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    for (auto it : s)
        os << it << " \n"[it == *rbegin(s)];
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp)
{
    for (auto &it : mp)
        os << it.first << " " << it.second << nl;
    return os;
}
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
ostream &operator<<(ostream &os, min_priority_queue<T> &pq)
{
    while (!pq.empty())
    {
        os << pq.top() << nl;
        pq.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> &pq)
{
    while (!pq.empty())
    {
        os << pq.top() << nl;
        pq.pop();
    }
    return os;
}

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
// const int MOD = 1e9 + 7;
const int MOD = 998244353;

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
    mint &operator++()
    {
        return *this += 1;
    }
    mint operator++(int)
    {
        mint res(*this);
        ++*this;
        return res;
    }
    mint &operator--()
    {
        return *this -= 1;
    }
    mint operator--(int)
    {
        mint res(*this);
        --*this;
        return res;
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

typedef vector<mint> vm;
typedef vector<vm> vvm;

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

struct UnionFind
{
    vi d;
    UnionFind(int n = 0) : d(n, -1)
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
        cout << x << nl;
        y = root(y);
        cout << y << nl;
        cout << nl;
        if (x == y)
            return false;
        if (d[x] > d[y])
            swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool is_same(int x, int y)
    {
        return root(x) == root(y);
    }
    int size(int x)
    {
        return -d[root(x)];
    }
};

template <class Abel>
struct WeightedUnionFind
{
    vi par, rank;
    vector<Abel> diff_weight;

    WeightedUnionFind(int n = 1, Abel SUM_UNITY = 0) : par(n), rank(n, 0), diff_weight(n, SUM_UNITY)
    {
        iota(all(par), 0);
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    Abel weight(int x)
    {
        root(x);
        return diff_weight[x];
    }

    bool is_same(int x, int y)
    {
        return root(x) == root(y);
    }

    bool unite(int x, int y, Abel w)
    {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y)
    {
        return weight(y) - weight(x);
    }
};

struct PartiallyPersistentUnionFind
{
    vi par, last;
    vvp history;
    PartiallyPersistentUnionFind(int n = 1) : par(n, -1), last(n, INF), history(n)
    {
        for (auto &v : history)
            v.emplace_back(-1, -1);
    }

    int root(int t, int x)
    {
        if (t < last[x])
            return x;
        return root(t, par[x]);
    }

    bool is_same(int t, int x, int y)
    {
        return root(t, x) == root(t, y);
    }

    bool unite(int t, int x, int y)
    {
        x = root(t, x);
        y = root(t, y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        history[x].emplace_back(t, par[x]);
        par[y] = x;
        last[y] = t;
        return true;
    }

    int size(int t, int x)
    {
        x = root(t, x);
        return -prev(lower_bound(all(history[x]), make_pair(t, 0)))->second;
    }
};

struct Edge
{
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost)
    {
    }
};

auto eratosthenes_sieve(int n)
{
    vi primes;
    vb is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

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
    int n, m;
    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);
    rng(i, 1, m + 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        uf.unite(i, a, b);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (!uf.is_same(m + 7, x, y))
        {
            cout << -1 << nl;
        }
        else
        {
            int ok = m + 7, ng = 0;
            while (ok - ng > 1)
            {
                int mid = (ok + ng) / 2;
                if (uf.is_same(mid, x, y))
                    ok = mid;
                else
                    ng = mid;
            }
            cout << ok << nl;
        }
    }
}
