class Solution {
public:
    long long myAtoi(string s) {
        long long temp = 0;
        long long final = 0;
        long long multiplier = 1;
        bool firstnchar = 0;
        bool neg = 0;
        int i = 0;
        for(i; i<s.size();i++){ 
            temp = s[i] - '0';
            if(temp<10 && temp>-1){
                if(final>2147483647){
                    break;
                }
                firstnchar = 1;
                final = final*10;
                final = final + temp;
            }
            else if(firstnchar == 0 && s[i] == '-'){
                neg = 1;
                firstnchar = 1;
            }
             else if(firstnchar == 0 && s[i] == '+'){
                firstnchar = 1;
            }
            else if(firstnchar == 0 && s[i] == ' '){
                
            }
            else{
                break;
            }
        }
        if(neg == 1){
            final = final*-1;
        }
        if(final>2147483647){
            return 2147483647;
        }
        if(final<-2147483648){
            return -2147483648;
        }

        return final;
    }
};