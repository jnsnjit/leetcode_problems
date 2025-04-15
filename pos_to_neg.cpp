#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class badSolution {
public:
    int reverse(int x) {
        //find out "length" of string//
        //need to save sign state//
        bool neg = false;
        if(x<0){neg=true;}
        int digP = floor(log10(abs(x))) + 1; //10->2,100->3...//
        cout<<digP<<endl;

        vector<int> temp;
        int itemp = x;
        //turn int into temp arr//
        for(int i = 1;i<=digP;i++){
            //mod will harvest the dig in the place//
            temp.push_back((abs(itemp) % static_cast<int>(pow(10,i)))/pow(10,i-1)); 
            itemp = itemp - abs(itemp) % static_cast<int>(pow(10,i));
            //cool hack, take num + 0 and it move to correct ascii value!//
        }
        //atp, number is backwards with sign state saved, convert back to int
        int r = 0;
        for(int s = 0;s<temp.size();s++){
            r = r + temp.at(s) * static_cast<int>(pow(10,digP-1));
            digP--;
        }
        //close, just need to put back sign
        if(neg){
            return (r - 2*r);
        }else{
            return r;
        }
    }
};
/* literally frick me, doesnt work for numbers when flipped break the int size cap */
/* GOOD ANSWER THAT STOPS OVERFLOW AND IS BETTER */
class goodSolution {
    public:
        int reverse(int x) {
            int ans = 0; // Initialize the reversed number to 0
            while (x != 0) {
                int digit = x % 10; // Get the last digit of x
                
                // Check for overflow/underflow before updating ans
                if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                    return 0; // Return 0 if reversing x would cause overflow/underflow
                }
                
                ans = ans * 10 + digit; // Append the digit to the reversed number
                x = x / 10; // Remove the last digit from x
            }
            return ans; // Return the reversed number
        }
};

int main(){
    badSolution b = badSolution();
    goodSolution g = goodSolution();

    cout << b.reverse(1534236469) << endl; //will overflow and create a bad answer
    cout << g.reverse(1534236469) << endl; //catches overflow, and returns zero instead
}
    