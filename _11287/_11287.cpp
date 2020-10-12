#include <bits/stdc++.h>


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



int main(int argc, char* argv[])
{
    
    std::cout << multiplyMod(3, 5, 7) << std::endl;;
    return 0;
}

