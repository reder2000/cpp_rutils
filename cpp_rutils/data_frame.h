#pragma once
#include "linalg.h"

// light DataFrame
template <typename _value_type, typename _index_type, typename _column_type>
struct LighDataFrame
{
  using value_type  = _value_type;
  using index_type  = _index_type;
  using column_type = _column_type;

  LighDataFrame() = default;
  LighDataFrame(LightMatrix<value_type>  data,
                std::vector<index_type>  index,
                std::vector<column_type> columns);


  LightMatrix<value_type>  _data;
  std::vector<index_type>  _index;
  std::vector<column_type> _columns;
};


// ----------------------------------------
// implementation
// ----------------------------------------

template <typename _value_type, typename _index_type, typename _column_type>
LighDataFrame<_value_type, _index_type, _column_type> make_LighDataFrame(
    LightMatrix<_value_type>  data,
    std::vector<_index_type>  index,
    std::vector<_column_type> columns)
{
  return LighDataFrame<_value_type, _index_type, _column_type>(data, index, columns);
}

template <typename _value_type, typename _index_type, typename _column_type>
LighDataFrame<_value_type, _index_type, _column_type>::LighDataFrame(
    LightMatrix<value_type>  data,
    std::vector<index_type>  index,
    std::vector<column_type> columns)
    : AM_(data), AM_(index), AM_(columns)
{
  MREQUIRE_EQUAL(_data.cols(), _columns.size());
  MREQUIRE_EQUAL(_data.rows(), _index.size());
}
