// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool checker(vector<int> list){
	if(list[0] + 1 == list[1] && list[0]+2==list[2]){
		return true;
	}
	return false;
}
int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int a,b,c; cin>>a>>b>>c;
	vector<int> list = {a,b,c};
	sort(list.begin(), list.end());
	if(checker(list) == true){cout<<0<<endl;}
	else if(list[0] + 2 == list[2] || list[1]+2 == list[2] || list[0]+2 == list[1]){cout<<1<<endl;}
	else{cout<<2<<endl;}
	int i=0; 
	i=max(abs(list[1]-list[0]), abs(list[1] - list[2]));
	/*while(checker(list)==false){
		i++;
		
		if(list[1]-list[0] > list[2]-list[1]){
			list[2] = list[0] + 1;
		}else{
			list[0] = list[2] -1;
		}
		sort(list.begin(),list.end());
	}*/
	cout<<i-1;
}
