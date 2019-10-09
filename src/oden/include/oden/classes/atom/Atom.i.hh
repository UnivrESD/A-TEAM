

namespace oden {

template <typename T> Atom<T>::Atom(size_t max_time) : _max_time(max_time) {
    // ntd
}

template <typename T> size_t Atom<T>::getMaxTime() { return _max_time; }

}