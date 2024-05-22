#pragma once
#include "light_matrix.h"
#include "always_false.h"
#include <cmath>

template <class T>
constexpr bool isempty(T t)
{
  static_assert(always_false_v<T>);
  return false;
}

template <class T>
concept has_isnan = requires { std::is_same_v<bool, decltype(std::isnan(T{}))>; };

template <has_isnan T>
constexpr bool isempty(T t)
{
  return std::isnan(t);
}

template <class T>
concept has_empty = requires { std::is_same_v<bool, decltype(T{}.empty())>; };

template <has_empty T>
constexpr bool isempty(const T &t)
{
  return t.empty();
}

enum class Axis
{
  index,
  column
};

// light DataFrame
template <typename _value_type, typename _index_value_type, typename _column_value_type>
struct LightDataFrame
{
  using value_type        = _value_type;
  using index_value_type  = _index_value_type;
  using column_value_type = _column_value_type;
  using data_type         = LightMatrix<value_type>;
  using index_type        = std::vector<index_value_type>;
  using columns_type      = std::vector<column_value_type>;


  LightDataFrame() = default;
  LightDataFrame(data_type data, index_type index, columns_type columns);


  LightDataFrame<value_type, column_value_type, index_value_type> transpose() const;

  LightDataFrame dropna(Axis axis = Axis::index) const;


  data_type    _data;
  index_type   _index;
  columns_type _columns;
};


// ----------------------------------------
// implementation
// ----------------------------------------

template <typename _value_type, typename _index_type, typename _column_type>
LightDataFrame<_value_type, _index_type, _column_type> make_LightDataFrame(
    LightMatrix<_value_type>  data,
    std::vector<_index_type>  index,
    std::vector<_column_type> columns)
{
  return LightDataFrame<_value_type, _index_type, _column_type>(data, index, columns);
}

template <typename _value_type, typename _index_value_type, typename _column_value_type>
LightDataFrame<_value_type, _index_value_type, _column_value_type>::LightDataFrame(
    data_type    data,
    index_type   index,
    columns_type columns)
    : AM_(data), AM_(index), AM_(columns)
{
  MREQUIRE_EQUAL(_data.cols(), _columns.size());
  MREQUIRE_EQUAL(_data.rows(), _index.size());
}

template <typename _value_type, typename _index_value_type, typename _column_value_type>
LightDataFrame<_value_type, _column_value_type, _index_value_type>
LightDataFrame<_value_type, _index_value_type, _column_value_type>::transpose() const
{
  data_type res_data = _data.transpose();
  return make_LightDataFrame(res_data, _columns, _index);
}

template <typename _value_type, typename _index_type, typename _column_type>
LightDataFrame<_value_type, _index_type, _column_type>
LightDataFrame<_value_type, _index_type, _column_type>::dropna(Axis axis) const
{
  if (axis == Axis::column) return transpose().dropna(Axis::index).transpose();
  // find empty rows
  std::vector<size_t> keep_rows;
  const int           N         = _columns.size();
  auto                row_empty = [&](size_t j)
  {
    size_t i = 0;
    for (; i < N && isempty(_data(j, i)); ++i)
      ;
    return i == N;
  };
  for (size_t j = 0; j < _index.size(); ++j)
    if (! row_empty(j)) keep_rows.push_back(j);
  if (keep_rows.size() == _data.rows()) return *this;
  if (! keep_rows.size())
    return make_LightDataFrame(LightMatrix<value_type>(0, _columns.size()), index_type{}, _columns);
  data_type  res_data(keep_rows.size(), _columns.size());
  index_type res_index(keep_rows.size());
  for (size_t j = 0; j < keep_rows.size(); ++j)
  {
    size_t k = keep_rows[j];
    res_data.assign_row(j, _data.get_row_view(k));
    res_index[j] = _index.data()[k];
  }
  return make_LightDataFrame(res_data, res_index, _columns);
}
