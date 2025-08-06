#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c; cin >> a >> b >> c;
	long long m; cin>>m;
    vector<long long> usb;
    vector<long long> ps;
    for(long long i=0; i<m; i++){
        long long s; cin>>s; string f; cin>>f;
        if(f=="USB"){
            usb.push_back(s);
        }else{
            ps.push_back(s);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());
    vector<bool> usbCheck(usb.size());
    vector<bool> psCheck(ps.size());
    long long equip=0; long long cost=0;
    long long p=0; long long u=0;
    for(long long i=0; i< usb.size(); i++){
        if(u!=a){
            cost+=usb[i];
            u++;
            equip++;
            usbCheck[i] = true;
        }
    }
    for(long long i=0; i< ps.size(); i++){
        if(p!=b){
            cost+=ps[i];
            p++;
            equip++;
            psCheck[i] = true;
        }
    }
    vector<long long> n;
    for(long long i=0; i<usb.size(); i++){
        if(!usbCheck[i]){
            n.push_back(usb[i]);
        }
    }
    for(long long i=0; i<ps.size(); i++){
        if(!psCheck[i]){
            n.push_back(ps[i]);
        }
    }
    sort(n.begin(), n.end());
    for(long long i=0; i<n.size(); i++){
        if(c > 0){
            c--;
            equip++;
            cost+=n[i];
        }
    }

    cout<<equip<<" "<<cost;
}
