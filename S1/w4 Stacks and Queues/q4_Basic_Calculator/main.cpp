// https://leetcode.com/problems/implement-queue-using-stacks/
// Memory: O(n)
// Time
// push: O(1)
// peek: O(n)
// pop: O(n)
// empty: O(1)
class MyQueue {
 public:
  // stack: LastIn FirstOut
  // queue: FirstIn FirstOut

  std::stack<int> stk;
  std::stack<int> rev_stk;
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stk.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ret = peek();
    rev_stk.pop();
    return ret;
  }

  /** Get the front element. */
  int peek() {
    // reverse stk to get front element
    if (rev_stk.empty()) {
      while (!stk.empty()) {
        rev_stk.push(stk.top());
        stk.pop();
      }
    }
    return rev_stk.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return rev_stk.empty() && stk.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
