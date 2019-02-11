<raileanu.arina1@gmail.com>
			
			Structura testelor
						
Algoritmii alesi de mine sunt: Floyd-Warshall, Bellman-Ford si Johnson. Pe
langa ei, am implementat in plus si algoritmul Dijkstra folosind o coada cu
prioritati.La algoritmul Bellman-Ford am folosit o coada, deoarece se comporta
mai bine in practica decat algoritmul original, desi are aceeasi complexitate.
In implementarea algoritmului Johnson am folosit implementari asemanatoare
pentru Dijkstra si Bellman-Ford cu cele explicate mai sus, pentru eficienta.
In acelasi timp, am cautat eficienta si in memorie, alocand vectori de
dimensiunea datelor, in loc sa definesc un MAX_DIM si sa aloc memorie inutil.

Structura arhiva:
algo1.cpp -> Floyd Warshall
algo2.cpp -> Bellman-Ford
algo3.cpp -> Johnson
algo4.cpp -> Dijkstra

Mai exista si fisierul main.cpp care apeleaza functia din fisierul cu care
este linkat si ruleaza toate testele si le afiseaza in fisierele de iesire.
Pentru folderul other_tests afisez in other_tests_out. Puteam sa fac un singur
header file, algo.h dar ma gandeam ca as putea extinde algoritmii si as avea
nevoie de biblioteci diferite. 
Am testat cu comanda git diff rezultatele pentru cei 3 algoritmi.
In Makefile am reguli de build pentru fiecare algoritm:
build_johnson, build_bellman, build_dijkstra, build_floyd.
Comanda "make fast_run" face build si ruleaza algoritmul Johnson pe 
toate testele. Floyd-Warshall ocupa cea mai putina memorie.

Pentru testele de intrare din folderul in am folosit atat teste generate de
mine, dar si cateva teste gasite. Am vrut sa fie cat mai variate, practic
random:
[test0] - original
Grafuri orientate numai cu arce pozitive:
[test1]https://infoarena.ro/problema/dijkstra?action=attach-list  (test 1)
[test2]https://infoarena.ro/problema/dijkstra?action=attach-list  (test 3)
Grafuri orientate cu arce de cost negativ si pozitiv (fara cicluri negative):
[test3] 10 varfuri
[test4] 161 varfuri
Grafuri orientate cu arce de cost 1:
[test5]
[test6] 
Grafuri neorientate (cu arce obligatoriu pozitive, ca sa nu avem ciclu neg.):
[test7]
[test8]

In folderul other_tests sunt teste care ne permit sa observam mai bine
diferenta intre algoritmi.
Graf orientat cu ciclu negativ:
[test0] (Floyd-Warshall e eronat, deoarece nu verifica ciclurile negative)
Graf dens orientat cu 10 varfuri:
[test1]
Graf dens orientat cu 100 varfuri:
[test2]
Graf dens orientat cu 1000 varfuri:
[test3]
Graf rar orientat cu 10 varfuri:
[test4]
Graf rar orientat cu 100 varfuri:
[test5]
Graf rar orientat cu 1000 varfuri:
[test6]

Pe langa aceste teste, am adaugat alte 2 teste intermediare. Testul 7
ne permite sa vedem mai bine trecerea dintre 100 si 1000 de varfuri pentru
un graf dens, iar testul 8 ne arata cum se maresc diferentele pentru un
graf rar cu 1500 varfuri.
Graf dens orientat cu 500 varfuri:
[test7] 
Graf rar orientat cu 1500 varfuri:
[test8]

Grafuri cu numar de arce generat aleator:
[test9] 10 varfuri, 65 arce
[test10] 100 varfuri, 3325 arce
[test11] 1000 varfuri, 67498 arce

Grafuri aciclice:
[test12] 100 varfuri, 99 arce
[test13] 1000 varfuri, 999 arce

Pentru generarea testelor, pe langa cele generate de mine, am folosit
urmatoarele programe:
http://spojtoolkit.com/TestCaseGenerator/
https://sourceforge.net/projects/test-case-generator-tool/
https://test-case-generator.herokuapp.com/
