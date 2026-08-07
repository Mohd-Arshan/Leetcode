class Solution {
    typedef long long ll;
private:
    // return the minimun next string of given length and Number(required)
    string getRemainingString(ll required,int len){
        string str;

        //start from 9 to 2(highest to lowest)
        for(int digit = 9; digit >=2; digit--){
            while(required%digit == 0){
                str.push_back(char(digit + '0'));
                required /= digit;
            }
        }

        while(str.size() < len){
            str.push_back('1');
        }

        //reverse for minimun number
        reverse(str.begin(),str.end());

        return str;
    }
public:
    string smallestNumber(string num, long long t) {
        int n = num.size();
        ll temp = t;

        //check given t is valid or not
        // t must be in form of (2^a * 3^b * 5^c * 7^d)
        for(int primeFact:{2,3,5,7}){
            while(temp%primeFact == 0){
                temp /= primeFact;
            }
        }

        //Invalid t
        if(temp != 1) return "-1";

        //storing remaining Factor based on length
        vector<ll> remFactor(n+1,t);
        for(int i=0; i<n; i++){
            int digit = num[i] -'0';

            //break in case of zero
            if(digit == 0) break;
            remFactor[i+1] = remFactor[i]/gcd(remFactor[i],(ll)digit);
        }

        //return if current num is form of x*(2^a * 3^b * 5^c * 7^d)
        if(remFactor[n] == 1) return num;

        //finding the zeroth position
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if(zeroPos != -1) zeroIdx = zeroPos;

        for(int i = zeroIdx; i>=0; i--){

            ll required = remFactor[i];
            int freeSlot = n - 1 - i;

            //start from low to hight
            for(int digit = (num[i]-'0')+1; digit<=9; digit++){
                ll furReq = required/ gcd(required,digit);
                string req = getRemainingString(furReq,freeSlot);

                //if req size is same as freeSlot then we got it answer
                if(req.size() == freeSlot) return num.substr(0,i)+char(digit+'0')+req;
            }
        }

        //Didnt find the answer in range of n
        return getRemainingString(t,n+1);
    }
};