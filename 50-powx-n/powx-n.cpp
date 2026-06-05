class Solution {
public:
    //Jay
    double myPow(double x, int n) {
        double result=1.0;
        long num=n;;
        if(n<0){
            num=(-1)*num;
        }
        while(num>0)
        {
            if(num%2==1)
            {
                result*=x;
                num-=1;
            }
            else
            {
                x=x*x;
                num/=2;
            }
        }
        if(n<0) return 1/result;
        return result;
    }
};