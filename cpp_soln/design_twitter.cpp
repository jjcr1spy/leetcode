#include <vector>
#include <unordered_map>
#include <unordered_set>

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(std::make_pair(userId, tweetId));
    }
    
    std::vector<int> getNewsFeed(int userId) {        
        int count = 10;
        std::vector<int> result;
        
        // since postTweet pushes to the back, looping from back gets most recent
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }
            
            int followingId = posts[i].first;
            int tweetId = posts[i].second;
    
            // add to result if they're following them or it's a tweet from themself
            if (following[userId].find(followingId) != following[userId].end() || followingId == userId) {
                result.push_back(tweetId);
                count--;
            }
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    std::unordered_map<int, std::unordered_set<int>> following; // who index id follows
    std::vector<std::pair<int, int>> posts; // posts for index id
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */