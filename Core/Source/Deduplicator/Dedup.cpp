#include "Dedup.h"

int Deduplicator::getDupeCount() { return dupeCount; }

Deduplicator::Deduplicator(const std::vector<std::filesystem::path> &inputPaths)
    : paths(inputPaths) {}
