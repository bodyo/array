#include <iostream>
#include "staticarray.h"
using namespace std;

template class Sarr<int>;
int main()
{
  const Sarr<int> a(2);
  Sarr<int> r;
  for(Sarr<int>::const_iterator i = a.begin(); i != a.end(); i++)
  {
	*i = 3;
	cout << *i;
  }
  r=a;
  cout << a << endl;
  cout << r << endl;
}
