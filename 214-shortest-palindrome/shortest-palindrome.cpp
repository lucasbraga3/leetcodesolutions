class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        
        // Create the KMP table
        vector<int> kmp(temp.size(), 0);
        for (int i = 1; i < temp.size(); i++) {
            int j = kmp[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = kmp[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            kmp[i] = j;
        }
        
        // The longest palindromic prefix of `s` is given by `kmp[temp.size() - 1]`
        int pal_len = kmp[temp.size() - 1];
        return rev_s.substr(0, s.size() - pal_len) + s;
    }
};
