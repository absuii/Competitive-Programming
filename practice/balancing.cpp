// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int up(int y, vector<pair<int,int>> cord){
	int up=0; int down=0;
	for(int i=0; i<cord.size(); i++){
		if(cord[i].second>y){
			up++;
		} else{
			down++;
		}
	}
	if(down>up){
		return -2;
	} if(up>down){
		return 2; //debug if needed by swapping
	}else{
		return 0;
	}
}

int side(int x, vector<pair<int,int>> cord){
	int right=0; // ++
	int left=0;// --
	for(int i=0; i<cord.size(); i++){
		if(cord[i].first>x){
			right++;
		}else{
			left++;
		}
	}
	if(left>right){
		return -2;
	}else if(right>left){
		return 2;
	}else{
		return 0;
	}
}
int search(int x, int y, vector<pair<int,int>> cord){
	int tr=0;
	int tl=0;
	int bl=0; int br=0;
	for(int i=0; i<cord.size();i++){
		if(cord[i].first > x && cord[i].second>y){
			tr++;
		} else if(cord[i].first > x && cord[i].second<y){
			br++;
		} else if(cord[i].first <x && cord[i].second>y){
			tl++;
		} else if(cord[i].first<x && cord[i].second<y){
			bl++;
		}
	}
	return max({tr,br,tl,bl});
}

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	int n,b; cin>>n>>b;
	vector<pair<int,int>> cord;
	int ans=101;
	for(int i=0; i<n; i++){
		int x,y; cin>>x>>y;
		pair<int, int> temp = {x,y};
		cord.push_back(temp);
	}
	int x=0; int y=0;
	for(int i = 0; i<b+1; i++){
		y+= up(y,cord);
		ans=min(ans,search(x,y,cord));
		x+= side(x,cord);
		ans=min(ans,search(x,y,cord));
		
		
	}

cout<<ans;
}
