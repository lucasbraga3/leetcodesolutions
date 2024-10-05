class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int permval = 0;
        int compval = 0;
        for(int i = 0;i<s1.size();i++){
            permval += s1[i];
        }
        int slice = 0;
        for(int j = 0;j<s2.size();j++){
            slice++;
            compval +=s2[j];
            if(slice == s1.size() and compval == permval){
                bool contains;
                for(int k=0;k<s1.size();k++){
                    for(int i = 0;i<s1.size();i++){
                        contains = false;
                        if(s2[j-i] == s1[k]){
                            contains = true;
                            i = s1.size();
                        }
                        if(i == (s1.size()-1)){
                            contains = false;
                            k = s1.size();
                        }     
                    }
                }
                if(contains == true){
                    return true;
                }
            }
            if(slice == s1.size()){
                slice = 0;
                compval = 0;
                j = j - (s1.size() - 1);
            }
        }
        return false;
    }
};