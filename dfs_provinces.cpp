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
using vvi = vector<vector<int>>;

#define F first
#define L last
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) = int(x.size())

class Solution {
public:

/*     void dfs(vector<vector<int>> &isConnected, int i, int rows, int cols, vector<bool>& visited){
        
        if(!visited[i]) {
            visited[i] = 1;
            //cout << "city " << i << endl;
            for(int c=0; c<=cols; c++){
                if(!visited[c] && i!=c && isConnected[i][c] == 1){
                    dfs(isConnected, c, rows, cols,visited);
                    return;
                }
            }
        }
    } */

    void dfs(int i, vector<int> adj_list[], vector<bool>& visited){
        visited[i] = true;
        for(auto it:adj_list[i]){
            if(!visited[it])
                dfs(it, adj_list, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size(), cols = isConnected[0].size(), count = 0;
        vector<bool> visited(rows, 0);
        vector<int> adj_list[rows];

/*         for(int i=0; i<rows; i++){
            if(!visited[i]) count++;
            dfs(isConnected, i, rows, cols, visited);
        } */

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(isConnected[i][j] == 1) 
                    adj_list[i].push_back(j);
            }
        }

        for(int i=0; i<rows; i++){
            if(!visited[i]){
                dfs(i, adj_list, visited);
                count++;
            }
        }
        return count;
    }
};

int main(){
    
    vector<vector<int>> grid{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    //vector<vector<int>> grid{{1,1,0},{1,1,0},{0,0,1}};
    Solution obj;
    cout << obj.findCircleNum(grid);
}