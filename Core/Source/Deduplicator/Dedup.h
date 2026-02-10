#define DEBUG
#ifndef DDUP_H

#define DDUP_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <openssl/md5.h>
#include <string>
#include <vector>
class Deduplicator {

private:
  bool hasDupe;
  std::map<int, int> goon;
  std::map<std::string, std::vector<std::string>> fileHashmap;
  int dupeCount;
  std::vector<std::filesystem::path> paths;

public:
  Deduplicator(const std::vector<std::filesystem::path> &);
  std::string hashFile(std::string);
  void groupHashes();
  int getDupeCount();
  void operator=(std::string newPath);
};
#endif
