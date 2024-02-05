class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        
        for (int i = 0; i< nums.size(); i++){
            sum = sum - nums[i];
            
            if(leftsum == sum){
                return i;
            }
            leftsum = leftsum + nums[i];
        }
        return -1;
    }
};