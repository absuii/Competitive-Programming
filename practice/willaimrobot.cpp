#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n; int sum = 0;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }sort(numbers.begin(), numbers.end());
    for(int i=n/2; i<n; i++){
        sum+=numbers[i];
    }
    cout<<sum;
}
