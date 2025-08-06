#include <iostream>
#include <string>
using namespace std;
int main(){
    int q; cin>>q;
    for(int l =0; l<q; l++){
        string letters; cin>>letters;
        int n = letters.length();
        int ans = 999999999;
        if (n<3){
            cout<<-1<<endl;
        }else if (n==3){
            if(letters[1] == 'O'){
                if(letters == "MOO"){
                    ans = 0;
                }else if(letters == "OOO"){
                    ans = 1;

                }else if(letters == "MOM"){
                    ans = 1;
                }else if(letters =="OOM"){
                    ans = 2;
                }

            }else{
                ans = -1;
            }
            cout<<ans<<endl;
        }
        else{
            bool mo = false;
            bool oo = false;
            bool moo = false;
            bool o = false;

            for(int i=0; i<n-1; i++){
                bool a = (letters[i] == 'M' && letters[i+1] == 'O' && i+1!=n-1);
                bool b = (letters[i] == 'O' && letters[i+1] == 'O' && i+1!=n-1 && i!=0);
                if(a){mo = true;}
                if(b){oo = true;}
                if(letters[i] == 'O' && i != 0){o = true;}
                if(i!=n-1){if(letters[i] == 'M' && letters[i+1] == 'O' && letters[i+2] == 'O'){moo=true;}}
            }
            
            if(mo){ans = min(ans, n-2);}
            if(oo){ans = min(ans, n-2);}
            if(moo){ans = min(ans, n-3);}
            if(o){ans = min(ans, n-1);}
            if(!mo && !oo && !moo && !o){ans = -1;}
            cout<<ans<<endl;
        }
    }
}
/*-1
-1
-1
-1
-1
-1
-1
1
-1
-1
-1
-1
-1
-1
-1
-1
-1
-1
2
1
-1
0
2
-1
-1
2
-1
-1
-1
-1
-1
-1
-1
1
1
1
-1
-1
-1
-1
-1
-1
-1
-1
-1
-1
-1
2
1
-1
-1
-1
-1
-1
-1
-1
2
-1
-1
-1
-1
-1
-1
-1
1
-1
0
-1
1
-1
-1
-1
-1
-1
-1
1
-1
-1
1
0
-1
1
-1
-1
1
-1
-1
-1
-1
-1
1
-1
-1
2
-1
-1
-1
-1
*/