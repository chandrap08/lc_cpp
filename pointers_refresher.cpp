#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using str = string;
using pii = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<ll>;

#define F first
#define L last
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) = int(x.size())

int main(){
    int a = 5;
    int* f = &a;
    vector<vector<int>> l;
    vector<int> b = {1,2,3,4,5};
    vector<vector<int>>* ptr;
    ptr = &l;

    ptr->push_back(b);
    ptr->push_back({2,4,6});
    priority_queue<int,vector<int>,greater<int>> q;

    for(auto i:*ptr){ 
        for(auto j:i){
            q.push(j);
        }
    }

    while(!q.empty()){
        cout << q.top() << endl; q.pop();
    }
    cout << "new tests" << endl;
    int *p1;
    int g[10] = {1,2,3,4,5};
    p1 = g;
    
    
    for(int i=0; i<5; i++){
        cout << *p1 << endl; p1++;
    }

  

}