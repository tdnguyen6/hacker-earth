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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int k;
    cin >> s >> k;
    s += '$';
    int l = s.length();
    int od[l] = {l - 1}, ec[l];
    {
        pair<char, int> a[l];
        REP(i, l) {
            a[i] = {s[i], i};
        }
        sort(a, a + l);

        od[0] = a[0].second;
        ec[od[0]] = 0;
        FOR(i, 1, l, 1) {
            od[i] = a[i].second;
            ec[od[i]] = ec[od[i - 1]] + (a[i].first > a[i - 1].first);
        }
    }

    pair<PII, int> a[l];
    for (int i = 0; 1 << i < l; i++) {
        REP(j, l) {
            a[j] = {{ec[j], ec[(j + (1 << i)) % l]}, j};
        }
        sort(a, a + l);

        REP(i, l) {
            od[i] = a[i].second;
        }

        FOR(j, 1, l, 1) {
            od[j] = a[j].second;
            ec[od[j]] = ec[od[j - 1]] + (a[j].first > a[j - 1].first);
        }
    }

    cout << s.substr(od[k], l - od[k] - 1) << '\n';
}
