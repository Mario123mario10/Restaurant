
//Akcje klienta i kelnera są już praktycznie nieaktualne

// enum Akcje_klienta
// {
//     Dosiadanie_sie_do_stolika,
//     Zastanawianie_się_nad_wyborem_dan,
//     Trwa_jedzenie_posilku,
//     Zakonczenie_posilku,
//     Zaplata_rachunku,
//     Wyjscie_z_restauracji


// enum Akcje_kelnera
// {
//     Podanie_menu_do_klienta,
//     Odebranie_zamowienia_od_stolika,
//     Podanie_dan_do_stolika,
//     Podanie_rachunku_klientom_przez_kelnera,
// };



// to jest aktualna kolejność ale mogą być różnice w tym co jest w programie

// };

// Wlasciwa kolejnosc:
//     Dosiadanie_się_do_stolika_nowych_klientow, // klienta lub klientów ale tylko do pustego stolika
//     Podanie_menu_do_klienta, // zakładamy że od razu po przysiedzeniu się pierwszych klientów do stolika od razu kelner podaje menu
//     Zastanawianie_się_nad_wyborem_dan,
//     Przyjscie_kolejnych_osob_do_tego_samego_stolika, // to się może wykonać wiele razy, ważne jest to aby starczało zawsze stolików w restauracji
//Tutaj może się wykonać albo przyjście jeszcze raz albo już odebranie zamówienia


//     Odebranie_zamowienia_od_stolika,  //Sytuacja, gdy już wszyscy zasiedli przy stoliku którzy powinni i kelner odbiera zamówienie
//     Podanie_dan_do_stolika,
//     Trwa_jedzenie_posilku,
//chodzi znowu o to aby wystarczyło stolików w restauracji, // będzie się pojawiało co 10 minut
//     Zakonczenie_posilku,         //kelner widzi ze wszyscy zakonczyli posilek i od razu
//     Podanie_rachunku_klientom_przez_kelnera,
//     Zaplata_rachunku,
//     Wyjscie_z_restauracji,
//     Przygotowanie_stolu_dla_nowych_klientow
