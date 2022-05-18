#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main()
{
  TVector<int> a(5, 4);
  TVector<int> b(5, 4);
  TVector<int> c(1);

  std::cout << a << "\n";

  c = a + b;
  c = a - b;
  std::cout << c <<"\n";
  c = a * 2;
  std::cout << c << "\n";

  if (a == b)
    std::cout <<"YES\n";
  if (a == c)
  {
    std::cout << "AAAA\n";
  } 
  else std::cout << "NO\n";

  c = a * b * b;
  std::cout << c << "\n";

  TMatrix<int> d(5, 5, 5);
  /*for (int i = 0; i < d.GetLen(); i++)
    for (int j = 0; j < d.GetLen2(); j++)
      std::cout << d;*/

  return 0;
}