#include <bits/stdc++.h>

// 最大测试次数
const int MAX_ITERATORS = 2;

// 针对两个long long相乘可能导致溢出
// (ab)%mod
long long multiplyMod(long long a, long long b, long long mod) {
    long long x = 0, y = a % mod;
    while (b) {
        if (b & 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b >>= 1;
    }
    return x;
}


// 快速幂取模
long long modulo(long long a, long long b, long long mod) {
    long long ans = 1, rns = a;
    while (b) {
        if (b & 1)
            ans = multiplyMod(ans, rns, mod);
        rns = multiplyMod(rns, rns, mod);
        b >>= 1;
    }
    return ans;
}


bool isPrime(long long p) {
    if (p < 2)
        return false;
    if (p == 2)                 // 把2排除
        return false;
    if (!(p & 1))               // 偶数肯定不是素数
        return false;

    /// 满足等式的最大q
    long long q = p - 1;
    while (!(q & 1)) q >>= 1;       // p-1=2^t*q


    for (size_t i = 0; i < MAX_ITERATORS; i++) {
        long long a = rand() % (p - 1) + 1;         // 从(1,p)随机选择一个证人
        long long t = q;
        long long mod = modulo(a, t, p);            // mod = a^t%p
        while (t!=p-1 && mod!=1 && mod!=p-1) {
            mod = multiplyMod(mod, mod, p);         // 二次探测定理
            t <<= 1;
        }
        if (mod != p - 1 && !(t & 1))
            return false;
    }
    return true;
}


int main(int argc, char* argv[])
{
    long long n = 0;
    while (std::cin>>n, n) {
        std::cout << isPrime(n) << std::endl;;
    }
    return 0;
}

