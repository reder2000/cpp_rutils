#pragma once

#include <memory>


class CloneableBase
{
 protected:
  virtual CloneableBase *clone_impl() const = 0;
};

template <typename Derived>
class UniquePtrCloneableBase : public CloneableBase
{
 public:
  std::unique_ptr<Derived> clone() const
  {
    return std::unique_ptr<Derived>(static_cast<Derived *>(this->clone_impl()));
  }
};

template <typename Derived>
class SharedPtrCloneableBase : public CloneableBase
{
 public:
  std::shared_ptr<Derived> clone() const
  {
    return std::shared_ptr<Derived>(static_cast<Derived *>(this->clone_impl()));
  }
};
