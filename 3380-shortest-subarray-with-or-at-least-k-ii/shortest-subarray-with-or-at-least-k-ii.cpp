class Solution {
public:
    int minimumSubarrayLength(vector<int>& numbers, int threshold) {
        vector<int> bitCount(32, 0);
        int left = 0, right = 0, minLength = INT_MAX;
        while (right < numbers.size()) {
            updateBitCount(bitCount, numbers[right], 1);
            while (left <= right && calculateBitwiseValue(bitCount) >= threshold) {
                minLength = min(minLength, right - left + 1);
                updateBitCount(bitCount, numbers[left], -1);
                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    void updateBitCount(vector<int>& bitCount, int number, int delta) {
        for (int bit = 0; bit < 32; bit++) {
            if ((number >> bit) & 1) {
                bitCount[bit] += delta;
            }
        }
    }  

    int calculateBitwiseValue(const vector<int>& bitCount) {
        int bitwiseValue = 0;
        for (int bit = 0; bit < 32; bit++) {
            if (bitCount[bit] > 0) {
                bitwiseValue |= (1 << bit);
            }
        }
        return bitwiseValue;
    }   
};