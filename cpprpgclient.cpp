#include <grpcpp/grpcpp.h>

#include "apiclient.h"

int main(int argc, char **argv) {
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
    target_str = "0.0.0.0:50051";
  }
  APIClient testservice(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  int testValue = 1;
  bool reply = testservice.useAbility(testValue);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
