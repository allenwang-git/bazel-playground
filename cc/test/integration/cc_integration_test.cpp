#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "tools/cpp/runfiles/runfiles.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

// utils that's provided by the bazel to r/w files
bazel::tools::cpp::runfiles::Runfiles* runfiles = bazel::tools::cpp::runfiles::Runfiles::CreateForTest();

// Run a binary
int run_binary(const std::string& binary) {
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(binary.c_str(), "r"), pclose);

    if (!pipe) {
        std::cerr << "ERROR: Failed to run binary";
        return 1;
    }

    return 0;
}

/// @brief Test case for C Test
TEST(CcIntegrationTest, CTest) {
    run_binary("./cc/c_pub &");
    run_binary("./cc/c_sub & >>  ./tmp/c_sub_out.txt");
    const std::string c_sub_out_txt = runfiles->Rlocation("cc/test/integration/tmp/c_sub_out.txt");
    std::ifstream file(c_sub_out_txt);
    std::string c_sub_out;
    std::string line;
    if (!file.is_open()) {
        std::cerr << "ERROR: Failed to open output file";
        return;
    }
    while (std::getline(file, line)) {
        c_sub_out += line;
    }
    file.close();
    ASSERT_THAT(c_sub_out, testing::HasSubstr("[Subscriber] Received : Message (1, Hello World)"));
}

/// @brief Test case for C++ Test
TEST(CcIntegrationTest, CppTest) {
    run_binary("./cc/cc_pub &");
    run_binary("./cc/cc_sub & >> ./tmp/cpp_sub_out.txt");
    const std::string cpp_sub_out_txt = runfiles->Rlocation("cc/test/integration/tmp/cpp_sub_out.txt");
    std::ifstream file(cpp_sub_out_txt);
    std::string cpp_sub_out;
    std::string line;
    if (!file.is_open()) {
        std::cerr << "ERROR: Failed to open file";
        return;
    }
    while (std::getline(file, line)) {
        cpp_sub_out += line;
    }
    file.close();
    ASSERT_THAT(cpp_sub_out, testing::HasSubstr("[Subscriber] Message received: [userID: 1, message: Hello World]"));
}
