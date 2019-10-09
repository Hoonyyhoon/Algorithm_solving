// https://leetcode.com/problems/time-based-key-value-store/
// Time
// per operation
// set / get
// O(1) / O(log(t)) //t: # of timestamp for element
// set n times / get m times
// O(n) / O(mlog(t))
// Memory
// O(KT)  // K: number of keys T: total number of timestamps

#include <unordered_map>
#include <map>
class TimeMap {
 public:
  /** Initialize your data structure here. */
  std::unordered_map<string, std::map<int, string>> data;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    data[key].insert(std::pair<int, string>(timestamp, value));
  }

  string get(string key, int timestamp) {
    auto elem = data[key].upper_bound(timestamp);
    if (data[key].begin() == elem)
      return "";
    else
      return prev(elem)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
