class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int product=1;
        int rev=0;
        while(n!=0){
            int digit=n%10;
            sum+=digit;
            product*=digit;
            rev=rev*10+digit;
            n=n/10;

        }
        int result=product-sum;
        return result;
    }
};