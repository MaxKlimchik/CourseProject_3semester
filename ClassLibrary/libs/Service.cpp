#include "Service.hpp"

SpellCheck::SC_Service::SC_Service(const std::string &dictionary_path) :
    curr_service(Service_type::HashTable_Chain)
{
    dict = new Dictionary_RU(dictionary_path);
    UINT wcount = static_cast<UINT>(dict->WordsCount());
    sc_container = SC_Factory::CreateSC(curr_service, wcount);

    for (size_t word_idx = 0; word_idx < wcount; ++word_idx)
    {
        const std::wstring *word = &(*dict)[word_idx];
        sc_container->Register(word);
    }
}

void SpellCheck::SC_Service::SelectService(Service_type service_)
{
    if (curr_service == service_) return;

    curr_service = service_;
    delete sc_container;
    
    UINT wcount = static_cast<UINT>(dict->WordsCount());
    sc_container = SC_Factory::CreateSC(curr_service, wcount);
    for (size_t word_idx = 0; word_idx < wcount; ++word_idx)
    {
        const std::wstring *word = &(*dict)[word_idx];
        sc_container->Register(word);
    }
}

bool SpellCheck::SC_Service::CheckWord(const std::wstring &word) const
{
    return sc_container->Check(word);
}

SpellCheck::SC_Service::~SC_Service()
{
    delete sc_container;
    delete dict;
}
