#ifndef PARSER_H
#define PARSER_H
#include <filesystem>
#include <string>
#include <system_error>
#include <vector>
class Parser {
private:
  std::error_code errorStatus;
  std::filesystem::path workingDirectory;
  std::filesystem::recursive_directory_iterator iterator;
  std::vector<std::filesystem::path> allFiles;
  int folderSize{0};
  int errofFiles{0};

public:
  Parser(const std::string inputPath);
  Parser();
  void scan();
};
#endif
