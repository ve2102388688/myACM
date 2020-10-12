#include <bits/stdc++.h>

const int MAX_N = 8;				// ��������8*8
const int MAX_K = 2*(MAX_N-1);		// �����Է��õ���2*(n-1)


long long otherSituation(int n, int k) {
	/// STEP 1
	/// ������Ͻ��ǰ���
	/// ������������,����8*8��������ת45�㣬�������8�����壩+7�����壩�ľ��棬��15��
	long long write[MAX_N+1] = { 0 };
	long long black[MAX_N+1] = { 0 };
	
	/// ��Ȼ������Ŀ�Ⱥ�ɫ����Ŀ��1
	// �����壬������ʽ������x 1 3 3 5 5 7 7
	for (size_t i = 1; i <= n; i++) {
		write[i] = (i % 2) ? i : write[i - 1];
	}
	// �����壬������ʽ������x 2 2 4 4 6 6 8
	for (size_t i = 1; i < n; i++) {
		black[i] = (i % 2) ? (i+1) : black[i - 1];
	}
	

	/// STEP 2
	/// �ֱ�������Ͱ���ķ�����Ŀ����ά������һ��һ�б�ʾ�߽�����-��Ȼt[i][0]=1,t[0][j]=0
	long long write_solution[MAX_N+1][MAX_K+1] = { {0} };
	long long black_solution[MAX_N+1][MAX_K+1] = { {0} };

	// ��ʼ���߽�����������������
	for (size_t i = 0; i <= n; i++) {
		write_solution[i][0] = 1;
	}
	for (size_t j = 1; j <= k; j++) {
		write_solution[0][j] = 0;
	}
	for (size_t i = 1; i <= n; i++) {
		for (size_t j = 1; j <= k && j<=i; j++) {
			write_solution[i][j] = write_solution[i - 1][j] + write_solution[i - 1][j - 1] * (write[i] - (j - 1));
		}
	}

	// ��ʼ���߽�����������������
	for (size_t i = 0; i <= n-1; i++) {
		black_solution[i][0] = 1;
	}
	for (size_t j = 1; j <= k; j++) {
		black_solution[0][j] = 0;
	}
	for (size_t i = 1; i <= n-1; i++) {
		for (size_t j = 1; j <= k && j<=i; j++) {
			black_solution[i][j] = black_solution[i - 1][j] + black_solution[i - 1][j - 1] * (black[i] - (j - 1));
		}
	}


	/// STEP3
	long long total = 0;
	for (size_t i = 0; i <= k; i++) {
		total += write_solution[n][i] * black_solution[n - 1][k - i];
	}

	return total;
}


long long algorithm(int n, int k) {
	// ����߽�������1-û�����̣�2-û����
	if (n == 1)
		return k;
	if (k == 0)
		return 1LL;
	// �������Ŀ����2(n-1)�������аڷŷ���
	if (k > 2 * (n - 1))
		return 0LL;

	return otherSituation(n, k);
}


int main(int argc, char* argv[]) 
{
	int n, k;

	while (std::cin>>n>>k, n||k) {
		std::cout << algorithm(n, k) << std::endl;;
	}

	return 0;
}

