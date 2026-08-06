class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> ds;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &it = ds[key];
        if(it.empty()) return "";
        if(it[0].first > timestamp) return "";
        if(it.back().first <= timestamp) return it.back().second;

        int low = 0;
        int high = it.size() - 1;

        while(low<high){
            int mid = low + (high - low + 1)/2;

            if(it[mid].first <= timestamp){
                low = mid;
            }
            else high = mid - 1;
        }

        return it[low].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */