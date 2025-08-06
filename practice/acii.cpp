//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;cin >> n >> m;
    vector<int> cows(100);
    for(int o=0;o<100;o++){cows.push_back(0);}
    vector<int> cost(m);
    vector<int> cool(m);
    vector<vector<int>> ac(m);  
    int size = 0;
    for (int q = 0; q < n; q++) {
    int a,b,c; cin>>a>>b>>c;
    for(int w=a; w<b+1; w++){cows[w-1] = c;}    }
    for(int e=0; e<m; e++){
        int a, b; cin>>a>>b>>cool[e]>>cost[e];
        for(int r=a; r<b+1; r++){ac[e].push_back(r-1);}
    }
    int ans = accumulate(cost.begin(), cost.end(), 0);
    for(int i=0; i<(1<<m); i++){
        vector<int> subset;
        vector<int> line;
        for(int loop=0;loop<100;loop++){line.push_back(0);}
        for(int j = 0; j<m; j++){
            if(i&(1<<j)){subset.push_back(j);}
        }
        for(int x=0; x<subset.size(); x++){
            for(int y = ac[subset[x]].front(); y<ac[subset[x]].back() + 1; y++){
                line[y]+=cool[subset[x]];
            }
        }
        int count=0;
        for(int z=0; z<100; z++){
            if(cows[z] > line[z]){
                count++;
            }
        }
        int sum=0;
        if(count==0){
            for(int v=0; v<subset.size(); v++){
                sum+=cost[subset[v]];
                
            }
         
            ans=min(ans,sum);
        }

    }
    
    cout<<ans;
    }