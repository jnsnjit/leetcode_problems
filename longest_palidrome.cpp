#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            string maxP;
            for (int start = 0; start < s.size(); ++start) {
                for (int size = 1; size + start <= s.size(); ++size) {
                    string substr = s.substr(start, size);
                    if (checkPalindrome(substr) && substr.size() > maxP.size()) {
                        maxP = substr;
                    }
                }
            }
            return maxP;
        }

        bool checkPalindrome(string s){
            //regular palidrome checker, recursive
            if(s.size() <= 1){
                return true;
            }else{
                if(s.at(0) == s.at(s.size()-1)){
                    return checkPalindrome(s.substr(1,s.size()-2));
                }else{
                    return false;
                }
            }
        }
    };

int main(){
    Solution s = Solution();
    cout << s.longestPalindrome("babad") << endl;

    return 0;
}