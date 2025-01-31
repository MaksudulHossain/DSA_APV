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
    vector<int> nth_term(int n) {
        vector<int> n_t = {};
        for (int i = 0; i <= n; i++)
        {
            n_t.push_back(nCr(n, i));
        }
        
        return n_t;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> all_terms;
        // n-th row vector
        for (int i = 0; i < numRows; i++)
        {
            all_terms.push_back(nth_term(i));
        }

        return all_terms;
    }
};



