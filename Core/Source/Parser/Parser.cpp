#include "Parser.h"
#include <filesystem>

class Parser {
private:
  std::filesystem::path workingDirectory;
  std::filesystem::recursive_directory_iterator iterator;
  int folderSize{0};
  int errofFiles{0};

public:
  Parser(const std::string inputPath)
      : workingDirectory{std::filesystem::path(inputPath)},
        iterator{
            std::filesystem::recursive_directory_iterator(workingDirectory)} {}
  Parser() : workingDirectory{std::filesystem::current_path()} {}
};
