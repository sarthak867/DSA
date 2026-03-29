class EventManager {
private:
    struct Entry {
        int id;
        int pr;

        Entry(int i, int p) : id(i), pr(p) {}
    };

    struct Compare {
        bool operator()(const Entry& a, const Entry& b) const {
            if (a.pr == b.pr) {
                return a.id > b.id;   // smaller id first
            }
            return a.pr < b.pr;       // higher priority first
        }
    };

    priority_queue<Entry, vector<Entry>, Compare> heap;
    unordered_map<int, int> latest;

public:
    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            int id = e[0];
            int pr = e[1];
            latest[id] = pr;
            heap.emplace(id, pr);
        }
    }

    void updatePriority(int eventId, int newPriority) {
        // overwrite latest priority
        latest[eventId] = newPriority;

        // push new state (lazy update)
        heap.emplace(eventId, newPriority);
    }

    int pollHighest() {
        while (!heap.empty()) {
            Entry cur = heap.top();
            heap.pop();

            // check if this entry is still valid
            if (latest.count(cur.id) && latest[cur.id] == cur.pr) {
                latest.erase(cur.id);
                return cur.id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */