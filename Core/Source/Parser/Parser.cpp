#include "Parser.h"
#include <filesystem>

class Parser {
public:
  Parser(const std::string inputPath)
      : workingDirectory{std::filesystem::path(inputPath)} {}

private:
  std::filesystem::path workingDirectory;

  int folderSize{0};
  int errofFiles{0};
};
