
namespace oden {

template <class T> List<T>::List() : _container() {}

template <class T> List<T>::~List() {
    typename std::vector<T *>::iterator it;
    for (it = _container.begin(); it != _container.end(); ++it)
        delete *it;
}

template <class T> typename std::vector<T *>::iterator List<T>::begin() {
    return _container.begin();
}

template <class T> typename std::vector<T *>::iterator List<T>::end() {
    return _container.end();
}

template <class T> void List<T>::push_back(T *value) {
    _container.push_back(value);
}

template <class T> void List<T>::push_front(T *value) {
    _container.push_front(value);
}

template <class T> T *List<T>::pop_front() {
    if (_container.empty())
        return nullptr;

    T *ret = _container.front();
    _container.erase(_container.begin());

    return ret;
}

template <class T> T *List<T>::pop_back() {
    if (_container.empty())
        return nullptr;

    T *ret = _container.back();
    _container.pop_back();

    return ret;
}

template <class T> size_t List<T>::size() const { return _container.size(); }

template <class T> bool List<T>::empty() const {
    return _container.size() == 0;
}

template <class T>
typename std::vector<T *>::iterator
List<T>::erase(typename std::vector<T *>::iterator pos) {
    return _container.erase(pos);
}

template <class T> void List<T>::erase(size_t pos) {
    auto l_iter = _container.begin();
    for (size_t i = 0; i < pos; ++i)
        ++l_iter;

    _container.erase(l_iter);
}

template <class T>
typename std::vector<T *>::iterator
List<T>::insert(typename std::vector<T *>::iterator pos, T *val) {
    return _container.insert(pos, val);
}

template <class T> T *List<T>::front() { return _container.front(); }

template <class T> T *List<T>::back() { return _container.back(); }

template <class T> T *List<T>::operator[](size_t n) {
    return (n < 0 || n >= _container.size()) ? nullptr : _container[n];
}

} // namespace oden
