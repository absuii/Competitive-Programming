#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<char> cows(n);
	vector<int> range(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	for(int i=0; i<n; i++){
		cin>>range[i];
		range[i]--;
	}
	pair<int,int> h_range = {1000000,0};
	pair<int,int> g_range = {1000000,0};
	vector<int> h_followers;
	vector<int> g_followers;
	for(int i=0; i<n; i++){
		if(cows[i] == 'H'){
			h_range.first = min(h_range.first, i);
			h_range.second = max(h_range.second,i);
		}else{
			g_range.first = min(g_range.first, i);
			g_range.second = max(g_range.second,i);
		}
	}
	vector<int> h_leaders;
	vector<int> g_leaders; // pos
	for(int i=0; i<n; i++){
				if(cows[i] == 'H'){
			if(i<=h_range.first && range[i] >= h_range.second){
				h_leaders.push_back(i);
			}else{
				h_followers.push_back(i);
			}
		}
		if(cows[i] == 'G'){
			if(i<=g_range.first && range[i] >= g_range.second){
				g_leaders.push_back(i);
			}else{
				g_followers.push_back(i);
			}
		}

	}
	int ans = (int) (h_leaders.size() * g_leaders.size());
	for(int i=0; i<g_leaders.size(); i++){
		for(int j=0; j<h_followers.size(); j++){
			if(h_followers[j] <= g_leaders[i] && range[h_followers[j]] >= g_leaders[i]){
				ans++;
			}
		}
	}
	for(int i=0; i<h_leaders.size(); i++){
		for(int j=0; j<g_followers.size(); j++){
			if(g_followers[j] <= h_leaders[i] && range[g_followers[j]] >= h_leaders[i]){
				ans++;
			}
		}
	}
	cout<<ans;
}
