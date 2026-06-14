#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>
#include "Service.hpp"
using namespace SpellCheck;
using namespace std;

wstring utf8_to_wstring(const string& utf8_str)
{
    if (utf8_str.empty()) return L"";

    int len = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, nullptr, 0);
    if (len == 0) return L"";

    wstring result(len - 1, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, &result[0], len);

    return result;
}

void SelectServiceMenu()
{
    wcout << L" [1] Хеш-таблица (метод цепочек)" << endl;
    wcout << L" [2] Хеш-таблица (двойное хеширование)" << endl;
    wcout << L" [3] Хеш-таблица (линейное пробирование)" << endl;
    wcout << L" [4] Фильтр Блума" << endl;
    wcout << L" [0] Выход" << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    string path = "..\\dictionaries\\RU_ru\\united_russian.dic";
    SC_Service SpellCheck(path);

    string input_utf8 = "0";
    int option = -1;
    while (option != 0) 
    {
        if (input_utf8 == "0")
        {
            SelectServiceMenu();
            do
            {
                cin >> option;
                if (option < 0 || option > 4)
                    wcout << L"Такой опции нет" << endl;
                else if (option > 0 && option < 5)
                {
                    wcout << L"Загрузка словаря" << endl;
                    SpellCheck.SelectService(static_cast<Service_type>(option - 1));
                    wcout << L"Словарь загружен" << endl;
                }
            } while (option < 0 || option > 4);

            if (option != 0)
                wcout << L"Введите '0', чтобы выйти в меню." << endl;
        }
        if (option == 0) break;

        wcout << L"Слово: ";
        cin >> input_utf8;
        
        if (input_utf8 == "0") continue;
        
        wstring input_word = utf8_to_wstring(input_utf8);

        if (SpellCheck.CheckWord(input_word))
            wcout << L"Есть в словаре" << endl;
        else {
            wcout << L"В словаре не нашёл" << endl;
        }
    }
}