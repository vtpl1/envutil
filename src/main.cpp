#include "env_utilities.h"
#include <iostream>

int main(int argc, char const* argv[])
{
  // $Env:DATA_DIR = "mydir"
  std::string _data_dir___;
  std::string default_value = "pwd";
  _data_dir___ = vtpl_utilities_get_environment_value(_data_dir___, default_value);
  std::cout << _data_dir___ << std::endl;
  return 0;
}
