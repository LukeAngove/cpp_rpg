#ifndef GRPCTESTCLIENT_H
#define GRPCTESTCLIENT_H

#include <memory>

#include <grpcpp/grpcpp.h>
#include "test.grpc.pb.h"

class TestClient {
  public:
  TestClient(std::shared_ptr<grpc::Channel> channel);

  bool useAbility(const int abilityID);

  private:
  std::unique_ptr<PlayerService::Stub> _stub;

};

#endif
