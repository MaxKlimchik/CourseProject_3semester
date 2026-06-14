#include <chrono>
#include <iostream>
#include <vector>
#include <windows.h>
#include "Service.hpp"
using namespace SpellCheck;
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    string path = "..\\dictionaries\\RU_ru\\united_russian.dic";
    vector<Service_type> to_init { Service_type::HashTable_Chain, Service_type::HashTable_DHash,
                                    Service_type::HashTable_Linear, Service_type::BloomFilter};
    vector<wstring> names { L"Хеш-таблица (метод цепочек)", L"Хеш-таблица (двойное хеширование)",
                            L"Хеш-таблица (линейное пробирование)", L"Фильтр Блума" };
    
    Dictionary_RU dict(path);
    SC_Service service(path);
    size_t wcount = dict.WordsCount();
    for (const auto& type : to_init)
    {
        service.SelectService(type);
        chrono::time_point<chrono::high_resolution_clock> begin = chrono::high_resolution_clock::now();

        for (size_t i = 0; i < wcount; ++i)
        {
            if (!service.CheckWord(dict[i]))
                wcout << names[(int)type] << L" не опознал слово " << dict[i] << endl;
        }

        chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - begin;
        wcout << names[(int)type] << L": " << chrono::duration_cast<chrono::milliseconds>(diff).count() << L"ms" << endl;
    }

    wcout << L"Нажмите клавишу, чтобы выйти...";
    getchar();
}