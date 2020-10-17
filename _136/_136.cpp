#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) 
{
	int factor[3] = { 2,3,5 };
	set<long long int> uglyNumer;
	priority_queue<long long int, vector<long long int>, greater<long long int>> candiates;		// 递增的优先级队列

	candiates.push(1);
	for (size_t i = 1; i <= 1500; i++) {
		long long int top;
		do {
			top = candiates.top();
			candiates.pop();
		} while (uglyNumer.count(top) > 0);
		uglyNumer.insert(top);					// top 其实是最小值
		for (size_t j = 0; j < 3; j++) {
			long long int next = top * factor[j];
			if (uglyNumer.count(next) == 0)				
				candiates.push(next);
		}

		if (i == 1500) {
			cout << "The 1500'th ugly number is " << top << "." << endl;
			break;
		}
	}

	return 0;
}