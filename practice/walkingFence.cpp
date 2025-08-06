#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p; cin>>n>>p;
	vector<pair<int,int>> posts(p);
	for(int i=0; i<p; i++){
		cin>>posts[i].first>>posts[i].second;
	}

    vector<pair<int,int>> distance;
    for(int i = 0; i < p; i++){
        int next = (i + 1) % p;
        if(posts[next].second == posts[i].second){
            if(posts[i].first < posts[next].first){
                for(int j = posts[i].first; j <= posts[next].first; j++){
                    distance.push_back({j, posts[i].second});
                }
            } else {
                for(int j = posts[i].first; j >= posts[next].first; j--){
                    distance.push_back({j, posts[i].second});
                }
            }
        } 
        else if(posts[next].first == posts[i].first){
            if(posts[i].second < posts[next].second){
                for(int j = posts[i].second; j <= posts[next].second; j++){
                    distance.push_back({posts[i].first, j});
                }
            } else {
                for(int j = posts[i].second; j >= posts[next].second; j--){
                    distance.push_back({posts[i].first, j});
                }
            }
        }
    }
    vector<pair<int,int>> path;
    for(int i=0; i<distance.size(); i++){
        if(distance[i].first == distance[(i+1) % distance.size()].first && distance[i].second == distance[(i+1) % distance.size()].second){
            
        }else{
            path.push_back(distance[i]);
        }
    }
    map<pair<int,int>, int> cows;
    for(int i=0; i<path.size(); i++){
        cows[path[i]] = i;
    }
    p = (int) cows.size();
    for(int i=0; i<n; i++){
        pair<int, int> start;
        pair<int, int> end;
        cin>>start.first>>start.second>>end.first>>end.second;
        int s = cows[start]; int e = cows[end];
        cout<< min({abs(s-e), abs(s-p) + abs(0 - e), abs(e-p) + abs(0-s)})<<endl;
    }
    
}
