class Solution {
public:

    bool alpha(char c){
        if((tolower(c)>='a' && tolower(c)<='z') || (c>='0' && c<='9')){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        while(left<=right){
            if(!alpha(s[left])){
                left++;
                continue;
            }
            if(!alpha(s[right])){
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])){
                return 0;
            }
            left++;
            right--;

        }
        return 1;
       
    }
};