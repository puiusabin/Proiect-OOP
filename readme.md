## Compiler
Sunt pe MacOS si nu imi merge visual studio asa ca am folosit Clion de la JetBrains.
https://www.jetbrains.com/clion/

---

##  Descriere

Acest proiect simulează un restaurant cu următoarele capabilităţi:

- **Mese** cu identificator, capacitate şi stare (disponibilă/ocupată).
- **Rezervări** cu validare capacitate masă şi format oră `HH:MM`.
- **Comenzi** ce pot conține multiple produse, cu calcul total şi combinare (`operator+`).
- **Inventar** de ingrediente (struct `Ingredient`), cu adăugare, scădere și persistență (fișier text).
- **Procesare asincronă a comenzilor**: fiecare comandă se “preparează” pe un thread dedicat, cu notificări către TUI.
- **Logging** thread-safe într-un fișier `restaurant.log` și pe consolă.
- **Pattern Observer/Observable** pentru notificări de evenimente (comenzi gata).

---

##  Funcționalități principale

1. **Listare Mese** — afișează toate mesele create și starea lor.
2. **Listare Rezervări** — afișează rezervările active.
3. **Listare Comenzi** — afișează comenzile curente și totalul fiecăreia.
4. **Adăugare Rezervare**
    - Validare că masă există
    - Verificare capacitate (număr de persoane ≤ capacitate)
    - Validare format oră `HH:MM`
5. **Adăugare Comandă**
    - Citire ID și produse (nume + preț)
    - Generare obiecte `MenuItem` pe heap (`std::make_shared<MenuItem>`)
    - Enqueue în `OrderProcessor` pentru procesare asincronă
6. **Procesare Comenzi**
    - Worker thread care simulează pregătirea (sleep 2s)
    - Notificare `Observer` (TUI) la final
7. **Gestionare Inventar**
    - Adăugare/Înlăturare ingrediente
    - Salvare/Încărcare din fișier `inventory.txt`
8. **Logging** — toate evenimentele (rezervare, comandă, notificare) sunt scrise în `restaurant.log`.
9. **TUI** — interfață text pentru navigare simplă în meniuri.
