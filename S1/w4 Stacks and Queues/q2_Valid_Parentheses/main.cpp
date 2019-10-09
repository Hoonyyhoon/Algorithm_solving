// https://leetcode.com/problems/min-stack/

class MinStack {
  /** initialize your data structure here. */
 private:
  // store value with val min
  std::stack<std::pair<int, int>> val_min_p;

 public:
  void push(int x) {
    std::pair<int, int> inst;
    if (val_min_p.empty()) {
      inst = std::make_pair(x, x);
    } else {
      int cur_min = val_min_p.top().second;
      if (cur_min < x)
        inst = std::make_pair(x, cur_min);
      else
        inst = std::make_pair(x, x);
    }
    val_min_p.push(inst);
  }

  void pop() { val_min_p.pop(); }

  int top() { return val_min_p.top().first; }

  int getMin() { return val_min_p.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
