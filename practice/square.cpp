#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int a, b, c, d,w,x,y,z;cin>>a>>b>>c>>d>>w>>x>>y>>z;
	int x_length = max({a,c,w,y}) - min({a,c,w,y});
	int y_length = max({b,d,x,z}) - min({b,d,x,z});
	cout<<max(x_length, y_length) * max(x_length, y_length);
}
