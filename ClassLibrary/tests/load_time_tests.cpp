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
    vector<Service_type> to_init { Service_type::BloomFilter, Service_type::HashTable_Chain,
                                    Service_type::HashTable_DHash, Service_type::HashTable_Linear };
    vector<wstring> names { L"Хеш-таблица (метод цепочек)", L"Хеш-таблица (двойное хеширование)",
                            L"Хеш-таблица (линейное пробирование)", L"Фильтр Блума" };
    
    wcout << L"Время загрузки словаря" << endl;
    SC_Service *service = new SC_Service(path);
    for (const auto& type : to_init)
    {
        chrono::time_point<chrono::high_resolution_clock> begin = chrono::high_resolution_clock::now();

        service->SelectService(type);

        chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - begin;
        wcout << names[(int)type] << L": " << chrono::duration_cast<chrono::milliseconds>(diff).count() << L"ms" << endl;
    }
    delete service;
}