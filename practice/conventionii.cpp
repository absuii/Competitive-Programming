#include <bits/stdc++.h>
using namespace std;
#define arrives first.first 
#define t first.second
#define senior second
#define vec vector<pair<pair<int,int>,int>>
#define pi pair<pair<int,int>, int>
struct customComparator {
    bool operator()(const pi& a, const pi& b) {
        return a.senior > b.senior; 
    }
};

int main(){
    int n; cin>>n;
    vec cows(n);
    for(int i=0;i<n;i++){
        cin>>cows[i].arrives>>cows[i].t;
        cows[i].senior = i;
    }
    sort(cows.begin(),cows.end());
    priority_queue<pi, vec, customComparator> waiting;
    int time = 0;
    int answer = INT_MIN;
    int i = 0;
    while(i<n || !waiting.empty()){
        i++;
        if(waiting.empty()){
            time = max(time, cows[i].arrives);
            waiting.push(cows[i]);
            i++;
        }
        int pos = i;
        while(i<n && cows[i].arrives <= time){
            waiting.push(cows[i]);
            i++;
        }

        pi current = waiting.top(); waiting.pop();
        answer = max(answer, time - current.arrives);
        time += current.t;

    }
    cout<<answer;


}