#ifndef STATICARRAY_H
#define STATICARRAY_H
#include <cassert>

template<class data_type>
class iterator
{
  friend class Sarr;
public:
  iterator() :elem{nullptr} {}
  iterator(data_type &a): elem{a} {}
  iterator(const iterator &iter): elem{iter.elem} {}
  bool operator== (const iterator& iter) const
  {
	return elem == iter.elem;
  }
  bool operator!=(const iterator& iter) const
  {
	return elem != iter.elem;
  }
  iterator& operator++()
  {
	if(elem != nullptr)
	  return ++elem;
  }
  iterator& operator--()
  {
	if(elem != nullptr)
	  return --elem;
  }


private:
  data_type *elem;
};


template<class data_type, size_t cap = 5>
class Sarr
{
  data_type data[cap];
  iterator<data_type> *beg;
  iterator<data_type> *en;
public:
  friend class iterator<data_type>;
  iterator<data_type>& begin()
  {
	return beg;
  }
  iterator<data_type>& end()
  {
	return en;
  }
  ~Sarr()
  {
	delete beg;
	delete en;
  }

  Sarr() : beg(&data[0]), en(&data[cap]) {};
  explicit Sarr(const Sarr& arr)
  {
	for(size_t i = 0; i < cap; ++i)
	  data[i] = arr.data[i];
  }
  Sarr(const data_type &a)
  {
	for(size_t i = 0; i < cap; ++i)
	  data[i] = a;
  }
  Sarr& operator =(const Sarr& arr)
  {
	for(size_t i = 0; i < cap; ++i)
	  data[i] = arr.data[i];
	return *this;
  }
  Sarr& operator =(const data_type& a)=delete;
  constexpr inline size_t size() const
  {
	return cap;
  }
  Sarr& operator +(const data_type& a);
  Sarr& operator +(const Sarr& a);
  data_type& operator[](const size_t index);
};

template<class data_type, size_t t>
data_type& Sarr<data_type, t>::operator[](size_t index)
{
  assert(index < t);
  return data[index];
}

template<class data_type, size_t t>
Sarr<data_type, t>& Sarr<data_type, t>::operator +(const data_type& a)
{
  for(size_t i = 0; i < t; ++i)
	data[i] += a;
  return *this;
}

template<class data_type, size_t t>
Sarr<data_type, t>& Sarr<data_type, t>::operator +(const Sarr& a)
{
  for(size_t i = 0; i < t; ++i)
	data[i] += a.data[i];
  return *this;
}

#endif // STATICARRAY_H
