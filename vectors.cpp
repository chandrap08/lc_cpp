#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    std::vector<int> v{ 3, 1, 4,5,6,7,8,9 };
 
    auto it = v.end();
    auto pv = std::prev(it, 3);
    std::cout << *pv << next(pv) <<  '\n';
 
    it = v.begin();
    pv = std::prev(it, -3);
    std::cout << *pv << '\n';
}