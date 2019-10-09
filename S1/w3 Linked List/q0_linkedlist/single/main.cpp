// linked list implementation
// 1) each node contains data and pointer(single: next, double next, prev)
// 2) Insert data, Delete data

#include <iostream>
#include <vector> // for test cases
template <typename T>
class sNode {
  private:
	T data;

  public:
	sNode* next;

	sNode(){
	  next = nullptr;
	}

	sNode(T data_){
	  data = data_;
	  next = nullptr;
	}

	T getData(){
	  return data;
	}
};

template <typename T>
class sLinkedList {
  private:
	sNode<T> *head;
	sNode<T> *tail;
  public:
	sLinkedList() {
	  // regard head as dummy node
	  head = new sNode<T>();
	  tail = head;
	}

	~sLinkedList() {
	  sNode<T> *ptr = head;
	  while(ptr!=nullptr) {
		sNode<T> *n_ptr = ptr->next;
		delete ptr;
		ptr = n_ptr;
	  }
	}

	void insertData(T data_) {
		tail->next = new sNode<T>(data_);
		tail = tail->next;
	}

	// delete data that firstly find
	bool deleteData(T data_) {
	  sNode<T> *cur = head->next; //  head is dummy node
	  sNode<T> *prev_cur = head;

	  //iterate
	  while(cur!=nullptr){
		if(cur->getData()==data_){
		  prev_cur->next = cur->next;
		  delete cur;
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
void sLinkedList<T>::visualize() {
  sNode<T> *cur = this->head->next;
  std::cout<<"[ "<<cur->getData()<<" -> ";
  while(cur->next!=nullptr){
	cur = cur->next;
	std::cout<<cur->getData()<<" -> ";
  }
  std::cout<<" ]"<<std::endl;
}

int main() {
  //test
  std::vector<double> data = {5, 10, 2, 1, 100, 40, 70};

  sLinkedList<double> *ttt = new sLinkedList<double>;
  for(auto &iter: data) {
	ttt->insertData(iter);
  }
  ttt->visualize();
  ttt->deleteData(5);

  ttt->visualize();
  ttt->deleteData(1);

  ttt->visualize();
  ttt->deleteData(70);
  ttt->visualize();

  delete ttt;
 
  return 0;
}
