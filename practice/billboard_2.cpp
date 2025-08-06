// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	int a,b,c,d; cin>>a>>b>>c>>d;
	int w,x,y,z; cin>>w>>x>>y>>z;
	int intersectionX = max(min(a,w) - max(c,y), 0);
	int intersectionY = max(min(b,x) - max(d,z), 0); //acwy
	int width=max(c,a) - min(c,a) - intersectionX;
	int height=max(b,d) - min(b,d) - intersectionY;
	int answer= width*height;
	cout<<answer;
}
