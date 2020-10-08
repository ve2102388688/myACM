#include <bits/stdc++.h>

const int MAX_SIZE = 100;

/// ����Ƿ񳬹���Ե
inline bool	range_checking(int x, int y, int cols, int rows) {
	return (x>=0&&x< cols) && (y >= 0 && y < rows);
}

void algorithm(char matrix[][MAX_SIZE], int cols, int rows) {
	// 8����λ
	int offset[8][2] = { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };

	for (size_t i = 0; i < cols; i++) {
		for (size_t j = 0; j < rows; j++) {
			if (matrix[i][j] == '*')
				std::cout << '*';
			else {
				int mines = 0;
				for (size_t k = 0; k < 8; ++k) {
					int m = i + offset[k][0];
					int n = j + offset[k][1];
					// ��Ե����ͳ�Ƶ��׵�����
					if (range_checking(m, n, cols, rows) && matrix[m][n] == '*')
						mines++;
				}
				std::cout << mines;
			}
		}
		std::cout << std::endl;
	}
}


int main(int argc, char* argv[])
{
	char matrix[MAX_SIZE][MAX_SIZE];
	int cols, rows, num = 0;


	/// readData ������Ϊ0 0�˳�
	while ((std::cin>> cols >>rows, cols &&rows)) {
		// ÿ������0
		memset(matrix, 0, sizeof(matrix));

		for (size_t i = 0; i < cols; i++) {
			for (size_t j = 0; j < rows; j++) {
				std::cin >> matrix[i][j];
			}
		}

		/// ���
		if(num>0)
			std::cout << std::endl;
		num++;

		std::cout << "Field #" << num << ":" << std::endl;
		algorithm(matrix, cols, rows);
	}
	return 0;
}
