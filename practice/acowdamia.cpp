#include <bits/stdc++.h>
using namespace std;

bool p(vector<int>& papers, int l, int k, int mid){
    int total = l * k;
    int ans = 0;
    for(int i = 0; i<papers.size(); i++){
        if(papers[i] >= mid){
            ans++;
        }else{
            if(abs(papers[i] - mid) <= k && total >= abs(papers[i] - mid)){
                total -= abs(papers[i]-mid);
                ans++;
            }
        }
    }
    return ans >= mid;

}
int main() {
	int n, k, l; cin>>n>>k>>l;
    vector<int> papers(n);
    for(int i=0; i<n; i++){
        cin>>papers[i];
    }
    sort(papers.rbegin(), papers.rend());
    int low = 0; int high = 1e9;
    int mid = (high - low)/2 + low;
    int c=100;
    int ans = 1;
    while(c--){
        mid = (high - low)/2 + low;
        if (p(papers, l, k, mid)){
            low = mid;
            ans = mid;
        }else{
            
            high = mid;
        }
    }
    cout<<mid<<endl;
}
