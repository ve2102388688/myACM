#include <bits/stdc++.h>

using namespace std;


// ��������ȼ� ���ŵ����ȼ��������͵�
map<char, int> priority = { {'+',1}, {'-',1}, {'*',2}, {'/',2}, {'(',0}, {')', 0} };

// ����С�ڵ���Ϊfalse
bool isLessPriority(char previous, char next) {
	return  priority[previous] <= priority[next];
}

string toPostfix(string previous) {
	// �������������
	stack<char> op, num;

	for (auto c: previous) {
		if (isdigit(c)) {
			num.push(c);
			continue;
		}

		// ������ֱ��ѹջ����������Ҫ����
		if (c == '(') {
			op.push(c);
			continue;
		}
		if (c == ')') {
			while (!op.empty() && op.top() != '(') {
				num.push(op.top());
				op.pop();
			}
			if (!op.empty())
				op.pop();
			continue;
		}
		
		if (op.empty() || op.top()=='('|| !isLessPriority(c, op.top())) {
			op.push(c);
		} else {
			while (!op.empty() && isLessPriority(c, op.top())) {
				num.push(op.top());
				op.pop();
			}
			op.push(c);
		}
	}

	// ��׺���ʽ���������ֱ��opȫ��ѹ��num��
	while (!op.empty()) {
		num.push(op.top());
		op.pop();
	}

	string posfix;
	while (!num.empty()) {
		posfix = num.top() + posfix;
		num.pop();
	}

	return posfix;
}


int main(int argc, char* argv[]) 
{
	cin.tie(0), cin.tie(0), ios::sync_with_stdio(false);

	int cases = 0;
	cin >> cases;
	cin.ignore(1024, '\n');		// ���Կո�ͻ���

	string line;
	getline(cin, line);

	for (size_t i = 1; i <= cases; i++){
		if(i>1) cout << "\n";

		string previos;
		while (getline(cin, line), line.length() > 0) previos += line;

		cout << toPostfix(previos) << "\n";

	}

	return 0;
}