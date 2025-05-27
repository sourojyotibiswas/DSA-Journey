class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for(int &it: nums){
            pq.push(it);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();

        return pq.top();
    }
};