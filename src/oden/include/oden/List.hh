#pragma once

#include <iterator>
#include <vector>

namespace oden {

/// @brief List struct is a data structure for collecting objects.
/// List has the purpose to prevent users from accidentally copying
/// the container. For this reason, the copy constructor and
/// the assign operator must not be implemented.
template <class T> class List {
  public:
    /// @brief Constructor.
    List();

    /// @brief Destructor.
    ~List();

    /// @brief Adds a new element at the end of the container
    /// @param value A value to be added into the container
    void push_back(T *value);

    /// @brief Adds a new element at the beginning of the container
    /// @param value A value to be added into the container
    void push_front(T *value);

    /// @brief Removes the last element in the container.
    /// @return The removed last element in the container
    T *pop_back();

    /// @brief Removes the first element in the container.
    /// @return The removed first element in the container.
    T *pop_front();

    /// @brief Returns the last element in the container.
    /// @return The last element in the container.
    T *back();

    /// @brief Returns the first element in the container.
    /// @return The first element in the container.
    T *front();

    /// @brief Returns the number of elements in the list container.
    /// $return The number of elements in the container.
    size_t size() const;

    /// @brief Returns whether the container is empty.
    /// @return True if the container size is 0, false otherwise.
    bool empty() const;

    /// @brief Returns a reference to the element at position n in the
    /// container.
    /// @return A reference to the element at the specified position.
    T *operator[](size_t n);

    /// @brief Returns an iterator pointing to the first element in the
    /// container.
    /// @return An iterator to the beginning of the sequence container.
    typename std::vector<T *>::iterator begin();

    /// @brief Returns an iterator pointing to the last element in the
    /// container.
    /// @return An iterator to the end of the sequence container.
    typename std::vector<T *>::iterator end();

    /// @brief Removes from the container the element at the given position.
    /// @param pos Iterator pointing to the element to be removed.
    /// @return An iterator pointing to the new location of the element that
    /// followed the last element erased by the function call.
    typename std::vector<T *>::iterator
    erase(typename std::vector<T *>::iterator pos);

    /// @brief Removes from the container the element between the two positions
    /// @param pos1 Iterator pointing to the first element to be removed.
    /// @param pos2 Iterator pointing to the element after the last to be removed.
    /// @return An iterator pointing to the new location of the element that
    /// followed the last element erased by the function call.
    typename std::vector<T *>::iterator
    erase(typename std::vector<T *>::iterator pos1,
          typename std::vector<T *>::iterator pos2);

    /// @brief Removes from the container the element at the given position.
    /// @param pos Position of the element to be removed.
    void erase(size_t pos);

    /// @brief The vector is extended by inserting new elements before the
    /// element at the specified position, effectively increasing the container
    /// size by the number of elements inserted.
    /// @param pos Position in the container where the new element is inserted.
    /// @param val Value to be copied to thec container in the given position.
    /// @return An iterator that points to the first of the newly inserted
    /// elements.
    typename std::vector<T *>::iterator
    insert(typename std::vector<T *>::iterator pos, T *val);


    /// @brief Copy constructor.
    List(const List<T> &other) = delete;

    /// @brief Assign operator.
    List<T> &operator=(const List<T> &other) = delete;


  private:
    /// @brief The wrapped container
    std::vector<T *> _container;
};

} // namespace oden

#include "List.i.hh"
