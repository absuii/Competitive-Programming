#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> cows(n);
        vector<int> rev(n);
        for(int i=0; i<n; i++){
            cin>>cows[i];
            rev[i] = cows[i];
        }
        sort(rev.rbegin(), rev.rend());
        int pos = 0;
        while(rev[pos]==cows[pos] && pos < n){
            pos++;
        }
        if(pos==n){
            for(int i=0; i<n; i++){
                cout<<cows[i];
                if(i!=n-1){
                    cout<<" ";
                }
            }
        }else{
            vector<int> c;
            for(int i=0; i<pos; i++){
                c.push_back(cows[i]);
            }
            c.push_back(rev[pos]);
            bool found = false;
            int ignore = 0;
            for(int i=n-1; i>=0; i--){
                if(cows[i] == rev[pos] && !found){
                    ignore = i;
                    found = true;
                }
            }
            for(int i=pos; i<n; i++){
                if(i!=ignore){
                    c.push_back(cows[i]);
                }
            }

            vector<int> answer;
            vector<int> l(n);
            for(int i=n-1; i>=1; i--){
                l[i] = c[i];
                if(i!=n-1){
                    l[i] = max(l[i], l[i+1]);
                }
            }
            for(int i=0; i<n; i++){
                if(i<=pos){
                    answer.push_back(c[i]);
                }else{
                    if(c[i] == l[i]){
                        answer.push_back(c[i]);
                    }
                }
            }

            for(int i=0; i<answer.size(); i++){
                cout<<answer[i];
                if(i!=answer.size()-1){
                    cout<<" ";
                }
            }

        }
        cout<<endl;
    }
}
