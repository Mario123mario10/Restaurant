
// #include <iostream>
// using std::cout;	using std::cin;	using std::endl;

// #include <string>
// using std::string;

// #include <vector>
// using std::vector;

// #include <memory>
// using std::unique_ptr; using std::make_unique;

// #include <regex>
// using std::regex;  using std::smatch;  using std::regex_search;  using std::regex_match;

// using std::move;

// #include "Danie.hpp"
// #include "Deser.hpp"
// #include "Menu.hpp"

// int main()
// {
//     Menu menu;
//     unique_ptr<Danie> danie1 = make_unique<Deser>("Budyń", 20);
//     unique_ptr<Danie> danie2 = make_unique<Deser>("Kisiel", 20);
//     unique_ptr<Danie> danie3 = make_unique<Deser>("Budyń", 20);

//     cout << ("Budyń" == "Budyń") << endl;
//     menu.wyswietl_menu();
//     menu.dodaj_danie(move(danie1));
//     menu.dodaj_danie(move(danie2));
//     menu.wyswietl_menu();
//     menu.kasuj_danie(move(danie3));
//     menu.wyswietl_menu();



//     return 0;
// }



