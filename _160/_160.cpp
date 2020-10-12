#include <bits/stdc++.h>

// 前100内的质数只有25个
int prime[25] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
	53,59,61,67,71,73,79,83,89,97
};


int main(int argc, char* argv[])
{
	int n;
	while (std::cin>>n, n) {
		std::cout << std::right << std::setw(3) << n << "! =";
		/// 统计2-n每个数的分解情况
		int counter[25] = { 0 };
		for (size_t i = 2; i <= n ; i++) {
			int m = i;
			while (m > 1) {
				for (size_t j = 0; j < 25; j++) {
					if (m % prime[j] == 0) {
						counter[j]++;
						m = m / prime[j];
					}
				}
			}
		}

		// 题意，第一行只有15个
		int last = 0;
		for (last = 24; last >= 0 ; --last) {
			if (counter[last] != 0)
				break;
		}

		int first = 0;
		int minPoint = std::min(14, last);
		while(first <= minPoint) {
			std::cout<< std::right << std::setw(3) << counter[first++] ;
		}
		if((first <= last))
			std::cout << std::endl << std::string(6, ' ');
		while (first <= last) {
			std::cout << std::right << std::setw(3) << counter[first++];
		}
		std::cout << std::endl;
	}

	return 0;
}