#include <bits/stdc++.h>
using namespace std;
int minPair(int one, int zero, int n){
    if(one == zero){
        return 0;
    }
    int temp1 = one;
    int temp0 = zero;
    one -= min(temp1,temp0);
    zero -=min(temp1, temp0);
    return max(one,zero)/2;

}
int maxPair(int one, int zero, int n){
    if(zero == one){
        return one;
    }
    return zero/2 + one/2;

}
int main() {
	int t; cin>>t;
    for(int p=0; p<t; p++){
        int n, k; cin>>n>>k;
        string a; cin>>a;
        int zero = 0;
        int one = 0;
        for(int i=0; i<n; i++){
            if(a[i] == '0'){zero++;}
            else{one++;}
        }
        int minimum = minPair(one, zero,n);
        int maximum = maxPair(one, zero,n);
        if(k >= minimum && k<=maximum && (k - minimum) % 2 == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
