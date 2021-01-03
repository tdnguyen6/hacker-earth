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

long long binomialCoeff(int n, int k)
{
    long long C[k + 1];

    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal
        // triangle using the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] += C[j - 1];
    }
    return C[k];
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_test; // 1 - 1000
    cin >> n_test;
    bitset<30> bs30;
    string s;
    int tmp;
    while (n_test--)
    {
        int n, l, bit_set_times[30] = {0}, bit_set_count = 0; // n: 1 - 20000, l: 1 - 30
        map<ll, int> contribution;
        ll ans = -1, c_val;
        cin >> n >> l;
        REP(i, n)
        {
            cin >> tmp;
            bs30 = tmp;
            s = bs30.to_string();
            REP(j, s.length())
            {
                if (s[s.length() - 1 - j] == '1')
                    bit_set_times[j]++;
            }
        }
        REP(i, 30)
        {
            if (bit_set_times[i])
            {
                c_val = (1 << i) * bit_set_times[i];
                contribution[c_val]++;
                bit_set_count++;
            }
        }

        if (l <= bit_set_count)
        {
            ans = 1;
            for (auto i = contribution.rbegin(); i != contribution.rend(); ++i)
            {
                if (l > i->second)
                {
                    l -= i->second;
                }
                else
                {
                    ans *= binomialCoeff(i->second, l);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}