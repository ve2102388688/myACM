#include <bits/stdc++.h>


using namespace std;

int main(int argc, char* argv[])
{
	// 将输入与输出解除绑定，提高cin的输入效率
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

	int cases = 0;
	vector<int> dna(10);

	cin >> cases;
	for (size_t i = 1; i <= cases; i++) {
		if (i > 1) cout << '\n';
		for (size_t j = 0; j < 10; j++) {
			cin >> dna[j];
		}

		// 由于假象最左边、最右边有两个0，总计42个
		vector<int> current(42, 0), next(42, 0);
		current[20] = 1;							// 中间位置初始化为1

		for (size_t j = 1; j <= 50; j++) {
			for (size_t k = 1; k <= 40; k++) {
				if (current[k] == 0) cout << ' ';
				else if (current[k] == 1) cout << '.';
				else if (current[k] == 2) cout << 'x';
				else cout << 'W';

				next[k] = dna[current[k - 1] + current[k] + current[k + 1]];
			}
			cout << '\n';

			current.assign(next.begin(), next.end());			// 开启下一次迭代
			fill(next.begin(), next.end(), 0);					// 用0填充next
		}
	}


	return 0;
}
