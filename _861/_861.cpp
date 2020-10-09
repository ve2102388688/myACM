//#include <bits/stdc++.h>
//
//const int MAX_N = 8;
//const int MAX_K = MAX_N*MAX_N;
//
//long t[MAX_N][MAX_K] = { 0 };
//
//
//long algorithm(long t[][MAX_K], int i, int j, int num) {
//	if (j == 0)
//		t[i][j] = 1;
//	if (i == 0)
//		t[i][j] = 0;
//
//	return algorithm(t, i - 1, j, num) + algorithm(t, i - 1, j-1, num) * (num -(j - 1));
//}
//
//
//int main(int argc, char* argv[]) 
//{
//	int n = 0, k = 0;
//
//	while ((std::cin>>n>>k, n&&k)) {
//		// 每次清零0
//		memset(t, 0, sizeof(t));
//
//		std::cout << algorithm(t, n, k, n) << std::endl;;
//	}
//	std::cout << std::endl;;
//
//	return 0;
//}


#include <bits/stdc++.h>

using namespace std;

#define MAXN 8

long long solution_count;

void construct_candidates(int bishops[], int c, int n, int candidates[],
	int* ncandidates)
{
	bool legal_move;	// 合法放置位置的标记。

	// 对于放置象来说，需要考虑每一个位置，因为不存在像放置皇后时一行只能放置
	// 一个的情况。只考虑比当前象的位置标记大的位置，避免重复解的生成。因为保证
	// 了后一位置的象的编号大于前一位置象的编号，故可以从具有最大编号的象的位置
	// 开始搜索可放置象的位置，这样可以减少搜索量。
	int start = 0;
	if (c)
		start = bishops[c - 1];

	*ncandidates = 0;
	for (int p = start; p < n * n; p++)
	{
		legal_move = true;

		// 已放置象的对角线上不能放置。需要检查已放置象的对角线。
		// 不满足条件，尽早退出循环。
		for (int j = 0; j < c; j++)
			if (abs(bishops[j] / n - p / n) ==
				abs(bishops[j] % n - p % n))
			{
				legal_move = false;
				break;
			}

		// 若该位置合法，添加到候选集中。
		if (legal_move == true)
			candidates[(*ncandidates)++] = p;
	}
}

// 回溯寻找所有可能的方案。
void backtracking(int bishops[], int c, int n, int k)
{
	if (c == k)
		solution_count++;
	else
	{
		int ncandidates;
		int candidates[MAXN * MAXN];

		// 构建候选集。
		construct_candidates(bishops, c, n, candidates, &ncandidates);

		for (int i = 0; i < ncandidates; i++)
		{
			bishops[c] = candidates[i];
			backtracking(bishops, c + 1, n, k);
		}
	}
}

long long little_bishops_by_backtracking(int n, int k)
{
	int bishops[2 * (MAXN - 1) + 1];

	solution_count = 0;
	backtracking(bishops, 0, n, k);

	return solution_count;
}

long long little_bishops_by_combinatorics(int n, int k)
{
	// 假设棋盘左上角第一个格子为白色格子。
	long long white[9];
	long long black[9];

	// 得到每一列白色格子的数目。格子数按从小到大排列。
	for (int i = 1; i <= n; i++)
		white[i] = ((i % 2) ? i : white[i - 1]);
	// 得到每一列黑色格子的数目。格子数按从小到大排列。
	for (int i = 1; i <= n - 1; i++)
		black[i] = ((i % 2) ? (i + 1) : black[i - 1]);

	// 存储前 i 列放置 j 个象的方法。白色格子和黑色格子的放置方法数分别计算。
	// 因为给定最多 8 * 8 的棋盘，则最大能放置象的数目为 14 个。	
	long long white_solutions[9][15] = { {0} };
	long long black_solutions[9][15] = { {0} };
	// 初始化边界条件。
	for (int i = 0; i <= n; i++)
		white_solutions[i][0] = 1;
	for (int j = 1; j <= k; j++)
		white_solutions[0][j] = 0;
	// 根据递推公式计算白色格子放置方案数。
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k && j <= i; j++)
			white_solutions[i][j] =
			white_solutions[i - 1][j] +
			white_solutions[i - 1][j - 1] * (white[i] - j + 1);
	// 初始化边界条件。
	for (int i = 0; i <= n - 1; i++)
		black_solutions[i][0] = 1;
	for (int j = 1; j <= k; j++)
		black_solutions[0][j] = 0;
	// 根据递推公式计算黑色格子放置方案数。
	for (int i = 1; i <= n - 1; i++)
		for (int j = 1; j <= k && j <= i; j++)
			black_solutions[i][j] =
			black_solutions[i - 1][j] +
			black_solutions[i - 1][j - 1] * (black[i] - j + 1);

	// 统计总的放置方案数。根据乘法原理和加法原理，总的方案数等于 n * n 的棋盘
	// n 行白色格子放置 0 个象的方案乘以 n - 1 行黑色格子放置 k 个象的方案数，
	// 加上 n 行白色格子放置 1 个象的方案乘以 n - 1 行黑色格子放置 k - 1 个
	// 象的方案数，加上 n 行白色格子放置 2 个象的方案乘以 n - 1 行黑色格子放
	// 置 k - 2 个象的方案数......
	long long total = 0;
	for (int i = 0; i <= k; i++)
		total += white_solutions[n][i] * black_solutions[n - 1][k - i];
	return total;
}

long long little_bishops(int n, int k)
{
	// 处理特殊情况的解。
	// k == 0，即棋盘上不放置象，只有一种方法。
	if (k == 0)
		return 1LL;

	// 当棋盘为 1 * 1 时，最多只能放置放置 1 个象。
	if (n == 1)
		return k;

	// 当 n >= 2 时，由分析可知，最多只能放置 2 * (n - 1) 个象。
	// 当大于 2 * (n - 1) 时无解。
	if (k > 2 * (n - 1))
		return 0LL;

	// 一般情况的解。
	//return little_bishops_by_backtracking(n, k);
	return little_bishops_by_combinatorics(n, k);
}

int main(int ac, char* av[])
{
	int n, k;

	while (cin >> n >> k, n || k)
		cout << little_bishops(n, k) << endl;

	return 0;
}