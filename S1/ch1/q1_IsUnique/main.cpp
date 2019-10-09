#include <iostream>
#include <list>
#include <algorithm>

class my_hash {
  private:
    int num_table;

    // Point to an list containing table 
    std::list<int> *table;

  public:
    my_hash(int size);	// Construct

    void insertItem(int x);

    void deleteItem(int key);

    int hashFunction(int x) {
    return(x%num_table);
    }

    void displayHash();
 
};

my_hash::my_hash(int size){
  this->num_table = size;
  table = new std::list<int>[num_table];
}

void my_hash::insertItem(int x){
int index = hashFunction(x);
table[index].push_back(x);
}

void my_hash::deleteItem(int key) {
int index = hashFunction(key);
table[index].remove_if( [&](int value) {return value==key;} );
}

void my_hash::displayHash() {
for(int i=0; i<num_table;i++) {
  std::cout<<i<<" ";
  for(auto &iter: table[i]) {
    std::cout<<"--> "<<iter;
  }
  std::cout<<std::endl;
}
}


int main() {
  int test[] = {1, 2, 4, 7, 12, 22};
  my_hash mh(5);
  for(const auto& iter: test) {
  mh.insertItem(iter);
  }
  mh.displayHash();
  mh.deleteItem(7);
 mh.deleteItem(12);
  mh.displayHash();
return 0;
}
