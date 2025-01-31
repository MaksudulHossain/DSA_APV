#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        if (r > n - r)  // nCr is symmetric: nCr = nC(n-r)
            r = n - r;

        long long result = 1;
        for (int i = 0; i < r; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<int> n_t = {};
        for (int i = 0; i <= rowIndex; i++)
        {
            n_t.push_back(nCr(rowIndex, i));
        }
        
        return n_t;       
    }

};



