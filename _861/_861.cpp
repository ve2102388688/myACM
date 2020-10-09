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
//		// ÿ������0
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
	bool legal_move;	// �Ϸ�����λ�õı�ǡ�

	// ���ڷ�������˵����Ҫ����ÿһ��λ�ã���Ϊ����������ûʺ�ʱһ��ֻ�ܷ���
	// һ���������ֻ���Ǳȵ�ǰ���λ�ñ�Ǵ��λ�ã������ظ�������ɡ���Ϊ��֤
	// �˺�һλ�õ���ı�Ŵ���ǰһλ����ı�ţ��ʿ��ԴӾ�������ŵ����λ��
	// ��ʼ�����ɷ������λ�ã��������Լ�����������
	int start = 0;
	if (c)
		start = bishops[c - 1];

	*ncandidates = 0;
	for (int p = start; p < n * n; p++)
	{
		legal_move = true;

		// �ѷ�����ĶԽ����ϲ��ܷ��á���Ҫ����ѷ�����ĶԽ��ߡ�
		// �����������������˳�ѭ����
		for (int j = 0; j < c; j++)
			if (abs(bishops[j] / n - p / n) ==
				abs(bishops[j] % n - p % n))
			{
				legal_move = false;
				break;
			}

		// ����λ�úϷ�����ӵ���ѡ���С�
		if (legal_move == true)
			candidates[(*ncandidates)++] = p;
	}
}

// ����Ѱ�����п��ܵķ�����
void backtracking(int bishops[], int c, int n, int k)
{
	if (c == k)
		solution_count++;
	else
	{
		int ncandidates;
		int candidates[MAXN * MAXN];

		// ������ѡ����
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
	// �����������Ͻǵ�һ������Ϊ��ɫ���ӡ�
	long long white[9];
	long long black[9];

	// �õ�ÿһ�а�ɫ���ӵ���Ŀ������������С�������С�
	for (int i = 1; i <= n; i++)
		white[i] = ((i % 2) ? i : white[i - 1]);
	// �õ�ÿһ�к�ɫ���ӵ���Ŀ������������С�������С�
	for (int i = 1; i <= n - 1; i++)
		black[i] = ((i % 2) ? (i + 1) : black[i - 1]);

	// �洢ǰ i �з��� j ����ķ�������ɫ���Ӻͺ�ɫ���ӵķ��÷������ֱ���㡣
	// ��Ϊ������� 8 * 8 �����̣�������ܷ��������ĿΪ 14 ����	
	long long white_solutions[9][15] = { {0} };
	long long black_solutions[9][15] = { {0} };
	// ��ʼ���߽�������
	for (int i = 0; i <= n; i++)
		white_solutions[i][0] = 1;
	for (int j = 1; j <= k; j++)
		white_solutions[0][j] = 0;
	// ���ݵ��ƹ�ʽ�����ɫ���ӷ��÷�������
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k && j <= i; j++)
			white_solutions[i][j] =
			white_solutions[i - 1][j] +
			white_solutions[i - 1][j - 1] * (white[i] - j + 1);
	// ��ʼ���߽�������
	for (int i = 0; i <= n - 1; i++)
		black_solutions[i][0] = 1;
	for (int j = 1; j <= k; j++)
		black_solutions[0][j] = 0;
	// ���ݵ��ƹ�ʽ�����ɫ���ӷ��÷�������
	for (int i = 1; i <= n - 1; i++)
		for (int j = 1; j <= k && j <= i; j++)
			black_solutions[i][j] =
			black_solutions[i - 1][j] +
			black_solutions[i - 1][j - 1] * (black[i] - j + 1);

	// ͳ���ܵķ��÷����������ݳ˷�ԭ��ͼӷ�ԭ���ܵķ��������� n * n ������
	// n �а�ɫ���ӷ��� 0 ����ķ������� n - 1 �к�ɫ���ӷ��� k ����ķ�������
	// ���� n �а�ɫ���ӷ��� 1 ����ķ������� n - 1 �к�ɫ���ӷ��� k - 1 ��
	// ��ķ����������� n �а�ɫ���ӷ��� 2 ����ķ������� n - 1 �к�ɫ���ӷ�
	// �� k - 2 ����ķ�����......
	long long total = 0;
	for (int i = 0; i <= k; i++)
		total += white_solutions[n][i] * black_solutions[n - 1][k - i];
	return total;
}

long long little_bishops(int n, int k)
{
	// ������������Ľ⡣
	// k == 0���������ϲ�������ֻ��һ�ַ�����
	if (k == 0)
		return 1LL;

	// ������Ϊ 1 * 1 ʱ�����ֻ�ܷ��÷��� 1 ����
	if (n == 1)
		return k;

	// �� n >= 2 ʱ���ɷ�����֪�����ֻ�ܷ��� 2 * (n - 1) ����
	// ������ 2 * (n - 1) ʱ�޽⡣
	if (k > 2 * (n - 1))
		return 0LL;

	// һ������Ľ⡣
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