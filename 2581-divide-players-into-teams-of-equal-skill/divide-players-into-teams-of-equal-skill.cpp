class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long tot_chem = 0;
        int target_sum = skill[0] + skill[skill.size() - 1];
        int n = skill.size();
        
        for (int i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - 1 - i] != target_sum) {
                return -1;
            }
            tot_chem += (long long)skill[i] * skill[n - 1 - i];
        }
        
        return tot_chem;
    }
};