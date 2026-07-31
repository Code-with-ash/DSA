class Solution {
    struct Data {
        int start;
        int end;
        int pos;
    };
    static bool cmp(Data a, Data b) {
        if (a.end == b.end)
            return a.start < b.start;
        return a.end < b.end;
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (intervals.empty())
            return 0;
        vector<Data> Numbers;
        for (int i = 0; i < n; i++) {
            Numbers.push_back({intervals[i][0], intervals[i][1], i});
        }
        // sorting
        sort(Numbers.begin(), Numbers.end(), cmp);

        // now we go to end , and find the counter
        int counter = 1;
        int lastEnd = Numbers[0].end; // last end
        for (int i = 1; i < Numbers.size(); i++) {
            int start = Numbers[i].start;
            int end = Numbers[i].end;
            if (start >= lastEnd) {
                counter++;
                lastEnd = end;
            }
        }
        return n - counter;
    }
};