#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
    vector<int> numbers(n+1);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        numbers[i+1] = numbers[i] + a;
    }
    /*int ans = INT_MIN;
    for(int i=1; i<n+1; i++){
        for(int j = 1; j<=i; j++){
            int sum = numbers[i] - numbers[j-1];
            ans = max(ans, sum);
        }
    }
    */
    int ans = INT_MIN;
    int back = 1;
    for(int i=1; i<n+1; i++){
        if(numbers[back] < 0){
            back = i;
        }
        ans = max(numbers[i] - numbers[back-1], ans);        
    }
    cout<<ans;
}
