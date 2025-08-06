#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n; n++;
    while(n--){
        string line; getline(cin, line);
        line = " " + line;bool p = false;
        for(int i=1; i<line.length(); i++){
            if(line[i-1] == ' '){
                cout<<line[i];
                p= true;
            }
        }
        if(p){
            cout<<endl;
        }
    }
    
}
