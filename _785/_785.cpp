#include <bits/stdc++.h>

const int MAX_ROWS = 35;
const int MAX_COLS = 85;

// ������
int offset[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
// Ŀ�����
char matrix[MAX_ROWS][MAX_COLS];


/// �������
void dfs(int row, int col, char old, char replaced) {
	// �Ƚ��з�Χ���
	if ((row>=0&&row<MAX_ROWS&&col>=0&&col<MAX_COLS) && matrix[row][col]==old) {
		matrix[row][col] = replaced;
		for (size_t i = 0; i < 4; i++) {
			dfs(row + offset[i][0], col + offset[i][1], old, replaced);
		}
	}
}


int main(int argc, char* argv[])
{
	std::string line;
	while (getline(std::cin, line)) {
		memset(matrix, ' ', sizeof(matrix));
		int rows = 0;									// ��ǰ�������		
		char wall = 0;									// �����ַ�

		do {
			for (size_t i = 0; i < line.length(); i++) {
				matrix[rows][i] = line[i];
				if (wall == 0 && line[i] != ' ')
					wall = line[i];
			}
			matrix[rows++][line.length()] = '\n';		// �ַ�����β��ʶ��

		} while (getline(std::cin, line) , line.front()!='_');

		// Ѱ�ҼȲ��������ַ���Ҳ���ǿ��ַ����Դ˽��з���
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < MAX_COLS; j++) {
				if (matrix[i][j] == '\n') break;
				if (matrix[i][j] != wall && matrix[i][j] != ' ') {
					// Ϊ�˺��滻
					char replaced = matrix[i][j];
					matrix[i][j] = ' ';			
					dfs(i, j, ' ', replaced);
				}
			}
		}

		// ���
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < MAX_COLS; j++) {
				std::cout << matrix[i][j];
				if (matrix[i][j] == '\n')
					break;
			}
		}
		std::cout << line << std::endl;			// ������һ��

	}


	return 0;
}
