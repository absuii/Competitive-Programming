#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n,q; cin>>n>>q;
    vector<ll> numbers(n);
    vector<ll> ranges(n+2);
    for(ll i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    for(ll i=0; i<q; i++){
        ll a,b; cin>>a>>b;
        ranges[a]++;
        ranges[b+1]--;
    }
    for(ll i=1; i<ranges.size()-1; i++){
        ranges[i]+=ranges[i-1];
    }
    sort(ranges.begin(), ranges.end());
    ll sum = 0;
    for(ll i=1; i<ranges.size()-1; i++){
        sum+=numbers[i-1] * ranges[i+1];
    }
    cout<<sum;

}

/*#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,q; cin>>n>>q;
    vector<int> numbers(n);
    vector<int> ranges(n+1);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<q; i++){
        int a,b; cin>>a>>b;
        ranges[a]++;
        ranges[b+1]--;
    }
    for(int i=1; i<ranges.size(); i++){
        ranges[i]+=ranges[i-1];
    }
    sort(ranges.begin(), ranges.end());
    int sum = 0;
    for(int i=1; i<ranges.size(); i++){
        sum+=numbers[i-1] * ranges[i];
    }
    cout<<sum;
 */
