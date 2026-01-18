// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cow(ll pos, ll time){
    ll position = pos;
    ll t = time;
    while(t>=0){
        if(position == t){
            return t;
        }
        ll mid = t/2;
        if(position>mid){
            return position;
        }
        if(position==mid){
            position = 0;
        }else{
            //bs ts
            ll low = 1;
            ll high = t;
            ll k = 0;
            while(high>=low){
                ll m = low + (high-low)/2;
                if(position+m -1 < (t-(m-1))/2){
                    k = m;
                    low = m+1;
                }else{
                    high = m-1;
                }
            }
            position+= k;
            t-= k;
            continue;
        }
        t--;
    }
}

ll posi(ll current, ll target){
    ll pos = current;
    ll present=current;
    while(target>present){
        ll next = present+ 1;
        ll m = next / 2;
        if (pos == 0) {
            pos = m;
            present = next;
            continue;
        }
        if(pos > m){
            ll t= 2LL * pos;
            if(t>target){
                present = target;
                break;
            }
            present = t-1;
            continue;
        }
        pos -= 1;
        present = next;
        if (pos > 0) {
            ll steps = min(pos,target-present);
            pos -= steps;
            present += steps;
        }
    }

    return pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll q; cin>>q;
    while(q-- ){
        ll type, pos, time; cin>>type>>pos>>time;
        if(type == 1){
            //what pos for cow at t
            cout<<posi(pos, time);
        }else{
            //what cow at pos after t
            cout<<cow(pos, time);
        }
        cout<<endl;
    }
        return 0;

}