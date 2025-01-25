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

void ULListStr::push_back(const std::string& val)
{
  // Use back func to see find the value
  if(tail_ == nullptr || tail_->last == ARRSIZE){
    Item* newItem = new Item();
    if(tail_ != nullptr){
      tail_->next = newItem;
      newItem->prev = tail_;
    }
    else{
      head_ = newItem;
    }
    //newItem->next = nullptr;
    tail_ = newItem;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back()
{
  // Use back func to see find the value
  if(head_ == nullptr || tail_ == nullptr){
    return;
  }

  if (tail_->last == 0) { // If the tail is empty, deallocate it 
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
        tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }
    delete temp;
  }
	
	tail_->last--;
  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val)
{
  // Empty List
  if(head_ == nullptr || head_->first == 0){
    Item* newItem = new Item();
    newItem->last = ARRSIZE; // Initialize last to ARRSIZE for reverse indexing
    newItem->first = ARRSIZE - 1; // Insert at the back of the new head
    newItem->val[ARRSIZE - 1] = val;

    newItem->next = head_;
    if (head_ != nullptr) {
      head_->prev = newItem;
    }
    head_ = newItem;

    if (tail_ == nullptr) { // If list was empty, tail points to head
      tail_ = head_;
    }
  } 
  else {
    // If there is space in the current head node
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
  if(head_ == nullptr){
    return;
  }

  if (head_->first == head_->last) { // If the node is empty
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    } 
    else { 
      tail_ = nullptr;
    }
    delete temp;
  }

	head_->first++; // Move the front index forward
  size_--;
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return nullptr;
  }

  size_t index = loc;
  Item* current = head_;
  while (current != nullptr) {
    size_t node_size = current->last - current->first;
    if (index < node_size) {
      return &current->val[current->first + index];
    }
    index -= node_size;
    current = current->next;
  }
  return nullptr;
}