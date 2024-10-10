class Solution {
public:
    // This method will check the substring is palindrome or not. 
    // We will compare the low index and high index, if same then we move forward 
    // or else we will exit.
    bool checkPalindrome(const string &s, int low, int high){
        while(low<high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int lenS= s.size();

        // All substring of length 1 are palindrome
        // For now maxLen is 1 which will be get changes in later part.
        // Maxlen will be 1 if there's no palindromic substring found.
        // we will pass start and maxlen to return substr
        int maxLen = 1, start = 0;

        for(int i=0; i<lenS; i++){
            for(int j=i; j<lenS; j++){
                //Check the current substring is palindrome 
                if(checkPalindrome(s, i, j) && (j-i+1) > maxLen ){
                    start = i;
                    maxLen = (j-i+1);
                }
             }
        }
        return s.substr(start, maxLen);
    }
};