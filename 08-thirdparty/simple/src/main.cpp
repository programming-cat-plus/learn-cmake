#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

int main(void)
{
    const char* host = "https://httpbin.io";
    const char* path = "/anything/hello";

    httplib::Client request{host};
    const auto response = request.Get(path);                                               
    std::cout << response->body << std::endl;
    return 0;
}
