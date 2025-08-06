#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int t; cin>>t;
    for(int l=0; l<t; l++){
        int n, k; cin>>n>>k;
        string cows; cin>>cows;
        vector<char> ans(n, '.');
        
        bool h = false; bool g = false;
        int gaura = -32222222; int haura = -32222222;
        int answer= 0;
        
        for(int i=0; i<n; i++){
             if(g){ // detect letter
                gaura++;
            }
            if(h){ // detect letter
                haura++;
            }
            if(cows[i] = 'H' && (!h)){ // new
                haura = 0;
                h = true;
            }else if(cows[i] = 'G' && (!g)){
                gaura = 0;
                g = true;
            }           
            if(gaura == k){ // add letter
                ans[i] = 'G';
                //answer++;
            }
            if(haura == k){ // add letter
                //answer++;
                ans[i] = 'H';
            }
            
            if(haura == 2*k+1){ // end aura
                h=false;
                haura = -32222222;
            }
            if(gaura == 2*k + 1){ // end aura
                g = false;
                gaura = -32222222;
            }
            
        }
        if(gaura != -32222222 && gaura < k){
            if(ans[n-1]=='.'){
                ans[n-1] = 'G';
                //answer++;
            } else if(ans[n-2]=='.'){
                ans[n-2] = 'G';
                //answer++;
            }
        }
        if(haura != -32222222 && haura < k){
            if(ans[n-1]=='.'){
                ans[n-1] = 'H';
                //answer++;
            }else if(ans[n-2]=='.'){
                ans[n-2] = 'H';
                //answer++;
            }
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!='.'){
                answer++;
            }
        }
        cout<<answer<<"\n";
            for(int i=0; i< ans.size(); i++){
            cout<<ans[i];
        }
        cout<<endl;
        }
        
    }