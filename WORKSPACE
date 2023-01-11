load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test
# https://google.github.io/googletest/
# https://github.com/google/googletest

GOOGLE_TEST_TAG = "1.13.0"
GOOGLE_TEST_SHA = "ffa17fbc5953900994e2deec164bb8949879ea09b411e07f215bfbb1f87f4632"

http_archive(
    name = "googletest",
    url = "https://github.com/google/googletest/archive/v%s.zip" % GOOGLE_TEST_TAG,
    sha256 = GOOGLE_TEST_SHA,
    strip_prefix = "googletest-%s" % GOOGLE_TEST_TAG,
)

# Abseil
# https://abseil.io/
# https://github.com/abseil/abseil-cpp

ABSEIL_REF = "20230125.3"
ABSEIL_SHA = "51d676b6846440210da48899e4df618a357e6e44ecde7106f1e44ea16ae8adc7"

http_archive(
    name = "abseil",
    url = "https://github.com/abseil/abseil-cpp/archive/%s.zip" % ABSEIL_REF,
    sha256 = ABSEIL_SHA,
    strip_prefix = "abseil-cpp-%s" % ABSEIL_REF,
)

# Bazel Skylib (required by Abseil)
# https://github.com/bazelbuild/bazel-skylib

BAZEL_SKYLIB_TAG = "1.4.1"
BAZEL_SKYLIB_SHA = "b8a1527901774180afc798aeb28c4634bdccf19c4d98e7bdd1ce79d1fe9aaad7"

http_archive(
    name = "bazel_skylib",
    url = "https://github.com/bazelbuild/bazel-skylib/releases/download/%s/bazel-skylib-%s.tar.gz" % (BAZEL_SKYLIB_TAG, BAZEL_SKYLIB_TAG),
    sha256 = BAZEL_SKYLIB_SHA,
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

# YAML parser and emitter in C++
# https://github.com/jbeder/yaml-cpp

# 2023-03-23
YAML_CPP_REF = "0e6e28d1a38224fc8172fae0109ea7f673c096db"
YAML_CPP_SHA = "2550c8447e173bbb9a0880dfb6d477dbdbbec7349ea8c87bdeacdcb0dbbb3989"

http_archive(
    name = "yaml_cpp",
    url = "https://github.com/jbeder/yaml-cpp/archive/%s.zip" % YAML_CPP_REF,
    sha256 = YAML_CPP_SHA,
    strip_prefix = "yaml-cpp-%s" % YAML_CPP_REF,
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor

# 2023-05-05
BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF = "80ac7efb33a65f0cc627635e5b958ea3eb03231d"
BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA = "5dbef97aa8c0ca5cf4ec0f50796f660338f69e63becda048f250d1ab833a4042"

http_archive(
    name = "hedron_compile_commands",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/%s.zip" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
    sha256 = BAZEL_COMPILE_COMMANDS_EXTRACTOR_SHA,
    strip_prefix = "bazel-compile-commands-extractor-%s" % BAZEL_COMPILE_COMMANDS_EXTRACTOR_REF,
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
