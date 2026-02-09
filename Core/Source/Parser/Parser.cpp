#include "Parser.h"
#include <filesystem>
#include <system_error>
class Parser {
private:
  std::error_code errorStatus;
  std::filesystem::path workingDirectory;
  std::filesystem::recursive_directory_iterator iterator;
  int folderSize{0};
  int errofFiles{0};

public:
  Parser(const std::string inputPath)
      : workingDirectory{std::filesystem::path(inputPath)},
        iterator{std::filesystem::recursive_directory_iterator(workingDirectory,
                                                               errorStatus)} {
    if (errorStatus) {
      workingDirectory = std::filesystem::current_path();
      iterator = std::filesystem::recursive_directory_iterator(
          std::filesystem::current_path());
    }
  }
  Parser()
      : workingDirectory{std::filesystem::current_path()}, errorStatus{},
        iterator{
            std::filesystem::recursive_directory_iterator(workingDirectory)} {}
};
