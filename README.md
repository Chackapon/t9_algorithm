# Algorytm T9

## Czym jest T9?
Algorytm T9 jest formą predictive text używanym na telefonach z klawiaturą numeryczną, gdzie każdy klawisz ma prypisany pewien zbiór liter. 
Zazwyczaj użytkownik musi nacisnąć klawisz odpowiednią ilość razy, aby uzyskać daną literę, lecz dzięki T9 musi zrobić to jedyny raz, a algorytm jest w stanie podpowiedzieć słowa, które są możliwe do uzyskania za pomocą podanych kombinacji klawiszy.

## Jak działa T9?
T9 polega na utworzeniu specjalnego drzewa przechowującego słowa. 
Rozpoczynając od początkowego węzła o pustej wartości, do słowa można dotrzeć idąc wzdłuż kolejnych węzłów, które są coraz większymi fragmentami tego słowa.
> "" -> "c" -> "ca" -> "cat"

Węzeł "ca" posiada jako dzieci węzeł każdego słowa, które zaczyna się na "ca".
Każdy węzeł posiada dodatkowo flagę, czy jest słowem, czy jedynie fragmentem. Dzięki temu trafiając na węzeł "go" jesteśmy w stanie rozpoznać go jako słowo - mimo, że nie jest  liściem drzewa, jak większość innych słów.
> Nie każde słowo jest liściem, ale każdy liść jest słowem

Przy wpisywaniu każdego kolejnego klawisza algorytm generuje kombinacje liter i sprawdza, które z nich są słowami, które są możliwymi fragmentami kolejnych słów, a które kombinacje są "śmieciowe".

## Moja implementacja

### Węzły
Klasa abstrakcyjna Node posiada dwa pola - typ, oznacząjący, czy węzeł jest kompletnym słowem, czy nie, oraz pole value, w którym jest przechowywany dany fragment słowa.
Inne elementy programu opierają się na Node, dzięki czemu konkretna implementacja węzła może być swobodnie zmieniana.

Zadaniem klas MapNode ora ArrayNode jest implementacja przechowywania wskaźników do swoich potomków.
Obydwie zawarte implementacje są funkcjonalne, ale obecnie korzystam z klasy MapNode, gdzie wskaźniki są przechowywane w mapie w parach **word_chunk : pointer**

### Drzewo T9_Trie
Drzewo składa się z węzłów node. Posiada metode odpowiedzialna za dodawanie słów do drzewa. Każde słowo jest po kolei iterowane dodająć kolejne litery do word chunka i dodawane do drzewa jako odpowiednie potomki do już istenijących węzłów lub tworząc nowe.

### KeyPad
Symulacja klawiatury numerycznej telefonu. Klawisze są dodawane do mapy parami **znak klawisza:zbiór liter**.
Klasa posiada też metody potrzebne do wygenerowania tekstowej reprezentacji klawiatury.

### Program
Klasa Program zawiera w sobie pola KeyPad oraz T9_Trie. Jest odpowiedzialna za zarządzanie wczytywaniem klawiszy oraz bazy słów z pliku, wyszukiwaniem słów w drzewie oraz czyszczeniem wyszukiwania.
Metoda wyszukująca search wczytuje klawisz a następnie tworzy iloczyn kartezjański z kandydatów z poprzednich wyszukiwań oraz zbioru liter przypisanych do wczytanego klawisza, zwracając listę kandydatów, których węzły posiadają flagę prawdziwego słowa.

### Plik main
Użytkowa implementacja klasy Program. Program jest wywoływany na zasadzie:
> ./nazwa_programu <sciezka_do_pliku_ze_slowami> <sciezka_do_pliku_z_klawiszami>

Najpierw następuje inicjalizacja obiektu Program razem z wczytaniem podanych plików tekstowych.
Główną częścia programu jest pętla wyświetlająca tekstowa reprezentację klawiatury, wczytująca wpisane numery klawiszy i odpowiednio je obsługująca. Posiada (na razie wszyte w kod) specjalne klawisze:
* <span>*</span> - odpowiada za przeglądanie zasugerowanych słów
* <span>#</span> - czyszczenie wyszukiwania
* <span>0</span> - kończy działanie programu

