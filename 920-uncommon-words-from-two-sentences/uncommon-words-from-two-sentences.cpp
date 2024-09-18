class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        string buffer = s1 + ' ' + s2;
        string word;
        int j;
        int result_size;
        bool indicator;
        stringstream stream(buffer);
        while (stream >> word) {
            result.push_back(word);
        }

        result_size = result.size();
        for (int i = 0; i < result_size; i++) {
            indicator = false;
            for (j = i + 1; j < result_size; j++) {
                if (result[j] == result[i]) {
                    result.erase(result.begin() + j);
                    j--;
                    result_size = result.size();
                    indicator = true;
                }
            }
            if (indicator) {
                result.erase(result.begin() + i);
                result_size = result.size();
                i--;
            }
        }
        return result;
    }
};
