#include <iostream>
#include "staticarray.h"
using namespace std;

int main()
{
  Sarr<int, 6> a(2);
  Sarr<int, 6> r;
  for(size_t i = 0; i < a.size(); ++i)
  {
	//a[i] = i;
	r[i] = i;
  }
  a=r;
  //a = 5;
  for(size_t i = 0; i < a.size(); ++i)
	cout << a[i] << ' ';
  cout << endl;
  for(size_t i = 0; i < a.size(); ++i)
	cout << r[i] << ' ';
  cout << endl;
}
