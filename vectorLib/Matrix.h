#pragma once
#include "Vector.h"

template<class A>
class TMatrix : public TVector<TVector<A>>
{
public:
  TMatrix();
  //TMatrix(int n);
  TMatrix(int n1, int n2, A l);
  //TMatrix(const TMatrix<A>& m);
  //~TMatrix();

  int GetLen2();

protected:
  int len2;
  A** datam;
};

template<class A>
inline TMatrix<A>::TMatrix()
{
  len = 0;
  len2 = 0;
  datam = 0;
}

template<class A>
inline TMatrix<A>::TMatrix(int n1, int n2, A l)
{
  len = n1;
  len2 = n2;
  for (int j = 0; j < len; j++)
  {
    data[j] = TVector<A>(n2, l);
    std::cout << data[j]<<"\n";
  }


 /* len2 = n2;
  this->data = new TVector<A>[len2];
  for (int i = 0; i < len2; i++)
    this->data[i] = TVector<A>(n1);
  this->len = n1;
  
  for (int i = 0; i < len2; i++)
    for (int j = 0; j < this->len; j++)
      this->data[i][j] = l;*/

  /*for (int j = 0; j < len2; j++)
    data[j] = 3;*/
}

template<class A>
inline int TMatrix<A>::GetLen2()
{
  return len2;
}

//template<class A>
//inline TMatrix<A>::TMatrix(int n)
//{
//  len = n;
//  len2 = n;
//  this->data = new TVector<A>[n]
//  for (int i = 0; i < len; i++)
//
//}

//template<class A>
//inline TMatrix<A>::TMatrix(int n1, int n2) : TVector<TVector<A>>::TVector(n1)
//{
//  for (int i = 0; i < n1; i++)
//    this->data[i] = n2;
//}
