#include "Dedup.h"
#include <fstream>
#include <ios>
#include <vector>

int Deduplicator::getDupeCount() {
  for (auto &[hash, paths] : fileHashmap) {
    if (paths.size() > 1) {
      hasDupe = true;
      duplicates.push_back(hash);
      dupeCount++;
    }
  }
  return dupeCount;
}
std::vector<std::string> &Deduplicator::getDupes() { return duplicates; }

Deduplicator::Deduplicator(const std::vector<std::filesystem::path> &inputPaths)
    : paths(inputPaths), duplicates({}), fileHashmap({}), hasDupe(false) {}
void Deduplicator::operator=(std::string path) {}

std::string Deduplicator::hashFile(std::string path) {
  std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);
  if (!file.is_open()) {
    throw std::errc::io_error;
  }
  long fileSize = file.tellg();
  char *buffer = new char[fileSize];
  file.seekg(0, std::ios::beg);
  file.read(buffer, fileSize);
  file.close();

  unsigned char md5Buffer[MD5_DIGEST_LENGTH];
  MD5(reinterpret_cast<unsigned char *>(buffer), fileSize, md5Buffer);
  std::string stringHash = std::string(reinterpret_cast<char *>(md5Buffer));
#ifdef DEBUG
  std::cout << stringHash << std::endl;
#endif

  delete[] buffer;
  return stringHash;
};

void Deduplicator::groupHashes() {
  for (auto path : paths) {

    std::string hashed = hashFile(path);
    fileHashmap[hashed].push_back(path);
  }
};
