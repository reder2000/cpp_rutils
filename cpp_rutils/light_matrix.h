#pragma once

#include "linalg.h"


// light matrix
template <class T>
class LightMatrix
{
 public:
  using value_tye = T;
  using data_type = std::vector<T>;

  LightMatrix() = default;
  LightMatrix(size_t rows, size_t cols);
  LightMatrix(size_t rows, size_t cols, const T& val);
  LightMatrix(std::vector<T>&& values, size_t rows, size_t cols);
  LightMatrix(std::vector<std::vector<T>> const& values);

  [[nodiscard]] size_t rows() const { return _rows; }
  [[nodiscard]] size_t cols() const { return _cols; }
  [[nodiscard]] size_t size() const { return _data.size(); }
  const data_type&     data() const { return _data; }

  const T& at(size_t r, size_t c) const;
  T&       at(size_t r, size_t c);
  T&       operator()(size_t r, size_t c);
  const T& operator()(size_t r, size_t c) const;

  bool operator==(const LightMatrix<T>& other) const;

  data_type operator*(const data_type& v) const;

  using col_view = SliceVector<const T>;
  col_view get_col_view(size_t col) const;
  void     assign_col(size_t c, col_view v);
  //void                 assign_col(size_t c, col_view v);

  //std::vector<T>                          get_row(size_t r) const;
  using row_view = std::span<const T, std::dynamic_extent>;
  row_view get_row_view(size_t r) const;
  void     assign_row(size_t r, row_view rv);

  LightMatrix transpose() const;

 private:
  size_t    _rows = 0;
  size_t    _cols = 0;
  data_type _data;
};

// ----------------------------------------
// implementation
// ----------------------------------------


template <class T>
LightMatrix<T>::LightMatrix(size_t rows, size_t cols) : _rows(rows), _cols(cols), _data(rows * cols)
{
}

template <class T>
LightMatrix<T>::LightMatrix(size_t rows, size_t cols, const T& val)
    : _rows(rows), _cols(cols), _data(rows * cols, val)
{
}

template <class T>
LightMatrix<T>::LightMatrix(std::vector<T>&& values, size_t rows, size_t cols)
    : _rows(rows), _cols(cols), _data(std::move(values))
{
  MREQUIRE_EQUAL(rows * cols, _data.size());
}

template <class T>
const T& LightMatrix<T>::at(size_t r, size_t c) const
{
  MREQUIRE_LESS(r, _rows);
  MREQUIRE_LESS(c, _cols);
  return _data[r * _cols + c];
}
template <class T>
T& LightMatrix<T>::at(size_t r, size_t c)
{
  MREQUIRE_LESS(r, _rows);
  MREQUIRE_LESS(c, _cols);
  return _data[r * _cols + c];
}

template <class T>
T& LightMatrix<T>::operator()(size_t r, size_t c)
{
  return _data[r * _cols + c];
}
template <class T>
const T& LightMatrix<T>::operator()(size_t r, size_t c) const
{
  return _data[r * _cols + c];
}

template <class T>
inline bool LightMatrix<T>::operator==(const LightMatrix<T>& other) const
{
  return _rows == other._rows && _cols == other._cols && _data == other._data;
}

template <class T>
typename LightMatrix<T>::data_type LightMatrix<T>::operator*(const data_type& v) const
{
  MREQUIRE_EQUAL(_cols, v.size());
  data_type res;
  res.reserve(rows());
  auto iv = _data.begin();
  for (size_t i = 0; i < _rows; ++i)
  {
    T    r  = 0.;
    auto ij = v.begin();
    for (size_t j = 0; j < _cols; ++j)
      r += *iv++ * *ij++;
    res.push_back(r);
  }
  return res;
}

template <class T>
SliceVector<const T> LightMatrix<T>::get_col_view(size_t col) const
{
  return SliceVector<const T>{data().data() + col, _rows, _cols};
}

template <class T>
void LightMatrix<T>::assign_col(size_t c, SliceVector<const T> v)
{
  MREQUIRE_LESS(c, _cols);
  MREQUIRE_EQUAL(v.size(), _rows);
  T*   t  = std::addressof(_data[c]);
  auto pv = v.begin();
  for (size_t i = 0; i < _rows; ++i)
  {
    *t = *pv;
    t += _cols;
    pv++;
  }
}

//template <class T>
//std::vector<T> LightMatrix<T>::get_row(size_t r) const
//{
//  MREQUIRE_LESS(r, _rows);
//  std::vector<T> res;
//  res.reserve(_cols);
//  const T* t = std::addressof(_data[r * _cols]);
//  for (size_t i = 0; i < _cols; ++t, ++i)
//    res.push_back(*t);
//  return res;
//}

template <class T>
std::span<const T, std::dynamic_extent> LightMatrix<T>::get_row_view(size_t r) const
{
  return std::span<const T, std::dynamic_extent>(_data.data() + r * cols(), cols());
}

template <class T>
void LightMatrix<T>::assign_row(size_t r, row_view rv)
{
  MREQUIRE_EQUAL(this->cols(), rv.size());
  T*       t   = std::addressof(_data[r * rv.size()]);
  const T* sdt = rv.data();
  for (size_t i = 0; i < _cols; ++i)
    *t++ = *sdt++;
}

template <class T>
LightMatrix<T> LightMatrix<T>::transpose() const
{
  LightMatrix<T> res(_cols, _rows);
  for (size_t j = 0; j < _rows; ++j)
    for (size_t i = 0; i < _cols; ++i)
      res(i, j) = (*this)(j, i);
  return res;
}

template <class T>
LightMatrix<T>::LightMatrix(std::vector<std::vector<T>> const& values)
    : _rows(values.size()), _cols(values.front().size())
{
  _data.resize(_rows * _cols);
  for (size_t j = 0; j < _rows; ++j)
  {
    MREQUIRE_EQUAL(_cols, values[j].size(), "sizes do not match at row {}", j);
    assign_row(j, row_view(values[j].begin(), _cols));
  }
}
