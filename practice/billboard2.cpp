#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("billboard.in", "r", stdin);freopen("billboard.out", "w", stdout);
	int a, b, c, d, e, f, g, h, w,x,y,z; cin >> a >> b >> c >> d >> e >> f >> g >> h>>w>>x>>y>>z;
	cout<<(abs(a-c) * abs(b-d)) + (abs(g-e) * abs(h-f)) -(max(min(c,y)-max(a,w),0) * max(min(z,d) - max(b,x), 0) +  max(min(g,y)-max(e,w),0) * max(min(z,h) - max(f,x), 0));}