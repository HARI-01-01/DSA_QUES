class Solution {
public:
    vector<int> gcdValues(vector<int>& arr, vector<long long>& qu) {
        int maxVal = *max_element(arr.begin(),arr.end());
        vector<int> freq(maxVal+1);
        for(int val:arr){
            freq[val]++;
        }
        vector<int> divCnt(maxVal+1);
        for(int i=1;i<=maxVal;i++){
            for(int j=i;j<=maxVal;j+=i){
                divCnt[i]+=freq[j];
            }
        }

        vector<long long> gcdPair(maxVal+1);
        for(int i=maxVal;i>=1;i--){
            long long cnt = divCnt[i];
            gcdPair[i]=cnt*(cnt-1)/2;
            for(int j=i*2;j<=maxVal;j+=i){
                gcdPair[i]-=gcdPair[j];
            }
        }
        vector<long long> pre(maxVal+1);
        for(int i=1;i<=maxVal;i++){
            pre[i]=pre[i-1]+gcdPair[i];
        }
        vector<int> ans;
        for(long long q:qu){
            int str = 1;
            int end = maxVal;
            while(str<end){
                int mid = str + (end-str)/2;
                if(pre[mid]>q){
                    end = mid;
                }else{
                    str = mid+1;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};