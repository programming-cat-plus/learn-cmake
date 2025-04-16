#include <gtest/gtest.h>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

// Demonstrate some basic assertions.
TEST(DemoTest, StatusOK) {
    const char* host = "https://httpbin.io";
    const char* path = "/anything/hello";

    httplib::Client request{host};
    const auto response = request.Get(path);                                               
    EXPECT_EQ(response->status, 200);
}

TEST(DemoTest, Status404) {
    const char* host = "https://httpbin.io";
    const char* path = "/hidden-basic-auth/user/passwd";

    httplib::Client request{host};
    const auto response = request.Get(path);                                               
    EXPECT_EQ(response->status, 404);
}

TEST(DemoTest, Base64) {
    const char* host = "https://httpbin.io";
    const char* path = "/base64/aGVsbG8gd29ybGQ=";

    httplib::Client request{host};
    const auto response = request.Get(path);                                               
    EXPECT_EQ(response->body, "hello world");
}
