#include <iostream>
#include <cstdio>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    std::vector<int> A;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        A.push_back(a);
    }

    int S = N - 1, l_di_S = 0, l_di_i = 0;
    for (int i = 0; i < N; ++i) {
        l_di_i += A[i] - 10;
        if (l_di_i < l_di_S) {
            S = i;
            l_di_S = l_di_i;
        }
    }

    std::cout << ((S + 1) % N + 1) << std::endl;
    return 0;
}
