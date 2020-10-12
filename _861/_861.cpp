#include <bits/stdc++.h>

const int MAX_N = 8;				// 最大的棋盘8*8
const int MAX_K = 2*(MAX_N-1);		// 最多可以放置的象2*(n-1)


long long otherSituation(int n, int k) {
	/// STEP 1
	/// 如果左上角是白棋
	/// 考虑最大的棋盘,当把8*8的棋盘旋转45°，将会出现8（白棋）+7（黑棋）的局面，共15行
	long long write[MAX_N+1] = { 0 };
	long long black[MAX_N+1] = { 0 };
	
	/// 显然白棋数目比黑色棋数目多1
	// 填充白棋，递增方式，最终x 1 3 3 5 5 7 7
	for (size_t i = 1; i <= n; i++) {
		write[i] = (i % 2) ? i : write[i - 1];
	}
	// 填充黑棋，递增方式，最终x 2 2 4 4 6 6 8
	for (size_t i = 1; i < n; i++) {
		black[i] = (i % 2) ? (i+1) : black[i - 1];
	}
	

	/// STEP 2
	/// 分别计算黑棋和白棋的方案数目，二维数组多加一行一列表示边界条件-显然t[i][0]=1,t[0][j]=0
	long long write_solution[MAX_N+1][MAX_K+1] = { {0} };
	long long black_solution[MAX_N+1][MAX_K+1] = { {0} };

	// 初始化边界条件及白棋解决方案
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

	// 初始化边界条件及黑棋解决方案
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
	// 处理边界条件，1-没有棋盘，2-没有象
	if (n == 1)
		return k;
	if (k == 0)
		return 1LL;
	// 当象的数目大于2(n-1)不可能有摆放方案
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

