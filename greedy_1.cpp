#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    int M, a,b,movies = 0;
    vector<pair<ll,ll>> x;
    cin >> M;
    for(int i = 0; i <= M; i++){
        cin >> a >> b;
        x.emplace_back(make_pair(b,a));
    }
    sort(x.begin(),x.end());
    
    int temp = 0;   

    for(int j=0; j<M; j++){
        if(x[j].second >= temp ){
            temp = x[j].first;
            movies++;
        }
    }
    cout << movies << endl;
}