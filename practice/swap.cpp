#include <bits/stdc++.h>
using namespace std;
vector<int> cows; 
int succ(int i){
    return cows[i];
}
int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
	int n,m,k; cin>>n>>m>>k;
    cows.resize(n);
    for(int i=0; i<n; i++){
        cows[i] = i;
    }
    for(int i=0; i<k; i++){
        int a, b; cin>>a>>b;
        a--;
        b--;
        while (a < b) {
            swap(cows[a], cows[b]);
            a++; b--;
        }
    }
    vector<shared_ptr<vector<int>>> cycles(n);
    vector<int> order(n);
    for(int i=0; i<n; i++){
        if(!cycles[i]){
            cycles[i] = make_shared<vector<int>>();
            cycles[i]->push_back(i);
            int p = succ(i);
            order[i] = 0;
            while(p!=i){
                cycles[i]->push_back(p);
                cycles[p] = cycles[i];
                order[p] = cycles[i]->size()-1;
                p = succ(p);
            }
        }
    }
    vector<int> newPos(n);
    for(int i=0; i<n; i++){
        int len = cycles[i]->size();
        int pos = (order[i] + k) % len; 
        newPos[ (*cycles[i])[pos] ] = i;

    }
    for(int i=0; i<n; i++){
        cout<<newPos[i]+1<<endl;
    }


}
