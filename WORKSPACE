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

# YAML parser and emitter in C++
# https://github.com/jbeder/yaml-cpp

YAML_CPP_REF = "1b50109f7bea60bd382d8ea7befce3d2bd67da5f"
YAML_CPP_SHA = "40ece1e7e4b3d075d92c58eaa2a16948518cd2d303152cfcb6eb3dab8f3b9ee7"

http_archive(
    name = "yaml_cpp",
    url = "https://github.com/jbeder/yaml-cpp/archive/%s.zip" % YAML_CPP_REF,
    sha256 = YAML_CPP_SHA,
    strip_prefix = "yaml-cpp-%s" % YAML_CPP_REF,
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
