#ifndef STATICARRAY_H
#define STATICARRAY_H
#include <cassert>
#include <iostream>
template<class data_type, size_t cap = 5>
class Sarr
{
  data_type data[cap];
public:
  class iterator
  {
  public:
	iterator() :elem{nullptr} {}
	iterator(data_type *a): elem{a} {}
	iterator(const iterator &iter): elem{iter.elem} {}
	bool operator== (const iterator& iter) const
	{ return elem == iter.elem; }
	bool operator!=(const iterator& iter) const
	{ return elem != iter.elem; }

	data_type& operator*()
	{ return *elem; }

	data_type* operator ->()
	{ return elem; }

	iterator operator++()
	{
	  ++elem;
	  return *this;
	}
	iterator operator--(int)
	{
	  iterator temp(*this);
	  --elem;
	  return temp;
	}
	iterator operator--()
	{
	  --elem;
	  return *this;
	}

	iterator operator++(int)
	{
	  iterator temp(*this);
	  ++elem;
	  return temp;
	}

	iterator operator +=(const size_t add)
	{
	  elem+=add;
	  return *this;
	}

	iterator operator+(const size_t add)
	{
	  return *this+=add;
	}

  private:
	data_type *elem;
  };

  class const_iterator
  {
  public:
	const_iterator() :elem{nullptr} {}
	const_iterator(data_type *a): elem{a} {}
	const_iterator(const const_iterator &iter): elem{iter.elem} {}
	bool operator== (const const_iterator& iter) const
	{ return elem == iter.elem; }
	bool operator!=(const const_iterator& iter) const
	{ return elem != iter.elem; }

	const data_type& operator*()
	{ return *elem; }

	const data_type* operator ->()
	{ return elem; }

	const_iterator operator++()
	{
	  ++elem;
	  return *this;
	}
	const_iterator operator--(int)
	{
	  const_iterator temp(*this);
	  --elem;
	  return temp;
	}
	const_iterator operator--()
	{
	  --elem;
	  return *this;
	}
	const_iterator operator++(int)
	{
	  const_iterator temp(*this);
	  ++elem;
	  return temp;
	}

	const_iterator operator +=(const size_t add)
	{
	  elem+=add;
	  return *this;
	}

	const_iterator operator+(const size_t add)
	{
	  return *this+=add;
	}

  private:
	data_type *elem;
  };

  iterator begin()
  {
	return iterator(data);
  }
  iterator end()
  {
	return iterator(data+cap);
  }

  const_iterator begin() const
  {
	return const_iterator(const_cast<data_type*>(data));
  }
  const_iterator end() const
  {
	return const_iterator(const_cast<data_type*>(data+cap));
  }
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
  constexpr inline size_t size() const
  {
	return cap;
  }
  Sarr& operator +(const data_type& a);
  Sarr& operator +(const Sarr& a);
  data_type& operator[](const size_t index);
  const data_type& operator[](const size_t index) const;
  template<class data_typew, size_t t>
  friend std::ostream& operator << (std::ostream& os, const Sarr<data_typew, t> & temp);
};

template<class data_type, size_t t>
std::ostream& operator << (std::ostream& os, const Sarr<data_type, t>& temp)
{
  for(size_t i = 0; i < temp.size(); i++)
	os << temp[i] <<' ';
  return os;
}

template<class data_type, size_t t>
data_type& Sarr<data_type, t>::operator[](size_t index)
{
  assert(index < t);
  return data[index];
}

template<class data_type, size_t t>
const data_type& Sarr<data_type, t>::operator[](const size_t index) const
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
