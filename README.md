# Algorytm T9

## Czym jest T9?
lorem ipsum

## Jak działa T9?
T9 polega na utworzeniu specjalnego drzewa przechowującego słowa. 
Rozpoczynając od początkowego węzła o pustej wartości, do słowa można dotrzeć idąc wzdłuż kolejnych węzłów, które są coraz większymi fragmentami tego słowa.
> "" -> "c" -> "ca" -> "cat"

Węzeł "ca" posiada jako dzieci węzeł każdego słowa, które zaczyna się na "ca".
Każdy węzeł posiada dodatkowo flagę, czy jest słowem, czy jedynie fragmentem. Dzięki temu trafiając na węzeł "go" jesteśmy w stanie rozpoznać go jako słowo - mimo, że nie jest  liściem drzewa, jak większość innych słów.
> Nie każde słowo jest liściem, ale każdy liść jest słowem

## Moja implementacja

### Węzły
Klasa abstrakcyjna Node posiada dwa pola - typ, oznacząjący, czy węzeł jest kompletnym słowem, czy nie, oraz pole value, w którym jest przechowywany dany fragment słowa.
Inne elementy programu opierają się na Node, dzięki czemu konkretna implementacja węzła może być swobodnie zmieniana.

Zadaniem klas MapNode ora ArrayNode jest implementacja przechowywania wskaźników do swoich potomków.
Obydwie zawarte implementacje są funkcjonalne, ale obecnie korzystam z klasy MapNode, gdzie wskaźniki są przechowywane w mapie w parach **word_chunk : pointer**

### Drzewo Trie
lorem ipsum

### KeyPad
lorem ipsum

### Program
lorem ipsum