// https://leetcode.com/problems/task-scheduler
// Time Complexity: O(n)
// Memory Complexity: O(1) (constant size)

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    // store number of task for each tasks
    std::unordered_map<char, int> num_tasks;
    for (auto& iter : tasks) num_tasks[iter]++;

    // sort it as priority queue
    std::priority_queue<int> task_queue;
    for (auto& iter : num_tasks) task_queue.push(iter.second);

    // cycle: the time that certain task can be done again
    int cycle = n + 1;
    int t_total = 0;
    int t_each = 0;

    while (!task_queue.empty()) {
      // within cycle, each task can only be done one time
      std::vector<int> update_queue;
      update_queue.reserve(26);
      t_each = 0;
      for (int i = 0; i < cycle; i++) {
        if (!task_queue.empty()) {
          int task_left = task_queue.top() - 1;
          if (task_left > 0) update_queue.push_back(task_left);
          task_queue.pop();
          t_each++;
        } else
          break;
      }

      // after cycle, update task_queue
      for (auto& iter : update_queue) {
        task_queue.push(iter);
      }

      // determine whether task is all done
      t_total += task_queue.empty() ? t_each : cycle;
    }

    return t_total;
  }
};
