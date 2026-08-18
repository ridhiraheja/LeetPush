class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<num;i++){
            if(num%i==0) sum+=i;
        }
        if(num==sum) return true;
        return false;
        
    }
};
// bool checkPerfectNumber(int num){
//     int sum=0;
//     int sq=sqrt(num);
//     for(int i=1;i<=sq;i++){
//         if(num%i==0){
//             sum+=i;
//             if(num/i !=i) sum+=num/i;
//         }
//     }
//     if(sum-num==num) return true;
//     return false;

// }