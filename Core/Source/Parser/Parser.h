#ifndef PARSER_H
#define PARSER_H
#include <filesystem>
#include <string>
#include <system_error>
class Parser {
private:
  std::error_code errorStatus;
  std::filesystem::path workingDirectory;
  std::filesystem::recursive_directory_iterator iterator;
  int folderSize{0};
  int errofFiles{0};

public:
  Parser(const std::string inputPath);
  Parser();
};
#endif
