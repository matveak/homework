#include <iostream>
float searcha(int* a, int n) {
    int summ = 0;
    for (int i = 0; i <= n; i++) {
        summ = summ + a[i];
    }
    return (summ / n);
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << searcha(a, n);
}
