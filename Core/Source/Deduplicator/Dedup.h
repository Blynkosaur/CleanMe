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
  std::map<std::string, std::vector<std::filesystem ::path>> fileHashmap;
  int dupeCount;
  std::vector<std::filesystem::path> paths;
  std::vector<std::string> duplicates;

public:
  Deduplicator(const std::vector<std::filesystem::path> &);
  std::string hashFile(std::string);
  void groupHashes();
  int getDupeCount();
  std::vector<std::string> &getDupes();
  void operator=(std::string newPath);
};
#endif
