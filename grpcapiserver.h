#ifndef GRPCAPISERVER_H
#define GRPCAPISERVER_H

#include <tuple>
#include <memory>
#include <grpcpp/grpcpp.h>

std::tuple<std::unique_ptr<grpc::Server>, std::unique_ptr<grpc::Service>> RunServer();

#endif