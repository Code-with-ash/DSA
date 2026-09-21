class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i = 0 ; i < n ; i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int first = pq.top();
            pq.pop();
            if(pq.empty()) return first ;
            int second = pq.top();
            pq.pop();
            pq.push(abs(first-second));
        }
        return 0 ;
    }
};