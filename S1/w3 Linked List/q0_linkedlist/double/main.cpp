// linked list implementation
// 1) each node contains data and pointer(single: next, double next, prev)
// 2) Insert data, Delete data

#include <iostream>
#include <vector> // for test cases

template <typename T>
class dNode {
  private:
	T data;

  public:
	dNode* next;
	dNode* prev;

	dNode(){
	  next = nullptr;
	  prev = nullptr;
	}

	dNode(T data_){
	  data = data_;
	  next = nullptr;
	  prev = nullptr;
	}

	void putData(T data_){
	  data = data_;
	}

	T getData(){
	  return data;
	}
};

template <typename T>
class dLinkedList {
  private:
	dNode<T> *head;
	dNode<T> *tail;
	int count = 0;
  public:
	dLinkedList() { 
	  // dummy head
	  head = new dNode<T>();
	  tail = head;
	  tail->prev = head;
	  count = 0;
	}

	~dLinkedList() {
	  dNode<T> *ptr = head;
	  while(ptr!=nullptr) {
		dNode<T> *n_ptr = ptr->next;
		delete ptr;
		ptr = n_ptr;
	  }
	}


	void insertData_end(T data_) {
	  dNode<T> *newNode = new dNode<T>(data_);
	  tail->next = newNode;	//	current tail next: newNode
	  newNode->prev = tail;	//	newNode prev: current tail
	  newNode->next = head;	//	newNode next: current head
	  head->prev = newNode;	//	head prev: newNode
	  tail = newNode;	//newNode == tail
	  count++;
	}

	void insertData_front(T data_) {
	  // head is dummy --> regard head->next as head
	  dNode<T> *newNode = new dNode<T>(data_);
	  newNode->prev = head;
	  newNode->next = head->next;
	  head->next->prev = newNode;
	  head->next = newNode;
	  count++;
	}

	// delete data that firstly find
	bool deleteData(T data_) {
	  dNode<T> *cur = head->next;
	  dNode<T> *prev_cur = head;

	  //iterate
	  while(cur!=nullptr){
		if(cur->getData()==data_) {
		  cur->next->prev = prev_cur;
		  prev_cur->next = cur->next;
		  delete cur;
		  count--;
		  return true;
		}
		prev_cur = cur;
		cur = cur->next;
	  }
	  return false;
	}

	void visualize();
};

template <typename T>
void dLinkedList<T>::visualize() {
  // very first
  dNode<T> *cur = this->head->next;
  std::cout<<"[ "<<cur->getData()<<" -> ";
  int data_size = this->count;
  while(data_size>1){
	cur = cur->next;
	std::cout<<cur->getData()<<" -> ";
	data_size--;
  }
  std::cout<<" ]"<<std::endl;
}

int main() {
  //test
  std::vector<double> data = {5, 10, 2, 1, 100, 40, 70};
  std::vector<double> f_data = {4,3,2,1};
  dLinkedList<double> test;
  for(auto &iter: data) test.insertData_end(iter);
  for(auto &iter:f_data) test.insertData_front(iter);

  test.visualize();
  test.deleteData(5);

  test.visualize();
  test.deleteData(1);

  test.visualize();
  test.deleteData(70);
  test.visualize();
}
