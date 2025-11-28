#include <iostream>
#include <map>
#include <functional>

// Универсальный кеш для чистых функций f(int) -> int
class Memo {
public:
    explicit Memo(std::function<long long(int)> func) : f(func) {}

    long long operator()(int n) {
        if (cache.count(n)) return cache[n];
        long long result = f(n);
        cache[n] = result;
        return result;
    }

private:
    std::function<long long(int)> f;
    std::map<int, long long> cache;
};

int main() {
    // Оборачиваем лямбда-функцию в мемоизацию
    Memo fib([&](int n) -> long long {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    });

    for (int i = 0; i <= 40; i++) {
        std::cout << "fib(" << i << ") = " << fib(i) << "\n";
    }
}