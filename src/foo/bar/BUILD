cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    data = [":data.txt"],
    deps = [
        "//src:util",
        "@googletest//:gtest",
        "@abseil//absl/flags:flag",
        "@abseil//absl/flags:parse",
    ],
    args = [
        "--path=$(location :data.txt)",
    ],
)
