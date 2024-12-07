# Rock-Paper-Scissors Game

## Descriere

Acest proiect implementează un joc Rock-Paper-Scissors (Piatră, Hârtie, Foarfecă) cu o interfață grafică simplă folosind SFML. Utilizatorul alege Rock (1), Paper (2) sau Scissors (3), iar calculatorul face o mutare aleatorie. Rezultatul (You Win, You Lose sau Draw) va fi afișat, împreună cu simbolurile corespunzătoare.

## Autor
Crăciunel Daniel 
An: 2024

## Reguli de Joc

- Rock bate Scissors.
- Scissors bate Paper.
- Paper bate Rock.
- Dacă ambele alegeri sunt la fel, este Draw.

## Dependențe

- **C++17** sau o versiune mai nouă.
- **SFML** pentru grafică. Asigurați-vă că SFML este instalat și că includeți calea către headere și librăriile dinamice/static.
- **Compilator**: g++ sau clang++.

## Compilare și Rulare

1. Clonați repository-ul:
   ```bash
   git clone https://github.com/username/rock-paper-scissors.git
   cd rock-paper-scissors
2. Compilați cu Makefile:
   make
3. Rulați executabilul
   ./bin/game
## Teste 
1. Testele sunt în directorul tests/, acestea pot fi compilate și rulate astfel:
   make test
   ./bin/test_gamedata
