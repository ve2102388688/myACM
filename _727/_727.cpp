#include <bits/stdc++.h>

using namespace std;


// 运算符优先级 括号的优先级定义成最低的
map<char, int> priority = { {'+',1}, {'-',1}, {'*',2}, {'/',2}, {'(',0}, {')', 0} };

// 定义小于等于为false
bool isLessPriority(char previous, char next) {
	return  priority[previous] <= priority[next];
}

string toPostfix(string previous) {
	// 操作符与操作数
	stack<char> op, num;

	for (auto c: previous) {
		if (isdigit(c)) {
			num.push(c);
			continue;
		}

		// 左括号直接压栈，右括号需要弹出
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

	// 中缀表达式处理结束后，直接op全部压入num中
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
	cin.ignore(1024, '\n');		// 忽略空格和换行

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