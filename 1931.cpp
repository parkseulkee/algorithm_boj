#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	vector <pair<int, int>> a;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int s, e;
		cin >> s >> e;
		a.push_back(make_pair(e,s));
	}
	sort(a.begin(), a.end());

	int result = 1;
	int end = a[0].first;
	for (int i = 1;i < n;i++) {
		if (end <= a[i].second) {
			result += 1;
			end = a[i].first;
		}
	}
	cout << result << endl;
	return 0;
}