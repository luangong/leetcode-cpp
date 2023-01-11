package(default_visibility = ["//visibility:public"])

cc_library(
    name = "util",
    srcs = ["common/util.cc"],
    hdrs = ["common/util.h"],
    includes = ["."],
    deps = [
        # "@googletest//:gtest",
        "@nlohmann_json//:json",
        "@abseil//absl/flags:flag",
    ],
)

cc_library(
    name = "main",
    srcs = ["common/main.cc"],
    deps = [
        "@googletest//:gtest",
        "@abseil//absl/flags:flag",
        "@abseil//absl/flags:parse",
    ],
)
