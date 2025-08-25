class Solution {
public:
    double myPow(double x, long n) {
        double res=1.00;
    
        if(n<0){
            x=1/x;
            n=-n;
        }
        while(n>0){
            if(n&1){
                res*=x;
            }
            x*=x;
            n=n>>1;
        }
        return res;
    }
};