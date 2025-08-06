#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &i : a) { cin >> i; }

	// stores currently selected numbers
	priority_queue<int, vector<int>, greater<int>> taken;

	for (int i = 0; i < n; ++i) {
		taken.push(a[i]);
		if (i & 1) taken.pop();
	}

	long long ans = 0;
	while (!taken.empty()) {
		ans += taken.top();
		taken.pop();
	}

	cout << ans << endl;
}