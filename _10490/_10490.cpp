//#include <bits/stdc++.h>
//
///// ��ʽ����������
///// prime[in/out] ��������
///// n[in]		
///// cnt[out]	��������ĸ���
//void sieve(int* prime, int n, int& cnt) {
//	cnt = 0;
//	// �ٶ���ʼ������������
//	memset(prime, 0, n * sizeof(int));
//	for (size_t i = 0; i < n; i++) {
//		prime[i] = 1;
//	}
//
//	for (size_t i = 2; i < n; i++) {
//		// 2��������
//		if (prime[i])
//			prime[cnt++] = i;
//		// �����ı�������������
//		for (size_t j = 2*i; j < n; j+=i) {
//			prime[j] = 0;
//		}
//	}
//}
//
//
//void sieve1(int* prime, int n, int& cnt) {
//	cnt = 0;
//	// �ٶ���ʼ������������
//	memset(prime, 0, n * sizeof(int));
//	for (size_t i = 0; i < n; i++) {
//		prime[i] = 1;
//	}
//	int a = 0;
//	for (size_t i = 2; i < n; i++) {
//		// ������������ǰ�����δ��
//		if (prime[i])
//			prime[cnt++] = i;
//		
//		// ��Ǻ���
//		for (size_t j = 0; j < cnt && i*prime[j]<n; i++) {
//			// �����ı������Ϊ����
//			prime[i * prime[j]] = 0;
//			// �˳���ǲ���
//			if (i % prime[j] == 0) break;
//		}
//	}
//}
//
//
//int main(int argc, char* argv[])
//{
//	int a;
//	int* prime = &a;
//	int cnt = 0;
//	int n = 0;
//
//	while (std::cin>>n, n) {
//		//sieve(prime, n, cnt);
//		sieve1(prime, n, cnt);
//		//std::cout << cnt << std::endl;
//		for (size_t i = 0; i < cnt; i++) {
//			//std::cout << prime[i] << " ";
//		}
//		std::cout << std::endl;
//	}
//
//	return 0;
//}

#include <bits/stdc++.h>

const int MAXB = 100000001;
int B[MAXB >> 5] = { 3 };


int main(int argc, char* argv[])
{
	int n = 0;
	while (std::cin>>n, n) {
		std::cout << (B[n>>5]&(1<<(n&0x1f))) << std::endl;
	}
}