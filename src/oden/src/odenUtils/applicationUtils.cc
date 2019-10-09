#include "oden/odenUtils/applicationUtils.hh"

#include <assert.h>
#include <iostream>
#include <sys/time.h>

namespace oden {
namespace applicationUtils {

namespace /* anon */ {

std::string NowTime() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    char buffer[100];
    tm r;
    strftime(buffer, sizeof(buffer), "%X", localtime_r(&tv.tv_sec, &r));
    char result[100];
    snprintf(result, 100, "%s" /*.%06ld"*/, buffer /*, (long)tv.tv_usec*/);
    return result;
}

} // namespace

void _oden_internal_messageInfo(const std::string &message) {
    std::cout << "[INFO] " << NowTime() << " - "
              << "Message: " << message << std::endl;
    std::cout.flush();
}

void _oden_internal_messageWarning(const std::string &file, unsigned int line,
                                   const std::string &message) {
    std::cout << "[WARNING] " << NowTime() << " - "
              << "File: " << file << " -- "
              << "Line: " << line << std::endl
              << "\tMessage: " << message << std::endl;

    std::cout.flush();
}

void _oden_internal_messageError(const std::string &file, unsigned int line,
                                 const std::string &message) {
    std::cerr << "[ERROR] " << NowTime() << " - "
              << "File: " << file << std::endl
              << "Line: " << line << std::endl
              << "Message: " << message << std::endl;

    std::cerr.flush();
    assert(false);
    exit(1);
}

} // namespace applicationUtils
} // namespace oden
