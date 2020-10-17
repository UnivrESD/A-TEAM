
namespace oden {

template <typename T>
Constant<T>::Constant(T value, size_t max_time)
    : Atom<T>(max_time), _value(value) {
    // ntd
}

template <typename T>
Constant<T>::Constant(const Constant &other)
    : Atom<T>(other._max_time), _value(other._value) {
    // ntd
}

template <typename T>
Constant<T> &Constant<T>::operator=(const Constant<T> &other) {
    _value = other._value;
    return *this;
}

}