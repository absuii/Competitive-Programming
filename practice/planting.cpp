#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int n; cin>>n;
	vector<int> field(n);
	for(int i=1; i<n; i++){
		int a,b; cin>>a>>b;
		field[a-1]++;
		field[b-1]++;
	}
	cout<<*max_element(field.begin(), field.end())+1;
}
