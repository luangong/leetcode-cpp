load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test
# https://google.github.io/googletest/

GOOGLE_TEST_TAG = "release-1.12.1"
GOOGLE_TEST_SHA = "24564e3b712d3eb30ac9a85d92f7d720f60cc0173730ac166f27dda7fed76cb2"

http_archive(
    name = "googletest",
    url = "https://github.com/google/googletest/archive/%s.zip" % GOOGLE_TEST_TAG,
    sha256 = GOOGLE_TEST_SHA,
    strip_prefix = "googletest-%s" % GOOGLE_TEST_TAG,
)

# Abseil
# https://abseil.io/

ABSEIL_REF = "20220623.1"
ABSEIL_SHA = "54707f411cb62a26a776dad5fd60829098c181700edcd022ea5c2ca49e9b7ef1"

http_archive(
    name = "abseil",
    url = "https://github.com/abseil/abseil-cpp/archive/%s.zip" % ABSEIL_REF,
    sha256 = ABSEIL_SHA,
    strip_prefix = "abseil-cpp-%s" % ABSEIL_REF,
)

# Bazel Skylib (required by Abseil)
# https://github.com/bazelbuild/bazel-skylib

BAZEL_SKYLIB_TAG = "1.3.0"
BAZEL_SKYLIB_SHA = "4756ab3ec46d94d99e5ed685d2d24aece484015e45af303eb3a11cab3cdc2e71"

http_archive(
    name = "bazel_skylib",
    url = "https://github.com/bazelbuild/bazel-skylib/archive/%s.zip" % BAZEL_SKYLIB_TAG,
    sha256 = BAZEL_SKYLIB_SHA,
    strip_prefix = "bazel-skylib-%s" % BAZEL_SKYLIB_TAG,
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

# JSON
# https://github.com/nlohman/json

NLOHMANN_JSON_REF = "4c6cde72e533158e044252718c013a48bcff346c"
NLOHMANN_JSON_SHA = "bafcb307b92e57f53f6b4a9b18173243f7b59a2a797e4984de0a1eeae685b954"

http_archive(
    name = "nlohmann_json",
    url = "https://github.com/nlohmann/json/archive/%s.zip" % NLOHMANN_JSON_REF,
    sha256 = NLOHMANN_JSON_SHA,
    strip_prefix = "json-%s" % NLOHMANN_JSON_REF,
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor

BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF = "0197fc673a1a6035078ac7790318659d7442e27e"
BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA = "7ddcaba4c569fdcfe6b9355206fc1ff49a7f1b98f63938e72057649f9a0621d7"

http_archive(
    name = "hedron_compile_commands",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/%s.zip" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
    sha256 = BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA,
    strip_prefix = "bazel-compile-commands-extractor-%s" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
