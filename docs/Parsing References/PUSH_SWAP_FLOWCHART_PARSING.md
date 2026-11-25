# Push_swap — Flowcharts du parsing (référence v1.2)

Ces schémas suivent les **six fichiers C de référence** (`src/parsing/*.c`).
Ils sont rendus directement par GitHub (Mermaid) : ce fichier `.md` est autonome.

## 1. Vue d'ensemble : les deux passes sur `argv`

```mermaid
flowchart TD
    S([main initialise t_app / MODE_ADAPTIVE]) --> P["parse_arguments(app, argc, argv)"]
    P --> A{"argc == 1 ?"}
    A -->|oui| NO(["return 1 : aucune sortie, gérée par main"])
    A -->|non| O["parse_options : passe 1, vérifie les flags"]
    O --> V{"options valides ?"}
    V -->|non| ERR(["return 0 : erreur"])
    V -->|oui| I["i = 1 : passe 2"]
    I --> LOOP{"i < argc ?"}
    LOOP -->|oui| FL{"argv[i] est un flag connu ?"}
    FL -->|oui| NEXT["i++"]
    FL -->|non| SC["parse_scan_arg : lire et ajouter les nombres"]
    SC --> SUC{"réussite ?"}
    SUC -->|non| ERR
    SUC -->|oui| NEXT
    NEXT --> LOOP
    LOOP -->|non| EMPTY{"a.size == 0 ?"}
    EMPTY -->|oui| ERR
    EMPTY -->|non| OK(["initial_size = a.size ; return 1"])
    ERR --> CLEAN["L'appelant libère les ressources et écrit Error\n sur stderr"]
    classDef good fill:#dcfce7,stroke:#16a34a,color:#14532d;
    classDef bad fill:#fee2e2,stroke:#dc2626,color:#7f1d1d;
    classDef test fill:#fef3c7,stroke:#d97706,color:#78350f;
    class NO,OK good;
    class ERR,CLEAN bad;
    class A,V,LOOP,FL,SUC,EMPTY test;
```

## 2. Zoom : parcours d'un argument et de ses nombres

```mermaid
flowchart TD
    A(["parse_scan_arg(app, arg)"]) --> B{"arg NULL ou vide ?"}
    B -->|oui| E(["return 0"])
    B -->|non| INIT["cursor = 0 ; seen = 0"]
    INIT --> TOK["parse_next_token : repère start + len, sans allocation"]
    TOK --> FOUND{"token trouvé ?"}
    FOUND -->|non| SEEN{"seen == 1 ?"}
    SEEN -->|non| E
    SEEN -->|oui| OK(["return 1"])
    FOUND -->|oui| BUILD["seen = 1 ; parse_token_to_stack"]
    BUILD --> INT["parse_int32 : signe / chiffres / INT_MIN et INT_MAX"]
    INT --> VALID{"entier valide ?"}
    VALID -->|non| E
    VALID -->|oui| DUP["parse_is_duplicate : comparer les valeurs dans A"]
    DUP --> EXISTS{"doublon ?"}
    EXISTS -->|oui| E
    EXISTS -->|non| APP["stack_append_value : ajouter à la fin de A"]
    APP --> ADDED{"ajout réussi ?"}
    ADDED -->|non| E
    ADDED -->|oui| TOK
    classDef good fill:#dcfce7,stroke:#16a34a,color:#14532d;
    classDef bad fill:#fee2e2,stroke:#dc2626,color:#7f1d1d;
    classDef test fill:#fef3c7,stroke:#d97706,color:#78350f;
    class OK good;
    class E bad;
    class B,FOUND,SEEN,VALID,EXISTS,ADDED test;
```

## 3. Exemple à suivre à la main

`./push_swap --bench --medium "42 -10" 7`

- **Passe 1** : `parse_options()` enregistre `mode = MODE_MEDIUM`, `bench = 1`.
- **Passe 2** : les deux flags connus sont sautés ; `"42 -10"` fournit deux tokens (`42`, `-10`) ; `7` fournit un token.
- Chaque token est converti, vérifié contre les doublons, puis ajouté à la **fin** de A.
- Résultat : `A = [42, -10, 7]` (sommet à gauche), `A.size = 3`, `initial_size = 3`, `B` reste vide.
- Pas de tri, de rangs ni d'opérations écrites pendant le parsing.

## 4. Erreurs et responsabilités

Un flag inconnu `--...` ou un mode répété est rejeté par la première passe ; un argument vide, un nombre invalide, un dépassement d'entier, un doublon, une allocation échouée ou l'absence de nombres après des flags font renvoyer **0** à `parse_arguments()`.

**Important :** le parsing **ne libère pas** lui-même les nœuds déjà insérés et **n'imprime rien**. Le code appelant doit nettoyer la mémoire et afficher `Error\n` sur `stderr`. S'il n'y a aucun argument (`argc == 1`), le parsing renvoie **1**, et le `main` doit se terminer sans rien afficher.

## 5. Correspondance avec les fichiers

| Fonction | Fichier |
|---|---|
| `parse_arguments` | `parse_arguments.c` |
| `parse_options`, `parse_flag_kind` | `parse_options.c` |
| `parse_scan_arg`, `parse_next_token` | `parse_tokens.c` |
| `parse_token_to_stack` | `parse_build_a.c` |
| `parse_int32` | `parse_int.c` |
| `parse_is_duplicate` | `parse_unique.c` |
| `stack_append_value` | `stack/` du binôme (hors parsing) |

## 6. Images pleine résolution

- `PUSH_SWAP_FLOWCHART_PARSING_GLOBAL.png` ou `.svg` : vue d'ensemble.
- `PUSH_SWAP_FLOWCHART_PARSING_TOKEN.png` ou `.svg` : détail d'un argument.
