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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, m = matrix.size(), n = matrix[0].size(), hi = m;
        vector<int> rowStart;
        vector<int> targetRow;
        bool foundRow = false, found = false;

        for(auto& i:matrix){
            rowStart.push_back(i[0]);
        }

        for(int i=0; i<=m-1; i++){
            if(rowStart[i] <= target && target <= matrix[i][n-1] )
            {
                targetRow = matrix[i];      
                foundRow = true;  
            }
        }
        if(!foundRow){
            return false;
        }else{     
            // we now know that range is lo.
            lo = 0, hi = n;
            while(lo <= hi){
                int mid = lo + (hi-lo)/2;
                if(target == targetRow[mid]){
                    return true;
                }else if(target < targetRow[mid]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
        }
        return found;
    }
};

int main(){
    
    //vector<vector<int>> nums({{1,3,5,7},{10,11,16,20},{23,30,34,60}});
    vector<vector<int>> nums({{1}});
    Solution obj;
    int target = 1;
    bool result = obj.searchMatrix(nums,target);
    if(result){
        cout << "found";
    }else{
        cout << "not found";
    }


}