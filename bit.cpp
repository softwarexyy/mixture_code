/*
***** 进制转换 *****
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x;			//需要转换的数
	int y;			//进制数
	cin >> x >> y;
	vector<int> rslt;
	rslt.clear();
	
	while (x > y) {
		int temp = x % y;
		x = x/y;
		rslt.push_back(temp);
	}
	rslt.push_back(x);

	cout << "result: " ;
	for (vector<int>::reverse_iterator it = rslt.rbegin(); it != rslt.rend(); it++) {
		cout << *it ;
	}

	cout << endl << "Press 'q' to quit..." << endl;

	while (true) {	//屏幕停留
		if (getchar() == 'q')
			break;
	}

	return 0;
}
