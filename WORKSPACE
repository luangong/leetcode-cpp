load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test
# https://github.com/google/googletest
# https://google.github.io/googletest/

GOOGLE_TEST_TAG = "1.14.0"
GOOGLE_TEST_SHA = "8ad598c73ad796e0d8280b082cebd82a630d73e73cd3c70057938a6501bba5d7"

http_archive(
    name = "googletest",
    url = "https://github.com/google/googletest/archive/v%s.tar.gz" % GOOGLE_TEST_TAG,
    sha256 = GOOGLE_TEST_SHA,
    strip_prefix = "googletest-%s" % GOOGLE_TEST_TAG,
)

# Abseil
# https://abseil.io/
# https://github.com/abseil/abseil-cpp

ABSEIL_REF = "20230802.0"
ABSEIL_SHA = "59d2976af9d6ecf001a81a35749a6e551a335b949d34918cfade07737b9d93c5"

http_archive(
    name = "abseil",
    url = "https://github.com/abseil/abseil-cpp/archive/%s.tar.gz" % ABSEIL_REF,
    sha256 = ABSEIL_SHA,
    strip_prefix = "abseil-cpp-%s" % ABSEIL_REF,
)

# Bazel Skylib (required by Abseil)
# https://github.com/bazelbuild/bazel-skylib

BAZEL_SKYLIB_TAG = "1.4.2"
BAZEL_SKYLIB_SHA = "66ffd9315665bfaafc96b52278f57c7e2dd09f5ede279ea6d39b2be471e7e3aa"

http_archive(
    name = "bazel_skylib",
    url = "https://github.com/bazelbuild/bazel-skylib/releases/download/%s/bazel-skylib-%s.tar.gz" % (BAZEL_SKYLIB_TAG, BAZEL_SKYLIB_TAG),
    sha256 = BAZEL_SKYLIB_SHA,
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

# YAML parser and emitter in C++
# https://github.com/jbeder/yaml-cpp

YAML_CPP_TAG = "0.8.0"
YAML_CPP_SHA = "fbe74bbdcee21d656715688706da3c8becfd946d92cd44705cc6098bb23b3a16"

http_archive(
    name = "yaml_cpp",
    url = "https://github.com/jbeder/yaml-cpp/archive/%s.tar.gz" % YAML_CPP_TAG,
    sha256 = YAML_CPP_SHA,
    strip_prefix = "yaml-cpp-%s" % YAML_CPP_TAG,
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor

# 2023-08-11
BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF = "e16062717d9b098c3c2ac95717d2b3e661c50608"
BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA = "ed5aea1dc87856aa2029cb6940a51511557c5cac3dbbcb05a4abd989862c36b4"

http_archive(
    name = "hedron_compile_commands",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/%s.tar.gz" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
    sha256 = BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA,
    strip_prefix = "bazel-compile-commands-extractor-%s" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
