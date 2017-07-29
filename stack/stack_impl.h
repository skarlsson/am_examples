template <class T>
stack<T>::stack() {
	}

  // creates a stack with size number of elelemts with value  (2, 200) -> [ 200, 200]
	template <class T>
  stack<T>::stack(size_t size, T value){
	}

  // creates a stack with elemts from v
  template <class T>
  stack<T>::stack(std::vector<T> v){
  }

  // returns the number of elements
template <class T>
	size_t stack<T>::size() const {
	return 0;
	}

  // insert a new element
template <class T>
	void stack<T>::push(T value){
	}

  // removes and returns the last inserted element
template <class T>
  T stack<T>::pop() {
    return T();
  }

  // this should reverse contents
  // [2, 3, 4] -> [ 4, 3, 2]
template <class T>
  void stack<T>::reverse()
  {

  }

  // removes all elements
template <class T>
  void stack<T>::clear()
  {

  }

template <class T>
std::string stack<T>::str() const{
  return "nisse";
}


