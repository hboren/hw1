#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const{
    return head_->val[head_->first];
}

/**			
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val){
  //if empty, create a new item
	if(empty()){
    Item* current = new Item;
    head_ = current;
    tail_ = current;
    }
	//if there is room at the end of the array, add the value there,
	//update size
  if(tail_->last !=ARRSIZE){
    tail_->val[tail_->last] = val;     
    tail_->last++;
     size_++;
  }
	//if there is no room at the end of the array, create a new item
	//set that to tail, and change appropriate pointers to have the last
	//tail point to the new one and vice versa and add the new val at the
	//beginning of new node, update size
  else if(tail_->last == ARRSIZE && !empty()){
    Item* addition = new Item;
    tail_->next = addition;
    addition->prev = tail_;
    tail_ = addition;
    tail_->last++;
    tail_->val[tail_->first] = val;
    size_++;
    }
}


/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val){
  //if empty, create a new node
  if(empty()){
    //create a new node
    Item* current = new Item;
    head_ = current;
    tail_ = current;
    current->first = ARRSIZE;
    current->last = ARRSIZE;
    }
    //if there is space at the beginning of the array
    if(head_->first !=0){
      //decrement head's first, then put val there and increment size
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
    }
    //if no room in the front create a new head node, add val to the back of
    //that node, and update pointers appropriately so the new node is head
    //and the previous head and new head point correctly to each other
    else if(head_->first == 0 && !empty()){
      Item* addition = new Item;
      head_->prev = addition;
      addition->next = head_;
      head_ = addition;
      addition->first = ARRSIZE;
      addition->last = ARRSIZE;
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
    }
  
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front(){
  //if empty aka no node at all, return here;
  if(empty()){
    return;
  }
  //if only one value in head array
  if(head_->first == head_->last-1){
    //then if only one item, delete the item and decrement the size
    if(head_ == tail_){
      head_ = nullptr;
      delete tail_;
      tail_ = nullptr;
      size_--;
    }
    //if multiple items and one value in head, delete that item and make head
    //point to the next item and decrement size
    else{
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
      head_->prev = nullptr;
      size_--;
    }
  }
  //else just increment first and decrement size
  else{
    head_->first++;
    size_--;
  }
}
  
/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back(){
  //if empty aka no node at all, return
  if(empty()){
    return;
  }
  //if only one value in tail array
  if(tail_->first == tail_->last-1){
    //then if only one item delete item and decrement size
    if(head_ == tail_){
      head_ = nullptr;
      delete tail_;
      tail_ = nullptr;
      size_--;
    }
    //if multiple items and one value in tail, delete current tail, 
    //reduce size and make the next to last item tail
    else{
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
      tail_->next = nullptr;
      size_--;
    }
  }
  //otherwise decrement tail last to ignore that value and decrement size
  else{
    tail_->last--;
    size_--;
  }
}

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   * only index items that are actually there
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_ || loc < 0){
    return nullptr;
  }
  Item* temp = head_;
  //check if location is in current node, last-first<=location
  //if its not, then in loop update location and update current node
  while(loc >= temp->last - temp->first){
    loc = loc - (temp->last - temp->first);    
		temp = temp->next;
  }
  //correct the location so points to correct value in the current node
  int correct_loc = loc+temp->first;
  return &temp->val[correct_loc];
}




void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

