/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts;
        vector<int> ends;
        for (int i = 0; i < n; i++) {
            Interval itv = intervals[i];
            starts.push_back(itv.start);
            ends.push_back(itv.end);
        }
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        int end_time = 0;
        for (int i = 0; i < n; i++) {
            if (starts[i] < end_time) {
                return false;
            } else {
                end_time = ends[i];
            }
        }
        return true;
    }
};
