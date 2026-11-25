# PUSH_SWAP — CHECKLIST MAÎTRESSE DE DÉVELOPPEMENT

**Référentiel de travail du binôme — sujet officiel Push_swap v1.2 — 24 novembre 2026**  
**Algorithmes fixés :** `--simple` = Selection Sort ; `--medium` = Chunk Sort canonisé puis optimisé ; `--complex` = LSD Binary Radix ; `--adaptive` = sélection selon les inversions.  
**Document parent :** `PUSH_SWAP_PLAN_DE_BATAILLE_A_Z_V1-1.md` ; **source normative :** `en.subject (1).pdf`, v1.2, 22 pages.

> **Utilisation** — Cette checklist est un **outil de suivi de travail**, pas du code à copier tel quel. Toute ligne `- [ ]` est une tâche non validée ; passer à `- [x]` **uniquement** après implémentation, test, revue croisée et intégration. Les noms de fonctions et les fichiers sont des **interfaces proposées par notre plan**, pas des noms exigés par le PDF. Si une fonction est fusionnée, renommée ou volontairement supprimée, mettre à jour la tâche et noter la raison dans `docs/decisions.md` au lieu de cocher artificiellement une fonction inexistante.

## Tableau de pilotage et règles communes [PIL]

**Équipe :** développeur A / login : `________` ; développeur B / login : `________`.  
**Branches :** `main` stable, branches de tâches courtes ; **révision croisée obligatoire**.  
**Attribution :** la case `Resp. : ____` apparaît sur chaque tâche : renseigner `A`, `B` ou `A+B`.  
**Statut en cours :** laisser `[ ]` et ajouter `EN COURS` en fin de ligne ; **bloqué :** ajouter `BLOQUÉ : cause`, sans cocher.  
**Date :** à renseigner dans les jalons, ne pas inventer de planning.

| Lot | Propriétaire | Relecteur | Dépend de | Livrable / preuve |
|---|---|---|---|---|
| PIL — pilotage / exigences | ____ | ____ | — | critères d'acceptation signés |
| INF — dépôt / Makefile / headers | ____ | ____ | PIL | compilation Linux sans relink |
| MEM — structure de pile / mémoire | ____ | ____ | INF | invariants des liens testés |
| PAR — arguments / validation | ____ | ____ | INF, MEM | matrice entrées valides/invalides |
| RAN — normalisation des rangs | ____ | ____ | PAR | bijection valeur/rang prouvée |
| OPS — 11 instructions | ____ | ____ | MEM, INF | simulateur indépendant conforme |
| SML — petits tris | ____ | ____ | OPS, RAN | toutes les permutations 0–5 |
| SEL — Selection général | ____ | ____ | SML, OPS, RAN | mode forcé correct, borne O(n²) |
| CHK — Chunk Medium | ____ | ____ | OPS, RAN | O(n√n) prouvé, tests OK |
| RDX — Radix Complex | ____ | ____ | OPS, RAN | O(n log n) prouvé, tests OK |
| ADP — inversions / choix | ____ | ____ | SEL, CHK, RDX | frontières vérifiées |
| BEN — rapport / comptage | ____ | ____ | OPS, ADP | stderr exact, stdout inchangé |
| APP — orchestration | ____ | ____ | PAR à BEN | binaire complet opérationnel |
| TST — harness de tests | ____ | ____ | OPS, APP | logs reproductibles |
| PERF — optimisation & mesures | ____ | ____ | TST, CHK, RDX | rapport avant/après |
| DOC — README / preuves / AI | ____ | ____ | Tous | README officiel et contributions |
| REV — revue / correction | A+B | A+B | Tous mandatory | soutenance blanche |
| BNS — checker bonus (optionnel) | à décider | à décider | Mandatory parfait | `make bonus`, `checker` |
| LIV — livraison | A+B | A+B | REV (+ BNS si retenu) | archive Git propre, tests OK |

### Suivi quantitatif — état initial (à mettre à jour après chaque fusion)

| Lot | Cases totales | Cases cochées | % terminé |
|---|---:|---:|---:|
| `PIL` | 22 | 0 | 0 % |
| `INF` | 38 | 0 | 0 % |
| `MEM` | 30 | 0 | 0 % |
| `PAR` | 37 | 0 | 0 % |
| `RAN` | 15 | 0 | 0 % |
| `OPS` | 39 | 0 | 0 % |
| `SML` | 20 | 0 | 0 % |
| `SEL` | 22 | 0 | 0 % |
| `CHK` | 55 | 0 | 0 % |
| `RDX` | 27 | 0 | 0 % |
| `ADP` | 30 | 0 | 0 % |
| `BEN` | 29 | 0 | 0 % |
| `APP` | 18 | 0 | 0 % |
| `TST` | 62 | 0 | 0 % |
| `PER` | 27 | 0 | 0 % |
| `DOC` | 30 | 0 | 0 % |
| `EQU` | 21 | 0 | 0 % |
| `REV` | 29 | 0 | 0 % |
| `BNS` | 28 | 0 | 0 % |
| `LIV` | 22 | 0 | 0 % |
| **TOTAL mandatory** | **573** | **0** | **0 %** |
| **BONUS facultatif** | **28** | **0** | **0 %** |

> Ce tableau constitue un **instantané initial** : GitHub ne recalcule pas les colonnes après un clic sur les cases. Les mettre à jour manuellement en fusionnant une branche, ou utiliser un petit script de comptage. Les tâches non applicables (helpers facultatifs, bonus non retenu) doivent être **documentées** plutôt que cochées artificiellement.

**Définition universelle de « terminé » :** fonction compilable sous Linux du campus, comportement conforme au contrat, tests positifs/négatifs, Norminette, aucun accès invalide ni fuite, intégration dans `main`, revue et explication par l'autre membre. Une tâche de conception se coche lorsque la décision est écrite et validée par les deux ; une tâche de test se coche uniquement lorsque le test a réellement tourné avec une trace conservée.

- [ ] **PIL-001** · Relire ensemble les chapitres VI.1 à VI.6 et VII du sujet v1.2, en distinguant obligation officielle et recommandation interne.  **· Resp. :** `____`
- [ ] **PIL-002** · Vérifier que la version du PDF disponible dans l'Intra correspond à `v1.2` et conserver la date de vérification.  **· Resp. :** `____`
- [ ] **PIL-003** · Noter les deux logins réels et les noms des membres à utiliser dans le README et le dépôt.  **· Resp. :** `____`
- [ ] **PIL-004** · Valider définitivement Selection / Chunk / Radix et conserver la décision dans `docs/decisions.md`.  **· Resp. :** `____`
- [ ] **PIL-005** · Se mettre d'accord sur la convention : sommet = `head`, premier argument numérique = sommet, affichage pédagogique sommet à gauche.  **· Resp. :** `____`
- [ ] **PIL-006** · Se mettre d'accord sur la double liste non circulaire `head` / `tail` / `size` et ses invariants.  **· Resp. :** `____`
- [ ] **PIL-007** · Décider si les options peuvent apparaître après les nombres : extension de tolérance **non imposée** par le sujet.  **· Resp. :** `____`
- [ ] **PIL-008** · Décider si les arguments numériques entre guillemets peuvent contenir plusieurs nombres : tolérance du plan à confirmer localement.  **· Resp. :** `____`
- [ ] **PIL-009** · Décider si les espaces ASCII, tabulations et retours à la ligne sont acceptés comme séparateurs dans un `argv[i]`.  **· Resp. :** `____`
- [ ] **PIL-010** · Décider de l'erreur sur `--simple --simple`, `--bench --bench`, deux sélecteurs et les options inconnues.  **· Resp. :** `____`
- [ ] **PIL-011** · Définir le comportement de `./push_swap --bench` sans valeur numérique, sans inventer une contrainte officielle.  **· Resp. :** `____`
- [ ] **PIL-012** · Décider de la politique des opérations sans effet : émission uniquement si une pile est effectivement modifiée (convention du plan).  **· Resp. :** `____`
- [ ] **PIL-013** · Valider le format exact interne des lignes de benchmark, en conservant les champs obligatoires du sujet.  **· Resp. :** `____`
- [ ] **PIL-014** · Valider le choix : algorithme forcé réellement exécuté sur toutes les tailles ; petit tri réservé à la voie adaptative initiale.  **· Resp. :** `____`
- [ ] **PIL-015** · Définir la convention `mode_requested` / `used_mode`, notamment dans `--bench` avec `n<=5`.  **· Resp. :** `____`
- [ ] **PIL-016** · Écrire les signatures C définitives dans les headers communs avant de répartir l'implémentation.  **· Resp. :** `____`
- [ ] **PIL-017** · Choisir qui est responsable de chaque lot dans le tableau ci-dessus.  **· Resp. :** `____`
- [ ] **PIL-018** · Identifier qui fait la revue croisée de chaque lot et comment consigner l'approbation.  **· Resp. :** `____`
- [ ] **PIL-019** · Définir une politique de code de retour (`0` succès, non-zéro erreur) comme choix d'implémentation.  **· Resp. :** `____`
- [ ] **PIL-020** · Définir le mode de traçage des tests : commit Git, taille, seed, entrée, mode, résultats, compteur.  **· Resp. :** `____`
- [ ] **PIL-021** · Définir les jalons de validation bloquants (voir tableau de livraison en fin de document).  **· Resp. :** `____`
- [ ] **PIL-022** · Définir pour chaque stratégie la complexité en mouvements, la complexité CPU (analyses C) et la mémoire auxiliaire ; ne pas mélanger ces métriques.  **· Resp. :** `____`

## 01. Dépôt, arborescence, Makefile et interfaces [INF]

**Fichiers prévus :** `Makefile`, `src/main.c`, `include/push_swap.h`, `include/ps_ops.h`, `include/ps_sort.h`, `src/...` ; `libft/` si utilisée, `tests/` et `docs/` hors compilation standard. **Attention :** ne pas créer des fichiers artificiels pour respecter une arborescence imaginée ; respecter au maximum cinq définitions de fonctions par `.c` conformément à la Norme locale.

- [ ] **INF-001** · Créer le dépôt Git de travail de l'équipe ou valider le dépôt 42 imposé, sa branche principale et les accès des deux membres.  **· Resp. :** `____`
- [ ] **INF-002** · Ajouter un `.gitignore` minimal (objets, exécutables locaux, rapports temporaires, fichiers de bench générés, caches Python).  **· Resp. :** `____`
- [ ] **INF-003** · Créer `include/`, `src/parsing/`, `src/stack/`, `src/rank/`, `src/ops/`, `src/sort/`, `src/adaptive/`, `src/bench/` au fur et à mesure des besoins.  **· Resp. :** `____`
- [ ] **INF-004** · Créer `tests/`, `tests/cases/`, `tools/`, `docs/` sans lier les outils Python au binaire rendu.  **· Resp. :** `____`
- [ ] **INF-005** · Figer l'API de `t_node` : `int value`, `int rank`, `next`, `prev` ; zéro mutation du rang après normalisation.  **· Resp. :** `____`
- [ ] **INF-006** · Figer l'API de `t_stack` : `head`, `tail`, `size`, pile vide identifiée par les trois champs.  **· Resp. :** `____`
- [ ] **INF-007** · Figer `t_mode` avec les modes adaptive, simple, medium et complex.  **· Resp. :** `____`
- [ ] **INF-008** · Figer `t_options` : sélecteur unique et booléen `bench`, sans globales.  **· Resp. :** `____`
- [ ] **INF-009** · Figer l'énumération des 11 opérations avec un ordre stable pour les compteurs.  **· Resp. :** `____`
- [ ] **INF-010** · Figer `t_stats` : compteurs par opération, total, désordre initial, moteur réellement utilisé.  **· Resp. :** `____`
- [ ] **INF-011** · Figer `t_app` : deux piles, options, statistiques et `initial_size`.  **· Resp. :** `____`
- [ ] **INF-012** · Documenter la propriété de la mémoire (nœuds détenus par une pile ; tableaux temporaires détenus par la fonction qui les alloue).  **· Resp. :** `____`
- [ ] **INF-013** · Définir les prototypes publics des opérations dans `ps_ops.h` ; helpers internes `static` ou prototype privé si partagés.  **· Resp. :** `____`
- [ ] **INF-014** · Définir les prototypes publics des tris et du dispatcher dans `ps_sort.h`.  **· Resp. :** `____`
- [ ] **INF-015** · Définir les prototypes communs de parsing, normalisation, nettoyage et rapport dans `push_swap.h` ou un header dédié, sans circularité.  **· Resp. :** `____`
- [ ] **INF-016** · Vérifier l'inclusion unique via guards `#ifndef`/`#define` dans chaque header.  **· Resp. :** `____`
- [ ] **INF-017** · Faire compiler un programme minimal `push_swap` avec `cc -Wall -Wextra -Werror`.  **· Resp. :** `____`
- [ ] **INF-018** · Définir `NAME = push_swap`, `CC = cc`, `CFLAGS = -Wall -Wextra -Werror` dans le Makefile.  **· Resp. :** `____`
- [ ] **INF-019** · Lister explicitement les `.c` actifs et générer leurs `.o` en conservant les sous-dossiers.  **· Resp. :** `____`
- [ ] **INF-020** · Ajouter la règle `$(NAME)` liant uniquement les objets nécessaires, sans ajouter les tests au binaire.  **· Resp. :** `____`
- [ ] **INF-021** · Ajouter la règle `all` dépendant de `$(NAME)`.  **· Resp. :** `____`
- [ ] **INF-022** · Ajouter `clean` supprimant les `.o` et dépendances générées.  **· Resp. :** `____`
- [ ] **INF-023** · Ajouter `fclean` supprimant aussi `push_swap` et les binaires bonus si concerné.  **· Resp. :** `____`
- [ ] **INF-024** · Ajouter `re` effectuant une reconstruction complète.  **· Resp. :** `____`
- [ ] **INF-025** · Ajouter une dépendance des objets sur les headers utilisés (manuelle ou `-MMD -MP`, si maîtrisé).  **· Resp. :** `____`
- [ ] **INF-026** · Tester qu'un second `make` ne recompile ni ne relinke inutilement.  **· Resp. :** `____`
- [ ] **INF-027** · Tester que changer un header recompilera les sources concernées.  **· Resp. :** `____`
- [ ] **INF-028** · Tester `make clean`, `make`, `make fclean`, `make re` dans cet ordre.  **· Resp. :** `____`
- [ ] **INF-029** · Si Libft utilisée, copier **sources et Makefile** dans `libft/` et l'invoquer depuis le Makefile principal.  **· Resp. :** `____`
- [ ] **INF-030** · Si Libft utilisée, vérifier le `make clean/fclean` du sous-projet et le lien explicite vers `libft.a`.  **· Resp. :** `____`
- [ ] **INF-031** · Vérifier que chaque fonction externe du binaire provient de la liste officielle ou de fonctions personnelles autorisées.  **· Resp. :** `____`
- [ ] **INF-032** · Vérifier que `printf`, `atoi`, `qsort`, `sqrt`, `log2` et équivalents système non autorisés ne sont pas appelés par le livrable.  **· Resp. :** `____`
- [ ] **INF-033** · Tester une compilation à froid sur l'environnement Linux du campus (et pas seulement MSYS2/Windows).  **· Resp. :** `____`
- [ ] **INF-034** · Préparer un Makefile séparant clairement `push_swap` obligatoire et `checker` facultatif via la cible `bonus`.  **· Resp. :** `____`
- [ ] **INF-035** · Exécuter `norminette` sur les fichiers créés et corriger les erreurs au fil de l'eau.  **· Resp. :** `____`
- [ ] **INF-036** · Vérifier tout spécialement : 25 lignes/fonction, 5 variables, 4 paramètres, 5 fonctions par `.c`, 80 colonnes et blancs obligatoires selon la version du campus.  **· Resp. :** `____`
- [ ] **INF-037** · Vérifier l'absence de variables globales ; les configurations et compteurs doivent être dans `t_app`.  **· Resp. :** `____`
- [ ] **INF-038** · Vérifier que le build n'utilise ni dépendance réseau ni fichier situé uniquement sur l'ordinateur d'un coéquipier.  **· Resp. :** `____`

## 02. Piles doublement chaînées et mémoire [MEM]

**Contrat** : chaque opération conserve `size_a + size_b = n`, les champs `head/tail` cohérents, les liens réciproques et les nœuds uniques. Les modifications de pile sont muettes ; seules les fonctions `ps_*` émettent des instructions.

**Inventaire des fonctions proposées** (`src/stack/*.c`) :

- [ ] **MEM-001** · **`stack_init(t_stack *)`** — initialiser `head=NULL`, `tail=NULL`, `size=0` ; fonctionne sur deux piles distinctes.  **· Resp. :** `____`
- [ ] **MEM-002** · **`stack_new_node(int)`** — `malloc` d'un seul nœud, initialiser `value`, `rank` provisoire, `next/prev=NULL` ; renvoyer `NULL` en échec.  **· Resp. :** `____`
- [ ] **MEM-003** · **`stack_attach_head(t_stack *, t_node *)`** — ajouter un nœud isolé en tête, gérer pile vide, taille 1 et la mise à jour de `prev`.  **· Resp. :** `____`
- [ ] **MEM-004** · **`stack_attach_tail(t_stack *, t_node *)`** — ajouter à la queue, conserver la première tête et actualiser `size`.  **· Resp. :** `____`
- [ ] **MEM-005** · **`stack_detach_head(t_stack *)`** — retirer le sommet, renvoyer nœud ou `NULL`, effacer ses liens, gérer pile devenue vide.  **· Resp. :** `____`
- [ ] **MEM-006** · **`stack_detach_tail(t_stack *)`** — retirer la queue, renvoyer nœud ou `NULL`, effacer ses liens, gérer pile devenue vide.  **· Resp. :** `____`
- [ ] **MEM-007** · **`stack_swap_heads(t_stack *)`** — échanger les deux premiers par réarrangement sûr, ne rien faire si taille < 2.  **· Resp. :** `____`
- [ ] **MEM-008** · **`stack_rotate(t_stack *)`** — détacher tête puis attacher queue ; renvoyer un indicateur d'effet, sans afficher.  **· Resp. :** `____`
- [ ] **MEM-009** · **`stack_revrotate(t_stack *)`** — détacher queue puis attacher tête ; renvoyer un indicateur d'effet, sans afficher.  **· Resp. :** `____`
- [ ] **MEM-010** · **`stack_find_min_pos(const t_stack *)`** — rechercher la position du rang minimum sans modifier la pile, contrat sur vide documenté.  **· Resp. :** `____`
- [ ] **MEM-011** · **`stack_find_max_pos(const t_stack *)`** — rechercher la position du rang maximum sans modifier la pile, si la fonction est effectivement utilisée.  **· Resp. :** `____`
- [ ] **MEM-012** · **`stack_is_sorted(const t_stack *)`** — tester l'ordre strict croissant du sommet à la queue ; vide/singleton considérés triés.  **· Resp. :** `____`
- [ ] **MEM-013** · **`stack_free(t_stack *)`** — libérer chaque nœud restant exactement une fois et remettre la pile à vide.  **· Resp. :** `____`
- [ ] **MEM-014** · **`app_cleanup(t_app *)`** — libérer A, B et allocations temporaires possédées par l'application ; usage possible après échec partiel.  **· Resp. :** `____`
- [ ] **MEM-015** · **`stack_check_links(const t_stack *)` (outil de test)** — vérifier réciprocité des liens, taille, tête/queue, absence de cycles et de nœuds en double.  **· Resp. :** `____`

**Validation du module :**

- [ ] **MEM-016** · Tester initialisation de deux piles vides et nettoyage à répétition d'états propres.  **· Resp. :** `____`
- [ ] **MEM-017** · Tester `attach_head` sur taille 0/1/2 et vérifier manuellement la séquence, les liens, la taille.  **· Resp. :** `____`
- [ ] **MEM-018** · Tester `attach_tail` sur taille 0/1/2 et l'ordre conservé.  **· Resp. :** `____`
- [ ] **MEM-019** · Tester `detach_head` sur taille 0/1/2/3 ; vérifier le nœud renvoyé et isolé.  **· Resp. :** `____`
- [ ] **MEM-020** · Tester `detach_tail` sur taille 0/1/2/3 ; vérifier tête/queue après le retrait.  **· Resp. :** `____`
- [ ] **MEM-021** · Tester échange de têtes sur taille 0/1/2/3/4, notamment l'adjacence des nœuds échangés.  **· Resp. :** `____`
- [ ] **MEM-022** · Tester rotation et rotation inverse sur tailles 0/1/2/3/4, puis vérifier qu'elles s'annulent.  **· Resp. :** `____`
- [ ] **MEM-023** · Tester `push` entre deux piles en enchaînant des opérations de base, y compris B vide / A vide.  **· Resp. :** `____`
- [ ] **MEM-024** · Tester `stack_is_sorted` sur vide, un élément, trié, inversé et quasi trié.  **· Resp. :** `____`
- [ ] **MEM-025** · Tester la cohérence constante `a.size+b.size=n_initial` après 1 000 séquences de mouvements aléatoires.  **· Resp. :** `____`
- [ ] **MEM-026** · Tester qu'aucun nœud n'est perdu, doublé, libéré ou recréé pendant les mouvements.  **· Resp. :** `____`
- [ ] **MEM-027** · Tester que le `free` de A et B après des milliers de pushes/rotations ne crée ni double free ni fuite.  **· Resp. :** `____`
- [ ] **MEM-028** · Vérifier le cas `stack_new_node` échoue après création de n nœuds : nettoyer les précédents et ne pas émettre de mouvement.  **· Resp. :** `____`
- [ ] **MEM-029** · Vérifier que les fonctions de lecture ne modifient ni `head`/`tail` ni les liens.  **· Resp. :** `____`
- [ ] **MEM-030** · Exécuter Valgrind ou AddressSanitizer sur le module dans les limites des outils disponibles.  **· Resp. :** `____`

## 03. Parsing des flags et des valeurs [PAR]

**Normatif (sujet, pages 15–16) :** entiers signés, pas de doublon, `Error\n` sur `stderr`, cinq options (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`), aucune sortie sans argument. **Choix du plan :** flags isolés partout dans `argv` si validé en PIL, support des chaînes contenant plusieurs nombres, gestion des doublons de flags.

**Fonctions à écrire** (`src/parsing/*.c`) :

- [ ] **PAR-001** · **`parse_options(...)`** — reconnaître les 5 flags exacts, n'admettre qu'un sélecteur, positionner `bench`, conserver les arguments numériques.  **· Resp. :** `____`
- [ ] **PAR-002** · **`parse_flag(...)` (helper)** — reconnaître un argument `argv[i]` entier égal à un flag ; ne jamais considérer `-3` comme option.  **· Resp. :** `____`
- [ ] **PAR-003** · **`parse_count_values(...)`** — compter les tokens numériques en conservant leur ordre, détecter les chaînes vides selon la politique adoptée.  **· Resp. :** `____`
- [ ] **PAR-004** · **`parse_next_token(...)`** — extraire bornes `(start,len)` d'un token sans écrire hors des arguments ou allouer inutilement.  **· Resp. :** `____`
- [ ] **PAR-005** · **`parse_is_space(char)` (helper)** — définir une unique politique des séparateurs pour toutes les entrées.  **· Resp. :** `____`
- [ ] **PAR-006** · **`parse_int32(const char *, len, int *)`** — contrôler signe, chiffres, longueur, entier 32 bits ; refuser un débordement avant multiplication.  **· Resp. :** `____`
- [ ] **PAR-007** · **`parse_is_duplicate(const t_stack *, int)`** — rechercher l'égalité des **valeurs numériques**, pas des textes.  **· Resp. :** `____`
- [ ] **PAR-008** · **`parse_build_a(...)`** — construire A en append à la queue, afin que le premier entier reste au sommet.  **· Resp. :** `____`
- [ ] **PAR-009** · **`parse_arguments(argc, argv, t_app *)`** — orchestrer options, tokenisation, conversion, unicité et construction ; renvoyer un état de succès/erreur.  **· Resp. :** `____`
- [ ] **PAR-010** · **`parse_fail(t_app *)` ou erreur centralisée** — nettoyer toute allocation partielle, émettre exactement `Error\n` sur stderr, jamais stdout.  **· Resp. :** `____`
- [ ] **PAR-011** · **`app_init(t_app *)`** — initialiser piles/options/stats avant toute allocation, pour permettre un nettoyage sûr sur erreur.  **· Resp. :** `____`

**Scénarios de parsing obligatoires :**

- [ ] **PAR-012** · `./push_swap` : stdout vide, stderr vide ; aucun segfault.  **· Resp. :** `____`
- [ ] **PAR-013** · `./push_swap 1` et `./push_swap 1 2 3` : entrées valides, sans instruction.  **· Resp. :** `____`
- [ ] **PAR-014** · `./push_swap 2 1` : valide ; comparaison au checker.  **· Resp. :** `____`
- [ ] **PAR-015** · `2147483647`, `-2147483648`, et les deux valeurs ensemble : acceptés.  **· Resp. :** `____`
- [ ] **PAR-016** · `2147483648` et `-2147483649` : `Error`, sans overflow en C.  **· Resp. :** `____`
- [ ] **PAR-017** · `99999999999999999999999999` / négatif extrême : `Error` sans UB.  **· Resp. :** `____`
- [ ] **PAR-018** · `+0`, `-0`, `0000`, `01`, `+1` : accepter comme formes numériques si politique retenue, et dédupliquer par valeur.  **· Resp. :** `____`
- [ ] **PAR-019** · `0 -0`, `+0 0`, `1 01`, `-0001 -1` : `Error` pour doublon.  **· Resp. :** `____`
- [ ] **PAR-020** · Tokens `+`, `-`, `++1`, `--1`, `+-1`, `1+`, `1-` : `Error`.  **· Resp. :** `____`
- [ ] **PAR-021** · Tokens `a`, `1a`, `3.14`, `0x10`, `1_000` : `Error`.  **· Resp. :** `____`
- [ ] **PAR-022** · Tokens `""`, `" "`, `"\t"`, chaînes mêlant tokens vides : comportement conforme à la politique documentée.  **· Resp. :** `____`
- [ ] **PAR-023** · `"3 2 1"`, `"3 2" "1"`, `"3" "2 1"` : ordre d'entrée conservé si guillemets autorisés.  **· Resp. :** `____`
- [ ] **PAR-024** · Multiples espaces et tabulations internes : comportement conforme à la politique adoptée.  **· Resp. :** `____`
- [ ] **PAR-025** · Flags : exécuter séparément `--simple`, `--medium`, `--complex`, `--adaptive` sur la même entrée.  **· Resp. :** `____`
- [ ] **PAR-026** · Sans sélecteur : confirmer l'usage effectif d'adaptive.  **· Resp. :** `____`
- [ ] **PAR-027** · `--bench --simple` et `--simple --bench` : comportement identique, si ordre libre validé.  **· Resp. :** `____`
- [ ] **PAR-028** · `--bench` seul : résultat stable conforme à la politique documentée.  **· Resp. :** `____`
- [ ] **PAR-029** · `--unknown`, `--benchmarks`, `--`, `---simple` : `Error` et aucune opération.  **· Resp. :** `____`
- [ ] **PAR-030** · Deux sélecteurs différents : `Error` ; préciser le traitement des sélecteurs répétés.  **· Resp. :** `____`
- [ ] **PAR-031** · `--bench --bench` : rejet/acceptation selon politique documentée (ne pas inventer obligation sujet).  **· Resp. :** `____`
- [ ] **PAR-032** · Nombre négatif `-3` et options isolées dans le même `argv` : pas de confusion.  **· Resp. :** `____`
- [ ] **PAR-033** · Aucun argument invalidant ne doit provoquer une émission partielle d'instructions avant `Error`.  **· Resp. :** `____`
- [ ] **PAR-034** · Échec de `malloc` au début, au milieu et à la fin du parsing : nettoyage sans fuite.  **· Resp. :** `____`
- [ ] **PAR-035** · Arguments très longs et grand nombre de tokens : pas de dépassement de tampon, d'entier ou de taille.  **· Resp. :** `____`
- [ ] **PAR-036** · Capturer séparément stdout, stderr et code de retour ; vérifier octets et `\n` exact.  **· Resp. :** `____`
- [ ] **PAR-037** · Tester Valgrind et la Norminette après intégration du parsing.  **· Resp. :** `____`

## 04. Normalisation des rangs [RAN]

**Contrat :** conserver `value` et l'ordre de A, attribuer à chacun exactement un `rank` dans `[0,n−1]`. Seuls les `rank` serviront à Selection, Chunk et Radix.

- [ ] **RAN-001** · **`rank_normalize(t_app *)`** — point d'entrée : associer un rang unique à chaque nœud sans changer A.  **· Resp. :** `____`
- [ ] **RAN-002** · **`rank_sorted_copy(...)` (si méthode par tableau)** — copier les `value` dans un tableau temporaire sans altérer les nœuds.  **· Resp. :** `____`
- [ ] **RAN-003** · **`rank_sort_array(...)` (si méthode par tableau)** — trier la copie par algorithme C personnel autorisé, sans `qsort`.  **· Resp. :** `____`
- [ ] **RAN-004** · **`rank_find_value(...)` (si méthode par tableau)** — retrouver une valeur et retourner son indice dans la copie croissante.  **· Resp. :** `____`
- [ ] **RAN-005** · Ou choisir **une seule alternative** : calculer chaque rang comme le nombre de valeurs plus petites, sans tableau temporaire.  **· Resp. :** `____`
- [ ] **RAN-006** · Gérer l'échec de l'allocation du tableau éventuel et garantir le nettoyage des nœuds.  **· Resp. :** `____`
- [ ] **RAN-007** · Libérer tout tableau temporaire avant le premier mouvement.  **· Resp. :** `____`
- [ ] **RAN-008** · Tester `42 -10 100 7` → rangs `[2,0,3,1]` dans l'ordre initial.  **· Resp. :** `____`
- [ ] **RAN-009** · Tester tous les ordres possibles de `INT_MIN`, `0`, `INT_MAX` sans débordement arithmétique.  **· Resp. :** `____`
- [ ] **RAN-010** · Tester n=0, 1, 2, 3, 5, 100 et 500.  **· Resp. :** `____`
- [ ] **RAN-011** · Vérifier que chaque rang est dans `[0,n−1]` et qu'aucun rang ne se répète.  **· Resp. :** `____`
- [ ] **RAN-012** · Vérifier `value_i < value_j` si et seulement si `rank_i < rank_j` pour toute paire.  **· Resp. :** `____`
- [ ] **RAN-013** · Vérifier que l'adresse et la position de chaque nœud dans A sont identiques avant et après normalisation.  **· Resp. :** `____`
- [ ] **RAN-014** · Vérifier que la liste des rangs triés représente exactement `0...n−1`.  **· Resp. :** `____`
- [ ] **RAN-015** · Tester la conservation de l'ordre et l'absence de fuite sur 1 000 valeurs de test si taille acceptée par l'implémentation.  **· Resp. :** `____`

## 05. Les onze opérations Push_swap : primitives, sorties, compteurs [OPS]

**Fichiers :** `src/ops/ops_swap.c`, `ops_push.c`, `ops_rotate.c`, `ops_revrotate.c`, `ops_emit.c`. **Invariant :** chaque instruction visible est l'une des 11 autorisées et coûte exactement une unité ; `ss`, `rr`, `rrr` restent **une seule ligne**, même si elles modifient les deux piles. Les helpers bas niveau sont silencieux.

**Fonctions et API :**

- [ ] **OPS-001** · **`ps_sa(t_app *)`** — échanger les deux premiers de A si possible ; émettre/compter `sa` conformément à la politique définie.  **· Resp. :** `____`
- [ ] **OPS-002** · **`ps_sb(t_app *)`** — échanger les deux premiers de B, sans toucher A.  **· Resp. :** `____`
- [ ] **OPS-003** · **`ps_ss(t_app *)`** — appliquer les deux échanges muets, puis produire **au maximum une** instruction `ss`.  **· Resp. :** `____`
- [ ] **OPS-004** · **`ps_pa(t_app *)`** — déplacer le sommet de B vers le sommet de A, mettre à jour les deux tailles, ne rien allouer.  **· Resp. :** `____`
- [ ] **OPS-005** · **`ps_pb(t_app *)`** — déplacer le sommet de A vers le sommet de B, conserver la même adresse de nœud.  **· Resp. :** `____`
- [ ] **OPS-006** · **`ps_ra(t_app *)`** — déplacer tête de A vers sa queue si au moins 2 nœuds.  **· Resp. :** `____`
- [ ] **OPS-007** · **`ps_rb(t_app *)`** — déplacer tête de B vers sa queue si au moins 2 nœuds.  **· Resp. :** `____`
- [ ] **OPS-008** · **`ps_rr(t_app *)`** — appliquer `ra` + `rb` de manière muette ; **une seule** émission `rr`.  **· Resp. :** `____`
- [ ] **OPS-009** · **`ps_rra(t_app *)`** — déplacer queue de A vers sa tête si au moins 2 nœuds.  **· Resp. :** `____`
- [ ] **OPS-010** · **`ps_rrb(t_app *)`** — déplacer queue de B vers sa tête si au moins 2 nœuds.  **· Resp. :** `____`
- [ ] **OPS-011** · **`ps_rrr(t_app *)`** — appliquer les deux rotations inverses muettes ; **une seule** émission `rrr`.  **· Resp. :** `____`
- [ ] **OPS-012** · **`emit_operation(t_app *, t_op)`** — retrouver le nom de l'instruction, effectuer un `write` de la ligne exacte sur stdout, incrémenter le bon compteur et `total` ; politique d'échec I/O explicite.  **· Resp. :** `____`
- [ ] **OPS-013** · **`op_name(t_op)` ou table privée** — associer exactement les 11 noms à l'énumération, sans case manquante.  **· Resp. :** `____`
- [ ] **OPS-014** · Prévoir un stockage/rapport d'erreur de `write` si l'API choisie le demande ; éviter un résultat partiellement affiché silencieusement.  **· Resp. :** `____`
- [ ] **OPS-015** · Vérifier que toutes les fonctions de tri appellent **uniquement** `ps_*` pour modifier l'ordre des piles.  **· Resp. :** `____`

**Tests élémentaires :**

- [ ] **OPS-016** · Tester `sa`, `sb`, `ss` avec tailles des deux piles parmi 0,1,2,3 (16 couples de tailles possibles).  **· Resp. :** `____`
- [ ] **OPS-017** · Tester `pa` avec B vide, B singleton et B de taille >1 ; A vide/non vide.  **· Resp. :** `____`
- [ ] **OPS-018** · Tester `pb` avec A vide, A singleton et A de taille >1 ; B vide/non vide.  **· Resp. :** `____`
- [ ] **OPS-019** · Tester `ra`, `rb`, `rr` sur tailles 0,1,2,3,4 ; vérifier la tête, la queue et les liens.  **· Resp. :** `____`
- [ ] **OPS-020** · Tester `rra`, `rrb`, `rrr` sur les mêmes tailles ; vérifier aussi les piles de taille 2.  **· Resp. :** `____`
- [ ] **OPS-021** · Vérifier `ra` suivi de `rra` (taille >=2) rend exactement l'ordre initial.  **· Resp. :** `____`
- [ ] **OPS-022** · Vérifier `rb` suivi de `rrb` (taille >=2) rend exactement l'ordre initial.  **· Resp. :** `____`
- [ ] **OPS-023** · Vérifier `pb` puis `pa` rend exactement A et B initiales lorsque A non vide.  **· Resp. :** `____`
- [ ] **OPS-024** · Vérifier `pa` puis `pb` rend exactement les deux piles initiales lorsque B non vide.  **· Resp. :** `____`
- [ ] **OPS-025** · Vérifier `ss` a le même **effet** que `sa` et `sb` mais ne produit qu'une ligne.  **· Resp. :** `____`
- [ ] **OPS-026** · Vérifier `rr` a le même **effet** que `ra` et `rb` mais ne produit qu'une ligne.  **· Resp. :** `____`
- [ ] **OPS-027** · Vérifier `rrr` a le même **effet** que `rra` et `rrb` mais ne produit qu'une ligne.  **· Resp. :** `____`
- [ ] **OPS-028** · Vérifier les cas combinés où une seule pile est assez grande pour avoir un effet, puis où aucune ne l'est.  **· Resp. :** `____`
- [ ] **OPS-029** · Vérifier l'absence d'émission d'instructions sans effet si cette politique a été validée en PIL.  **· Resp. :** `____`
- [ ] **OPS-030** · Vérifier que le contenu stdout ne contient que `sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr` suivis de `\n`.  **· Resp. :** `____`
- [ ] **OPS-031** · Vérifier qu'aucune instruction n'est imprimée **deux fois** par les opérations combinées.  **· Resp. :** `____`
- [ ] **OPS-032** · Vérifier `total == somme(counts[0..10])` après chaque séquence de mouvements.  **· Resp. :** `____`
- [ ] **OPS-033** · Vérifier `total == nombre de lignes stdout` même avec des opérations combinées et des opérations sans effet.  **· Resp. :** `____`
- [ ] **OPS-034** · Vérifier `counts[OP_RR]` augmente d'un et `counts[OP_RA]`, `counts[OP_RB]` restent inchangés quand `rr` est émis.  **· Resp. :** `____`
- [ ] **OPS-035** · Vérifier de même `ss` et `rrr` ; tous les types, y compris inutilisés, doivent être comptables.  **· Resp. :** `____`
- [ ] **OPS-036** · Vérifier les 11 primitives contre un oracle Python qui rejoue leur effet sur deux listes indépendantes.  **· Resp. :** `____`
- [ ] **OPS-037** · Vérifier que les nœuds restent les mêmes et que les tailles demeurent cohérentes après 10 000 opérations aléatoires.  **· Resp. :** `____`
- [ ] **OPS-038** · Tester `write` sur sortie fermée si possible ; absence d'accès mémoire invalide et politique I/O respectée.  **· Resp. :** `____`
- [ ] **OPS-039** · Valider la Norminette et l'absence de fuites après la fusion du moteur OP.  **· Resp. :** `____`

## 06. Petit tri spécialisé de 0 à 5 nombres [SML]

**But :** court-circuiter les petites tailles en mode adaptatif, sans masquer le fonctionnement des algorithmes forcés. **Attention :** `sort_three` doit comparer les valeurs relatives des trois nœuds, pas supposer des rangs globaux `0,1,2`.

- [ ] **SML-001** · **`sort_two(t_app *)`** — si A a deux nombres et est inversée, `sa`, sinon aucune instruction.  **· Resp. :** `____`
- [ ] **SML-002** · **`sort_three(t_app *)`** — discriminer les six permutations relatives sans `switch` si la Norme locale l'interdit.  **· Resp. :** `____`
- [ ] **SML-003** · Traiter `[0,1,2]` par zéro instruction.  **· Resp. :** `____`
- [ ] **SML-004** · Traiter `[0,2,1]` par `sa`, `ra` (ou une séquence correcte équivalente de longueur <=2).  **· Resp. :** `____`
- [ ] **SML-005** · Traiter `[1,0,2]` par `sa`.  **· Resp. :** `____`
- [ ] **SML-006** · Traiter `[1,2,0]` par `rra`.  **· Resp. :** `____`
- [ ] **SML-007** · Traiter `[2,0,1]` par `ra`.  **· Resp. :** `____`
- [ ] **SML-008** · Traiter `[2,1,0]` par `sa`, `rra`.  **· Resp. :** `____`
- [ ] **SML-009** · **`sort_four(t_app *)`** — trouver minimum, l'amener au sommet par le plus court chemin, `pb`, trier trois, `pa`.  **· Resp. :** `____`
- [ ] **SML-010** · **`sort_five(t_app *)`** — extraire les deux minima successifs, trier les trois restants, puis `pa`, `pa` ; valider l'ordre inverse de B.  **· Resp. :** `____`
- [ ] **SML-011** · **`sort_small(t_app *)`** — diriger uniquement vers cas 0/1/2/3/4/5 et ne rien faire si déjà trié.  **· Resp. :** `____`
- [ ] **SML-012** · Vérifier que les helpers de trois nombres acceptent des rangs globaux non consécutifs.  **· Resp. :** `____`
- [ ] **SML-013** · Vérifier que l'extraction des minimums recalcule la position après chaque `pb`.  **· Resp. :** `____`
- [ ] **SML-014** · Vérifier B vide et A triée après les retours `pa`.  **· Resp. :** `____`
- [ ] **SML-015** · Tester exhaustivement les permutations n=0 (vide), n=1 (1), n=2 (2), n=3 (6), n=4 (24) et n=5 (120).  **· Resp. :** `____`
- [ ] **SML-016** · Tester les mêmes ordres avec de vrais nombres négatifs et valeurs non consécutives, pas uniquement `[0..4]`.  **· Resp. :** `____`
- [ ] **SML-017** · Mesurer le nombre maximum et moyen de mouvements par taille, puis conserver la trace.  **· Resp. :** `____`
- [ ] **SML-018** · Vérifier qu'une pile déjà triée produit zéro opération, y compris avec `--bench` (hors rapport stderr).  **· Resp. :** `____`
- [ ] **SML-019** · Vérifier que `sort_small` ne déforme ni mode forcé ni information de stratégie réellement exécutée.  **· Resp. :** `____`
- [ ] **SML-020** · Vérifier la Norminette et relire le code des petits tris à deux.  **· Resp. :** `____`

## 07. `--simple` : Selection Sort général [SEL]

**Entrées valides :** toute taille et tout désordre, y compris 100 et 500 en mode forcé. **Invariant :** B contient, dans l'ordre décroissant du sommet vers le bas, les minimums déjà extraits ; A contient les éléments plus grands non encore placés.

- [ ] **SEL-001** · **`simple_sort(t_app *)`** — point d'entrée du tri, vérifier déjà trié puis extraire les minima jusqu'à n<=3, trier la fin, restaurer B.  **· Resp. :** `____`
- [ ] **SEL-002** · **`simple_align_min(t_app *)`** — obtenir la position du minimum courant ; `ra` si `p <= size/2`, sinon `rra`, jusqu'au sommet.  **· Resp. :** `____`
- [ ] **SEL-003** · **`simple_extract_min(t_app *)` (si utile)** — aligner le minimum puis `pb`, sans allouer et en préservant l'invariant.  **· Resp. :** `____`
- [ ] **SEL-004** · **`simple_restore(t_app *)` (si utile)** — `pa` jusqu'à B vide, sans rotations supplémentaires.  **· Resp. :** `____`
- [ ] **SEL-005** · Prévoir la sortie immédiate si A déjà triée, indépendamment du nombre d'éléments.  **· Resp. :** `____`
- [ ] **SEL-006** · Gérer n=0/1/2/3 proprement sans hypothèse de taille supérieure.  **· Resp. :** `____`
- [ ] **SEL-007** · Pour chaque extraction, recalculer la taille réelle et la position du minimum après les rotations précédentes.  **· Resp. :** `____`
- [ ] **SEL-008** · Vérifier qu'un minimum en tête nécessite zéro rotation avant `pb`.  **· Resp. :** `____`
- [ ] **SEL-009** · Vérifier qu'un minimum en queue favorise `rra` et non n−1 `ra`.  **· Resp. :** `____`
- [ ] **SEL-010** · Vérifier la règle de départage si les deux chemins sont de longueur égale (pile paire).  **· Resp. :** `____`
- [ ] **SEL-011** · Vérifier qu'au plus trois éléments restent en A avant le tri final spécialisé.  **· Resp. :** `____`
- [ ] **SEL-012** · Vérifier qu'après la phase d'extraction B est strictement décroissante (du sommet vers la queue).  **· Resp. :** `____`
- [ ] **SEL-013** · Vérifier qu'aucun `pa` n'est oublié quand B contient n−3 nœuds.  **· Resp. :** `____`
- [ ] **SEL-014** · Documenter la preuve : chaque `pa` pose une nouvelle valeur plus petite devant A déjà triée.  **· Resp. :** `____`
- [ ] **SEL-015** · Documenter la borne de mouvements `O(n²)` : somme des rotations <= somme `floor(m/2)` + pushes.  **· Resp. :** `____`
- [ ] **SEL-016** · Documenter séparément le temps CPU de recherche des minimums et la mémoire additionnelle de Selection (hors représentation des nœuds).  **· Resp. :** `____`
- [ ] **SEL-017** · Tester exhaustive n=1..7 sur les permutations, sans se limiter aux tailles 2–5.  **· Resp. :** `____`
- [ ] **SEL-018** · Tester n=100 et n=500 sur entrées inversées, presque triées et aléatoires.  **· Resp. :** `____`
- [ ] **SEL-019** · Tester `--simple` forcé à 100/500 : checker `OK`, aucune exigence inventée de score identique à adaptive.  **· Resp. :** `____`
- [ ] **SEL-020** · Tester que les nœuds ne sont pas modifiés directement par le code Selection.  **· Resp. :** `____`
- [ ] **SEL-021** · Mesurer maximum d'opérations, moyenne et écart sur une batterie stable ; conserver la base de référence.  **· Resp. :** `____`
- [ ] **SEL-022** · Vérifier une explication orale de 60 secondes par chacun sur la correction et la borne O(n²).  **· Resp. :** `____`

## 08. `--medium` : Chunk Sort à borne O(n√n) [CHK]

**Important :** la version 1 de notre plan est **canonisée**, et non un Chunk « optimisé librement » : elle prend des chunks croissants dans A, les empile sans `rb` dans B, puis récupère les maxima en restaurant l'orientation de B après chaque extraction. C'est ce mécanisme précis qui justifie la borne. La version de base est connue pour être peu performante sur n=500 (simulation indicative ~11 435 opérations en moyenne sur 500 permutations aléatoires, et 17 085 sur l'inversion complète). L'optimisation est donc un **lot séparé à prouver de nouveau**.

**Fonctions proposées :**

- [ ] **CHK-001** · **`medium_sort(t_app *)`** — orchestrer normalisation déjà faite, calcul des chunks, phase A→B, phase B→A, contrôle final.  **· Resp. :** `____`
- [ ] **CHK-002** · **`medium_chunk_size(int n)`** — calculer `ceil(sqrt(n))` par arithmétique entière, retourner >=1 ; éviter `sqrt()` externe.  **· Resp. :** `____`
- [ ] **CHK-003** · **`medium_chunk_bounds(int start, int c, int n, ...)` (si utile)** — calculer `hi=min(start+c,n)` sans erreur de borne, convention intervalle `[start,hi)`.  **· Resp. :** `____`
- [ ] **CHK-004** · **`medium_push_chunk(t_app *, lo, hi)`** — parcourir A par `ra`, `pb` si rang dans `[lo,hi)`, jusqu'à extraction exacte du bloc.  **· Resp. :** `____`
- [ ] **CHK-005** · **`medium_push_all(t_app *)` (si utile)** — visiter `lo=0,c,2c...` et garantir A vide à la fin.  **· Resp. :** `____`
- [ ] **CHK-006** · **`medium_find_max_pos(t_stack *, left)`** — chercher maximum uniquement parmi les `left` premiers nœuds de B, sans parcourir au-delà du chunk supérieur.  **· Resp. :** `____`
- [ ] **CHK-007** · **`medium_take_max(t_app *, p)`** — pour référence : `rb` p fois, `pa`, puis `rrb` p fois ; restaurer l'ordre relatif de B.  **· Resp. :** `____`
- [ ] **CHK-008** · **`medium_take_max_reverse(t_app *, p)` (facultatif prouvé)** — si choisi : `rrb` `size_b-p` fois, `pa`, puis `rb` `size_b-p-1` fois.  **· Resp. :** `____`
- [ ] **CHK-009** · **`medium_restore_chunk(t_app *, left)`** — extraire exactement les `left` maxima du chunk courant dans l'ordre global décroissant.  **· Resp. :** `____`
- [ ] **CHK-010** · **`medium_restore_all(t_app *)`** — parcourir les chunks du plus grand au plus petit et reconstituer A croissante.  **· Resp. :** `____`
- [ ] **CHK-011** · **`medium_is_top_chunk_valid(...)` (outil de debug)** — vérifier que les `left` premiers nœuds correspondent au bloc attendu.  **· Resp. :** `____`

**Phase A → B :**

- [ ] **CHK-012** · Initialiser `c=ceil(sqrt(n))`, `k=ceil(n/c)` sans division par zéro (n=0/1).  **· Resp. :** `____`
- [ ] **CHK-013** · Former des intervalles disjoints `[j*c,min((j+1)*c,n))`, couvrant tous les rangs exactement une fois.  **· Resp. :** `____`
- [ ] **CHK-014** · Pour chaque chunk, initialiser `left` au **nombre réel** de rangs du bloc (dernier bloc incomplet possible).  **· Resp. :** `____`
- [ ] **CHK-015** · Lire uniquement `a.head->rank` tant que A non vide ; ne jamais dereferencer un pointeur nul.  **· Resp. :** `____`
- [ ] **CHK-016** · Si le rang de tête appartient au chunk courant, appeler `ps_pb`, décrémenter `left`.  **· Resp. :** `____`
- [ ] **CHK-017** · Sinon appeler `ps_ra` ; aucune rotation de B dans la version canonique.  **· Resp. :** `____`
- [ ] **CHK-018** · Vérifier qu'un chunk ne provoque pas de boucle infinie même si les rangs initiaux sont très dispersés.  **· Resp. :** `____`
- [ ] **CHK-019** · Vérifier qu'après traitement d'un chunk, aucun élément de son intervalle ne reste en A.  **· Resp. :** `____`
- [ ] **CHK-020** · Vérifier qu'après transfert de tous les chunks A est vide et B contient exactement n nœuds.  **· Resp. :** `____`
- [ ] **CHK-021** · Vérifier que B présente les chunks **contigus**, plus grands chunks au sommet, indépendamment de l'ordre interne d'un chunk.  **· Resp. :** `____`

**Phase B → A :**

- [ ] **CHK-022** · Commencer par le dernier chunk non vide (valeurs les plus grandes).  **· Resp. :** `____`
- [ ] **CHK-023** · Pour chaque chunk, chercher uniquement le maximum du **bloc supérieur restant**, position de 0 à `left−1`.  **· Resp. :** `____`
- [ ] **CHK-024** · Exécuter `rb` exactement p fois ; constater que la cible est en tête de B.  **· Resp. :** `____`
- [ ] **CHK-025** · Exécuter `pa` exactement une fois pour déplacer cette cible vers A.  **· Resp. :** `____`
- [ ] **CHK-026** · Exécuter `rrb` exactement p fois pour rétablir l'ordre relatif des éléments restants dans B.  **· Resp. :** `____`
- [ ] **CHK-027** · Diminuer `left` après l'extraction ; vérifier que le nouveau bloc supérieur a bien la taille attendue.  **· Resp. :** `____`
- [ ] **CHK-028** · Démontrer que `rb^p ; pa ; rrb^p` restitue le même ordre relatif dans B, excepté l'élément extrait.  **· Resp. :** `____`
- [ ] **CHK-029** · Vérifier que le maximum global est extrait en premier, puis les valeurs n−2, n−3, ..., 0.  **· Resp. :** `____`
- [ ] **CHK-030** · Vérifier après chaque `pa` que A contient un préfixe croissant composé des derniers rangs extraits.  **· Resp. :** `____`
- [ ] **CHK-031** · Vérifier qu'à la fin A vaut `[0,1,...,n−1]`, B est vide.  **· Resp. :** `____`
- [ ] **CHK-032** · Si optimisation inverse activée : tester exactement `size_b−p` rotations `rrb`, `pa`, puis `size_b−p−1` `rb` (taille modifiée après `pa`).  **· Resp. :** `____`
- [ ] **CHK-033** · Si optimisation inverse activée : prouver qu'elle préserve l'ordre relatif des blocs, **sans** utiliser le nombre erroné de rotations de restauration.  **· Resp. :** `____`
- [ ] **CHK-034** · Si optimisation inverse activée : comparer à la référence sur les mêmes permutations, puis conserver ou annuler selon résultats.  **· Resp. :** `____`

**Preuves, garde-fous et mesures :**

- [ ] **CHK-035** · Justifier le balayage A : au plus O(n) `ra/pb` par chunk, donc O(n·k).  **· Resp. :** `____`
- [ ] **CHK-036** · Justifier l'extraction B : chaque maximum est à une profondeur < c et sa restauration coûte O(c), donc O(n·c).  **· Resp. :** `____`
- [ ] **CHK-037** · Conclure `k=ceil(n/c)` et `c=ceil(sqrt(n))` => O(n√n) **en instructions émises**.  **· Resp. :** `____`
- [ ] **CHK-038** · Écrire la preuve de correction « contiguïté des blocs + extraction décroissante + pa en tête ».  **· Resp. :** `____`
- [ ] **CHK-039** · Préciser la mémoire auxiliaire utilisée par les bornes de chunks, les positions et éventuelles optimisations ; distinguer des n nœuds déjà alloués.  **· Resp. :** `____`
- [ ] **CHK-040** · Tester c pour n=1,2,3,4,15,16,17,99,100,101,499,500,501.  **· Resp. :** `____`
- [ ] **CHK-041** · Tester n qui vaut exactement un carré, juste inférieur ou juste supérieur à un carré.  **· Resp. :** `____`
- [ ] **CHK-042** · Tester la dernière tranche incomplète et les cas où les maxima sont d'abord en tête puis tout au fond du bloc.  **· Resp. :** `____`
- [ ] **CHK-043** · Tester toutes les permutations de n=1..7 avec `--medium` forcé.  **· Resp. :** `____`
- [ ] **CHK-044** · Tester des centaines/milliers de permutations n=100 et n=500 avec le checker indépendant.  **· Resp. :** `____`
- [ ] **CHK-045** · Tester piles triées, inversées, rotations, alternance extrêmes et faible désordre.  **· Resp. :** `____`
- [ ] **CHK-046** · Tester que les mouvements ne violent jamais la contiguïté des chunks pendant le transfert.  **· Resp. :** `____`
- [ ] **CHK-047** · Tester l'ordre restauré de B après **chaque extraction**, et pas uniquement l'état final.  **· Resp. :** `____`
- [ ] **CHK-048** · Mesurer min/moyenne/P95/max pour 100 et 500 ; enregistrer les entrées des pires cas.  **· Resp. :** `____`
- [ ] **CHK-049** · Comparer à titre informatif aux seuils <2000/<1500/<700 à 100 et <12000/<8000/<5500 à 500.  **· Resp. :** `____`
- [ ] **CHK-050** · Mesurer le nombre moyen de `ra`, `rb`, `rrb`, `pa`, `pb` ; identifier le coût dominant.  **· Resp. :** `____`
- [ ] **CHK-051** · Développer une optimisation **derrière un commutateur de compilation de test ou sur branche séparée**, jamais sur `main` non validée.  **· Resp. :** `____`
- [ ] **CHK-052** · Si optimisation modifie la politique de B, redémontrer la borne : « environ √n chunks » ne suffit pas à prouver O(n√n).  **· Resp. :** `____`
- [ ] **CHK-053** · Benchmark de la variante sur **les mêmes seeds** que la référence ; rejeter toute variante produisant un KO.  **· Resp. :** `____`
- [ ] **CHK-054** · Vérifier le respect des seuils officiels en mode adaptive sur entrées qui utilisent effectivement Chunk ; ne pas assimiler les aléas random à un régime 100% medium.  **· Resp. :** `____`
- [ ] **CHK-055** · Effectuer une revue croisée du module pour détecter les erreurs d'orientation et les bugs du dernier chunk.  **· Resp. :** `____`

## 09. `--complex` : LSD Binary Radix sur les rangs [RDX]

**Invariant :** chaque passe trie stablement les rangs selon le bit courant ; B est vide en début et fin de passe, et le balayage traite **exactement n éléments** initiaux.

- [ ] **RDX-001** · **`radix_sort(t_app *)`** — si déjà trié, sortir ; sinon parcourir les bits utiles du plus faible au plus fort.  **· Resp. :** `____`
- [ ] **RDX-002** · **`radix_bit_count(int max_rank)`** — trouver le nombre de bits du plus grand rang par décalages d'un entier non négatif ; ne pas utiliser `log2()`.  **· Resp. :** `____`
- [ ] **RDX-003** · **`radix_pass(t_app *, int bit)`** — sauvegarder n en début de passe ; effectuer exactement n tests, `pb` pour 0 et `ra` pour 1, puis `pa` jusqu'à B vide.  **· Resp. :** `____`
- [ ] **RDX-004** · **`radix_is_bit_set(...)` (helper optionnel)** — calculer `((rank >> bit) & 1)`, pas sur valeur brute signée.  **· Resp. :** `____`
- [ ] **RDX-005** · Vérifier pour n<=1 : zéro mouvement, pas de lecture de `a.head` nul.  **· Resp. :** `____`
- [ ] **RDX-006** · Vérifier pour `n=2`, `n=4`, `n=8`, `n=100`, `n=500` le nombre de passes attendu.  **· Resp. :** `____`
- [ ] **RDX-007** · S'assurer que l'indice du bit démarre à 0 et augmente de 1, sans sauter ni répéter de passe.  **· Resp. :** `____`
- [ ] **RDX-008** · S'assurer que `processed < n_initial`, pas `processed < a.size` (taille variable pendant les `pb`).  **· Resp. :** `____`
- [ ] **RDX-009** · Pour bit=0, vérifier que les 0 reviennent dans leur ordre relatif initial après les `pa`.  **· Resp. :** `____`
- [ ] **RDX-010** · Pour bit=0, vérifier que les 1 conservent leur ordre relatif par les `ra`.  **· Resp. :** `____`
- [ ] **RDX-011** · Pour chaque bit, vérifier que les rangs sont classés selon leurs bits faibles déjà traités.  **· Resp. :** `____`
- [ ] **RDX-012** · Vérifier B vide avant chaque nouvelle passe et après la dernière.  **· Resp. :** `____`
- [ ] **RDX-013** · Vérifier qu'aucun élément n'est créé, supprimé ni modifié pendant les passes.  **· Resp. :** `____`
- [ ] **RDX-014** · Vérifier que le rang maximal `n−1` suffit à déterminer le nombre de bits.  **· Resp. :** `____`
- [ ] **RDX-015** · Tester l'exemple détaillé `[2,0,3,1]`, deux passes, A finale `[0,1,2,3]`.  **· Resp. :** `____`
- [ ] **RDX-016** · Tester exhaustivement toutes les permutations n=1..7 en mode `--complex` forcé.  **· Resp. :** `____`
- [ ] **RDX-017** · Tester sur des milliers de permutations de 100 et de 500 éléments avec checker indépendant.  **· Resp. :** `____`
- [ ] **RDX-018** · Pour l'algorithme canonique **sans sortie anticipée**, vérifier 1 084 opérations à n=100 sur une entrée non triée.  **· Resp. :** `____`
- [ ] **RDX-019** · Pour l'algorithme canonique **sans sortie anticipée**, vérifier 6 784 opérations à n=500 sur une entrée non triée.  **· Resp. :** `____`
- [ ] **RDX-020** · Vérifier que la séquence produite dépend de l'ordre des données mais que son nombre total de passes et le total canonique dépendent des rangs.  **· Resp. :** `____`
- [ ] **RDX-021** · Prouver la stabilité du partitionnement `pb/pa` et des `ra`.  **· Resp. :** `____`
- [ ] **RDX-022** · Prouver par induction que chaque passe préserve l'ordre acquis sur les bits moins significatifs.  **· Resp. :** `____`
- [ ] **RDX-023** · Prouver borne `n * ceil(log2 n)` scans + au plus autant de `pa`, soit O(n log n) instructions.  **· Resp. :** `____`
- [ ] **RDX-024** · Justifier la mémoire additionnelle de Radix (compteurs de bit et de passe), indépendamment de la liste des nœuds déjà créée.  **· Resp. :** `____`
- [ ] **RDX-025** · Vérifier que `--complex` forcé fonctionne pour une taille petite, sans appel silencieux à Selection/Chunk.  **· Resp. :** `____`
- [ ] **RDX-026** · Comparer systématiquement avec/sans `--bench` : même stdout, mêmes résultats.  **· Resp. :** `____`
- [ ] **RDX-027** · Documenter que Radix peut générer davantage d'opérations que Chunk pour n=500 malgré son meilleur Big-O.  **· Resp. :** `____`

## 10. Désordre initial et sélection adaptative [ADP]

**Source officielle, pages 11–13 :** calculer les inversions avant tout mouvement ; utiliser `D = I / (n(n−1)/2)` ; `D < 0,2` → classe O(n²), `0,2 <= D < 0,5` → O(n√n), `D >= 0,5` → O(n log n). **Attention :** le mode `--adaptive` est la stratégie par défaut, mais le sujet demande également les trois modes forcés pour toutes les entrées.

- [ ] **ADP-001** · **`count_inversions(const t_stack *)`** — compter exactement chaque paire de positions i<j dont le rang i est plus grand que le rang j ; sans mutation.  **· Resp. :** `____`
- [ ] **ADP-002** · **`disorder_pair_count(int n)` (helper)** — calculer n(n−1)/2 avec un type assez grand ; n<2 → zéro paire.  **· Resp. :** `____`
- [ ] **ADP-003** · **`calculate_disorder(t_app *)`** — enregistrer I, paires et pourcentage initial avant la première instruction.  **· Resp. :** `____`
- [ ] **ADP-004** · **`choose_strategy(t_app *)`** — respecter le mode forcé si demandé ; sinon appliquer les frontières au désordre initial.  **· Resp. :** `____`
- [ ] **ADP-005** · **`adaptive_select_by_counts(I,pairs)` (helper)** — comparer de préférence `5*I < pairs`, puis `2*I < pairs`, sans imprécision de virgule flottante.  **· Resp. :** `____`
- [ ] **ADP-006** · **`run_selected_sort(t_app *)`** — exécuter exactement **un** moteur de tri, enregistrer la branche utilisée et son identité théorique.  **· Resp. :** `____`
- [ ] **ADP-007** · Prévoir `n<=1` sans division par zéro ni opération.  **· Resp. :** `____`
- [ ] **ADP-008** · Prévoir le cas `a` déjà triée : aucune instruction et désordre calculé = 0 %.  **· Resp. :** `____`
- [ ] **ADP-009** · Tester que le désordre est calculé **avant** le tri, même si un sélecteur forcé est utilisé avec `--bench`.  **· Resp. :** `____`
- [ ] **ADP-010** · Tester que les inversions comptent des **paires** et non seulement les adjacences inversées.  **· Resp. :** `____`
- [ ] **ADP-011** · Tester `[1,2,3,4,5]` → I=0, D=0 %.  **· Resp. :** `____`
- [ ] **ADP-012** · Tester `[5,4,3,2,1]` → I=10, D=100 %.  **· Resp. :** `____`
- [ ] **ADP-013** · Tester `[4,67,3,87,23]` → I=4/10, D=40 %.  **· Resp. :** `____`
- [ ] **ADP-014** · Tester `[1,2,3,5,4]` → I=1/10, D=10 %.  **· Resp. :** `____`
- [ ] **ADP-015** · Tester `[2,3,4,5,1]` → I=4/10, D=40 %.  **· Resp. :** `____`
- [ ] **ADP-016** · Tester à la frontière `D=20 %` : classer en **Medium** (si l'entrée réelle donne exactement ce ratio).  **· Resp. :** `____`
- [ ] **ADP-017** · Tester juste en dessous de 20 % : classer en **Simple**.  **· Resp. :** `____`
- [ ] **ADP-018** · Tester juste au-dessus de 20 % : classer en **Medium**.  **· Resp. :** `____`
- [ ] **ADP-019** · Tester à la frontière `D=50 %` : classer en **Complex**.  **· Resp. :** `____`
- [ ] **ADP-020** · Tester juste en dessous de 50 % : classer en **Medium**.  **· Resp. :** `____`
- [ ] **ADP-021** · Tester juste au-dessus de 50 % : classer en **Complex**.  **· Resp. :** `____`
- [ ] **ADP-022** · Construire les cas frontières en déterminant **I et paires**, pas avec un arrondi des pourcentages affichés.  **· Resp. :** `____`
- [ ] **ADP-023** · Vérifier que les nombres négatifs donnent exactement le même D que leurs rangs normalisés.  **· Resp. :** `____`
- [ ] **ADP-024** · Vérifier que `--adaptive` explicite et absence de sélecteur choisissent la même branche et produisent la même sortie.  **· Resp. :** `____`
- [ ] **ADP-025** · Vérifier que `--simple`, `--medium`, `--complex` forcent leurs moteurs, même si leur D est dans une autre zone.  **· Resp. :** `____`
- [ ] **ADP-026** · En mode adaptatif sur 2–5 nombres, définir clairement le raccourci petit tri et la manière de l'annoncer dans le benchmark.  **· Resp. :** `____`
- [ ] **ADP-027** · Vérifier que le mode exécuté peut être distingué du mode demandé pour éviter un rapport trompeur.  **· Resp. :** `____`
- [ ] **ADP-028** · Documenter le coût CPU du calcul d'inversions O(n²) séparément de la complexité des **instructions émises**.  **· Resp. :** `____`
- [ ] **ADP-029** · Documenter les trois régimes de complexité et les conditions exactes dans le README.  **· Resp. :** `____`
- [ ] **ADP-030** · Documenter le coût CPU du calcul d’inversions et la mémoire additionnelle du dispatcher, sans prétendre qu’ils génèrent des opérations de pile.  **· Resp. :** `____`

## 11. Bench intégré et comptage des onze mouvements [BEN]

**Source officielle, pages 16–17 :** avec `--bench`, publier sur **stderr uniquement** le désordre en % à deux décimales, la stratégie et sa complexité, le nombre total de mouvements, les onze compteurs. Sans `--bench`, aucune statistique imprimée. Le flux d'opérations reste sur stdout et doit être identique.

- [ ] **BEN-001** · **`bench_init(t_stats *)`** — mettre à zéro tous les compteurs et total, initialiser le désordre et le mode enregistré.  **· Resp. :** `____`
- [ ] **BEN-002** · **`bench_count(t_stats *, t_op)`** — incrémenter le bon compteur et total une fois par instruction réellement émise.  **· Resp. :** `____`
- [ ] **BEN-003** · **`bench_strategy_name(t_mode)` (helper)** — associer un nom lisible à la stratégie exécutée/demandée.  **· Resp. :** `____`
- [ ] **BEN-004** · **`bench_complexity_name(t_mode)` (helper)** — associer `O(n²)`, `O(n√n)` ou `O(n log n)` à la branche réellement exécutée ; éviter « O(?) ».  **· Resp. :** `____`
- [ ] **BEN-005** · **`bench_report(const t_app *)`** — écrire sur `stderr` les statistiques complètes et uniquement si flag actif.  **· Resp. :** `____`
- [ ] **BEN-006** · **`bench_write_text(...)` (helper)** — émettre des chaînes sur fd=2 par une fonction personnelle autorisée.  **· Resp. :** `____`
- [ ] **BEN-007** · **`bench_write_number(...)` (helper)** — afficher des entiers positifs/compteurs sans `printf` système non autorisé.  **· Resp. :** `____`
- [ ] **BEN-008** · **`bench_write_percent(...)` (helper)** — produire un pourcentage formaté **avec deux chiffres après le point** (arrondi correct et signe selon convention).  **· Resp. :** `____`
- [ ] **BEN-009** · Décider d'une politique claire si `used_mode` correspond au petit tri spécialisé plutôt qu'au moteur nommé demandé.  **· Resp. :** `____`
- [ ] **BEN-010** · S'assurer que `--bench` ne choisit jamais un autre algorithme et n'injecte aucun mouvement.  **· Resp. :** `____`
- [ ] **BEN-011** · Imprimer explicitement `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, même si un compteur vaut 0.  **· Resp. :** `____`
- [ ] **BEN-012** · Afficher `total_ops` égal à la somme des 11 types, sans additionner à nouveau les mouvements constitutifs de `rr`, `rrr`, `ss`.  **· Resp. :** `____`
- [ ] **BEN-013** · Afficher le désordre initial (pas recalculé à 0 % après le tri).  **· Resp. :** `____`
- [ ] **BEN-014** · Afficher une classe de complexité correspondant à la stratégie réellement sélectionnée.  **· Resp. :** `____`
- [ ] **BEN-015** · Choisir la forme `[bench] disorder: XX.XX%` pour rester proche des exemples du sujet.  **· Resp. :** `____`
- [ ] **BEN-016** · Choisir la forme `[bench] strategy: ...` et `[bench] total_ops: ...`, puis compteur pour chaque type.  **· Resp. :** `____`
- [ ] **BEN-017** · Tester `--bench` sur pile déjà triée : `total_ops=0`, zéro pour les 11 types, aucun mouvement sur stdout.  **· Resp. :** `____`
- [ ] **BEN-018** · Tester `--bench` sur 2 nombres inversés : `sa=1` si moteur choisi utilise `sa`.  **· Resp. :** `____`
- [ ] **BEN-019** · Tester un `rr`, un `ss`, un `rrr` forcés par un test unitaire et vérifier les compteurs.  **· Resp. :** `____`
- [ ] **BEN-020** · Tester les quatre stratégies avec `--bench`, dont `--adaptive` sans flag explicite.  **· Resp. :** `____`
- [ ] **BEN-021** · Tester `--bench` avec 100 et 500 nombres et des compteurs à plusieurs chiffres.  **· Resp. :** `____`
- [ ] **BEN-022** · Tester D=0 %, 10 %, 40 %, 50 % et 100 %, notamment l'arrondi à deux décimales.  **· Resp. :** `____`
- [ ] **BEN-023** · Tester l'égalité `total_ops == len(stdout.splitlines())` avec un parseur indépendant.  **· Resp. :** `____`
- [ ] **BEN-024** · Tester que le rapport existe **uniquement** dans stderr, et jamais sur stdout.  **· Resp. :** `____`
- [ ] **BEN-025** · Tester `cmp` sur stdout avec et sans `--bench`, même mode et mêmes données : octets identiques.  **· Resp. :** `____`
- [ ] **BEN-026** · Tester que stderr est vide en exécution normale réussie sans `--bench`.  **· Resp. :** `____`
- [ ] **BEN-027** · Tester que le rapport de benchmark n'est pas imprimé lors d'un parsing invalide qui doit afficher `Error`.  **· Resp. :** `____`
- [ ] **BEN-028** · Tester `./push_swap --bench --medium ... | checker` sans polluer le pipe.  **· Resp. :** `____`
- [ ] **BEN-029** · Revoir ensemble le calcul de l'arrondi du pourcentage, particulièrement les frontières visuelles 19,995 % et 49,995 %.  **· Resp. :** `____`

## 12. Orchestration de `main`, erreurs et nettoyage [APP]

**Objectif :** le binaire est un pipeline cohérent, avec une seule route de sortie normale, une seule politique d'erreur, et zéro instruction générée si l'entrée est invalide.

- [ ] **APP-001** · **`main(int argc, char **argv)`** — gérer immédiatement l'absence d'arguments et déléguer les autres étapes sans dépasser la Norminette.  **· Resp. :** `____`
- [ ] **APP-002** · **`app_init(t_app *)`** — initialiser tous les champs de piles, options, statistiques, initial_size et état d'erreur.  **· Resp. :** `____`
- [ ] **APP-003** · **`app_parse(t_app *, argc, argv)` ou `parse_arguments`** — valider intégralement l'entrée avant le premier tri.  **· Resp. :** `____`
- [ ] **APP-004** · **`app_prepare(t_app *)`** — normaliser les rangs, calculer le désordre initial et préparer la stratégie.  **· Resp. :** `____`
- [ ] **APP-005** · **`app_run(t_app *)`** — appeler le moteur choisi et ne jamais manipuler les liens sans passer par OPS.  **· Resp. :** `____`
- [ ] **APP-006** · **`app_finish(t_app *)`** — afficher le bench si demandé, libérer A+B, retourner un statut explicite.  **· Resp. :** `____`
- [ ] **APP-007** · **`app_error(t_app *)`** — centraliser la voie d'erreur `Error\n` sur stderr et le nettoyage sûr ; ne pas double-afficher.  **· Resp. :** `____`
- [ ] **APP-008** · Faire apparaître les choix `mode_requested`, `used_mode`, `bench` sans variable globale.  **· Resp. :** `____`
- [ ] **APP-009** · Interdire tout début d'émission stdout avant validation intégrale de l'entrée.  **· Resp. :** `____`
- [ ] **APP-010** · Garantir la taille de A égale à `initial_size` et B vide avant le dispatch.  **· Resp. :** `____`
- [ ] **APP-011** · Garantir la pile A triée, B vide avant la fin d'une exécution normale, en debug/test uniquement si vérification interne.  **· Resp. :** `____`
- [ ] **APP-012** · En cas d'échec de `write`, prévoir une politique explicite et éviter les boucles infinies ou fuites.  **· Resp. :** `____`
- [ ] **APP-013** · Tester `argc=1`, `argc=2`, liste grande et flags dans l'ordre retenu.  **· Resp. :** `____`
- [ ] **APP-014** · Tester erreurs en fin de ligne après un grand nombre d'entiers déjà alloués.  **· Resp. :** `____`
- [ ] **APP-015** · Tester tous les modes avec les mêmes tokens et vérifier l'égalité de l'ensemble des valeurs triées.  **· Resp. :** `____`
- [ ] **APP-016** · Tester que l'état `t_app` n'est ni réutilisé ni accédé après `app_cleanup`.  **· Resp. :** `____`
- [ ] **APP-017** · Vérifier que `main` et helpers tiennent leurs limites de fonctions, lignes et paramètres de la Norme.  **· Resp. :** `____`
- [ ] **APP-018** · Exécuter un cycle complet `make`, test checker, bench, Valgrind et Norminette après intégration.  **· Resp. :** `____`

## 13. Oracle indépendant, scripts de test et campagnes [TST]

**Important :** le sujet tolère des programmes de test non remis et encourage leur utilisation pendant la défense (page 4). Ces scripts sont des **outils externes**, éventuellement Python, et non des fonctions externes ajoutées au binaire C. Le testeur doit rejouer le texte stdout ; il ne doit **pas** appeler les mêmes primitives C que le programme qu'il valide.

**Outils à écrire** (`tests/*.py`, `tools/*.py`, scripts shell) :

- [ ] **TST-001** · **`tests/test_operations.py`** — simulateur indépendant des 11 opérations à partir de listes Python de rangs/valeurs.  **· Resp. :** `____`
- [ ] **TST-002** · **`tests/test_exhaustive.py`** — générer chaque permutation de 1..7 et exécuter les quatre modes.  **· Resp. :** `____`
- [ ] **TST-003** · **`tests/test_invalid.sh` ou `.py`** — lancer les cas d'entrée invalide, valider stdout/stderr/code retour.  **· Resp. :** `____`
- [ ] **TST-004** · **`tests/test_bench.py`** — extraire les 11 compteurs, valider `total_ops` et l'absence de pollution stdout.  **· Resp. :** `____`
- [ ] **TST-005** · **`tests/test_adaptive.py`** — calculer inversions de référence, appliquer les seuils exacts, comparer le mode choisi.  **· Resp. :** `____`
- [ ] **TST-006** · **`tests/test_normalization.c` ou helper debug** — comparer valeurs brutes et rangs, sans être lié au programme final.  **· Resp. :** `____`
- [ ] **TST-007** · **`tests/test_chunk_invariants.py` ou trace debug** — contrôler contiguïté des blocs et restauration de B pendant les extractions.  **· Resp. :** `____`
- [ ] **TST-008** · **`tests/test_radix_pass.py` ou trace debug** — contrôler chaque passe et le maintien de l'ordre des bits faibles.  **· Resp. :** `____`
- [ ] **TST-009** · **`tools/benchmark.py`** — générer permutations reproductibles et produire moyenne, min, médiane, P95 et max par mode et taille.  **· Resp. :** `____`
- [ ] **TST-010** · **`tools/reproduce_case.py` (facultatif utile)** — rejouer automatiquement une seed en une commande et sauvegarder entrée + stdout + stderr.  **· Resp. :** `____`
- [ ] **TST-011** · **`tests/cases/README.md`** — décrire le format de stockage des cas ayant échoué, pour éviter les logs inutilisables.  **· Resp. :** `____`

**Tests du simulateur avant de l'utiliser comme juge :**

- [ ] **TST-012** · Pour chacune des 11 instructions, écrire au moins une transition manuelle dont l'état attendu est connu.  **· Resp. :** `____`
- [ ] **TST-013** · Vérifier que le simulateur ne perd pas l'information d'ordre du sommet ; premier argument = sommet.  **· Resp. :** `____`
- [ ] **TST-014** · Vérifier `pa/pb` vides et rotations sur pile de taille 0/1 selon les règles du sujet.  **· Resp. :** `____`
- [ ] **TST-015** · Vérifier les opérations combinées `ss`, `rr`, `rrr` comme une instruction logique unique.  **· Resp. :** `____`
- [ ] **TST-016** · Vérifier le traitement d'une instruction inconnue ou mal formatée dans l'oracle.  **· Resp. :** `____`
- [ ] **TST-017** · Vérifier qu'une sortie vide est acceptée si A est déjà triée (et B toujours vide).  **· Resp. :** `____`
- [ ] **TST-018** · Vérifier que l'oracle rejette une séquence qui finit avec A triée mais B non vide.  **· Resp. :** `____`
- [ ] **TST-019** · Vérifier que l'oracle rejette une séquence qui conserve tous les éléments mais laisse A désordonnée.  **· Resp. :** `____`
- [ ] **TST-020** · Vérifier que l'oracle rejette une ligne parasite, une faute de frappe ou une instruction incomplète.  **· Resp. :** `____`

**Campagnes exhaustives et variées :**

- [ ] **TST-021** · Générer toutes les permutations n=2 (2 entrées) et n=3 (6 entrées), sur les 4 modes.  **· Resp. :** `____`
- [ ] **TST-022** · Générer toutes les permutations n=4 (24 entrées) et n=5 (120 entrées), sur les 4 modes.  **· Resp. :** `____`
- [ ] **TST-023** · Générer toutes les permutations n=6 (720 entrées), sur les 4 modes.  **· Resp. :** `____`
- [ ] **TST-024** · Générer toutes les permutations n=7 (5 040 entrées), sur les 4 modes.  **· Resp. :** `____`
- [ ] **TST-025** · Tester n=0 et n=1 séparément, dont entrée sans argument et un entier négatif.  **· Resp. :** `____`
- [ ] **TST-026** · Tester valeurs positives, négatives, mélangées, INT_MIN et INT_MAX.  **· Resp. :** `____`
- [ ] **TST-027** · Tester pile déjà triée 2,3,4,5,10,100,500 : zéro instruction pour tous les modes.  **· Resp. :** `____`
- [ ] **TST-028** · Tester pile inversée 2,3,5,10,100,500 : toujours checker OK.  **· Resp. :** `____`
- [ ] **TST-029** · Tester une rotation d'une pile croissante `[2,3,...,n,1]`, parfois trompeuse pour le ratio d'inversions.  **· Resp. :** `____`
- [ ] **TST-030** · Tester une transposition adjacente unique en début, milieu et fin.  **· Resp. :** `____`
- [ ] **TST-031** · Tester alternance petits/grands (`0, n−1, 1, n−2, ...`).  **· Resp. :** `____`
- [ ] **TST-032** · Tester rangs en blocs inversés, blocs déjà triés, permutations à LIS longue.  **· Resp. :** `____`
- [ ] **TST-033** · Tester distribution de 100 et 500 valeurs avec des écarts numériques extrêmes, pour vérifier la normalisation.  **· Resp. :** `____`
- [ ] **TST-034** · Générer au minimum 1 000 permutations aléatoires reproductibles de n=100 pour chaque mode.  **· Resp. :** `____`
- [ ] **TST-035** · Générer au minimum 1 000 permutations aléatoires reproductibles de n=500 pour chaque mode (si budget de tests le permet).  **· Resp. :** `____`
- [ ] **TST-036** · Ajouter des tailles intermédiaires 8,9,10,15,16,17,24,25,26,49,50,64,99,101,127,128,129,255,256,257,499.  **· Resp. :** `____`
- [ ] **TST-037** · Vérifier spécifiquement n=1/2 autour des bords de Radix et des chunks.  **· Resp. :** `____`
- [ ] **TST-038** · Sauvegarder toute permutation en échec dans `tests/cases/` avec mode, seed, commit et erreur reproductible.  **· Resp. :** `____`
- [ ] **TST-039** · Pour chaque cas en échec, rejouer la **première opération divergente** avec un traceur des piles.  **· Resp. :** `____`
- [ ] **TST-040** · S'assurer que les batteries tests ne dépendent pas uniquement de `checker_linux` fourni : conserver l'oracle indépendant.  **· Resp. :** `____`
- [ ] **TST-041** · Comparer des échantillons de résultats au checker officiel fourni lorsqu'il est disponible.  **· Resp. :** `____`
- [ ] **TST-042** · Vérifier qu'une séquence de mouvements est correcte pour **chaque mode forcé** et pour adaptive.  **· Resp. :** `____`
- [ ] **TST-043** · Vérifier pour toute entrée que B est vide à la fin du replay.  **· Resp. :** `____`
- [ ] **TST-044** · Vérifier pour toute entrée que A contient exactement les nombres distincts d'origine, triés.  **· Resp. :** `____`
- [ ] **TST-045** · Vérifier qu'aucun mouvement invalide, texte de débogage ou benchmark n'apparaît dans stdout.  **· Resp. :** `____`
- [ ] **TST-046** · Vérifier que les résultats sont reproductibles sur deux lancements identiques (déterminisme attendu du plan).  **· Resp. :** `____`

**Tests du parsing et du benchmark en subprocess :**

- [ ] **TST-047** · Tester erreurs de signe, caractères, doublons, limites int, arguments vides, flags combinés.  **· Resp. :** `____`
- [ ] **TST-048** · Contrôler l'orthographe et les octets exacts `Error\n` et le canal stderr uniquement.  **· Resp. :** `____`
- [ ] **TST-049** · Contrôler la séparation stdout/stderr pour `--bench` et sans `--bench`.  **· Resp. :** `____`
- [ ] **TST-050** · Contrôler désordre d'entrée à deux décimales sur plusieurs paires/modes.  **· Resp. :** `____`
- [ ] **TST-051** · Contrôler la somme des 11 compteurs et le nombre de lignes stdout.  **· Resp. :** `____`
- [ ] **TST-052** · Contrôler les frontières de dispatch 20 %/50 % sur des permutations construites exactement.  **· Resp. :** `____`
- [ ] **TST-053** · Contrôler que chaque mode forcé se lance pour des tailles inhabituelles et indépendamment de D.  **· Resp. :** `____`
- [ ] **TST-054** · Contrôler les sorties et l'état mémoire après échecs d'allocation simulés, si harness disponible.  **· Resp. :** `____`
- [ ] **TST-055** · Contrôler l'absence de relink inutile du Makefile comme test d'intégration.  **· Resp. :** `____`

**Mémoire et outillage :**

- [ ] **TST-056** · Faire tourner `valgrind --leak-check=full --show-leak-kinds=all` sur entrées valides de 1,5,100,500 nombres.  **· Resp. :** `____`
- [ ] **TST-057** · Faire tourner Valgrind sur doublons, overflow, options inconnues et échec après allocations partielles.  **· Resp. :** `____`
- [ ] **TST-058** · Construire si possible un binaire debug avec `-g3 -fsanitize=address,undefined` **hors configuration livrée**.  **· Resp. :** `____`
- [ ] **TST-059** · Faire tourner les tests de piles/ops/algorithmes avec ASan/UBSan lorsqu'ils sont disponibles.  **· Resp. :** `____`
- [ ] **TST-060** · Détecter les doubles libérations, fuites, pointeurs déréférencés après free, itérations après tête NULL.  **· Resp. :** `____`
- [ ] **TST-061** · Valider qu'aucun compteur ni indice arithmétique n'overflow sur les tailles testées.  **· Resp. :** `____`
- [ ] **TST-062** · Examiner tout crash, KO, boucle infinie ou erreur de Norminette comme **bloquant**, même si les benchmarks sont bons.  **· Resp. :** `____`

## 14. Mesures de performances et optimisation contrôlée [PER]

**Paliers officiels (pages 18 du sujet, seuils STRICTS) :** pour 100 aléatoires, `<2000` (minimum), `<1500` (bon), `<700` (excellent). Pour 500 aléatoires, `<12000`, `<8000`, `<5500`. La réussite d'un test de correction n'implique pas l'atteinte d'un seuil. **Ne pas annoncer d'excellence sans mesures réelles sur votre binaire.**

- [ ] **PER-001** · Définir un jeu stable de seeds et conserver la liste des entrées, tailles et désordres initiaux.  **· Resp. :** `____`
- [ ] **PER-002** · Écrire le générateur de permutations sans doublons et vérifier leur cardinalité.  **· Resp. :** `____`
- [ ] **PER-003** · Mesurer `--simple`, `--medium`, `--complex`, `--adaptive` sur **les mêmes** permutations.  **· Resp. :** `____`
- [ ] **PER-004** · Pour chaque mode et n=100, mesurer minimum, moyenne, médiane, P95 et maximum du nombre d'opérations.  **· Resp. :** `____`
- [ ] **PER-005** · Pour chaque mode et n=500, mesurer les mêmes statistiques.  **· Resp. :** `____`
- [ ] **PER-006** · Calculer la proportion de tests strictement sous chaque palier officiel ; indiquer taille et régime des échantillons.  **· Resp. :** `____`
- [ ] **PER-007** · Ne pas utiliser une moyenne pour dissimuler les cas individuels qui dépassent la barre de réussite.  **· Resp. :** `____`
- [ ] **PER-008** · Mesurer le désordre réel de chaque entrée aléatoire et vérifier la branche effectivement choisie par adaptive.  **· Resp. :** `____`
- [ ] **PER-009** · Mesurer le nombre d'occurrences de chacun des 11 mouvements, pas seulement le total.  **· Resp. :** `____`
- [ ] **PER-010** · Mesurer la répartition du temps CPU séparément des instructions émises, sans confondre les deux.  **· Resp. :** `____`
- [ ] **PER-011** · Comparer la version canonique de Chunk à la version avec voie de restauration inverse, sur jeux identiques.  **· Resp. :** `____`
- [ ] **PER-012** · Comparer plusieurs tailles de chunk qui restent proportionnelles à √n ; enregistrer formules exactes et bords.  **· Resp. :** `____`
- [ ] **PER-013** · Vérifier qu'un paramètre améliorant n=100 ne dégrade pas fortement n=500 ou les cas extrêmes.  **· Resp. :** `____`
- [ ] **PER-014** · Enregistrer le pire cas observé de Chunk et le rejouer manuellement pour comprendre d'où viennent les `ra/rb/rrb`.  **· Resp. :** `____`
- [ ] **PER-015** · Tester des rotations et permutations inversées, même si les seuils officiels portent sur les nombres aléatoires.  **· Resp. :** `____`
- [ ] **PER-016** · Si modification de B pendant A→B, redémontrer la contiguïté ou substituer un invariant formellement vérifiable.  **· Resp. :** `____`
- [ ] **PER-017** · Si suppression de la restauration de B pendant B→A, prouver la borne de profondeur des maxima futurs ; sinon refuser l'optimisation.  **· Resp. :** `____`
- [ ] **PER-018** · Vérifier la borne par construction dans le code, pas seulement par ajustement d'une courbe sur 500 valeurs.  **· Resp. :** `____`
- [ ] **PER-019** · Vérifier après chaque optimisation que le nombre d'opérations baisse **sans** générer des mouvements inutiles ou invalides.  **· Resp. :** `____`
- [ ] **PER-020** · Utiliser une branche Git dédiée et noter commit de référence, changement exact et résultats avant/après.  **· Resp. :** `____`
- [ ] **PER-021** · Exécuter de nouveau l'exhaustivité n<=7 et les erreurs de parsing après chaque changement de l'algorithme.  **· Resp. :** `____`
- [ ] **PER-022** · Revenir à la version précédente immédiatement si KO, crash, fuite, Norminette ou perte de garantie.  **· Resp. :** `____`
- [ ] **PER-023** · Ne pas optimiser le mode `--complex` au détriment de sa preuve `O(n log n)`.  **· Resp. :** `____`
- [ ] **PER-024** · Tester les éventuels raccourcis Radix (`is_sorted` entre passes) sur toutes les petites permutations.  **· Resp. :** `____`
- [ ] **PER-025** · Écrire dans `docs/algorithms.md` le coût exact de Radix classique et la distinction théorique/empirique.  **· Resp. :** `____`
- [ ] **PER-026** · Tenir un tableau de progression daté sur 100/500 avec moyenne, P95, max et barème visé.  **· Resp. :** `____`
- [ ] **PER-027** · Discuter ensemble du choix final des optimisations lors d'une revue croisée avec résultats reproductibles.  **· Resp. :** `____`

## 15. README obligatoire et documentation d'équipe [DOC]

**Source officielle, page 19 (VII) + page 10 :** README à la racine avec première ligne exacte **en italique**, Description, Instructions, Resources, usage de l'IA, algorithmes détaillés et justifiés, et contributions des **deux** membres. Le document d'architecture `PLAN_A_Z.md` est un support interne ; le `README.md` n'est pas censé être une copie brute de plusieurs milliers de lignes.

- [ ] **DOC-001** · Créer `README.md` à la racine du dépôt.  **· Resp. :** `____`
- [ ] **DOC-002** · Écrire **sur sa première ligne** la formule officielle en italique, adaptée aux deux logins réels : `*This project has been created as part of the 42 curriculum by login1, login2.*`.  **· Resp. :** `____`
- [ ] **DOC-003** · Confirmer que les deux logins figurent également dans les informations du dépôt et de contribution.  **· Resp. :** `____`
- [ ] **DOC-004** · Écrire une section `Description` : objectif, piles A/B, ordre ascendant, onze opérations.  **· Resp. :** `____`
- [ ] **DOC-005** · Écrire une section `Instructions` avec `make`, `make clean`, `make fclean`, `make re`.  **· Resp. :** `____`
- [ ] **DOC-006** · Expliquer comment lancer un tri sans flag (adaptive implicite).  **· Resp. :** `____`
- [ ] **DOC-007** · Expliquer `--simple`, `--medium`, `--complex`, `--adaptive` avec exemples réels du binaire.  **· Resp. :** `____`
- [ ] **DOC-008** · Expliquer `--bench` et la séparation stdout (mouvements) / stderr (rapport).  **· Resp. :** `____`
- [ ] **DOC-009** · Inclure des exemples de pipe vers `checker_linux` fourni **si disponible** ou checker bonus, sans prétendre qu'il est toujours présent.  **· Resp. :** `____`
- [ ] **DOC-010** · Documenter la stratégie Selection : extraction des minima, invariant de B, borne O(n²) en mouvements.  **· Resp. :** `____`
- [ ] **DOC-011** · Documenter la stratégie Chunk **implémentée réellement** : taille des blocs, invariant de B, reconstruction et borne O(n√n) en mouvements.  **· Resp. :** `____`
- [ ] **DOC-012** · Documenter la stratégie Radix LSD : rangs, bits, stabilité, preuve O(n log n) en mouvements.  **· Resp. :** `____`
- [ ] **DOC-013** · Documenter le désordre : inversions, formule, calcul avant mouvement, seuils exacts 0.2/0.5.  **· Resp. :** `____`
- [ ] **DOC-014** · Documenter le comportement du raccourci n<=5 en adaptive et ce que `--bench` annonce réellement.  **· Resp. :** `____`
- [ ] **DOC-015** · Documenter les conventions de parsing qui **dépassent** le strict texte officiel (flags, guillemets, tabulations).  **· Resp. :** `____`
- [ ] **DOC-016** · Documenter les contraintes mémoire et le choix de structure `head/tail/size`.  **· Resp. :** `____`
- [ ] **DOC-017** · Ajouter les justifications de complexité **temps CPU et espace** pour chaque stratégie et pour la normalisation, distinctes du nombre de mouvements noté par le sujet.  **· Resp. :** `____`
- [ ] **DOC-018** · Inclure une section `Resources` avec sources réellement consultées, notamment le sujet officiel, la Norminette et les documents techniques pertinents.  **· Resp. :** `____`
- [ ] **DOC-019** · Écrire précisément **quelles tâches ont bénéficié d'une IA** (architecture, recherche, planification, tests, explications), sans inventer une paternité humaine ni cacher une génération de code effective.  **· Resp. :** `____`
- [ ] **DOC-020** · Préciser quelles parties ont été relues, adaptées et testées par les deux apprenants.  **· Resp. :** `____`
- [ ] **DOC-021** · Décrire la répartition concrète des contributions : modules, fonctions, tests, optimisations et revue.  **· Resp. :** `____`
- [ ] **DOC-022** · Mettre des exemples de benchmarks **réellement mesurés** sur votre version C et dater les chiffres.  **· Resp. :** `____`
- [ ] **DOC-023** · Mentionner le statut exact du bonus checker seulement s'il est effectivement implémenté et intégré.  **· Resp. :** `____`
- [ ] **DOC-024** · Relire le README à deux pour qu'aucune assertion de complexité, de performance ou d'utilisation d'IA ne soit trompeuse.  **· Resp. :** `____`
- [ ] **DOC-025** · Vérifier que liens relatifs, commandes et noms des fichiers fonctionnent depuis le dépôt clone propre.  **· Resp. :** `____`
- [ ] **DOC-026** · Maintenir `docs/decisions.md` : décisions, alternatives écartées et raisons (Turk non retenu, etc.).  **· Resp. :** `____`
- [ ] **DOC-027** · Maintenir `docs/algorithms.md` : invariants, tableaux de performances et preuve des variantes optimisées.  **· Resp. :** `____`
- [ ] **DOC-028** · Maintenir `docs/evaluations.md` : questions de soutenance, cas de test, remarques des relectures.  **· Resp. :** `____`
- [ ] **DOC-029** · Enregistrer cette checklist dans `docs/CHECKLIST_DEVELOPPEMENT.md` et mettre à jour les cases à chaque fusion.  **· Resp. :** `____`
- [ ] **DOC-030** · Conserver le plan détaillé `docs/PLAN_A_Z.md` comme référence, cohérent avec les noms effectivement implémentés.  **· Resp. :** `____`

## 16. Git, collaboration et contrats du binôme [EQU]

- [ ] **EQU-001** · Désigner un responsable principal et un relecteur **différent** pour chaque lot majeur (voir tableau initial).  **· Resp. :** `____`
- [ ] **EQU-002** · Préciser pour chaque lot les fichiers ou interfaces dont le propriétaire assure les modifications.  **· Resp. :** `____`
- [ ] **EQU-003** · S'accorder sur les prototypes avant des développements parallèles afin d'éviter les interfaces divergentes.  **· Resp. :** `____`
- [ ] **EQU-004** · Répartir les lots `PAR/RAN` et `MEM/OPS` de façon à permettre un travail parallèle sans éditer simultanément les mêmes headers.  **· Resp. :** `____`
- [ ] **EQU-005** · Répartir les algorithmes SEL, CHK, RDX en tenant compte des dépendances OPS et RAN.  **· Resp. :** `____`
- [ ] **EQU-006** · Prévoir un travail partagé sur ADP, BEN et APP, qui traversent tous les modules.  **· Resp. :** `____`
- [ ] **EQU-007** · Faire créer au moins une branche de travail par tâche ou petit groupe cohérent de tâches.  **· Resp. :** `____`
- [ ] **EQU-008** · Utiliser des messages de commits explicites : `feat(parser): ...`, `test(ops): ...`, `fix(chunk): ...`.  **· Resp. :** `____`
- [ ] **EQU-009** · Limiter chaque fusion à du code compilable, normé et accompagné des tests correspondants.  **· Resp. :** `____`
- [ ] **EQU-010** · Vérifier avant fusion qu'aucune API publique n'a changé sans accord du binôme.  **· Resp. :** `____`
- [ ] **EQU-011** · Vérifier avant fusion que les opérations ne sont pas dupliquées dans les modules de tri.  **· Resp. :** `____`
- [ ] **EQU-012** · Vérifier avant fusion que chaque pointeur et allocation a un propriétaire clair.  **· Resp. :** `____`
- [ ] **EQU-013** · Vérifier avant fusion que les tests du lot fonctionnent sur un clone propre et pas seulement sur un répertoire local.  **· Resp. :** `____`
- [ ] **EQU-014** · Organiser la revue croisée : auteur explique but, invariants, cas limites et test, relecteur vérifie et reformule.  **· Resp. :** `____`
- [ ] **EQU-015** · Consigner l'issue d'une revue : fusion acceptée, correction demandée, bug bloquant.  **· Resp. :** `____`
- [ ] **EQU-016** · Mettre à jour les cases et propriétaires **dans la même PR / fusion** que le travail correspondant.  **· Resp. :** `____`
- [ ] **EQU-017** · Réaliser une revue mutuelle des fonctions complexes (parsing overflow, swap double liste, Chunk restoration, Radix pass).  **· Resp. :** `____`
- [ ] **EQU-018** · Faire coder ou réécrire un petit helper par l'autre membre pendant une session de compréhension, pas seulement lui faire lire.  **· Resp. :** `____`
- [ ] **EQU-019** · Répéter au moins une fois par semaine les explications des trois tris sans le support du code.  **· Resp. :** `____`
- [ ] **EQU-020** · Vérifier que les deux apprenants apparaissent effectivement dans les contributions du dépôt et du README.  **· Resp. :** `____`
- [ ] **EQU-021** · Faire une revue finale de l'historique Git, des branches non fusionnées et des fichiers temporaires.  **· Resp. :** `____`

## 17. Soutenance, conformité, Norminette finale [REV]

**Sources officielles, pages 10 et 22 :** les deux étudiants présents, tous deux capables d'expliquer **n'importe quelle** partie du code ; une petite modification peut être demandée en correction. La compréhension de l'architecture est un critère de travail, pas une simple formalité.

- [ ] **REV-001** · Chacun sait expliquer le rôle de chaque champ de `t_node`, `t_stack`, `t_options`, `t_stats`, `t_app`.  **· Resp. :** `____`
- [ ] **REV-002** · Chacun sait montrer la tête et la queue de A/B et expliquer `sa`, `pb`, `ra`, `rra` sur une liste de 2 et 3 nœuds.  **· Resp. :** `____`
- [ ] **REV-003** · Chacun sait expliquer pourquoi `ss`, `rr` et `rrr` ne coûtent qu'une instruction.  **· Resp. :** `____`
- [ ] **REV-004** · Chacun sait démontrer `size_a+size_b=n_initial` et expliquer la propriété mémoire des nœuds.  **· Resp. :** `____`
- [ ] **REV-005** · Chacun sait expliquer comment `INT_MIN` est accepté et `INT_MAX+1` rejeté sans overflow.  **· Resp. :** `____`
- [ ] **REV-006** · Chacun sait expliquer comment des chaînes `+0`, `-0`, `000` constituent le même entier pour la détection des doublons.  **· Resp. :** `____`
- [ ] **REV-007** · Chacun sait expliquer le choix des rangs et la normalisation sans trier la pile directement.  **· Resp. :** `____`
- [ ] **REV-008** · Chacun sait reconstruire à la main le tri d'une pile de 3, 4, puis 5 valeurs.  **· Resp. :** `____`
- [ ] **REV-009** · Chacun sait expliquer le tri Selection et sa borne O(n²) en instructions.  **· Resp. :** `____`
- [ ] **REV-010** · Chacun sait expliquer les chunks, leurs intervalles et leur ordre en B.  **· Resp. :** `____`
- [ ] **REV-011** · Chacun sait **démontrer sur papier** que `rb^p,pa,rrb^p` préserve l'ordre des éléments restants de B.  **· Resp. :** `____`
- [ ] **REV-012** · Chacun sait justifier la borne O(n√n) de **notre Chunk effectivement livré**, et les effets des optimisations retenues.  **· Resp. :** `____`
- [ ] **REV-013** · Chacun sait expliquer la stabilité de Radix bit à bit et le rôle des deux inversions via `pb/pa`.  **· Resp. :** `____`
- [ ] **REV-014** · Chacun sait calculer le nombre de passes de Radix pour n=100 et n=500.  **· Resp. :** `____`
- [ ] **REV-015** · Chacun sait justifier O(n log n) en instructions et expliquer la différence avec le nombre de comparaisons C.  **· Resp. :** `____`
- [ ] **REV-016** · Chacun sait expliquer la mémoire auxiliaire des trois algorithmes et différencier mémoire totale des nœuds et mémoire propre au tri.  **· Resp. :** `____`
- [ ] **REV-017** · Chacun sait compter le désordre de `[4,67,3,87,23]` et appliquer les seuils 0.2/0.5.  **· Resp. :** `____`
- [ ] **REV-018** · Chacun sait justifier la séparation stdout/stderr et tous les champs du benchmark.  **· Resp. :** `____`
- [ ] **REV-019** · Chacun sait expliquer l'échec attendu du bonus si les benchmarks mandatory ne sont pas validés.  **· Resp. :** `____`
- [ ] **REV-020** · Chacun sait interpréter `checker: KO`, remonter au premier mouvement incorrect et corriger un cas simple.  **· Resp. :** `____`
- [ ] **REV-021** · Chacun sait exécuter `make`, `norminette`, les tests essentiels, un test Valgrind et un exemple `--bench`.  **· Resp. :** `____`
- [ ] **REV-022** · Chacun sait expliquer pourquoi aucun `printf/qsort/sqrt` système non autorisé n'est requis.  **· Resp. :** `____`
- [ ] **REV-023** · Chacun sait modifier rapidement une petite fonction (condition, garde, compteur, structure) sans casser le code.  **· Resp. :** `____`
- [ ] **REV-024** · Effectuer une soutenance blanche : A explique les modules initialement développés par B, et inversement.  **· Resp. :** `____`
- [ ] **REV-025** · Effectuer une seconde soutenance blanche avec questions aléatoires sur les trois algorithmes.  **· Resp. :** `____`
- [ ] **REV-026** · Confirmer que les deux seront présents et que les deux logins figurent dans la livraison.  **· Resp. :** `____`
- [ ] **REV-027** · Vérifier une dernière fois Norminette (toutes sources et bonus si présent) sur l'environnement de correction.  **· Resp. :** `____`
- [ ] **REV-028** · Vérifier une dernière fois les fonctions externes autorisées et l'absence de variables globales.  **· Resp. :** `____`
- [ ] **REV-029** · Vérifier que les rapports de tests conservés correspondent au **dernier commit** livré.  **· Resp. :** `____`

## 18. Checker bonus : lot strictement facultatif [BNS]

**Condition stricte (sujet, pages 20–21) :** le bonus `checker` n'est évalué que si **toute** la partie obligatoire est parfaite, benchmarks inclus. À réaliser uniquement une fois les lots précédents stables et les performances minimum atteintes. Les scripts Python d'oracle sont des **tests internes**, pas le bonus C.

- [ ] **BNS-001** · Décider explicitement en équipe si le bonus sera réalisé ; si non, annoter ce lot comme `NON RETENU`, **sans** cocher les tâches.  **· Resp. :** `____`
- [ ] **BNS-002** · Prévoir `checker` comme deuxième binaire avec point d'entrée distinct, sans introduire de second `main` dans `push_swap`.  **· Resp. :** `____`
- [ ] **BNS-003** · Ajouter la règle `bonus` au Makefile et isoler les fichiers bonus `_bonus.c` / `_bonus.h` selon règles communes du sujet.  **· Resp. :** `____`
- [ ] **BNS-004** · Réutiliser les primitives muettes de piles sans imprimer de mouvements lors de l'exécution des instructions lues.  **· Resp. :** `____`
- [ ] **BNS-005** · Réutiliser une logique de parsing valide compatible avec les règles du checker, sans recoder un parser divergent.  **· Resp. :** `____`
- [ ] **BNS-006** · **`checker_main(...)`** — analyser les nombres de A, attendre les instructions sur stdin, afficher le verdict final.  **· Resp. :** `____`
- [ ] **BNS-007** · **`checker_read_line(int fd)` ou lecteur personnel** — lire chaque ligne jusqu'à EOF avec `read` autorisé, gérer entrée volumineuse et allocation.  **· Resp. :** `____`
- [ ] **BNS-008** · **`checker_parse_op(const char *)`** — accepter exactement 11 instructions avec newline requis, rejeter toute autre chaîne.  **· Resp. :** `____`
- [ ] **BNS-009** · **`checker_apply_op(t_app *, t_op)`** — exécuter la primitive muette correspondante, sans `write` stdout d'opérations.  **· Resp. :** `____`
- [ ] **BNS-010** · **`checker_finish(t_app *)`** — afficher `OK\n` si A croissante et B vide, sinon `KO\n`.  **· Resp. :** `____`
- [ ] **BNS-011** · **`checker_error(t_app *)`** — afficher `Error\n` sur stderr en cas d'argument ou instruction incorrecte, puis nettoyer.  **· Resp. :** `____`
- [ ] **BNS-012** · Gestion de l'EOF après une ligne complète : évaluer l'état final.  **· Resp. :** `____`
- [ ] **BNS-013** · Gestion d'une ligne vide, d'un nom d'opération inconnu et d'un newline manquant : erreur selon le sujet.  **· Resp. :** `____`
- [ ] **BNS-014** · Gestion de plusieurs opérations consécutives sans état final trié : afficher `KO` et non `Error` si les commandes sont valides.  **· Resp. :** `____`
- [ ] **BNS-015** · Vérifier que le checker ne lit pas sur stdin après avoir atteint EOF.  **· Resp. :** `____`
- [ ] **BNS-016** · Vérifier que le checker peut recevoir des centaines de milliers de lignes sans fuite mémoire.  **· Resp. :** `____`
- [ ] **BNS-017** · Vérifier que `./checker` sans valeurs affiche rien et termine proprement.  **· Resp. :** `____`
- [ ] **BNS-018** · Vérifier qu'un `checker` lancé avec une entrée invalide affiche `Error\n` sur stderr.  **· Resp. :** `____`
- [ ] **BNS-019** · Vérifier `./checker 3 2 1 0` alimenté avec une séquence correcte → `OK\n`.  **· Resp. :** `____`
- [ ] **BNS-020** · Vérifier la même entrée alimentée avec une séquence de commandes valides mais non triantes → `KO\n`.  **· Resp. :** `____`
- [ ] **BNS-021** · Vérifier que B non vide à EOF produit `KO`, même si A est croissante.  **· Resp. :** `____`
- [ ] **BNS-022** · Vérifier qu'une seule instruction inconnue ou mal formée déclenche `Error\n`, non `KO`.  **· Resp. :** `____`
- [ ] **BNS-023** · Vérifier que les instructions sur stdin n'ont **pas** d'écho sur stdout ; seul verdict final.  **· Resp. :** `____`
- [ ] **BNS-024** · Vérifier `./push_swap ... | ./checker ...` dans chaque mode, avec et sans `--bench` côté `push_swap`.  **· Resp. :** `____`
- [ ] **BNS-025** · Vérifier libération complète des buffers de lecture même lorsque l'instruction est invalide.  **· Resp. :** `____`
- [ ] **BNS-026** · Vérifier le comportement du checker en cas de `read()` interrompu ou d'erreur I/O si scénario testable.  **· Resp. :** `____`
- [ ] **BNS-027** · Tester Norminette, Valgrind, flags du compilateur et le `make bonus` sans relink superflu.  **· Resp. :** `____`
- [ ] **BNS-028** · Mettre à jour README avec compilation et utilisation du checker **uniquement après finalisation**.  **· Resp. :** `____`

## 19. Vérification de livraison et traçabilité finale [LIV]

**Définition de la livraison :** seul le travail réellement présent dans le dépôt attribué sera évalué. Il faut à la fois une application conforme, des preuves de correction et des contributions explicites du binôme.

- [ ] **LIV-001** · Cloner le dépôt dans un répertoire propre ne contenant aucun binaire ou objet précédemment compilé.  **· Resp. :** `____`
- [ ] **LIV-002** · Faire `make` à froid et vérifier la génération de `push_swap` sans compilation d'outils de test.  **· Resp. :** `____`
- [ ] **LIV-003** · Lancer `make` une seconde fois et constater aucune compilation ni relink inutile.  **· Resp. :** `____`
- [ ] **LIV-004** · Lancer `make clean`, `make fclean`, `make re` et vérifier les effets attendus.  **· Resp. :** `____`
- [ ] **LIV-005** · Si bonus retenu, lancer `make bonus` à froid et vérifier `checker`.  **· Resp. :** `____`
- [ ] **LIV-006** · Lancer la Norminette sur tous les fichiers de sources et headers du dépôt.  **· Resp. :** `____`
- [ ] **LIV-007** · Lancer les tests d'erreur, de parsing et de modes forcés sur le **dernier commit**.  **· Resp. :** `____`
- [ ] **LIV-008** · Lancer les tests exhaustifs n<=7 sur le **dernier commit**.  **· Resp. :** `____`
- [ ] **LIV-009** · Lancer les tests aléatoires 100/500 sur le **dernier commit**.  **· Resp. :** `____`
- [ ] **LIV-010** · Lancer les tests de `--bench`, y compris 11 compteurs et comparaison exacte de stdout.  **· Resp. :** `____`
- [ ] **LIV-011** · Lancer les tests mémoire valides et invalides, vérifier absence de fuites et d'UB.  **· Resp. :** `____`
- [ ] **LIV-012** · Mesurer les seuils de performance sur le **binaire final**, noter la date et les seeds.  **· Resp. :** `____`
- [ ] **LIV-013** · Vérifier que la structure finale respecte les complexités annoncées, y compris toute optimisation de Chunk.  **· Resp. :** `____`
- [ ] **LIV-014** · Vérifier le README : première ligne exacte, deux logins, sections requises, usage réel de l'IA, contributions et justifications.  **· Resp. :** `____`
- [ ] **LIV-015** · Vérifier que les fichiers `.c/.h` et le Makefile sont bien dans le dépôt évalué, sans dépendance cachée.  **· Resp. :** `____`
- [ ] **LIV-016** · Supprimer les logs temporaires, les clés, les binaires de debug et les fichiers source obsolètes ou conflictuels.  **· Resp. :** `____`
- [ ] **LIV-017** · Vérifier qu'aucun `main` de test n'est accidentellement inclus dans le build final.  **· Resp. :** `____`
- [ ] **LIV-018** · Vérifier qu'aucun `write` de débogage ne se produit sur stdout lors d'une exécution normale.  **· Resp. :** `____`
- [ ] **LIV-019** · Vérifier que toutes les cases cochées correspondent réellement à du code ou à une preuve consultable.  **· Resp. :** `____`
- [ ] **LIV-020** · Faire valider le dernier commit et les résultats par **les deux** membres.  **· Resp. :** `____`
- [ ] **LIV-021** · Confirmer que les deux membres sont présents pour la correction et peuvent expliquer chaque module.  **· Resp. :** `____`
- [ ] **LIV-022** · Garder disponibles les commandes de reproduction des tests essentiels pour la soutenance.  **· Resp. :** `____`

---

## Jalons de passage (à renseigner ensemble)

| Jalon | Preuve obligatoire | Responsable | Date validée | Commit / trace |
|---|---|---|---|---|
| **J0** — Contrat | PIL + choix C et API figés | ____ | ____ | ____ |
| **J1** — Infrastructure | INF, Makefile compile à froid | ____ | ____ | ____ |
| **J2** — Piles | MEM, invariants et mémoire | ____ | ____ | ____ |
| **J3** — Parsing | PAR, matrice de validation | ____ | ____ | ____ |
| **J4** — Moteur | OPS, 11 opérations et oracle | ____ | ____ | ____ |
| **J5** — Rangs | RAN, bijection prouvée | ____ | ____ | ____ |
| **J6** — Petites piles | SML, exhaustivité ≤5 | ____ | ____ | ____ |
| **J7** — Simple | SEL, O(n²) correct et expliqué | ____ | ____ | ____ |
| **J8** — Complex | RDX, 1084/6784 canonique & preuve | ____ | ____ | ____ |
| **J9** — Medium | CHK, version canonique correcte & preuve | ____ | ____ | ____ |
| **J10** — Modes | ADP + APP, sélecteurs et frontières | ____ | ____ | ____ |
| **J11** — Bench | BEN, rapport exact et sans pollution | ____ | ____ | ____ |
| **J12** — Tests | TST, 0 KO, memory clean | ____ | ____ | ____ |
| **J13** — Performance | PER, seuils officiels atteints pour les évaluations pertinentes | ____ | ____ | ____ |
| **J14** — Documentation | DOC, README et contributions complets | ____ | ____ | ____ |
| **J15** — Soutenance | REV, les deux comprennent tout | A+B | ____ | ____ |
| **J16** — Bonus (si retenu) | BNS, `checker` conforme | ____ | ____ | ____ |
| **J17** — Livraison | LIV, clone final et tests réussis | A+B | ____ | ____ |

## Modèle à copier dans une issue ou une PR

```md
### Tâche : [ID] titre
- Responsable : A / B
- Relecteur : A / B
- Dépendance(s) : ID(s)
- Fichier(s) touché(s) : ...
- Contrat : entrée / sortie / effet de bord / erreurs
- Tests à exécuter : ...
- Preuve : commande, log, seed, commit ...
- [ ] Implémenté
- [ ] Testé (cas normaux et limites)
- [ ] Norminette / mémoire
- [ ] Revue croisée
- [ ] Fusionné et checklist mise à jour
```

## Règles de maintenance de ce fichier

- Ne jamais effacer une tâche parce qu'elle est difficile : la répartir, expliquer le blocage, ou constater explicitement qu'elle est **facultative**.
- Ne pas cocher une fonction optionnelle jamais écrite. Marquer « non applicable / non retenue » et préciser où sa responsabilité est traitée autrement.
- Une optimisation qui modifie un invariant ajoute des tâches de preuve, d'oracle et de régression.
- Toute case critique cochée doit pouvoir être reliée à un test, une revue et un commit.
- Les exigences du PDF officiel v1.2 priment sur toutes les recommandations de ce fichier et du plan parent.

*Checklist maîtresse destinée à être suivie dans GitHub : cocher au fur et à mesure, attribuer les responsabilités et conserver les traces de validation.*
