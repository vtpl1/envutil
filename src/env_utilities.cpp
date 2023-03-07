// *****************************************************
//    Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#include "env_utilities.h"
#include <Poco/Environment.h>
#include <algorithm>
#include <string>

static inline void ltrim(std::string& s)
{
  s.erase(s.begin(),
          std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch) && !('_' == ch); }));
}

// trim from end (in place)
static inline void rtrim(std::string& s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch) && !('_' == ch); }).base(),
          s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s)
{
  rtrim(s);
  ltrim(s);
}
std::string vtpl::utilities::get_environment_value(const std::string& value, const std::string& default_value)
{
  std::string variable_name(value);
  trim(variable_name);
  // std::cout << "Searching for environment variable: " << variable_name << std::endl;

  if (Poco::Environment::has(variable_name)) {
    return Poco::Environment::get(variable_name);
  }
  std::transform(variable_name.begin(), variable_name.end(), variable_name.begin(), ::toupper);
  // std::cout << "Searching for environment variable: " << variable_name << std::endl;
  if (Poco::Environment::has(variable_name)) {
    return Poco::Environment::get(variable_name);
  }
  return default_value;
}
