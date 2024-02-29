#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vectors>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapArray;
  int m; //m-aryness of the tree

  void trickleUp(int index);
  void trickleDown(int index);
};

// Add implementation of member functions here

//Default Constructor
template <typename T, typename Comparator>
Heap<T, Comparator>::Heap(int m = 2, PComparator = c = PComparator()) {};

template <typename T, typename Comparator>
Heap<T, Comparator>::Heap(int m, Comparator c) : m(m), comparator(c) {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heapArray.push_back(item);
  trickleUp(heapArray.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heapArray.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heapArray.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heapArray[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }

  std::swap(heapArray[0], heapArray[heapArray.size() - 1]);
  heapArray.pop_back();

  trickleDown(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index) {
    int heapSize = heapArray.size();

    int parentIndex = index;

    while (true) {
        int targetIndex = parentIndex;
        int firstChildIndex = m * parentIndex + 1;

        // Find the index of the child with the highest priority
        for (int i = 0; i < m; ++i) {
            int childIndex = firstChildIndex + i;
            if (childIndex < heapSize && comparator(heapArray[childIndex], heapArray[targetIndex])) {
                targetIndex = childIndex;
            }
        }

        // If no child has higher priority, break
        if (targetIndex == parentIndex) {
            break;
        }

        // Swap parent with the highest priority child
        std::swap(heapArray[parentIndex], heapArray[targetIndex]);
        parentIndex = targetIndex;
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index)
{
	if(index >= heapArray.size())
	{
		return;
	}

	int currentIndex = index;

	while(currentIndex > 0)
	{
		int parentIndex = (currentIndex - 1) / m;

		if(comparator(heapArray[currentIndex], heapArray[parentIndex]))
		{
			std::swap(heapArray[currentIndex], heapArray[parentIndex]);
			currentIndex = parentIndex;
		}

		else break;
	}
}

#endif