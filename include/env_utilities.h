// *****************************************************
//    Copyright 2023 Videonetics Technology Pvt Ltd
// *****************************************************

#pragma once
#ifndef file_utilities_h
#define file_utilities_h

#include <string>
#include <envutil_export.h>
#include <version.h>

namespace vtpl
{
namespace utilities
{
#define vtpl_utilities_get_environment_value(value, default_value)  vtpl::utilities::get_environment_value(#value, default_value)

std::string ENVUTIL_EXPORT get_environment_value(const std::string& value, const std::string& default_value);
} // namespace utilities
} // namespace vtpl
#endif // file_utilities_h
