#include <bits/stdc++.h>


using namespace std;

int main(int argc, char* argv[])
{
	// ���������������󶨣����cin������Ч��
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

	int cases = 0;
	vector<int> dna(10);

	cin >> cases;
	for (size_t i = 1; i <= cases; i++) {
		if (i > 1) cout << '\n';
		for (size_t j = 0; j < 10; j++) {
			cin >> dna[j];
		}

		// ���ڼ�������ߡ����ұ�������0���ܼ�42��
		vector<int> current(42, 0), next(42, 0);
		current[20] = 1;							// �м�λ�ó�ʼ��Ϊ1

		for (size_t j = 1; j <= 50; j++) {
			for (size_t k = 1; k <= 40; k++) {
				if (current[k] == 0) cout << ' ';
				else if (current[k] == 1) cout << '.';
				else if (current[k] == 2) cout << 'x';
				else cout << 'W';

				next[k] = dna[current[k - 1] + current[k] + current[k + 1]];
			}
			cout << '\n';

			current.assign(next.begin(), next.end());			// ������һ�ε���
			fill(next.begin(), next.end(), 0);					// ��0���next
		}
	}


	return 0;
}
