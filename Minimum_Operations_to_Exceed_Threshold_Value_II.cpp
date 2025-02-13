//WITH VECTOR--- 674/675 test case passed
// precession issue
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
         int operations = 0;

        while(nums.size()>1 && nums[0]<k){
          int x = nums[0];
          int y = nums[1];

          nums.erase(nums.begin(),nums.begin()+2);

          long long newElement = (long long) min(x, y) * 2 + max(x, y);

          auto pos = lower_bound(nums.begin(), nums.end(),newElement);
          nums.insert(pos,newElement);

          operations++;

        }

        return operations;
    }
};


//USING PRIORITY QUEUE
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int operations = 0;

        while (pq.size() > 1 && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            long long newElement = x * 2 + y;
            pq.push(newElement);
            operations++;
        }

        return operations;
    }
};