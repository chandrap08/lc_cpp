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


class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), count = 0;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int,int>> q; 

        if(grid[0][0] == 0){
            q.push({0,0});
            visited[0][0] = true;
        }

        while(!q.empty()){
            int l = q.size();
            count++;
            while(l--){
                pair<int,int> v = q.front();
                q.pop();
                int i = v.first; int j = v.second;
                if(i==n-1 and j==n-1) return count;
                for(int k=i-1; k<=i+1; k++){
                    for(int l=j-1; l<=j+1; l++){
                        if(k >= 0 and l >= 0 and k < n and l < n and grid[k][l] == 0 and !visited[k][l]){
                            q.push({k,l});
                            visited[k][l] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1},{1,0}};
    Solution* obj;
    int res = obj->shortestPathBinaryMatrix(grid);
    cout << res;
}


