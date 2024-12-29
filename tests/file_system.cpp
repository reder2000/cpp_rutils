
#include <filesystem>
#include <format.h>



TEST(cpp_rutils, file_system)
{
  std::filesystem::path p = std::filesystem::current_path();
  auto                  s = std__format("Current path: {}", p);
  std::cout << s << std::endl;
}
