#include <bits/stdc++.h>


void sieve(int* prime, int n, int& cnt);
void sieve1(int* prime, int n, int& cnt);


/// 埃式生成素数发
/// prime[in/out] 素数数组
/// n[in]		
/// cnt[out]	结果素数的个数
void sieve(int* prime, int n, int& cnt) {
	cnt = 0;
	// 假定初始的数都是素数
	memset(prime, 0, n * sizeof(int));
	for (size_t i = 0; i < n; i++) {
		prime[i] = 1;
	}

	for (size_t i = 2; i < n; i++) {
		// 2是素数！
		if (prime[i])
			prime[cnt++] = i;
		// 素数的倍数都不是素数
		for (size_t j = 2*i; j < n; j+=i) {
			prime[j] = 0;
		}
	}
}


void sieve1(int* prime, int n, int& cnt) {
	cnt = 0;
	// 假定初始的数都是素数
	memset(prime, 0, n * sizeof(int));
	for (size_t i = 0; i < n; i++) {
		prime[i] = 1;
	}

	for (size_t i = 2; i < n; i++) {
		// 素数从数组最前面依次存放
		if (prime[i])
			prime[cnt++] = i;
		
		// 标记合数
		for (size_t j = 0; j < cnt && i*prime[j]<n; j++) {
			// 素数的倍数标记为合数
			prime[i * prime[j]] = 0;
			// 退出标记操作
			if (i % prime[j] == 0) 
				break;
		}
	}
}

const int MAXB = 1000;

int main(int argc, char* argv[])
{
	int prime[MAXB] = { 0 };
	int cnt = 0;
	int n = 0;
	sieve1(prime, 100, cnt);


	while (std::cin>>n, n) {
		std::map<int, int> factors;
		for (size_t i = 0; i < cnt; i++) {
			if (prime[i] * prime[i] > n)
				break;

			while (n % prime[i] == 0) {
				n /= prime[i];
				factors[prime[i]]++;	// 素因子累加
			}
		}

		if (n > 1)
			factors[n]++;
		
		std::vector<int> divisors = { 1 };
		for (const auto e: factors) {
			int base = e.first, numOfDivisors = divisors.size();
			for (size_t i = 0; i < e.second; i++) {
				base *= e.first;
				for (size_t j = 0; j < numOfDivisors; j++) {
					divisors.push_back(base * divisors[j]);
				}
			}
		}
		std::sort(divisors.begin(), divisors.end());
		divisors.erase(std::unique(divisors.begin(), divisors.end()), divisors.end());



		std::cout << divisors.size() << std::endl;
	}

	return 0;
}

//#include <bits/stdc++.h>
//
//const int MAXB = 100000001;
//int B[MAXB >> 5] = { 3 };
//
//
//int main(int argc, char* argv[])
//{
//	int n = 0;
//	while (std::cin>>n, n) {
//		std::cout << (B[n>>5]&(1<<(n&0x1f))) << std::endl;
//	}
//}