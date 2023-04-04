load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")

cc_library(
  name = "board",
  srcs = [
    "board.cpp",
    "element.cpp",
    "movemap.cpp",
    "sphere.cpp",
  ],
  hdrs = [
    "board.h",
    "element.h",
    "movemap.h",
    "sphere.h",
    "move.h",
  ],
)

cc_library(
  name = "api",
  srcs = [
    "api.cpp",
  ],
  hdrs = [
    "api.h",
  ],
)

cc_library(
  name = "grpcapiclient",
  srcs = [
    "grpctestclient.cpp",
  ],
  hdrs = [
    "grpctestclient.h",
  ],
  deps = [
    ":test_cc_proto",
  ],
)
cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":board",
  ],
)

cc_test(
  name = "boardtest",
  size = "small",
  srcs = ["boardtest.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":board",
  ],
)

proto_library(
    name = "test_proto",
    srcs = ["test.proto"],
)

cpp_grpc_library(
    name = "test_cc_proto",
    protos = [":test_proto"],
)

cc_test(
  name = "apitest",
  size = "small",
  srcs = ["apitest.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":api",
  ],
)

cc_binary(
  name = "grpctestclass",
  srcs = ["grpctestclass.cpp"],
  deps = [
    ":test_cc_proto",
  ],
)

cc_binary (
  name = "grpctestclient",
  srcs = ["grpctestclientexe.cpp",],
  deps = [
    ":grpcapiclient",
  ],
)
