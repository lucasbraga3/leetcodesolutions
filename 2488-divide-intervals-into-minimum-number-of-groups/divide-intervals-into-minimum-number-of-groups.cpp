class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> inic, fim;
        for (const auto& inter : intervals) {
            inic.push_back(inter[0]);
            fim.push_back(inter[1]);
        }
        sort(inic.begin(), inic.end());
        sort(fim.begin(), fim.end());
        int f = 0, grupos = 0;
        for (int s : inic) {
            if (s > fim[f]) {
                f++;
            } else {
                grupos++;
            }
        }

        return grupos;
    }
};