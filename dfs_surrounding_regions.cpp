#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <thread>

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

class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){

            if(i <0 or i> m-1 or j<0 or j>n-1 or board[i][j] != 'O') return;
            board[i][j] = 'p';

            dfs(board, i+1,j,m,n);
            dfs(board, i-1,j, m,n);
            dfs(board, i, j+1,m,n);
            dfs(board, i, j-1,m,n);
 
    } 

    void solve(vector<vector<char>>& board) {
        int m = board.size(); int n = board[0].size();

        for(int i=0; i<m; i++){ dfs(board, i, 0, m, n); dfs(board, i,n-1,m,n);};
    
        for(int j=0; j<n; j++){ dfs(board, 0,j,m,n); dfs(board, m-1,j,m,n);};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'p') { cout << "change p"; board[i][j] = 'O';}
            }
        }
    }
};

int main(){

    Solution* obj;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    
    obj->solve(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++)
            cout << board[i][j] << " ";
    }
}