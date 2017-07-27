////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2006 - 2017, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// This file contains all the strings that should be localized.  If a string is
// *not* in this file, then either:
//   (a) it should not be localized, or
//   (b) you have found a bug - please report it
//
// Strings that should be localized:
//   - text output that the user sees
//
// Strings that should NOT be localized:
//   - .taskrc configuration variable names
//   - command names
//   - extension function names
//   - certain literals associated with parsing
//   - debug strings
//   - attribute names
//   - modifier names
//   - logical operators (and, or, xor)
//
// Rules:
//   - Localized strings should not in general  contain leading or trailing
//     white space, including \n, thus allowing the code to compose strings.
//   - Retain the tense of the original string.
//   - Retain the same degree of verbosity of the original string.
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Translators:
//   1. Copy this file (eng-USA.h) to a new file with the target locale as the
//      file name.  Using German as an example, do this:
//
//        cp eng-USA.h deu-DEU.h
//
//   2. Modify all the strings below.
//        i.e. change "Unknown error." to "Unbekannter Fehler.".
//
//   3. Add your new translation to the task.git/src/i18n.h file, if necessary,
//      by inserting:
//
//        #elif PACKAGE_LANGUAGE == LANGUAGE_DEU_DEU
//        #include <deu-DEU.h>
//
//   4. Add your new language to task.git/CMakeLists.txt, making sure that
//      number is unique:
//
//        set (LANGUAGE_DEU_DEU 3)
//
//   5. Add your new language to task.git/cmake.h.in:
//
//        #define LANGUAGE_DEU_DEU ${LANGUAGE_DEU_DEU}
//
//   6. Build your localized Taskwarrior with these commands:
//
//      cd task.git
//      cmake -D LANGUAGE=3 .
//      make
//
//   7. Submit your translation to support@taskwarrior.org, where it will be
//      shared with others.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDED_STRINGS
#define INCLUDED_STRINGS

// Note that for English, the following two lines are not displayed.  For all
// other localizations, these lines will appear in the output of the 'version'
// and 'diagnostics' commands.
//
// DO NOT include a copyright in the translation.
//
#define STRING_LOCALIZATION_DESC     "Tłumaczenie polskie"
#define STRING_LOCALIZATION_AUTHOR   "Przetłumaczył na język polski Ł. Panek."

// Parser
#define STRING_PARSER_ALIAS_NEST     "Limit {1} zagnieżdżonych aliasów osiągnięty"
#define STRING_PARSER_OVERRIDE_RC    "Nadpisanie konfiguracji rc.{1}:{2}"
#define STRING_PARSER_UNKNOWN_ATTMOD "Błąd: nierozpoznany atrybut '{1}'."
#define STRING_PARSER_ALTERNATE_RC   "Wczytanie alternatywnego pliku .taskrc {1}"
#define STRING_PARSER_ALTERNATE_DATA "Alternatywne data.location {1}"
#define STRING_PARSER_UNEXPECTED_ARG "The '{1}' command does not allow '{2}'."

// Color
#define STRING_COLOR_UNRECOGNIZED    "Kolor '{1}' nie został rozpoznany."

// columns/Col*
#define STRING_COLUMN_BAD_NAME       "Nierozpoznano nazwy kolumny '{1}'."
#define STRING_COLUMN_BAD_FORMAT     "Nierozpoznano formatu kolumny '{1}.{2}'"
#define STRING_COLUMN_LABEL_TASKS    "Zadania"
#define STRING_COLUMN_LABEL_DEP      "Związane"
#define STRING_COLUMN_LABEL_DEP_S    "Zwi"
#define STRING_COLUMN_LABEL_DESC     "Opis"
#define STRING_COLUMN_LABEL_DUE      "Do"
#define STRING_COLUMN_LABEL_END      "Koniec"
#define STRING_COLUMN_LABEL_ENTERED  "Dodane"
#define STRING_COLUMN_LABEL_COUNT    "Ile"
#define STRING_COLUMN_LABEL_COMPLETE "Ukończone"
#define STRING_COLUMN_LABEL_MOD      "Zmienione"
#define STRING_COLUMN_LABEL_ADDED    "Dodane"
#define STRING_COLUMN_LABEL_AGE      "Wiek"
#define STRING_COLUMN_LABEL_ID       "ID"
#define STRING_COLUMN_LABEL_PROJECT  "Projekt"
#define STRING_COLUMN_LABEL_UNTIL    "Do"
#define STRING_COLUMN_LABEL_WAIT     "Czeka"
#define STRING_COLUMN_LABEL_WAITING  "Czeka dopóki"
#define STRING_COLUMN_LABEL_RECUR    "Period"
#define STRING_COLUMN_LABEL_RECUR_L  "Periodyczny"
#define STRING_COLUMN_LABEL_START    "Start"
#define STRING_COLUMN_LABEL_STARTED  "Rozpoczęte"
#define STRING_COLUMN_LABEL_ACTIVE   "A"
#define STRING_COLUMN_LABEL_STATUS   "Status"
#define STRING_COLUMN_LABEL_STAT     "St"
#define STRING_COLUMN_LABEL_STAT_PE  "W toku"
#define STRING_COLUMN_LABEL_STAT_CO  "Ukończone"
#define STRING_COLUMN_LABEL_STAT_DE  "Usnięte"
#define STRING_COLUMN_LABEL_STAT_WA  "Zawieszone"
#define STRING_COLUMN_LABEL_STAT_RE  "Zależne"
#define STRING_COLUMN_LABEL_STAT_P   "P"
#define STRING_COLUMN_LABEL_STAT_C   "C"
#define STRING_COLUMN_LABEL_STAT_D   "D"
#define STRING_COLUMN_LABEL_STAT_W   "W"
#define STRING_COLUMN_LABEL_STAT_R   "R"
#define STRING_COLUMN_LABEL_TAGS     "Tagi"
#define STRING_COLUMN_LABEL_TAG      "Tag"
#define STRING_COLUMN_LABEL_UUID     "UUID"
#define STRING_COLUMN_LABEL_URGENCY  "Pilność"
#define STRING_COLUMN_LABEL_NAME     "Nazwa"
#define STRING_COLUMN_LABEL_VALUE    "Wartość"
#define STRING_COLUMN_LABEL_MASK     "Maska"
#define STRING_COLUMN_LABEL_MASK_IDX "Indeks Maski"
#define STRING_COLUMN_LABEL_LAST     "Last instance"
#define STRING_COLUMN_LABEL_RTYPE    "Recurrence type"
#define STRING_COLUMN_LABEL_PARENT   "Zadanie rodzic"
#define STRING_COLUMN_LABEL_TEMPLATE "Template task"
#define STRING_COLUMN_LABEL_DATE     "Data"
#define STRING_COLUMN_LABEL_COLUMN   "Kolumny"
#define STRING_COLUMN_LABEL_STYLES   "Formaty"
#define STRING_COLUMN_LABEL_EXAMPLES "Przykłady"
#define STRING_COLUMN_LABEL_SCHED    "Zaplanowane"
#define STRING_COLUMN_LABEL_UDA      "Nazwa"
#define STRING_COLUMN_LABEL_TYPE     "Typ"
#define STRING_COLUMN_LABEL_MODIFY   "Modifiable"
#define STRING_COLUMN_LABEL_NOMODIFY "Read Only"
#define STRING_COLUMN_LABEL_LABEL    "Etykieta"
#define STRING_COLUMN_LABEL_DEFAULT  "Domyślne"
#define STRING_COLUMN_LABEL_VALUES   "Dozwolone Wartości"
#define STRING_COLUMN_LABEL_UDACOUNT "Licznik Użycia"
#define STRING_COLUMN_LABEL_ORPHAN   "Osierocone UDA"

#define STRING_COLUMN_LABEL_COMMAND  "Command"
#define STRING_COLUMN_LABEL_CATEGORY "Category"
#define STRING_COLUMN_LABEL_RO       "R/W"
#define STRING_COLUMN_LABEL_SHOWS_ID "ID"
#define STRING_COLUMN_LABEL_GC       "GC"
#define STRING_COLUMN_LABEL_CONTEXT  "Context"
#define STRING_COLUMN_LABEL_FILTER   "Filter"
#define STRING_COLUMN_LABEL_MODS     "Mods"
#define STRING_COLUMN_LABEL_MISC     "Misc"

// Column Examples
#define STRING_COLUMN_EXAMPLES_TAGS  "home @chore next"
#define STRING_COLUMN_EXAMPLES_PROJ  "dom.ogród"
#define STRING_COLUMN_EXAMPLES_PAR   "dom"
#define STRING_COLUMN_EXAMPLES_IND   "  dom.ogród"
#define STRING_COLUMN_EXAMPLES_DESC  "Przewieś swoje ubrania na dolny wieszak"
#define STRING_COLUMN_EXAMPLES_ANNO1 "Odrazu przed obiadem"
#define STRING_COLUMN_EXAMPLES_ANNO2 "Jesli grasz mecz tego popołudnia"
#define STRING_COLUMN_EXAMPLES_ANNO3 "Przed napisaniem listu do domu"
#define STRING_COLUMN_EXAMPLES_ANNO4 "Jeśli nie udajesz się do fryzjera"

// commands/Cmd*
// USAGE strings are visible in 'task help'
#define STRING_CMD_CONFLICT          "Raport urzytkownika '{1}' jest w konflikcie z wbudowanym poleceniem."
#define STRING_CMD_VERSION_USAGE     "Pokazuje wersję programu taskwarrior"
#define STRING_CMD_VERSION_USAGE2    "Pokazuje numer wersji programu taskwarrior"
#define STRING_CMD_VERSION_MIT       "Taskwarrior może być kopiowany tylko na zasadach licencji MIT, którą znaleźć można w źródłach programu taskwarrior."
#define STRING_CMD_VERSION_DOCS      "Dokumentację dla taskwarrior można znaleźć z pomocą 'man task', 'man taskrc', 'man task-tutorial', 'man task-color', 'man task-sync', 'man task-faq' lub pod adresem http://taskwarrior.org"
#define STRING_CMD_VERSION_BUILT     "{1} {2} zbudowane dla "
#define STRING_CMD_VERSION_UNKNOWN   "nieznana"
#define STRING_CMD_VERSION_COPY      "Copyright (C) 2006 - 2017 P. Beckingham, F. Hernandez."
#define STRING_CMD_LOGO_USAGE        "Wyświetla logo Taskwarrior"
#define STRING_CMD_LOGO_COLOR_REQ    "Polecenie logo wymaga wsparcia kolorowania."
#define STRING_CMD_EXEC_USAGE        "Wykonuje zewnętrzne polecenia i skrypty"
#define STRING_CMD_URGENCY_USAGE     "Wyświetla pomiar ważności zadania"
#define STRING_CMD_URGENCY_RESULT    "zadanie {1} ważność {2}"
#define STRING_CMD_ADD_USAGE         "Dodaje nowe zadanie"
#define STRING_CMD_ADD_FEEDBACK      "Utworzono zadanie {1}."
#define STRING_CMD_ADD_RECUR         "Created task {1} (recurrence template)."
#define STRING_CMD_LOG_USAGE         "Dodaje nowe, ukończone zadanie"
#define STRING_CMD_LOG_NO_RECUR      "Nie możesz logować zadania cyklicznego."
#define STRING_CMD_LOG_NO_WAITING    "Nie możesz logować zadania czekającego."

//#define STRING_CMD_LOG_LOGGED        "Zadanie w logu."
#define STRING_CMD_LOG_LOGGED        "Logged task {1}."

#define STRING_CMD_IDS_USAGE_RANGE   "Pokazuje IDki pasujących zadań, w formie zakresu"
#define STRING_CMD_IDS_USAGE_LIST    "Pokazuje IDki pasujących zadań, w formie listy"
#define STRING_CMD_IDS_USAGE_ZSH     "Pokazuje IDki i opisy pasujących zadań"
#define STRING_CMD_UDAS_USAGE        "Pokazuje zdefiniowane UDA"
#define STRING_CMD_UDAS_COMPL_USAGE  "Pokazuje zdefiniowane UDA w celach autouzupełniania"
#define STRING_CMD_UUIDS_USAGE_RANGE "Pokazuje UUID pasujących zadań, w formie listy rozdzilonej przecinkami"
#define STRING_CMD_UUIDS_USAGE_LIST  "Pokazuje UUID pasujących zadań, w formie listy"
#define STRING_CMD_UUIDS_USAGE_ZSH   "Pokazuje UUID i opis pasujących zadań"
#define STRING_CMD_EXPORT_USAGE      "Eksportuje zadania do formatu JSON"
#define STRING_CMD_INFO_USAGE        "Pokazuje wszystkie dane i metadane"
#define STRING_CMD_INFO_BLOCKED      "To zadanie jest blokowane przez"
#define STRING_CMD_INFO_BLOCKING     "To zadanie blokuje"
#define STRING_CMD_INFO_UNTIL        "Do"
#define STRING_CMD_INFO_MODIFICATION "Modyfikacja"
#define STRING_CMD_INFO_MODIFIED     "Ostatnio zmodyfikowane"
#define STRING_CMD_INFO_VIRTUAL_TAGS "Virtual tags"
#define STRING_CMD_UNDO_USAGE        "Odwraca ostatnią zmianę w zadaniu"
#define STRING_CMD_STATS_USAGE       "Pokazuje statystyki bazy danych zadań"
#define STRING_CMD_STATS_CATEGORY    "Kategoria"
#define STRING_CMD_STATS_DATA        "Data"
#define STRING_CMD_STATS_TOTAL       "Razem"
#define STRING_CMD_STATS_ANNOTATIONS "Notatek"
#define STRING_CMD_STATS_UNIQUE_TAGS "Unikalnych tagów"
#define STRING_CMD_STATS_PROJECTS    "Projekty"
#define STRING_CMD_STATS_DATA_SIZE   "Rozmiar danych"
#define STRING_CMD_STATS_UNDO_TXNS   "Transakcji Cofnij"
#define STRING_CMD_STATS_BACKLOG     "Transakcji Sync backlog"
#define STRING_CMD_STATS_TAGGED      "Otagowanych zadań"
#define STRING_CMD_STATS_OLDEST      "Najstarsze zadanie"
#define STRING_CMD_STATS_NEWEST      "Najnowsze zadanie"
#define STRING_CMD_STATS_USED_FOR    "Zadanie używane przez"
#define STRING_CMD_STATS_ADD_EVERY   "Zadanie dodawane co"
#define STRING_CMD_STATS_COMP_EVERY  "Zadanie kończone co"
#define STRING_CMD_STATS_DEL_EVERY   "Zadanie usuwane co"
#define STRING_CMD_STATS_AVG_PEND    "Średni czas w toku"
#define STRING_CMD_STATS_DESC_LEN    "Średnia długość opisu"
#define STRING_CMD_STATS_CHARS       "{1} znaków"
#define STRING_CMD_STATS_BLOCKED     "Zadania blokowane"
#define STRING_CMD_STATS_BLOCKING    "Zadania blokujące"
#define STRING_CMD_REPORTS_USAGE     "Lista wszystkich wspieranych raportów"
#define STRING_CMD_REPORTS_REPORT    "Raport"
#define STRING_CMD_REPORTS_DESC      "Opis"
#define STRING_CMD_REPORTS_SUMMARY   "{1} raportów"
#define STRING_CMD_TAGS_USAGE        "Pokazuje listę użytych tagów"
#define STRING_CMD_COMTAGS_USAGE     "Pokazuje listę użytych tagów dla celów autouzupełniania"
#define STRING_CMD_TAGS_SINGLE       "1 tag"
#define STRING_CMD_TAGS_PLURAL       "{1} tagów"
#define STRING_CMD_TAGS_NO_TAGS      "Brak tagów."
#define STRING_CMD_HISTORY_USAGE_D   "Shows a report of task history, by day"
#define STRING_CMD_HISTORY_USAGE_W   "Shows a report of task history, by week"
#define STRING_CMD_HISTORY_DAY       "Day"
#define STRING_CMD_GHISTORY_USAGE_D  "Shows a graphical report of task history, by day"
#define STRING_CMD_GHISTORY_USAGE_W  "Shows a graphical report of task history, by week"
#define STRING_CMD_GHISTORY_USAGE_D  "Shows a graphical report of task history, by day"
#define STRING_CMD_GHISTORY_USAGE_W  "Shows a graphical report of task history, by week"
#define STRING_CMD_GHISTORY_DAY      "Day"
#define STRING_CMD_HISTORY_USAGE_M   "Pokazuje raport historii zadań w ujęciu miesięcznym"
#define STRING_CMD_HISTORY_YEAR      "Rok"
#define STRING_CMD_HISTORY_MONTH     "Miesiąc"
#define STRING_CMD_HISTORY_ADDED     "Dodane"
#define STRING_CMD_HISTORY_COMP      "Ukończone"
#define STRING_CMD_HISTORY_DEL       "Usunięte"
#define STRING_CMD_HISTORY_NET       "Net"
#define STRING_CMD_HISTORY_USAGE_A   "Pokazuje raport historii zadań w ujęciu rocznym"
#define STRING_CMD_HISTORY_AVERAGE   "Średnia"
#define STRING_CMD_HISTORY_LEGEND    "Legenda: {1}, {2}, {3}"
#define STRING_CMD_HISTORY_LEGEND_A  "Legenda: + dodane, X ukończone, - usunięte"
#define STRING_CMD_GHISTORY_USAGE_M  "Pokazuje graficzny raport z historii zadań, w miesięcznych podsumowaniach"
#define STRING_CMD_GHISTORY_USAGE_A  "Pokazuje graficzny raport z historii zadań, w rocznych podsumowaniach"
#define STRING_CMD_GHISTORY_YEAR     "Rok"
#define STRING_CMD_GHISTORY_MONTH    "Miesiąc"
#define STRING_CMD_GHISTORY_NUMBER   "Liczba Dodanych/Ukończonych/Usuniętych"
#define STRING_CMD_UNIQUE_USAGE      "Generates lists of unique attribute values"
#define STRING_CMD_UNIQUE_MISSING    "An attribute must be specified.  See 'task _columns'."
#define STRING_CMD_UNIQUE_VALID      "You must specify an attribute or UDA."

#define STRING_CMD_DONE_USAGE        "Oznacza wybrane zadanie jako zakończone"
#define STRING_CMD_DONE_CONFIRM      "Zakończyć zadanie {1} '{2}'?"
#define STRING_CMD_DONE_TASK         "Zakończono zadanie {1} '{2}'."
#define STRING_CMD_DONE_NO           "Zadanie niezakończone."
#define STRING_CMD_DONE_NOTPEND      "Zadanie {1} '{2}' nie jest realizowane ani oczekujące."
#define STRING_CMD_DONE_1            "Zakończono {1} zadanie."
#define STRING_CMD_DONE_N            "Zakończono {1} zadań."

#define STRING_CMD_PROJECTS_USAGE    "Pokazuje statystyki wszystkich projektów"
#define STRING_CMD_PROJECTS_USAGE_2  "Pokazuje tylko nazwy prowadzonych projektów"
#define STRING_CMD_PROJECTS_NO       "Brak projektów"
#define STRING_CMD_PROJECTS_NONE     "(brak)"
#define STRING_CMD_PROJECTS_SUMMARY  "{1} projekt"
#define STRING_CMD_PROJECTS_SUMMARY2 "{1} projektów"
#define STRING_CMD_PROJECTS_TASK     "({1} zadanie)"
#define STRING_CMD_PROJECTS_TASKS    "({1} zadań)"
#define STRING_CMD_SUMMARY_USAGE     "Pokazuje raport ze stanu zadań per projekt"
#define STRING_CMD_SUMMARY_PROJECT   "Projekt"
#define STRING_CMD_SUMMARY_REMAINING "Pozostało"
#define STRING_CMD_SUMMARY_AVG_AGE   "Średni wiek"
#define STRING_CMD_SUMMARY_COMPLETE  "Ukończone"
#define STRING_CMD_SUMMARY_NONE      "(brak)"
#define STRING_CMD_COUNT_USAGE       "Zlicza pasujące zadania"
#define STRING_CMD_GET_USAGE         "DOM Akcesor"
#define STRING_CMD_GET_NO_DOM        "Brak zdefiniowanej referencji do DOM."
#define STRING_CMD_GET_BAD_REF       "'{1}' is not a DOM reference."

#define STRING_CMD_UDAS_NO           "Nie zdefiniowano UDA"
#define STRING_CMD_UDAS_SUMMARY      "{1} zdefiniowane UDA"
#define STRING_CMD_UDAS_SUMMARY2     "{1} zdefiniowanych UDA"
#define STRING_CMD_UDAS_ORPHAN       "{1} Osierocone UDA"
#define STRING_CMD_UDAS_ORPHANS      "{1} Osierocone UDA"

#define STRING_CMD_DELETE_USAGE      "Usuwa wybrane zadanie"
#define STRING_CMD_DELETE_CONFIRM    "Usunąć zadanie {1} '{2}'?"
#define STRING_CMD_DELETE_TASK       "Usuwanie zadania {1} '{2}'."
#define STRING_CMD_DELETE_TASK_R     "Usuwanie zadania cyklicznego {1} '{2}'."
#define STRING_CMD_DELETE_CONFIRM_R  "To zadanie jest cykliczne. Czy chcesz usunąć wszystkie pozostałe cykle tego zadania?"
#define STRING_CMD_DELETE_NO         "Zadanie nie zostało usunięte"
#define STRING_CMD_DELETE_NOT_DEL    "Zadanie {1} '{2}' jest nieusuwalne."
#define STRING_CMD_DELETE_1          "Usunięto {1} zadanie "
#define STRING_CMD_DELETE_N          "Usunięto {1} zadań"

#define STRING_CMD_DUPLICATE_USAGE   "Tworzy kopię wybranego zadania"
#define STRING_CMD_DUPLICATE_REC     "Uwaga: zadanie {1} było cyklicznym zadaniem-rodzicem. Kopia jest nim również"
#define STRING_CMD_DUPLICATE_NON_REC "Uwaga: zadanie {1} było cykliczne. Kopia nie jest cykliczna."
#define STRING_CMD_DUPLICATE_CONFIRM "Skopiować zadanie {1} '{2}'?"
#define STRING_CMD_DUPLICATE_TASK    "Skopiowano zadanie {1} '{2}'."
#define STRING_CMD_DUPLICATE_NO      "Nie skopiowano zadańia"
#define STRING_CMD_DUPLICATE_1       "Skopiowano {1} zadanie."
#define STRING_CMD_DUPLICATE_N       "Skopiowano {1} zadań."

#define STRING_CMD_PURGE_USAGE       "Removes the specified tasks from the data files. Causes permanent loss of data."
#define STRING_CMD_PURGE_ABRT        "Purge operation aborted."
#define STRING_CMD_PURGE_1           "Purged {1} task."
#define STRING_CMD_PURGE_N           "Purged {1} tasks."
#define STRING_CMD_PURGE_CONFIRM     "Permanently remove task {1} '{2}'?"
#define STRING_CMD_PURGE_CONFIRM_R   "Task '{1}' is a recurrence template. All its {2} deleted children tasks will be purged as well. Continue?"
#define STRING_CMD_PURGE_NDEL_CHILD  "Task '{1}' is a recurrence template. Its child task {2} must be deleted before it can be purged."

#define STRING_CMD_START_USAGE       "Oznacza zadanie jako uruchomione"
#define STRING_CMD_START_NO          "Zadanie nie uruchomione"
#define STRING_CMD_START_ALREADY     "Zadanie {1} '{2}' jest już uruchomione"
#define STRING_CMD_START_TASK        "Uruchamianie zadania {1} '{2}'"
#define STRING_CMD_START_CONFIRM     "Uruchomić zadanie {1} '{2}'?"
#define STRING_CMD_START_1           "Uruchomiono {1} zadanie."
#define STRING_CMD_START_N           "Uruchomiono {1} zadań."

#define STRING_CMD_STOP_USAGE        "Usuwa marker 'start' z zadania"
#define STRING_CMD_STOP_NO           "Zadanie nie zatrzymane"
#define STRING_CMD_STOP_ALREADY      "Zadanie {1} '{2}' nie jest uruchomione"
#define STRING_CMD_STOP_TASK         "Zatrzymywanie zadania {1} '{2}'."
#define STRING_CMD_STOP_CONFIRM      "Zatrzymać zadanie {1} '{2}'?"
#define STRING_CMD_STOP_1            "Zatrzymano {1} zadanie."
#define STRING_CMD_STOP_N            "Zatrzymano {1} zadań."

#define STRING_CMD_APPEND_USAGE      "Dodaje ciąg na końcu opisu zadania"
#define STRING_CMD_APPEND_1          "Dodano ciąg do opisu {1} zadania"
#define STRING_CMD_APPEND_N          "Dodano ciąg do opisu {1} zadań"
#define STRING_CMD_APPEND_TASK       "Dodawanie ciągu do opisu zadania {1} '{2}'."
#define STRING_CMD_APPEND_TASK_R     "Dodawanie ciągu do opisu zadania cyklicznego {1} '{2}'."
#define STRING_CMD_APPEND_CONFIRM_R  "To zadanie jest cykliczne. Czy chcesz dodać ciąg do opisu kolejnych zadań w cyklu?"
#define STRING_CMD_APPEND_CONFIRM    "Dodać ciąg do opisu zadania {1} '{2}'?"
#define STRING_CMD_APPEND_NO         "Nie dodano ciągu do opisu."

#define STRING_CMD_PREPEND_USAGE     "Dodaje ciąg na początku opisu zadania"
#define STRING_CMD_PREPEND_1         "Dodano ciąg do opisu {1} zadania."
#define STRING_CMD_PREPEND_N         "Dodano ciąg do opisu {1} zadań."
#define STRING_CMD_PREPEND_TASK      "Dodawanie ciągu do opisu zadania {1} '{2}'."
#define STRING_CMD_PREPEND_TASK_R    "Dodawanie ciągu do opisu zadania cyklicznego {1} '{2}'."
#define STRING_CMD_PREPEND_CONFIRM_R "To zadanie jest cykliczne. Czy chcesz dodać ciąg do opisu kolejnych zadań w cyklu?"
#define STRING_CMD_PREPEND_CONFIRM   "Dodać ciąg do opisu zadania {1} '{2}'?"
#define STRING_CMD_PREPEND_NO        "Nie dodano ciągu do opisu."

#define STRING_CMD_ANNO_USAGE        "Dodaje komentarz do istniejącego zadania"
#define STRING_CMD_ANNO_CONFIRM      "Skomentować zadanie {1} '{2}'?"
#define STRING_CMD_ANNO_TASK         "Komentowanie zadania {1} '{2}'."
#define STRING_CMD_ANNO_TASK_R       "Komentowanie zadania cyklicznego {1} '{2}'."
#define STRING_CMD_ANNO_CONFIRM_R    "To zadanie jest cykliczne. Czy chcesz skomentować kolejne zadania w cyklu?"
#define STRING_CMD_ANNO_NO           "Nie skomentowano zadania."
#define STRING_CMD_ANNO_1            "Skomentowano {1} zadanie."
#define STRING_CMD_ANNO_N            "Skomentowano {1} zadań."

#define STRING_CMD_COLUMNS_USAGE     "Wszystkie kolumny i wspierane style formatowania"
#define STRING_CMD_COLUMNS_NOTE      "* Oznacza domyślne formatowanie, w konsekwencji niewymagane explicite. Na przykład: 'due' i 'due.formatted' są równoznaczne."
#define STRING_CMD_COLUMNS_USAGE2    "Wyświetla tylko listę wspieranych kolumn"
#define STRING_CMD_COLUMNS_ARGS      "Możesz podać tylko jeden szukany ciąg znaków."

#define STRING_CMD_DENO_USAGE        "Usuwa komentarz"
#define STRING_CMD_DENO_NONE         "Wybrane zadanie nie posiada komentarza do usunięcia."
#define STRING_CMD_DENO_CONFIRM      "Usunąć komentarz zadania {1} '{2}'?"
#define STRING_CMD_DENO_FOUND        "Znaleziono i usunięto komentarz '{1}'."
#define STRING_CMD_DENO_NOMATCH      "Nie znaleziono żadnego pasującego komentarza do usunięcia '{1}'."
#define STRING_CMD_DENO_NO           "Nie usunięto komentarza."
#define STRING_CMD_DENO_1            "Usunięto {1} komentarz."
#define STRING_CMD_DENO_N            "Usunięto {1} komentarzy."

#define STRING_CMD_IMPORT_USAGE      "Importuje pliki JSON"
#define STRING_CMD_IMPORT_SUMMARY    "Zaimportowano {1} zadań."
#define STRING_CMD_IMPORT_FILE       "Importowanie '{1}'"
#define STRING_CMD_IMPORT_MISSING    "File '{1}' not found."
#define STRING_CMD_IMPORT_UUID_BAD   "Not a valid UUID '{1}'."
#define STRING_TASK_NO_DESC          "Komentarz nie posiada treści: {1}"
#define STRING_TASK_NO_ENTRY         "Komentarz nie posiada daty utworzenia: {1}"
#define STRING_CMD_SYNC_USAGE        "Synchronizuje dane z serwerem zadań"
#define STRING_CMD_SYNC_NO_SERVER    "Serwer zadań jest nieskonfigurowany."
#define STRING_CMD_SYNC_BAD_CRED     "Zaburzone uwierzytelnianie dla serwera zadań."
#define STRING_CMD_SYNC_BAD_CERT     "Nieznaleziony certyfikat serwera zadań."
#define STRING_CMD_SYNC_BAD_KEY      "Nieznaleziony klucz serwera zadań."
#define STRING_CMD_SYNC_ADD          "   dodaj {1} '{2}'"
#define STRING_CMD_SYNC_MOD          "modyfikuj {1} '{2}'"
#define STRING_CMD_SYNC_PROGRESS     "Synchronizacja z {1}"
#define STRING_CMD_SYNC_SUCCESS0     "Synchronizacja udana"
#define STRING_CMD_SYNC_SUCCESS1     "Synchronizacja udana.  {1} wysłanych zmian."
#define STRING_CMD_SYNC_SUCCESS2     "Synchronizacja udana.  {1} ściągniętych zmian."
#define STRING_CMD_SYNC_SUCCESS3     "Synchronizacja udana.  {1} wysłanych zmian, {2} ściągniętych zmian."
#define STRING_CMD_SYNC_SUCCESS_NOP  "Synchronizacja udana.  Żadnych zmian."
#define STRING_CMD_SYNC_FAIL_ACCOUNT "Synchronizacja nieudana.  Nieudane uwierzytelnianie lub nie aktywne konto na serwerze zadań."
#define STRING_CMD_SYNC_FAIL_ERROR   "Synchronizacja nieudana.  Serwer zadań zwrócił błąd: {1} {2}"
#define STRING_CMD_SYNC_FAIL_CONNECT "Synchronizacja nieudana.  Nie można połączyć się z serwerem zadań."
#define STRING_CMD_SYNC_BAD_SERVER   "Synchronizacja nieudana.  Uszkodzone ustawienia konfiguracji '{1}'"
#define STRING_CMD_SYNC_NO_TLS       "Taskwarrior zbudowany bez wsparcia dla GnuTLS. Synchronizacja niedostępna."
#define STRING_CMD_SYNC_INIT         "Proszę potwierdzić zamiar wysłania na serwer zadań wszystkich twoich oczekujących zadań"
#define STRING_CMD_SYNC_NO_INIT      "Taskwarrior nie wykona inicjalizacji dla pierwszej synchronizacji"
#define STRING_CMD_SYNC_RELOCATE0    "Konto na serwerze zostało przeniesione.  Proszę uaktualnij swoją konfigurację używając:"
#define STRING_CMD_SYNC_RELOCATE1    "konfiguracji taskd.server {1}"
#define STRING_CMD_SYNC_BAD_CA       "Certyfikat CA nie znaleziony."
#define STRING_CMD_SYNC_TRUST_CA     "Powinieneś udostępnić certyfikat CA lub nadpisać weryfikację. Wybierz jedną z opcji."
#define STRING_CMD_SYNC_TRUST_OBS    "The 'taskd.trust' settings may now only contain a value of 'strict', 'ignore hostname' or 'allow all'."

// STRING_CMD_DIAG_* strings all appear on the 'diag' command output.
#define STRING_CMD_DIAG_USAGE        "Szczegóły platformy i środowiska budowania"
#define STRING_CMD_DIAG_PLATFORM     "Platforma"
#define STRING_CMD_DIAG_COMPILER     "Kompilator"
#define STRING_CMD_DIAG_VERSION      "Wersja"
#define STRING_CMD_DIAG_CAPS         "Flagi"
#define STRING_CMD_DIAG_COMPLIANCE   "Compliance"
#define STRING_CMD_DIAG_FEATURES     "Opcje budowania"
#define STRING_CMD_DIAG_BUILT        "Zbudowano"
#define STRING_CMD_DIAG_COMMIT       "Zatwierdzenie"
#define STRING_CMD_DIAG_FOUND        "(jest)"
#define STRING_CMD_DIAG_MISSING      "(brak)"
#define STRING_CMD_DIAG_MISS_DEP     "Task {1} depends on nonexistent task: {2}"
#define STRING_CMD_DIAG_MISS_PAR     "Task {1} has nonexistent recurrence template: {2}"
#define STRING_CMD_DIAG_ENABLED      "Włączone"
#define STRING_CMD_DIAG_DISABLED     "Wyłączone"
#define STRING_CMD_DIAG_CONFIG       "Konfiguracja"
#define STRING_CMD_DIAG_TESTS        "Testy"
#define STRING_CMD_DIAG_UUID_SCAN    "Zeskanowano {1} zadań w poszukiwaniu zdublowanych UUIDów:"
#define STRING_CMD_DIAG_REF_SCAN     "Scanned {1} tasks for broken references:"
#define STRING_CMD_DIAG_REF_OK       "No broken references found"
#define STRING_CMD_DIAG_UUID_DUP     "Znaleziono duplikaty {1}"
#define STRING_CMD_DIAG_UUID_NO_DUP  "Nie znaleziono duplikatów"
#define STRING_CMD_DIAG_NONE         "-brak-"
#define STRING_CMD_DIAG_HOOKS        "Haki"
#define STRING_CMD_DIAG_HOOK_NAME    "unrecognized hook name"
#define STRING_CMD_DIAG_HOOK_SYMLINK "symlink"
#define STRING_CMD_DIAG_HOOK_EXEC    "executable"
#define STRING_CMD_DIAG_HOOK_NO_EXEC "not executable"
#define STRING_CMD_DIAG_HOOK_ENABLE  "Enabled"
#define STRING_CMD_DIAG_HOOK_DISABLE "Disabled"

#define STRING_CMD_COMMANDS_USAGE    "Generates a list of all commands, with behavior details"
#define STRING_CMD_HCOMMANDS_USAGE   "Generuje listę wszystkich poleceń dla funkcji autouzupełniania"
#define STRING_CMD_ZSHCOMMANDS_USAGE "Generuje listę wszystkich poleceń dla funkcji autouzupełniania w powłoce zsh"
#define STRING_CMD_ZSHATTS_USAGE     "Generates a list of all attributes, for zsh autocompletion purposes"
#define STRING_CMD_ALIASES_USAGE     "Generuje listę wszystkich aliasów dla funkcji autouzupełniania"

#define STRING_CMD_MODIFY_USAGE1     "Modyfikuje istniejące zadanie pod kątem podanych argumentów."
#define STRING_CMD_MODIFY_NO_DUE     "Nie możesz specyfikować rekurencyjnego zadania bez podania terminu."
#define STRING_CMD_MODIFY_REM_DUE    "Nie możesz usunąć właściwości 'termin' z zadanie rekurencyjnego."
#define STRING_CMD_MODIFY_REC_ALWAYS "Nie możesz usunąć właściwości 'rekurencja' z zadania rekurencyjnego."
#define STRING_CMD_MODIFY_TASK       "Modyfikacja zadania {1} '{2}'."
#define STRING_CMD_MODIFY_TASK_R     "Modyfikacja zadania rekurencyjnego {1} '{2}'."
#define STRING_CMD_MODIFY_1          "Zmodyfikowano {1} zadanie."
#define STRING_CMD_MODIFY_N          "Zmodyfikowano {1} zadań."
#define STRING_CMD_MODIFY_NO         "Zadanie nie zmodyfikowane."
#define STRING_CMD_MODIFY_CONFIRM    "Zmienić zadanie {1} '{2}'?"
#define STRING_CMD_MODIFY_RECUR      "To zadanie jest cykliczne. Czy chcesz zmodyfikować kolejne zadania w cyklu?"
#define STRING_CMD_MODIFY_NEED_TEXT  "Należy podać tekst"
#define STRING_CMD_MODIFY_INACTIVE   "Note: Modified task {1} is {2}.  You may wish to make this task pending with: task {3} modify status:pending"

#define STRING_CMD_COLOR_USAGE       "Wszystkie kolory, próbki lub legenda"
#define STRING_CMD_COLOR_HERE        "To są aktualnie używane kolory:"
#define STRING_CMD_COLOR_COLOR       "Kolor"
#define STRING_CMD_COLOR_DEFINITION  "Definicja"
#define STRING_CMD_COLOR_EXPLANATION "Użyj tego polecenia aby sprawdzić jak twój terminal wyświetla kolory."
#define STRING_CMD_COLOR_16          "16 kolorów (wsparcie dla podkreślenia, pogrubienia, jasnego tła):"
#define STRING_CMD_COLOR_256         "256 kolorów (wsparcie dla podkreślenia):"
#define STRING_CMD_COLOR_YOURS       "Twoja próbka kolorów:"
#define STRING_CMD_COLOR_BASIC       "Podstawowe kolory"
#define STRING_CMD_COLOR_EFFECTS     "Efekty tekstu"
#define STRING_CMD_COLOR_CUBE        "Kostka kolorów rgb"
#define STRING_CMD_COLOR_RAMP        "Odcienie szarości"
#define STRING_CMD_COLOR_TRY         "Spróbuj wykonać '{1}'."
#define STRING_CMD_COLOR_OFF         "Aktualnie, kolorowanie jest wyłączone w twoim pliku .taskrc. Aby włączyć kolorowanie, usuń linie 'color=off', lub zmień wartość 'off' na 'on'."
#define STRING_CMD_CONFIG_USAGE      "Zmienia konfigurację programu"
#define STRING_CMD_CONFIG_CONFIRM    "Czy na pewno chcesz zmienić wartość '{1}' z '{2}' na '{3}'?"
#define STRING_CMD_CONFIG_CONFIRM2   "Czy na pewno chcesz dodać '{1}' z wartością '{2}'?"
#define STRING_CMD_CONFIG_CONFIRM3   "Czy na pewno chcesz usunąć '{1}'?"
#define STRING_CMD_CONFIG_NO_ENTRY   "Nie znaleziono wpisu '{1}'."
#define STRING_CMD_CONFIG_FILE_MOD   "Plik konfiguracyjny {1} został zmodyfikowany."
#define STRING_CMD_CONFIG_NO_CHANGE  "Brak zmian."
#define STRING_CMD_CONFIG_NO_NAME    "Podaj nazwę zmiennej w konfiguracji do zmiany."
#define STRING_CMD_HCONFIG_USAGE     "Wylistuj wszystkie zmienne konfiguracji."
#define STRING_CMD_CONTEXT_USAGE     "Set and define contexts (default filters)"
#define STRING_CMD_CONTEXT_DEF_SUCC  "Context '{1}' defined. Use 'task context {1}' to activate."
#define STRING_CMD_CONTEXT_DEF_FAIL  "Context '{1}' not defined."
#define STRING_CMD_CONTEXT_DEF_USAG  "Both context name and its definition must be provided."
#define STRING_CMD_CONTEXT_DEF_ABRT  "Context definiton aborted."
#define STRING_CMD_CONTEXT_DEF_ABRT2 "Filter validation failed: {1}"
#define STRING_CMD_CONTEXT_DEF_CONF  "The filter '{1}' matches 0 pending tasks. Do you wish to continue?"
#define STRING_CMD_CONTEXT_DEF_INVLD "The name '{1}' is reserved and not allowed to use as a context name."
#define STRING_CMD_CONTEXT_DEL_SUCC  "Context '{1}' deleted."
#define STRING_CMD_CONTEXT_DEL_FAIL  "Context '{1}' not deleted."
#define STRING_CMD_CONTEXT_DEL_USAG  "Context name needs to be specified."
#define STRING_CMD_CONTEXT_LIST_EMPT "No contexts defined."
#define STRING_CMD_CONTEXT_SET_NFOU  "Context '{1}' not found."
#define STRING_CMD_CONTEXT_SET_SUCC  "Context '{1}' set. Use 'task context none' to remove."
#define STRING_CMD_CONTEXT_SET_FAIL  "Context '{1}' not applied."
#define STRING_CMD_CONTEXT_SHOW_EMPT "No context is currently applied."
#define STRING_CMD_CONTEXT_SHOW      "Context '{1}' with filter '{2}' is currently applied."
#define STRING_CMD_CONTEXT_NON_SUCC  "Context unset."
#define STRING_CMD_CONTEXT_NON_FAIL  "Context not unset."
#define STRING_CMD_HCONTEXT_USAGE    "Lists all supported contexts, for completion purposes"
#define STRING_CMD_CUSTOM_MISMATCH   "Liczba kolumn i nagłówków nie zgadza się dla raportu '{1}'."
#define STRING_CMD_CUSTOM_SHOWN      "{1} pokazanych"
#define STRING_CMD_CUSTOM_COUNT      "1 zadanie"
#define STRING_CMD_CUSTOM_COUNTN     "{1} zadań"
#define STRING_CMD_CUSTOM_TRUNCATED  "przycięte do {1} linii"
#define STRING_CMD_TIMESHEET_USAGE   "Tygodniowe podsumowanie z ukończonych i uruchomionych zadań"
#define STRING_CMD_TIMESHEET_STARTED "Uruchomiono ({1} zadań)"
#define STRING_CMD_TIMESHEET_DONE    "Ukończono ({1} zadań)"
#define STRING_CMD_BURN_USAGE_M      "Wyświetla miesięczny postęp w postaci wykresu."
#define STRING_CMD_BURN_USAGE_W      "Wyświetla tygodniowy postęp w postaci wykresu."
#define STRING_CMD_BURN_USAGE_D      "Wyświetla dzienny postęp w postaci wykresu."
#define STRING_CMD_BURN_TITLE        "Postęp"
#define STRING_CMD_BURN_TOO_SMALL    "Okno terminal jest za małe do wyświetlenia wykresu."
#define STRING_CMD_BURN_TOO_LARGE    "Terminal window too large to draw a graph."
#define STRING_CMD_BURN_DAILY        "Dzienny"
#define STRING_CMD_BURN_WEEKLY       "Tygodniowy"
#define STRING_CMD_BURN_MONTHLY      "Miesięczny"
#define STRING_CMD_BURN_STARTED      "Started"          // Must be 7 or fewer characters
#define STRING_CMD_BURN_DONE         "Done"             // Must be 7 or fewer characters
#define STRING_CMD_BURN_PENDING      "Pending"          // Must be 7 or fewer characters
#define STRING_CMD_BURN_NO_CONVERGE  "Brak konwergencji" // ?
#define STRING_CMD_HELP_USAGE        "Wyświetla tą pomoc"
#define STRING_CMD_HELP_USAGE_LABEL  "Użycie:"
#define STRING_CMD_HELP_USAGE_DESC   "Wykonuje rc.default.command, jeśli podano."
#define STRING_CMD_HELP_ALIASED      "Alias na '{1}'"
#define STRING_CMD_CAL_USAGE         "Wyświetla kalendarz z zadaniami z terminem"
#define STRING_CMD_CAL_BAD_MONTH     "Argument '{1}' nie jest poprawnym miesiącem"
#define STRING_CMD_CAL_BAD_ARG       "Nie rozpoznany argument '{1}'."
#define STRING_CMD_CAL_LABEL_DATE    "Data"
#define STRING_CMD_CAL_LABEL_HOL     "Wakacje"
#define STRING_CMD_CAL_SUN_MON       "Początek tygodnia może mieć wartość 'Niedziela' lub 'Poniedziałek'."
#define STRING_CMD_EDIT_USAGE        "Uruchamia edytor do zmiany zadania"
#define STRING_CMD_CALC_USAGE        "Kalkulator"

// Config
#define STRING_CONFIG_OVERNEST       "Plik konfiguracji zagnieżdzony na więcej niż 10 poziomów - to musi być jakaś pomyłka."
#define STRING_CONFIG_READ_INCLUDE   "Nie można przeczytać dołączonego pliku '{1}'."
#define STRING_CONFIG_INCLUDE_PATH   "Scieżka dołączanych plików musi mieć postać adresu bezwzględnego, nie '{1}'"
#define STRING_CONFIG_BAD_ENTRY      "Uszkodzony wpis '{1}' w pliku konfiguracyjnym."
#define STRING_CONFIG_BAD_WRITE      "Nie można pisać do '{1}'."
#define STRING_CONFIG_DEPRECATED_COL "Twój plik .taskrc zawiera raport z przestarzałymi nazwami kolumn.  Sprawdź proszę entry_time, start_time lub end_time w:"
#define STRING_CONFIG_DEPRECATED_VAR "Twój plik .taskrc zawiera przestarzałe zmienne:"

// Context
#define STRING_CONTEXT_CREATE_RC     "Plik konfiguracji nie może zostać znaleziony w {1}\n\nCzy pragniesz utworzenia przykładowego pliku {2} tak aby taskwarrior mógł kontynuować?"
#define STRING_CONTEXT_NEED_RC       "Nie można kontynuować bez pliku rc."
#define STRING_CONTEXT_RC_OVERRIDE   "TASKRC nadpisane: {1}"
#define STRING_CONTEXT_DATA_OVERRIDE "TASKDATA nadpisane: {1}"

// Date
#define STRING_DATE_INVALID_FORMAT   "'{1}' nie jest poprawną wartością daty w formacie '{2}'."
#define STRING_DATE_BAD_WEEKSTART    "Zmienna konfiguracji 'weekstart' może przyjmować tylko wartość 'Sunday' lub 'Monday'."

#define STRING_DATE_JANUARY          "styczeń"
#define STRING_DATE_FEBRUARY         "luty"
#define STRING_DATE_MARCH            "marzec"
#define STRING_DATE_APRIL            "kwiecień"
#define STRING_DATE_MAY              "maj"
#define STRING_DATE_JUNE             "czerwiec"
#define STRING_DATE_JULY             "lipiec"
#define STRING_DATE_AUGUST           "sierpień"
#define STRING_DATE_SEPTEMBER        "wrzesień"
#define STRING_DATE_OCTOBER          "październik"
#define STRING_DATE_NOVEMBER         "listopad"
#define STRING_DATE_DECEMBER         "grudzień"

#define STRING_DATE_SUNDAY           "niedziela"
#define STRING_DATE_MONDAY           "poniedziałek"
#define STRING_DATE_TUESDAY          "wtorek"
#define STRING_DATE_WEDNESDAY        "środa"
#define STRING_DATE_THURSDAY         "czwartek"
#define STRING_DATE_FRIDAY           "piątek"
#define STRING_DATE_SATURDAY         "sobota"

// dependency
#define STRING_DEPEND_BLOCKED        "Zadanie {1} jest blokowane przez:"
#define STRING_DEPEND_BLOCKING       "oraz blokuje:"
#define STRING_DEPEND_FIX_CHAIN      "Czy chcesz naprawić łańcuch zależności?"

// DOM
#define STRING_DOM_UNREC             "DOM: Nie mogę pobrać nierozpoznanej nazwy '{1}'."

// Eval
#define STRING_EVAL_NO_EXPRESSION    "Brak wyrażenia do przetworzenia."
#define STRING_EVAL_UNSUPPORTED      "Niewspierany operator '{1}'."
#define STRING_EVAL_OP_EXPECTED      "Oczekiwany operator."
#define STRING_EVAL_NO_EVAL          "Wyrażenie nie może być przetworzone."
#define STRING_EVAL_NOT_EXPRESSION   "The value is not an expression."
#define STRING_PAREN_MISMATCH        "Niedopasowane nawiasy w wyrażeniu"

// edit
#define STRING_EDIT_NO_CHANGES       "Nie znaleziono żadnych edycji."
#define STRING_EDIT_FAILED           "Editing failed with exit code {1}."
#define STRING_EDIT_COMPLETE         "Edycja zakończona."
#define STRING_EDIT_IN_PROGRESS      "Task is already being edited."
#define STRING_EDIT_LAUNCHING        "Uruchamianie '{1}'..."
#define STRING_EDIT_CHANGES          "Zmiany wykryte."
#define STRING_EDIT_UNPARSEABLE      "Taskwarrior nie może wprowadzić twoich zmian. Czy chcesz spróbować jeszcze raz?"
#define STRING_EDIT_UNWRITABLE       "Brak możliwości zapisu do katalogu data.location"
#define STRING_EDIT_TAG_SEP          "Rozdziel tagi białymi znakami, na przykład: tag1 tag2"
#define STRING_EDIT_DEP_SEP          "Zależności powinny być elementami listy, rozdzielonymi przecinkami. Na listę składają się ID/UUID lub zakresy ID, bez spacji."
#define STRING_EDIT_UDA_SEP          "Atrybuty definiowane przez użytkownika"
#define STRING_EDIT_UDA_ORPHAN_SEP   "Atrybuty Orphan definiowane przez użytkownika"
#define STRING_EDIT_END              "Koniec"

#define STRING_EDIT_PROJECT_MOD      "Projekt zmieniony."
#define STRING_EDIT_PROJECT_DEL      "Projekt usunięty."
#define STRING_EDIT_DESC_MOD         "Opis zmieniony."
#define STRING_EDIT_DESC_REMOVE_ERR  "Nie można usunąć opisu."
#define STRING_EDIT_ENTRY_REMOVE_ERR "Nie można usunąć daty utworzenia."
#define STRING_EDIT_ENTRY_MOD        "Data utworzenia zmieniona."
#define STRING_EDIT_START_MOD        "Data startu zmieniona."
#define STRING_EDIT_START_DEL        "Data startu usunięta."
#define STRING_EDIT_END_MOD          "Data zakończenia zmieniona."
#define STRING_EDIT_END_DEL          "Data zakończenia usunięta."
#define STRING_EDIT_END_SET_ERR      "Nie można ustawić daty ukończenia na zadaniu oczekującym."
#define STRING_EDIT_SCHED_MOD        "Harmonogram zmieniony."
#define STRING_EDIT_SCHED_DEL        "Harmonogram usunięty."
#define STRING_EDIT_DUE_MOD          "Termin zmieniony."
#define STRING_EDIT_DUE_DEL          "Termin usunięty."
#define STRING_EDIT_DUE_DEL_ERR      "Nie można usunąć terminu z zadanie rekurencyjnego."
#define STRING_EDIT_UNTIL_MOD        "Data końcowa zmieniona."
#define STRING_EDIT_UNTIL_DEL        "Data końcowa usunięta."
#define STRING_EDIT_RECUR_MOD        "Rekurencja zmieniona."
#define STRING_EDIT_RECUR_DEL        "Rekurencja usunięta."
#define STRING_EDIT_RECUR_DUE_ERR    "Zadanie rekurencyjne musi posiadać termin."
#define STRING_EDIT_RECUR_ERR        "Nie poprawny termin zadania rekurencyjnego."
#define STRING_EDIT_WAIT_MOD         "Data oczekiwania zmieniona."
#define STRING_EDIT_WAIT_DEL         "Data oczekiwania usunięta."
#define STRING_EDIT_PARENT_MOD       "UUID rodzica zmieniony."
#define STRING_EDIT_PARENT_DEL       "UUID rodzica usunięty."
#define STRING_EDIT_UDA_MOD          "UDA {1} zmieniony."
#define STRING_EDIT_UDA_DEL          "UDA {1} usunięty."

// These four blocks can be replaced, but the number of lines must not change.
#define STRING_EDIT_HEADER_1         "Polecenie 'task <id> edit' pozwala Ci na modyfikację wszystkich aspektów zadania"
#define STRING_EDIT_HEADER_2         "za pomocą edytora.  Poniżej przedstawiono reprezentację właściwości zadania."
#define STRING_EDIT_HEADER_3         "Zmodyfikuj co tylko chcesz a następnie zapisz i zamknij edytor,"
#define STRING_EDIT_HEADER_4         "taskwarrior odczyta plik, odnajdzie modyfikacje, a następnie zastosuje"
#define STRING_EDIT_HEADER_5         "te zmiany.  Jeśli zamkniesz edytor bez zapisywania zmian lub ich nie zrobisz,"
#define STRING_EDIT_HEADER_6         "taskwarrior nie podejmie żadych działań."

#define STRING_EDIT_HEADER_7         "Linie zaczynające się od # oznaczają dane których nie możesz zmieniać, np. ID"
#define STRING_EDIT_HEADER_8         "Jeśli będziesz zbyt kreatywny przy edycji, taskwarrior odeśle Cię"
#define STRING_EDIT_HEADER_9         "zpowrotem do edytora abyś spróbował jeszcze raz."

#define STRING_EDIT_HEADER_10        "Jeśli zapętlisz się przy edycji tego samego pliku, poprostu zamknij"
#define STRING_EDIT_HEADER_11        "edytor bez dokonywania zmian.  Taskwarrior rozpozna to i przerwie"
#define STRING_EDIT_HEADER_12        "edycję."

#define STRING_EDIT_HEADER_13        "Notatki wyglądają tak: <data> -- <tekst> i może ich być dowolna ilość."
#define STRING_EDIT_HEADER_14        "Separator ' -- ' pomiędzy datą a tekstem nie powinien być pominięty."
#define STRING_EDIT_HEADER_15        "Pusty slot poniżej został dodany dla Twojej wygody."

// Maintain the same spacing.
#define STRING_EDIT_TABLE_HEADER_1   "Nazwa              Edytowalne wartości"
#define STRING_EDIT_TABLE_HEADER_2   "-----------------  ----------------------------------------------------"

// Errors
// TODO Move each of these to appropriate section.
#define STRING_ERROR_PREFIX          "Błąd: "
#define STRING_UNKNOWN_ERROR         "Nieznany błąd."
#define STRING_TRIVIAL_INPUT         "Musisz podać polecenie lub zadanie do zmiany."
#define STRING_ASSUME_INFO           "Nie podano polecenia - zakładam 'information'."
#define STRING_INFINITE_LOOP         "Podstawienie anulowane ponieważ wykonano więcej niż {1} zmian - zabezpieczenie przed zapętleniem."
#define STRING_UDA_TYPE              "Atrybuty definiowane przez użytkownika mogą być typu 'string', 'date', 'duration' lub 'numeric'."
#define STRING_UDA_NUMERIC           "Wartość '{1}' nie jest poprawną wartością numeryczną."
#define STRING_UDA_COLLISION         "Nazwa UDA '{1}' jest jedną z nazw atrybutów podstawowych i dlatego jest niedozwolona."
#define STRING_INVALID_MOD           "Atrybut '{1}' nie zezwala na wartość '{2}'."
#define STRING_INVALID_SORT_COL      "Kolumna '{1}' nie jest poprawnym parametrem sortowania."
#define STRING_ERROR_DETAILS         "Zmienna 'calendar.details.report' musi zawierać nazwę raportu."
#define STRING_ERROR_NO_FILTER       "Command line filters are not supported by this command."
#define STRING_ERROR_CONFIRM_SIGINT  "Interrupted: No changes made."
#define STRING_ERROR_BAD_STATUS      "The status '{1}' is not valid."

// Feedback
#define STRING_FEEDBACK_NO_TASKS     "Brak zadań."
#define STRING_FEEDBACK_NO_TASKS_SP  "Nie określono zadań"
#define STRING_FEEDBACK_NO_MATCH     "Nie znaleziono pasujących."
#define STRING_FEEDBACK_TASKS_SINGLE "(1 zadanie)"
#define STRING_FEEDBACK_TASKS_PLURAL "({1} zadania)"
#define STRING_FEEDBACK_DELETED      "{1} będzie usunięte."
#define STRING_FEEDBACK_DEP_SET      "Zależności będą ustawione na '{1}'."
#define STRING_FEEDBACK_DEP_MOD      "Zależności będą zmienione z '{1}' na '{2}'."
#define STRING_FEEDBACK_DEP_DEL      "Zależności '{1}' usunięte."
#define STRING_FEEDBACK_DEP_WAS_SET  "Zależności ustawione na '{1}'."
#define STRING_FEEDBACK_DEP_WAS_MOD  "Zależności zmienione z '{1}' na '{2}'."
#define STRING_FEEDBACK_ATT_SET      "{1} będzie ustawione na '{2}'."
#define STRING_FEEDBACK_ATT_MOD      "{1} będzie ustawione z '{2}' na '{3}'."
#define STRING_FEEDBACK_ATT_DEL      "{1} usunięte."
#define STRING_FEEDBACK_ATT_DEL_DUR  "{1} usunięte (czas trwania: {2})."
#define STRING_FEEDBACK_ATT_WAS_SET  "{1} ustawiono na '{2}'."
#define STRING_FEEDBACK_ATT_WAS_MOD  "{1} zmieniono z '{2}' na '{3}'."
#define STRING_FEEDBACK_ANN_ADD      "Notatka '{1}' dodana."
#define STRING_FEEDBACK_ANN_DEL      "Notatka '{1}' usunięta."
#define STRING_FEEDBACK_ANN_WAS_MOD  "Notatka zmieniona na '{1}'."
#define STRING_FEEDBACK_NOP          "Nie będą wprowadzone żadne zmiany."
#define STRING_FEEDBACK_WAS_NOP      "Nie wprowadzono żadnych zmian."
#define STRING_FEEDBACK_TAG_NOCOLOR  "Specjalny tag 'nocolor' wyłączy reguły kolorowania dla tego zadania."
#define STRING_FEEDBACK_TAG_NONAG    "Specjalny tag 'nonag' uchroni przed upierdliwością kiedy zadanie jest modyfikowane."
#define STRING_FEEDBACK_TAG_NOCAL    "Specjalny tag 'nocal' spowoduje nie dodawanie zadania do kalendarza."
#define STRING_FEEDBACK_TAG_NEXT     "Specjalny tag 'next' podniesie pilność tego zadania co spowoduje wyświetlenie go w raporcie 'next'."
#define STRING_FEEDBACK_TAG_VIRTUAL  "Virtual tags (including '{1}') are reserved and may not be added or removed."
#define STRING_FEEDBACK_UNBLOCKED    "Odblokowane {1} '{2}'."
#define STRING_FEEDBACK_EXPIRED      "Zadanie {1} '{2}' jest przedawnione i zostało usunięte."
#define STRING_FEEDBACK_BACKLOG_N    "Wykryto {1} lokalne zmiany. Wymagana synchronizacja."
#define STRING_FEEDBACK_BACKLOG      "Wykryto {1} lokalne zmiany. Wymagana synchronizacja."

// helpers
#define STRING_HELPER_PROJECT_CHANGE "The project '{1}' has changed."
#define STRING_HELPER_PROJECT_COMPL  "Project '{1}' is {2}% complete"
#define STRING_HELPER_PROJECT_REM    "({1} of {2} tasks remaining)."
#define STRING_HELPER_PROJECT_REM1   "({1} task remaining)."

// Hooks
#define STRING_HOOK_ERROR_OBJECT     "Hook Error: JSON Object '{...}' expected from hook script: {1}"
#define STRING_HOOK_ERROR_NODESC     "Hook Error: JSON Object missing 'description' attribute from hook script: {1}"
#define STRING_HOOK_ERROR_NOUUID     "Hook Error: JSON Object missing 'uuid' attribute from hook script: {1}"
#define STRING_HOOK_ERROR_SYNTAX     "Hook Error: JSON syntax error in: {1}"
#define STRING_HOOK_ERROR_JSON       "Hook Error: JSON "
#define STRING_HOOK_ERROR_NOPARSE    "Hook Error: JSON failed to parse: "
#define STRING_HOOK_ERROR_BAD_NUM    "Hook Error: Expected {1} JSON task(s), found {2}, in hook script: {3}"
#define STRING_HOOK_ERROR_SAME1      "Hook Error: JSON must be for the same task: {1}, in hook script: {2}"
#define STRING_HOOK_ERROR_SAME2      "Hook Error: JSON must be for the same task: {1} != {2}, in hook script: {3}"
#define STRING_HOOK_ERROR_NOFEEDBACK "Hook Error: Expected feedback from failing hook script: {1}"

// Record
#define STRING_RECORD_EMPTY          "Pusty wpis na wejściu."
#define STRING_RECORD_JUNK_AT_EOL    "Nierozpoznawalny znak na koncu lini."
#define STRING_RECORD_NOT_FF4        "Wpis nie rozpoznany jako wersja 4."

// 'show' command
#define STRING_CMD_SHOW              "Pokazuje wszystkie zmienne konfiguracji lub ich podzbiór"
#define STRING_CMD_SHOW_ARGS         "Możesz jedynie wybrać wszystkie lub wyszukać na podstawie ciągu."
#define STRING_CMD_SHOW_NONE         "Brak dopasowania zmiennych konfiguracyjnych."
#define STRING_CMD_SHOW_UNREC        "Twój plik .taskrc zawiera następujące nierozpoznane zmienne:"
#define STRING_CMD_SHOW_DIFFER       "Niektóre ze zmiennych w twoim .taskrc różnią się od wartości domyślnych."
#define STRING_CMD_SHOW_EMPTY        "Błąd konfiguracji: .taskrc jest puste."
#define STRING_CMD_SHOW_DIFFER_COLOR "Są one podświetlone na {1}."
#define STRING_CMD_SHOW_CONFIG_ERROR "Błąd konfiguracji: {1} zawiera nierozpoznaną wartość '{2}'."
#define STRING_CMD_SHOW_NO_LOCATION  "Błąd konfiguracji: data.location nie ustawione w pliku .taskrc."
#define STRING_CMD_SHOW_LOC_EXIST    "Błąd konfiguracji: data.location zawiera nazwę katalogu który nie istnieje lub jest nieosiągalny."
#define STRING_CMD_SHOW_CONF_VAR     "Zmienna Konfiguracji"
#define STRING_CMD_SHOW_CONF_VALUE   "Wartość"
#define STRING_CMD_SHOW_CONF_DEFAULT "Domyślna wartość"
#define STRING_CMD_SHOWRAW           "Pokazuje kompletną konfiguracjię w formacie dogodnym dla maszyny"

// Task
#define STRING_TASK_NO_FF1           "Taskwarrior nie wspiera więcej formatu plików 1, wcześniej używanego pomiędzy 27 Listopada 2006 i 31 Grudnia 2007."
#define STRING_TASK_NO_FF2           "Taskwarrior nie wspiera więcej formatu plików 2, wcześniej używanego pomiędzy 1 Stycznia 2008 i 12 Kwietnia 2009."
#define STRING_TASK_NO_FF3           "Taskwarrior nie wspiera więcej formatu plików 3, wcześniej używanego pomiędzy 23 Marca 2009 i 16 Maja 2009."
#define STRING_TASK_PARSE_UNREC_FF   "Nierozpoznany format pliku programu taskwarrior."
#define STRING_TASK_DEPEND_ITSELF    "Zadanie nie może zależeć od samego siebie."
#define STRING_TASK_DEPEND_MISS_CREA "Nie można dodać zależności dla zadania {1} - nie znaleziono."
#define STRING_TASK_DEPEND_MISS_DEL  "Nie można usunąć zależności dla zadania {1} - nie znaleziono."
#define STRING_TASK_DEPEND_DUP       "Zadanie {1} już jest zależne od zadania {2}."
#define STRING_TASK_DEPEND_CIRCULAR  "Wykryto i nie dopuszczono do zależności cyklicznej."
#define STRING_TASK_VALID_DESC       "Zadanie musi posiadać opis."
#define STRING_TASK_VALID_BLANK      "Nie można dodać pustego zadania."
#define STRING_TASK_VALID_BEFORE     "Uwaga: podałeś datę '{1}' jako datę po '{2}'."
#define STRING_TASK_VALID_REC_DUE    "Zadanie cykliczne musi posiadać datę zakończenia."
#define STRING_TASK_VALID_RECUR      "Wartość '{1}' określająca okres zadania jest niepoprawna."
#define STRING_TASK_SAFETY_VALVE     "This command has no filter, and will modify all (including completed and deleted) tasks.  Are you sure?"
#define STRING_TASK_SAFETY_FAIL      "Niedopuszczono do wykonania polecenia."
#define STRING_TASK_SAFETY_ALLOW     "Brak filtra, z aktywną flagą 'allow.empty.filter', nie podjęto akcji."
#define STRING_TASK_INVALID_DUR      "Wartość czas trwania '{1}' jest niewspierana."
#define STRING_TASK_INVALID_COL_TYPE "Nierozpoznany typ kolumny '{1}' dla kolumny '{2}'"

// TDB2
#define STRING_TDB2_PARSE_ERROR      " w {1} w lini {2}"
#define STRING_TDB2_UUID_NOT_UNIQUE  "Nie można dodać zadania ponieważ uuid '{1}' nie jest unikalny."
#define STRING_TDB2_MISSING          "Brakuje                       {1}  \"{2}\""
#define STRING_TDB2_NO_UNDO          "Nie ma żadnych zapisanych transakcji do cofnięcia."
#define STRING_TDB2_LAST_MOD         "Ostatnia dokonana modyfikcaja {1}"
#define STRING_TDB2_UNDO_PRIOR       "Prior Wartości"
#define STRING_TDB2_UNDO_CURRENT     "Aktualne Wartości"
#define STRING_TDB2_DIFF_PREV        "--- poprzedni stan"             // Same length
#define STRING_TDB2_DIFF_PREV_DESC   "Cofnij przywróci ten stan"      //   ||
#define STRING_TDB2_DIFF_CURR        "+++ aktualny stan "             // Same length
#define STRING_TDB2_DIFF_CURR_DESC   "Zmiana w {1}"
#define STRING_TDB2_UNDO_CONFIRM     "Polecenie cofnij jest nieodwracalne.  Czy jesteś pewien że chcesz przywrócić poprzedni stan?"
#define STRING_TDB2_MISSING_UUID     "Nie można zlokalizować UUID w zadaniu do cofnięcia."
#define STRING_TDB2_REVERTED         "Zrewerotowano zmienione zadania."
#define STRING_TDB2_REMOVED          "Zadanie usunięte."
#define STRING_TDB2_UNDO_COMPLETE    "Operacja cofnięcia zakończona."
#define STRING_TDB2_UNDO_SYNCED      "Nie można cofnąć zmian ponieważ zadanie zostało zsynchronizowane.  Zmodyfikuj zadanie."
#define STRING_TDB2_DIRTY_EXIT       "Zamykanie z niezapisanymi zmianami w {1}"
#define STRING_TDB2_UNWAIT           "Un-waiting task '{1}'"

// recur.cpp
#define STRING_RECUR_CREATE          "Creating recurring task instance '{1}'"

// View
#define STRING_VIEW_TOO_SMALL        "Raport ma minimalną szerokość {1} i nie mieści się w dostępnej przestrzeni {2}."

// Usage text.  This is an exception, and contains \n characters and formatting.
#define STRING_CMD_HELP_TEXT \
  "Dokumentację dla Taskwarrior można przeglądać za pomocą 'man task', 'man taskrc', 'man " \
  "task-color', 'man task-sync', lub na http://taskwarrior.org\n" \
  "\n" \
  "Ogólna postać poleceń jest następująca:\n" \
  "  task [<filtr>] <polecenie> [<mody>]\n" \
  "\n" \
  "Wyrażenie <filtr> składa się z zera lub więcej przybliżeń zmniejszających " \
  "wynikowy zbiór zadań, np.:\n" \
  "  task                                      <polecenie> <mody>\n" \
  "  task 28                                   <polecenie> <mody>\n" \
  "  task +weekend                             <polecenie> <mody>\n" \
  "  task project:Home due.before:today        <polecenie> <mody>\n" \
  "  task ebeeab00-ccf8-464b-8b58-f7f2d606edfb <polecenie> <mody>\n" \
  "\n" \
  "Domyślnie, elementy składowe filtra są łączone logicznym 'and', ale " \
  "'or' lub 'xor' może być również użyte:\n" \
  "  task '(/[Cc]at|[Dd]og/ or /[0-9]+/)'      <polecenie> <mody>\n" \
  "\n" \
  "Filtr może wybrać konkretne zadania na podstawie numerów ID lub UUID.  Aby wybrać " \
  "więcej niż jedno zadanie użyj jednej z form:\n" \
  "  task 1,2,3                                    delete\n" \
  "  task 1-3                                      info\n" \
  "  task 1,2-5,19                                 modify pri:H\n" \
  "  task 4-7 ebeeab00-ccf8-464b-8b58-f7f2d606edfb info\n" \
  "\n" \
  "Wyrażenia <mody> składają się na zera lub więcej zmian we właściwościach wybranych zadań," \
  "np.:\n" \
  "  task <filtr> <polecenie> project:Home\n" \
  "  task <filtr> <polecenie> +weekend +garden due:tomorrow\n" \
  "  task <filtr> <polecenie> Description/annotation text\n" \
  "  task <filtr> <polecenie> /from/to/     <- zastąpić pierwszego wystąpienia\n" \
  "  task <filtr> <polecenie> /from/to/g    <- zastąpić wszystkie wystąpienia\n" \
  "\n" \
  "Tagi są dowolnymi słowami występującymi w nieograniczonej ilości:\n" \
  "  +tag       + oznacza dodanie taga\n" \
  "  -tag       - oznacza usunięcie taga\n" \
  "\n" \
  "Wbudowanymi atrybutami są:\n" \
  "  description:    Tekst opisu zadania\n" \
  "  status:         Status zadania - zawieszone, zakończone, usunięte, czekające\n" \
  "  project:        Nazwa projektu\n" \
  "  priority:       Priorytet\n" \
  "  due:            Termin\n" \
  "  recur:          Częstotliwość powtarzania\n" \
  "  until:          Data przedawnienia zadania\n" \
  "  limit:          Oczekiwana liczba wierszy w raporcie lub 'stron'\n" \
  "  wait:           Data do kiedy zadanie pozostaje zawieszone\n" \
  "  entry:          Data utworzenia zadania\n" \
  "  end:            Data ukończenia/usunięcia zadania\n" \
  "  start:          Data wystartowania zadania\n" \
  "  scheduled:      Data zaplanowanego startu zadania\n" \
  "  modified:       Date task was last modified\n" \
  "  depends:        Inne zadania od których zależy dane zadanie\n" \
  "\n" \
  "Modyfikatory atrybutów zwiększają precyzję filtrów.  Dostępne modyfikatory:\n" \
  "\n" \
  "  Modifiers         Example            Equivalent           Meaning\n" \
  "  ----------------  -----------------  -------------------  -------------------------\n" \
  "                    due:today          due = today          Fuzzy match\n" \
  "  not               due.not:today      due != today         Fuzzy non-match\n" \
  "  before, below     due.before:today   due < tomorrow       Exact date comparison\n" \
  "  after, above      due.after:today    due > tomorrow       Exact date comparison\n" \
  "  none              project.none:      project == ''        Empty\n" \
  "  any               project.any:       project !== ''       Not empty\n" \
  "  is, equals        project.is:x       project == x         Exact match\n" \
  "  isnt              project.isnt:x     project !== x        Exact non-match\n" \
  "  has, contains     desc.has:Hello     desc ~ Hello         Pattern match\n" \
  "  hasnt,            desc.hasnt:Hello   desc !~ Hello        Pattern non-match\n" \
  "  startswith, left  desc.left:Hel      desc ~ '^Hel'        Beginning match\n" \
  "  endswith, right   desc.right:llo     desc ~ 'llo$'        End match\n" \
  "  word              desc.word:Hello    desc ~ '\\bHello\\b'   Boundaried word match\n" \
  "  noword            desc.noword:Hello  desc !~ '\\bHello\\b'  Boundaried word non-match\n" \
  "\n" \
  "Dostępne wyrażenia algebraiczne:\n" \
  "  and  or  xor            Operatory logiczne\n" \
  "  <  <=  =  !=  >=  >     Operatory relacji\n" \
  "  (  )                    Pierwszeństwa\n" \
  "\n" \
  "  task due.before:eom priority.not:L   list\n" \
  "  task '(due < eom or priority != L)'  list\n" \
  "\n" \
  "Domyślne .taskrc może być nadpisane, np.:\n" \
  "  task ... rc:<inny plik> ...\n" \
  "  task ... rc:~/.inny_taskrc ...\n" \
  "\n" \
  "Wartości w .taskrc (lub inne) mogą być nadpisane, np.:\n" \
  "  task ... rc.<nazwa>=<wartość> ...\n" \
  "  task rc.color=off list\n" \
  "\n" \
  "Dowolne polecenie może być wyrażone w formie skrótowej jeśli pozostaje jednoznaczne:\n" \
  "  task list project:Home\n" \
  "  task li       pro:Home\n" \
  "\n" \
  "Niektóre opisy zadań muszą być poprzedzone znakiem ucieczki z powodu zastrzeżonych symboli powłoki:\n" \
  "  task add \"quoted ' quote\"\n" \
  "  task add escaped \\' quote\n" \
  "\n" \
  "Argument -- mówi programowi taskwarrior aby traktował wszystkie pozostałe argumenty jako opis " \
  "zadania, nawet jeśli w innym przypadku zinterpretowałby je jako atrybuty lub tagi:\n" \
  "  task add -- project:Home needs scheduling\n" \
  "\n" \
  "Wiele znaków ma specialne znaczenie dla powłoki, włączając:\n" \
  "  $ ! ' \" ( ) ; \\ ` * ? { } [ ] < > | & % # ~\n" \
  "\n"

/*
  To be included later, before the 'precendence' line.

  "  +  -                    Addition, subtraction\n" \
  "  !                       Inversion\n" \
  "  ~  !~                   Match, no match\n" \
*/

// util
#define STRING_UTIL_CONFIRM_YES      "tak"
#define STRING_UTIL_CONFIRM_YES_U    "Tak"
#define STRING_UTIL_CONFIRM_NO       "nie"
#define STRING_UTIL_CONFIRM_ALL      "wszystko"
#define STRING_UTIL_CONFIRM_ALL_U    "Wszystko"
#define STRING_UTIL_CONFIRM_QUIT     "wyjście"

// Legacy
#define STRING_LEGACY_PRIORITY       "Legacy attribute found.  Please change '{1}' to '{2}'."

#endif
