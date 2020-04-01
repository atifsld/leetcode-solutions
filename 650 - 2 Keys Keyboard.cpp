/*
    https://leetcode.com/problems/2-keys-keyboard/
*/
class Solution {
public:
    int minSteps(int n) {
        int result = 0;
        int k = 2;
        while (n > 1) {
            while (n % k == 0) {
                result += k;
                n /= k;
            }
            k++;
        }
        return result;
    }
};