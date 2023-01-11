cc_test(
    name = "test",
    size = "small",
    srcs = ["solution.cc"],
    deps = [
        "//src:util",
        "//src:main",
        "@googletest//:gtest",
        "@nlohmann_json//:json",
        "@abseil//absl/flags:flag",
        "@abseil//absl/flags:parse",
    ],
    data = [":testcases.json"],
    args = [
        "--testcases=$(location :testcases.json)",
    ],
)
