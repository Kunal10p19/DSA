class Solution {
public:
    
    int getNext(int curr, vector<int>& nums){
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue; 
            
            int slow = i, fast = i;
            
            int iniDir = nums[i];
            
            while(true){
                
                if(nums[slow] * iniDir <= 0) break;
                
                
                if(nums[fast] * iniDir <= 0) break;
                
                
                int nextFast = getNext(fast, nums);
                if(nums[nextFast] * iniDir <= 0) break;
                
                
                slow = getNext(slow, nums);
                fast = getNext(nextFast, nums);
                
                // Cycle detected
                if(slow == fast){
                    // Check for self-loop (cycle length must be > 1)
                    if(slow == getNext(slow, nums)) break;
                    else return true;
                } 
            }
            
            // Optimization: Mark the path as 0 (visited/invalid)
            // We only need to mark nodes that follow the same direction
            int curr = i;
            while(nums[curr] * iniDir > 0){
                int next = getNext(curr, nums);
                nums[curr] = 0;
                curr = next;
            }
        }
        return false;
    }
};