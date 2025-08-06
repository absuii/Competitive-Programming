#include <bits/stdc++.h>
using namespace std;
int start = 0; int last = 0;
int dcount = 0;
int ans = INT_MAX;
int distinct;
void check(){
     if(dcount == distinct){
        ans = min(abs(start-last), ans);
    }
}
int main() {
	int n; cin>>n;
    string word; cin>>word;
    map<char, int> amountTemp;
    for(int i=0; i<n; i++){
        amountTemp[word[i]]++;
    }
    distinct = amountTemp.size();
    map<char, int> counted;

    while(start < n && last < n+1){
        if(counted[word[start]] > 1){
            counted[word[start]]--;
            start++;
        }else{
            if(counted[word[last]] == 0){
                dcount++;
            }
            counted[word[last]]++;
            last++;
        }
        check(); 
    }
    cout<<ans;
}