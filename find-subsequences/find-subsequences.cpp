#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax_n(T &x, U y)
{
    if (x < y)
        x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
}
/************************************/

/******* Debugging Class Template *******/
#define DEBUG

#ifdef DEBUG

#define debug(args...) (Debugger()), args

class Debugger
{
public:
    Debugger(const std::string &_separator = " - ") : first(true), separator(_separator) {}

    template <typename ObjectType>
    Debugger &operator,(const ObjectType &v)
    {
        if (!first)
        std:
            cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger()
    {
    std:
        cerr << endl;
    }

private:
    bool first;
    std::string separator;
};

#else
#define debug(args...) // Just strip off all debug tokens
#endif

/**************************************/

/******** Utilities Function *******/
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void file()
{
    auto a = freopen("a.in", "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if (!a || !b)
        cout << "uh oh" << endl;
}

/* void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
} */

/**************************************/

/******** User-defined Function *******/

void solve()
{
    int size;
    cin >> size;
    MPII freq;
    freq[1] = 0;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        if (freq.find(temp) == freq.end())
        {
            freq[temp] = 1;
        }
        else
        {
            freq[temp]++;
        }
    }

    ll need = 0;
    for (auto it = freq.rbegin(); next(it) != freq.rend(); it++)
    {
        auto next_it = next(it);
        int diff_second = it->second - next_it->second;
        int diff_first = it->first - next_it->first;
        if (diff_second > 0)
        {
            need += diff_second;
            next_it->second += diff_second;
        }
        if (diff_first > 1)
        {
            for (auto i = next_it->first + 1; i < it->first; i++)
            {
                freq[i] = it->second;
                need += it->second;
            }
        }
    }

    if (need)
    {
        cout << need;
        return;
    }

    auto it = freq.begin();
    cout << it->second << endl;
    while (it != freq.end())
    {
        cout << it->first << ' ';
        it->second--;
        if (next(it) != freq.end())
        {
            auto next_it = next(it);
            if (it->second >= next_it->second)
            {
                cout << endl;
                it = freq.begin();
                continue;
            }
        }
        else if (freq.begin()->second > 0)
        {
            cout << endl;
            it = freq.begin();
            continue;
        }
        it++;
    }
}

/**************************************/

/********** Main()  function **********/

int main()
{
    fast();
    // file();

    solve();
}