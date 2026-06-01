# Raport Asynchroniczny (Daily Standup)

## Instrukcja
Każdy z 5 członków zespołu proszony jest o aktualizowanie poniższej sekcji co kilka dni. Należy podać datę wpisu i odpowiedzieć krótko na 3 klasyczne pytania ze Scruma:
1. **Co zrobiłem/am?** (od ostatniego wpisu)
2. **Co zrobię?** (najbliższe kroki)
3. **Jakie mam blokady?** (co mnie wstrzymuje, problemy techniczne, braki w dokumentacji)

---

### Szymon Krenz
**Data wpisu:** 27-05-2026
* **Co zrobiłem/am:** Zaimplementowałem generator liczb z przedziału 0-36 dla koła ruletki i stworzyłem Pull Request.
* **Co zrobię:** Przejrzę kod reszty zespołu i zaktualizuję tablicę Kanban.
* **Blokady:** Brak.

### Wojciech Jan Krawczyk
**Data wpisu:** 01-06-2026
* **Co zrobiłem/am:** Skonfigurowałem plik .gitignore, utworzyłem STANDUP.md oraz napisałem main.cpp. Zajmowałem się również rozwiązywaniem konfliktów i scalaniem kodu (proces "Slejenie") z gałęzi develop do main.
* **Co zrobię:** Dołączę do prac nad wspólnymi modułami GameManager.h oraz BetManager.h, aby połączyć całą logikę w jedną całość.
* **Blokady:** Brak

### Wojciech Paweł Krawczyk
**Data wpisu:** 30-05-2026
* **Co zrobiłem/am:** Opracowałem dokumentację projektu w pliku README.md, zawierającą opis, wymagania i instrukcję uruchomienia aplikacji.
* **Co zrobię:** Wesprę zespół w pracach nad wspólnymi plikami logiki (GameManager.h i BetManager.h).
* **Blokady:** Brak

### Maciej Kołtek
**Data wpisu:** 27-05-2026
* **Co zrobiłem/am:** Stworzyłem klasę Wallet.h, która zarządza wirtualnym portfelem gracza, obsługuje dodawanie środków i weryfikuje pobieranie kwot na zakłady.
* **Co zrobię:** Zobaczę, jak mój kod integruje się z BetManager.h podczas rozliczania zwycięskich zakładów.
* **Blokady:** Brak

### Rafał Czajka
**Data wpisu:** 29-05-2026
* **Co zrobiłem/am:** Zaprojektowałem i zakodowałem interfejs konsolowy w pliku UI.h. Przygotowałem makietę stołu (ASCII art), menu główne oraz zabezpieczenia przed wpisywaniem błędnych znaków.
* **Co zrobię:** Pomogę przy GameManager.h, żeby poprawnie wywoływać metody interfejsu podczas trwania pętli gry.
* **Blokady:** Brak