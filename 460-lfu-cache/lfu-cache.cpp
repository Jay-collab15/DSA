class LFUCache {
public:
    //Jay
    struct Node {
        int key, value, freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };
    int capacity;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>> freqMap;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    void updateFreq(list<Node>::iterator it) {
        int key = it->key;
        int val = it->value;
        int freq = it->freq;

        freqMap[freq].erase(it);

        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }
        freqMap[freq + 1].push_front(Node(key, val));
        freqMap[freq + 1].front().freq = freq + 1;
        keyMap[key] = freqMap[freq + 1].begin();
    }
    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;
        auto it = keyMap[key];
        int value = it->value;
        updateFreq(it);
        return value;
    }
    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (keyMap.find(key) != keyMap.end()) {
            auto it = keyMap[key];
            it->value = value;
            updateFreq(it);
            return;
        }
        if (keyMap.size() == capacity) {
            auto &lst = freqMap[minFreq];
            int delKey = lst.back().key;
            keyMap.erase(delKey);
            lst.pop_back();
            if (lst.empty())
                freqMap.erase(minFreq);
        }
        minFreq = 1;
        freqMap[1].push_front(Node(key, value));
        keyMap[key] = freqMap[1].begin();
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */