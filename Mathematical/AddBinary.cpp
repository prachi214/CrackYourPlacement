class Solution {
public:
    string addBinary(string a, string b) {

        // for storing binary sum
string result= "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                //  -'0' because given a[i] char ko integer m convert kiya, for performing arithmetic operation
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 2;
                            //  +'0' because given   integer ko char  m convert kiya, bcs result char m store krna h
              result += (sum % 2) + '0'; 
        }
        
    reverse(result.begin(), result.end());
        return result; 
    }
};