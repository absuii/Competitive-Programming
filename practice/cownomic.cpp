#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> spot(n, vector<char>(n));
    vector<vector<char>> plain(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>spot[n];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>plain[n];
        }
    }

    for(int col1=0; col1<m; col1++){
        for(int col2=col1+1; col2<m; col2++){
            for(int col3=col2+1; col3<m; col3++){
                cout<<col1<<col2<<col3<<endl;
            }
        }
    }
}