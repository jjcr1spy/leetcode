#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        /*
        priority_queue<int> pq;
        queue<vector<int>> q;
        vector<int> counter(26);

        for (int i = 0; i < tasks.size(); ++i)
            ++counter[tasks[i] - 'A'];
        for (int i = 0; i < 26; ++i){
            if (counter[i])
                pq.push(counter[i]);
        }

        int time = 0;
        while (!q.empty() || !pq.empty()){
            ++time;
            if (!pq.empty()){
                if (pq.top() - 1)
                    q.push({pq.top() - 1, time + n});
                pq.pop();
            }
            if (!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
         
        faster than above, my logic:
        there will be max_freq number of "windows" and in each window there will be
        n + 1 tasks since we must wait n + 1 time to start the same task again but at the window
        we dont need to include any extra idles after all tasks are up so we need to account for this

        */

        int max_freq=0, sz=tasks.size(), num_maxFreq=0;
        int freq[26]={0};

        for(char c: tasks){
            int f=++freq[c-'A'];

            if (f == max_freq) num_maxFreq++;
            else if (f > max_freq){
                max_freq = f;
                num_maxFreq = 1;
            }
        }
       
        int time= (max_freq-1) * (n+1) + num_maxFreq;
        return std::max(time, sz);
    }
};