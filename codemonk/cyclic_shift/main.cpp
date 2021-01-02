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

int cmp(string s, int ft, int sc = 0) {
    int l = s.size();
    REP(i, l)
    {
        if (s[ft] > s[sc]) return 1;
        if (s[ft] < s[sc]) return -1;
        ft++;
        sc++;
        if (ft >= l) ft %= l;
        if (sc >= l) sc %= l;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // auto a = freopen("a.in", "r", stdin);
    // auto b = freopen("a.out", "w", stdout);
    // if (!a || !b)
    //     cout << "uh oh" << endl;

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int N, K;
        string A;
        cin >> N >> K >> A;
        int maxPos[N] = {0};
        int maxNum = 1;
        FOR(i, 1, N, 1)
        {
            int res = cmp(A, i, maxPos[0]);
            if (res > 0)
            {
                maxPos[0] = i;
                maxNum = 1;
            }
            else if (res == 0)
            {
                maxPos[maxNum] = i;
                maxNum++;
            }
        }

        ll ans = maxPos[0];
        ll total[maxNum];
        if (maxNum > 1)
        {
            total[0] = {maxPos[1] - maxPos[0]};
            FOR(i, 1, maxNum - 1, 1)
                total[i] = total[i - 1] + maxPos[i + 1] - maxPos[i];
            total[maxNum - 1] = total[maxNum - 2] + N - maxPos[maxNum - 1] + maxPos[0];
        }
        else
        {
            total[0] = N;
        }
       

        ans += (K - 1) / maxNum * total[maxNum - 1];
        int x = (K - 1) % maxNum;
        if (x > 0)
            ans += total[x - 1];
        cout << ans << '\n';
    }
}