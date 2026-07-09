class Twitter {
public:
    // Jay
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() { timeStamp = 0; }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        follows[userId].insert(userId);
        for (int followee : follows[userId]) {
            auto& t = tweets[followee];
            for (int i = max(0, (int)t.size() - 10); i < t.size(); i++) {
                pq.push({t[i].first, t[i].second});
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            follows[followerId].erase(followeeId);
    }
};