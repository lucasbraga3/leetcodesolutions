class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mapa;
        for(int num : nums) {
            mapa[num]++;
        }
        for(auto& entry : mapa) {
            if(entry.second > 1) {
                return entry.first;
             }
        }
        return -1;
    }
};
