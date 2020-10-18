#include <iostream>
#include <cmath>

int solution(int k, int m, int n) {
    if (k == m) return 0;
    if (k > m) return (k - m) % 2 + (k - m) / 2;
    int count = 1;
    int a = ceil((double) m / n);
    if (k < a) count += solution(k, a, n);
    else count += (k - a) / 2 + (k - a) % 2;
    int b = a * n;
    count += (b - m) / 2 + (b - m) % 2;
    return count;
}

int main() {
    int N, k, m, n;
    std::cin >> N;
    while (N--) {
        std::cin >> k >> m >> n;
        std::cout << solution(k, m, n) << '\n';
    }
    return 0;
}