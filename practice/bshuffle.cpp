#include <bits/stdc++.h>
using namespace std;

vector<int> adj;
int succ(int current) {
    return adj[current];
}
int c = 0;
void dfs(vector<bool>& visited, int current){
    if(visited[current]){
        return;
    }
    visited[current] = true;
    c++;
    dfs(visited,adj[current]);

}
int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
	int n; cin>>n;
    adj.resize(n);
    for(int i=0; i<n; i++){
        cin>>adj[i]; adj[i]--;
    }
    vector<bool> visited(n);
    vector<int> cycles;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int one =succ(i); int two = succ(succ(i));
            while(one!=two){
                visited[one] = true;
                visited[two] = true;
                one = succ(one);
                two = succ(succ(two));
            }
            cycles.push_back(one);
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    for(int i=0; i<cycles.size(); i++){
        dfs(visited,cycles[i]);
    }
    cout<<c<<endl;

}
