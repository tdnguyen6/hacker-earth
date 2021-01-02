#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int getW(ll n, int i)
{
    return n / (ll) pow(100000, (i - 1)) % 100000;
}

void sortNprint(ll A[], pair<int, int> WA[], int size)
{
    map<int, queue<int>> mp;
    REP(i, size)
    {
        mp[WA[i].first].push(WA[i].second);
    }
    int id = 0, tmp_idx = 0;
    ll tmp[size];
    for (auto me : mp)
    {
        while (!me.second.empty())
        {
            tmp_idx = me.second.front();
            me.second.pop();
            cout << A[tmp_idx] << ' ';
            tmp[id++] = A[tmp_idx];
        }
    }
    cout << '\n';
    copy(tmp, tmp + size, A);
}

pair<int, int> WA[1000000];
ll A[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, weight, no_w, idx;
    string s;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    {
        REP(j, N)
        {
            weight = getW(A[j], 1);
            no_w += weight == 0;
            WA[j] = {weight, j};
        }
    }

    using namespace chrono;
    auto start = high_resolution_clock::now();

    for (int i = 2, no_w = 0; no_w < N; i++)
    {
        sortNprint(A, WA, N);
        REP(j, N)
        {
            weight = getW(A[j], i);
            no_w += weight == 0;
            WA[j] = {weight, j};
        }
    }
    cout.imbue(locale("en_US.UTF8"));
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "It took: " << duration.count() << " us" << endl;
}