#include <grpcpp/grpcpp.h>

#include "test.grpc.pb.h"

class TestClient {
 public:
  TestClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(TestService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  bool TestProto(const bool& user) {
    // Data we are sending to the server.
    Test request;
    request.set_testbool(user);

    // Container for the data we expect from the server.
    Test reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->TestProto(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.testbool();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return false;
    }
  }

 private:
  std::unique_ptr<TestService::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target="
                  << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:50051";
  }
  TestClient testservice(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  bool testValue = true;
  bool reply = testservice.TestProto(testValue);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
