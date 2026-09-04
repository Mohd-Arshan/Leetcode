class Solution {
public:
    int addDigits(int num) {
        /*
          In this we can use 2 approches 
          1st itrative  
          2nd special formual (num - 1)%9 + 1
        */

        return (num-1)%9 + 1;
    }
};