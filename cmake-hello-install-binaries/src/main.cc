#include "absl/log/initialize.h"
#include "absl/log/log.h"
#include "absl/strings/str_cat.h"
#include <iostream>

int main(int argc, const char **argv) {
  for (int i = 0; i < argc; ++i) {
    LOG(INFO) << absl::StrCat("Arg ", i, ": ", argv[i], "\n");
  }
}
