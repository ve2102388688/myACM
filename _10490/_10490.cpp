#include <bits/stdc++.h>


void sieve(int* prime, int n, int& cnt);
void sieve1(int* prime, int n, int& cnt);


/// ��ʽ����������
/// prime[in/out] ��������
/// n[in]		
/// cnt[out]	��������ĸ���
void sieve(int* prime, int n, int& cnt) {
	cnt = 0;
	// �ٶ���ʼ������������
	memset(prime, 0, n * sizeof(int));
	for (size_t i = 0; i < n; i++) {
		prime[i] = 1;
	}

	for (size_t i = 2; i < n; i++) {
		// 2��������
		if (prime[i])
			prime[cnt++] = i;
		// �����ı�������������
		for (size_t j = 2*i; j < n; j+=i) {
			prime[j] = 0;
		}
	}
}


void sieve1(int* prime, int n, int& cnt) {
	cnt = 0;
	// �ٶ���ʼ������������
	memset(prime, 0, n * sizeof(int));
	for (size_t i = 0; i < n; i++) {
		prime[i] = 1;
	}

	for (size_t i = 2; i < n; i++) {
		// ������������ǰ�����δ��
		if (prime[i])
			prime[cnt++] = i;
		
		// ��Ǻ���
		for (size_t j = 0; j < cnt && i*prime[j]<n; j++) {
			// �����ı������Ϊ����
			prime[i * prime[j]] = 0;
			// �˳���ǲ���
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
				factors[prime[i]]++;	// �������ۼ�
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