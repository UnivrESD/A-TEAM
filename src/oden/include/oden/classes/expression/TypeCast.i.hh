namespace oden {

template <typename ET,typename RT>
TypeCast<ET,RT>::TypeCast(ET *e)
    : RT(e->getMaxTime()), _e(e){
  // ntd
}

template <typename ET,typename RT> TypeCast<ET,RT>::~TypeCast() { delete _e; }

template <typename ET,typename RT> ET &TypeCast<ET,RT>::getItem() { return *_e; }


} // namespace oden
