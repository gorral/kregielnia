# kregielnia [![Build Status](https://www.travis-ci.org/gorral/kregielnia.svg?branch=master)](https://www.travis-ci.org/gorral/kregielnia)

Obsługa kręgielni
========================
Wymagania:
----------------------------------------
- liczenie punktów cząstkowych (dla niepełnych ramek): 3-|X|4/|5
- liczenie punktów całościowych (szczegóły w załączniku)
- walidacja inputu z niepełnymi ramkami dla kilku graczy w poniższym formacie:
~~~~~~
Name1:X|4-|3
Name2:34|X|0-
:X|22|33
~~~~~~
- input z wielu plików w jednym katalogu, każdy plik z kilkoma graczami reprezentuje inny tor (zalecane użycie boost filesystem library lub https://en.cppreference.com/w/cpp/experimental/fs z C++17, uwaga na problemy z CI)
- wyświetlanie wyników na ekranie z podziałem na tory (ze statusem gry) i graczy oraz zapis do jednego pliku:
~~~~~~
### Lane 1: game in progress ###
Name1 30
Name2 44
34
### Lane 2: no game ###
### Lane 3: game finished ###
Michael 100
Radek 288
~~~~~~

Wymagania organizacyjne:
---------------------------------------------
- tablica dla projektu z podziałem na karteczki po planningu. Dodajcie też mnie abym mógł dodawać karteczki
- Continuous Integration
- praca przez pull requesty (każdy request ma mieć nr i opis z karteczki, musi przejść **Code Review** preferowane narzędzie [Codacy](https://www.codacy.com/) - zawsze musi być komentarz, przynajmniej że wszystko jest ok)
- zawartość tablicy może się zmieniać w miarę odkrywania nowych wymagań (i na pewno to co założycie na początku się zmieni i dojdzie dużo rzeczy, których nie przewidzieliście)
- od samego początku praca w trybie TDD
- każda funkcjonalność musi być przetestowana
- każdy musi dostarczyć jakieś zadanie z tablicy

Grupa 1:
------
- Justi
- matijaz
- Adam
- AndrzejBarecki
- bak83

