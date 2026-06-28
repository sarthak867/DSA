class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sz = arr.size();
        if(arr[0]>=sz) return sz;
        arr[0]=1;
        for(int i=1; i<sz;i++){
            if(arr[i]>arr[i-1]+1) arr[i]=arr[i-1]+1;
        }
        return arr[sz-1];
    }
};