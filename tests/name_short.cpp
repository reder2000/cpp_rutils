#include <name_short.h>

#include <unordered_map>
#include <iostream>


TEST(cpp_rutils,short_name_vector)
{
  const std::vector<int> toto;
  std::cout << type_name_short<decltype(toto)>() << std::endl;
  [[maybe_unused]] auto& toto_ref = toto;
  std::cout << type_name_short<decltype(toto_ref)>() << std::endl;
  std::vector<std::vector<int>> tototo;
  std::cout << type_name_short<decltype(tototo)>() << std::endl;
  std::unordered_map<int, decltype(tototo)> tata;
  std::cout << type_name_short<decltype(tata)>() << std::endl;
  std::shared_ptr<const std::vector<int>> sp;
  std::cout << type_name_short<decltype(sp)>() << std::endl;
}
