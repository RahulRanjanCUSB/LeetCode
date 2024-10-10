// There are multiple approach to solve this problem
// Naive Approach: By checking all the possible substr is palindrome
// Dynamic Programming : Time Complexity O(n2), Space Complexity O(n2) 
//                  A nested traversal is needed.
//                  A matrix of size N*N is needed to store the table.
// Expansion from centre: Two Pointer approach
// Use two pointers, low and hi, for the left and right end of the current palindromic substring being found. 
// Then checks if the characters at str[low] and str[hi] are the same. 
//      If they are, it expands the substring to the left and right by decrementing low and incrementing hi. 
//      It continues this process until the characters at str[low] and str[hi] are unequal or until the indices are in bounds.
// If the length of the current palindromic substring becomes greater than the maximum length, it updates the maximum length.
// 

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
// Naive Approach
// Time complexity: O(N3). Three nested loops are needed to find the longest palindromic substring in this approach.
// Auxiliary complexity: O(1). As no extra space is needed.

    // string longestPalindrome(string s) {
    //     int lenS= s.size();

    //     // All substring of length 1 are palindrome
    //     // For now maxLen is 1 which will be get changes in later part.
    //     // Maxlen will be 1 if there's no palindromic substring found.
    //     // we will pass start and maxlen to return substr
    //     int maxLen = 1, start = 0;

    //     for(int i=0; i<lenS; i++){
    //         for(int j=i; j<lenS; j++){
    //             //Check the current substring is palindrome 
    //             if(checkPalindrome(s, i, j) && (j-i+1) > maxLen ){
    //                 start = i;
    //                 maxLen = (j-i+1);
    //             }
    //          }
    //     }
    //     return s.substr(start, maxLen);
    // }

    string longestPalindrome(string s) {
        int lenS = s.length();
        if(lenS == 0) return "";

        int start=0, maxLen = 1;

        for(int i=0; i<lenS; i++){
            for(int j=0; j<=1; j++){
                int low = i;
                int high = i+j;

                while(low >=0 && high < lenS && s[low] == s[high]){
                    int currLen = high-low+1;
                    if(currLen > maxLen){
                        start = low;
                        maxLen = currLen;
                    }
                    low--;
                    high++;
                }
            }
        }
        return s.substr(start, maxLen);
    }

};