cc_library(
    name = "helloworld",
    srcs = [
        "helloworld.hpp",
    ],
)

cc_test(
    name = "helloworld_test",
    srcs = [
        "helloworld_test.cpp",
    ],
    deps = [
        "helloworld",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)