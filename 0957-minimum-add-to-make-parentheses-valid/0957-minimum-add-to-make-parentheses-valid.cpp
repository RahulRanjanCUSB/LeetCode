class Solution {
public:
    int minAddToMakeValid(string S) {

// Approach 1:
//     int open_needed = 0;
//     int close_needed = 0;

//     for (char c : S) {
//         if (c == '(') {
//             open_needed++;
//         } else if (c == ')') {
//             if (open_needed > 0) {
//                 open_needed--;
//             } else {
//                 close_needed++;
//             }
//         }
//     }
//     return open_needed + close_needed;

// Approach 2: Using Stack Data Structure
    stack<char> stk;
    int result=0;

    if(S.empty())
        return 0;
    for(char c: S){
        if(c == '('){
            stk.push(c);
        }
        else if(c == ')'){
            if(stk.empty()){
                result++;
            }
            else{
                stk.pop();
            }
        }
    }
    return result+stk.size();
}




};