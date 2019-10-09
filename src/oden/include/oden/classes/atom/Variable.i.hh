
namespace oden {

template <typename T>
Variable_Base<T>::Variable_Base(const std::string &name, size_t max_time)
    : Atom<T>(max_time), _name(name) {
    // ntd
}

template <typename T> const std::string &Variable_Base<T>::getName() {
    return _name;
}

} // namespace oden
