#include <bits/stdc++.h>
using namespace std;
// Input: digits = [1,2,3]
// Output: [1,2,4]
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //case 1 vector size 1 and elementis 9, return {1,0}
        if (digits.size()==1 && digits[0]==9)
        {
            return {1,0};
        }
        else if (digits.size()==1 && digits[0]!=9)
        {
            return {digits[0]+1};
        }
        else if (digits.size()>1 && digits[digits.size()-1]!=9)
        {
            digits[digits.size()-1] = digits[digits.size()-1]+1;
            return digits;
        }
        else if (all_of(digits.begin(), digits.end(), [](int x) { return x == 9; }))
        {
            int n = digits.size();  
            vector<int> vec(n+1, 0);  
            
            // Set the first element to 1
            vec[0] = 1;
            return vec;
        }
        else{
            int count=0;
            int idx = digits.size()-1;

            while (digits[idx]==9)
            {
                count++;
                idx--;
            }

            // we have count numbered consecutive 9999s from right
            digits[idx] += 1;
            idx++;
            for (int i = idx; i < digits.size(); i++)
            {
                digits[i] = 0;
            }
            
            return digits;
            
        }
        
        
        
        

    }
};

int main() {
    Solution sol;
    vector<int> digits1 = {1,9,9,9};
    vector<int> result = sol.plusOne(digits1);

    // Print the result
    cout << "Test case 1 result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}