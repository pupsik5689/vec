#pragma once
#include <iostream>

template<class T>
class TVector
{
public:
  //TVector();
  TVector(int n, T v);
  TVector(int n = 1);
  TVector(const TVector<T>& p);
  ~TVector();

  int GetLen();

  T& operator [] (int i);
  TVector<T>& operator = (const TVector<T>& p);
  TVector<T> operator + ( TVector<T>& p);
  TVector<T> operator - ( TVector<T>& p);

  TVector<T> operator * (const TVector<T>& p);
  TVector<T> operator * (const T p);

  TVector<T> operator / (const TVector<T>& p);
  TVector<T> operator / (const T p);

  bool operator == (const TVector<T>& p);

protected:
  int len;
  T* data;
};

//template<class T>
//inline TVector<T>::TVector()
//{
//  len = 1;
//  data = 0;
//}

template<class T>
inline TVector<T>::TVector(int n, T v)
{
  data = new T[n];
  len = n;
  for (int i = 0; i < n; i++)
    data[i] = v;
}

template<class T>
inline TVector<T>::TVector(int n)
{
  data = new T[n];
  len = n;
  
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  data = new T[p.len];
  len = p.len;
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != 0)
    delete data;
  data = 0;
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline T & TVector<T>::operator[](int i)
{
  return data[i];
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  data = new T[p.len];
  len = p.len;
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
  return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+( TVector<T>& p)
{
  if (len == p.len)
  {
    TVector <T> res(this->len);

    for (int i = 0; i < len; i++)
      res[i] = data[i] + p[i];

    return res;
  }
  else throw std::out_of_range("out");
}

template<class T>
inline TVector<T> TVector<T>::operator-( TVector<T>& p)
{
  if (len == p.len)
  {
    TVector <T> res(this->len);

    for (int i = 0; i < len; i++)
      res[i] = data[i] - p[i];

    return res;
  }
  else throw std::out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  TVector <T> res(this->len);
  if (len == p.len)
  {
    for (int i = 0; i < len; i++)
      res[i] = data[i] * p.data[i];

    return res;
  }
  else throw std::out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator*(const T p)
{
  TVector <T> res(this->len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] * p;
  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  TVector <T> res(this->len);
  if (len == p.len)
  {
    for (int i = 0; i < len; i++)
      res[i] = data[i] / p.data[i];

    return res;
  }
  else throw out_of_range("out!");
}

template<class T>
inline TVector<T> TVector<T>::operator/(const T p)
{
  TVector <T> res(this->len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] / p;
  return res;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  for (int i = 0; i < len; i++)
  {
    if (data[i] != p.data[i])
      return false;
  }
  return true;
}

template<class T>
std::ostream & operator<<(std::ostream & o, TVector<T>& p)
{
  for (int i = 0; i < p.GetLen(); i++)
    o << p[i] << "\t";

  return o;
}