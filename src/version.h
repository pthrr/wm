#pragma once

#include <format>
#include <string>
#include <string_view>

#include "types.h"

namespace version {

constexpr i8 PROJECT_VERSION_MAJOR{ 0 };
constexpr i8 PROJECT_VERSION_MINOR{ 1 };
constexpr i8 PROJECT_VERSION_PATCH{ 0 };

struct Version
{
    i8 major = -1;
    i8 minor = -1;
    i8 patch = -1;
};

constexpr Version PROJECT_VERSION{ PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH };

#ifdef NDEBUG
constexpr bool IS_DEBUG = false;
#else
constexpr bool IS_DEBUG = true;
#endif

constexpr std::string_view BUILD_VERSION{ "<COMMIT_SHA>" };
constexpr std::string_view BUILD_TYPE{ IS_DEBUG ? "DEBUG" : "RELEASE" };

auto getVersionInfo() -> std::string
{
    return std::format( "{}.{}.{}", PROJECT_VERSION.major, PROJECT_VERSION.minor, PROJECT_VERSION.patch );
}

auto getBuildInfo() -> std::string
{
    std::string version{ BUILD_VERSION };
    std::string type{ BUILD_TYPE };

    if( version == "<COMMIT_SHA>" or version.empty() ) {
        return type;
    }

    return std::format( "{}-{}", version, type );
}

} // namespace version
