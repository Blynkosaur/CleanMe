#include "./Parser.h"
Parser::Parser(const std::string inputPath)
    : workingDirectory{std::filesystem::path(inputPath)},
      iterator{std::filesystem::recursive_directory_iterator(workingDirectory,
                                                             errorStatus)} {
  if (errorStatus) {
    workingDirectory = std::filesystem::current_path();
    iterator = std::filesystem::recursive_directory_iterator(
        std::filesystem::current_path());
  }
}
Parser::Parser()
    : workingDirectory{std::filesystem::current_path()}, errorStatus{},
      iterator{
          std::filesystem::recursive_directory_iterator(workingDirectory)} {}
void Parser::scan() {}
