#ifndef APICLIENT_H
#define APICLIENT_H

#include <memory>

#include "cpprpg.grpc.pb.h"
#include <grpcpp/grpcpp.h>

class APIClient {
public:
  APIClient(std::shared_ptr<grpc::Channel> channel);

  bool useAbility(const int abilityID);

private:
  std::unique_ptr<PlayerService::Stub> _stub;
};

#endif
