#ifndef RATATOSK_ALIGNMENT_HPP
#define RATATOSK_ALIGNMENT_HPP

#include <iostream>
#include <cfloat>
#include <cmath>

#include "edlib.h"
#include "Path.hpp"
#include "ResultCorrection.hpp"
#include "TinyBloomFilter.hpp"
#include "UnitigData.hpp"

pair<int, int> selectBestAlignment(const vector<Path<UnitigData>>& candidates, const char* ref, const size_t len_ref);

pair<int, int> selectBestPrefixAlignment(const char* ref, const size_t ref_len, const vector<Path<UnitigData>>& candidates, const double cut_threshold_norm_edit = -1.0);
pair<int, int> selectBestPrefixAlignment(const char* ref, const size_t ref_len, const vector<const Path<UnitigData>*>& candidates, const double cut_threshold_norm_edit = -1.0);

pair<int, pair<int, int>> selectBestPrefixAlignment2(const char* ref, const size_t ref_len, const vector<Path<UnitigData>>& candidates, const bool get_end_location);

pair<string, string> generateConsensus(const ResultCorrection* fw_s, const ResultCorrection* bw_s, const string& ref_seq, const double max_norm_edit_distance = -1.0);

void fixAmbiguity(const CompactedDBG<UnitigData>& dbg, string& query, string& quality, const vector<pair<size_t, char>>& v_ambiguity, const char* ref_seq, const char* ref_qual, const size_t ref_len, const size_t min_qual, const bool force_fix = false);

pair<int, int> selectBestSubstringAlignment(const char* ref, const size_t ref_len, const vector<Path<UnitigData>>& candidates, const double cut_threshold_norm_edit = -1.0);

#endif