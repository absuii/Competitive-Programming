#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("paint.in", "r", stdin);freopen("paint.out","w", stdout);
	int n,m; cin>>n>>m; int a,b, ans=0; cin>>a>>b;
	vector<int> line(101);
	for(int i=n;i<m; i++){line[i]=1;}
	for(int i=a; i<b; i++){line[i]=1;}
	for(int i=0; i<101; i++){if(line[i]!=0){ans++;}}
	cout<<ans;}