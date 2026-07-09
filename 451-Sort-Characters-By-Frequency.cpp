class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for(char &c:s){
            mpp[c]++;
        }
        vector<pair<int,char>>vec;
        for(auto it:mpp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.rbegin(),vec.rend());     //rbegin,rend do decreasing order sorting
        string result;
        for(auto &it:vec){
            int freq=it.first;
            char ch=it.second;
            for(int i=0;i<freq;i++){
                result+=ch;
            }
        }
        return result;
        
    }
};
//first create a map then make a vector showing freq of each and then makeit in the form of string