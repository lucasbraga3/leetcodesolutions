class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mapa;
        for(int i=0;i<nums.size();i++){
            mapa[nums[i]] += 1;
        }
        int ref;
        int temp1 = 0;
        int actual;
        map<int,int>::iterator itr;
        for (itr = mapa.begin();itr != mapa.end();++itr) 
        {   
            if(itr->second>temp1){
            temp1 = itr->second;
            actual = itr->first;
            }
        }
        return actual;
    }
};