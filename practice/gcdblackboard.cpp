#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    int n;
    cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    vector<int> prefix(n+1, 0);
    vector<int> suffix(n+1, 0);


    for(int i = 1; i <= n; i++){
        prefix[i] = gcd(prefix[i-1], cows[i-1]);
    }


    for(int i = n-1; i >= 0; i--){
        suffix[i] = gcd(suffix[i+1], cows[i]);
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = max(ans, gcd(prefix[i], suffix[i+1]));
    }

    cout << ans << endl;
    return 0;
}
