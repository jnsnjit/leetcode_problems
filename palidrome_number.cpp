#include <cmath>
#include <climits>

class Solution {
    public:
        bool isPalindrome(int x) {
            //solution using reverse num count iter
            //neg cant be pali
            if(x<0){
                return false;
            }
            int reverse = 0;
            int tempx = x;
    
            //must check overflow :kill_me:
            while(tempx>0){
                if(reverse < INT_MAX/10){
                    reverse = (reverse * 10) + (tempx%10);
                    tempx = tempx/10;
                }else{
                    return false;
                }
            }
    
            return reverse == x;
        }
    };