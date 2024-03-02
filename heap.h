#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>> class Heap {
  public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

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
    void push(const T &item);

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const &top() const;

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
    // Add whatever helper functions and data members you need below
    void heapify_down(int idx);
    void heapify_up(int idx);

    std::vector<T> data_;
    int m_;
    PComparator c_;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : data_{}, m_{m}, c_{c} {}

template <typename T, typename PComparator> Heap<T, PComparator>::~Heap(){};

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
    data_.push_back(item);
    heapify_up(size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data_.size();
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const {
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error(
            "Cannot extract top element from an empty Heap");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return data_[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator> void Heap<T, PComparator>::pop() {
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Cannot pop from an empty Heap");
    }
    std::swap(data_[0], data_[data_.size() - 1]);
    data_.pop_back();
    heapify_down(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_down(int idx) {
    if (idx < 0 || idx >= (int)size())
        return;
    while (true) {
        int prio = idx;
        for (int i = 1; i <= m_; ++i) {
            int child_i = m_ * idx + i;
            if (child_i < (int)size() && c_(data_[child_i], data_[prio]))
                prio = child_i;
        }
        if (prio != idx) {
            std::swap(data_[prio], data_[idx]);
            idx = prio;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_up(int idx) {
    if (idx < 0 || idx >= (int)size())
        return;
    while (idx != 0) {
        int parent_i = std::floor((idx - 1) / m_);
        if (c_(data_[idx], data_[parent_i])) {
            std::swap(data_[idx], data_[parent_i]);
            idx = parent_i;
        } else {
            break;
        }
    }
}

#endif
