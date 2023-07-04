#ifndef APISERVER_H
#define APISERVER_H

#include <tuple>
#include <memory>
#include <grpcpp/grpcpp.h>

std::tuple<std::unique_ptr<grpc::Server>, std::unique_ptr<grpc::Service>> RunServer();

#endif