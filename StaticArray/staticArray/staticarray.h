#ifndef STATICARRAY_H
#define STATICARRAY_H
#include <cassert>

template<class data_type, size_t cap = 5>
class Sarr
{
  data_type data[cap];
public:
  Sarr() = default;
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
  inline size_t size() const
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
