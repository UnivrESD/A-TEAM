
namespace oden {

template <typename ET>
NextOperator<ET>::NextOperator(ET *e, size_t offset)
    : ET(e->getMaxTime()), _e(e), _offset(offset) {
    // ntd
}

template <typename ET> NextOperator<ET>::~NextOperator() { delete _e; }

template <typename ET> ET &NextOperator<ET>::getItem() { return *_e; }

template <typename ET> size_t NextOperator<ET>::getOffset() { return _offset; }

} // namespace oden
