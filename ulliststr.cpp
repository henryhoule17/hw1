#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;

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
  while(head_ != NULL)
	{
    Item *temp = head_;
		head_ = head_->next;
    delete temp;
  }
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val)
{
  size_++;
  if(head_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1;
    return;
  }

  if(tail_->last == ARRSIZE)
  {
    tail_->next = new Item();
    tail_->next->prev = tail_;
    tail_ = tail_->next;
    tail_->next = NULL;
    tail_->val[0] = val;
    tail_->last++;
  }
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
}
/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back()
{
  if(size_ == 0)
    return;
  else
    size_--;

  if(tail_->last == 1)
  {
    Item* temp = tail_;

    if(tail_->prev != NULL)
    {
      tail_ = tail_->prev;
      tail_->next = NULL;
    }

    else
    {
      tail_ = NULL;
      head_ = NULL;
    }
    temp->val[0] = "\0";
    delete temp;
  }
  else
  {
    tail_->last--;
    tail_->val[tail_->last] = "\0";
  }
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
  size_++;
  if(head_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1;
    return;
  }

  if(head_->first == 0)
  {
    head_->prev = new Item();
    head_->prev->next = head_;
    head_ = head_->prev;
    head_->prev = NULL;
    head_->val[ARRSIZE-1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
  }
  else
  {
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front()
{
  if(size_ == 0)
    return;
  else
    size_--;

  if(head_->first == ARRSIZE - 1)
  {
    Item* temp = head_;

    if(head_->next != NULL)
    {
      head_ = head_->next;
      head_->prev = NULL;
    }

    else
    {
      tail_ = NULL;
      head_ = NULL;
    }
    temp->val[0] = "\0";
    delete temp;
  }
  else
  {
    head_->val[head_->first] = "\0";
    head_->first++;
  }
}
/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
 if(loc >= size_ + ARRSIZE|| loc < 0)
    return NULL;

  Item* temp = head_;
  unsigned int j = head_->first;
  string* ptr = &head_->val[j];
  for(unsigned int i=0; i<=loc; i++)
  {
    if(j == temp->last)
    {
      if(temp->next != NULL)
      {
        temp = temp->next;
        j = 0;
        ptr = &temp->val[j];
        j++;
      }
      else if(i == loc)
        return ptr = &temp->val[j];
      else
        return NULL;
    }
    else
    {
      ptr = &temp->val[j];
      j++;
    }
  }
  /*if(*ptr == "\0")
    return NULL;
  else*/
    return ptr;
}

/*void ULListStr::print() const
{
  Item* temp = head_;

  while(temp != NULL)
  {
    for(int i=0; i<10; i++)
      if(temp->val[i] != "")
        std::cout << temp << " ";

    temp = temp->next;
  }

  std::cout << std::endl;
}
*/


  /*if(head_->next == NULL)
  {
    if(head_->last >= ARRSIZE)
    {
      head_->next = new Item();
      tail_ = head_->next;
      tail_->prev = head_;
      head_->next->val[0] = val;
      head_->next->last = 1;
    }
    else
    {
      head_->val[head->last] = val;
      head->last++;
    }
  }
  else
  {*/