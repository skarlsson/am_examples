#include <vector>

template <class T>
class stack
{
	public:
  // creates an empty stack
	stack();

  // creates a stack with size number of elelemts with value  (2, 200) -> [ 200, 200]
	stack(size_t size, T value);

  // creates a stack with elemts from v
  stack(std::vector<T> v);

  // returns the number of elements
size_t size() const;

  // insert a new element
void push(T value);

  // removes and returns the last inserted element
  T pop();

  // this should reverse contents
  // [2, 3, 4] -> [ 4, 3, 2]
  void reverse();

  // removes all elements
  void clear();


  // this should return a string represenmtation of the content for example "[200, 200]"
  std::string str() const;

private:
	std::vector<T> v_;
};

#include "stack_impl.h"
