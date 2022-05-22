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

    void dfs(vector<vector<char>> &grid, int i, int j, int rows, int cols){
        if(i>=rows || j>=cols || grid[i][j] != '1') return;
        grid[i][j] = '2';

        dfs(grid, i-1,j,rows,cols);
        dfs(grid, i+1,j,rows,cols);
        dfs(grid, i,j-1,rows,cols);
        dfs(grid, i,j+1,rows, cols);

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,rows,cols);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid{{'1','1','1','1','0'},
                              {'1','1','0','1','0'},
                              {'1','1','0','0','0'},
                              {'0','0','0','0','0'}};
    Solution obj;
    cout << obj.numIslands(grid);
}