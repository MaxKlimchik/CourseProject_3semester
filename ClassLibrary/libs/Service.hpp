#pragma once

#include "NearestPrime.hpp"
#include "Dictionary_RU.hpp"
#include "SC_Bloom_filter.hpp"
#include "SC_HT_Chain.hpp"
#include "SC_HT_DoubleHash.hpp"
#include "SC_HT_Linear.hpp"
#include "SC_SimpleFactory.hpp"

namespace SpellCheck { class SC_Service; }

class SpellCheck::SC_Service
{
private:
    Dictionary_RU *dict;
    ISpellCheck* sc_container;
    Service_type curr_service;

public:
    SC_Service(const std::string &dictionary_path);
    void SelectService(Service_type service_);
    bool CheckWord(const std::wstring &word) const;
    ~SC_Service();
};