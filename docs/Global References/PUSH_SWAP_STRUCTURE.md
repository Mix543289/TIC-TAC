# Push_swap — Inventaire du squelette Git (sujet v1.2)

Le ZIP contient **uniquement des fichiers de zéro octet** ; aucun code n’est implémenté.
Il se décompresse **directement à la racine du dépôt Git**, sans dossier parent `push_swap/`.
L’arborescence reprend le plan A à Z vérifié et la checklist ; quelques fichiers
de séparation sont proposés sans constituer des obligations du sujet.

**Important :** `Makefile` et les `.c/.h` sont vides, donc `make` ne fonctionne pas encore.
Le dossier `libft/` ne contient qu’un `.gitkeep` ; y copier votre propre Libft si utilisée.
Les fichiers de `bonus/` et `include/checker_bonus.h` restent facultatifs.

## Répartition possible

- Développeur parsing : `src/parsing/` (avec validation des interfaces communes).
- Binôme : `src/stack/`, `src/ops/`, `src/rank/`, `src/sort/` selon votre accord.
- Ensemble : `include/`, `src/app/`, `src/adaptive/`, `src/bench/`, tests et docs.

**Total : 60 fichiers vides.**

## Fichiers racine — 3

- `Makefile`
- `README.md`
- `.gitignore`

## En-têtes partagés — 4

- `include/push_swap.h`
- `include/ps_ops.h`
- `include/ps_sort.h`
- `include/checker_bonus.h`

## Orchestration de l’application — 6

- `src/main.c`
- `src/app/app_init.c`
- `src/app/app_prepare.c`
- `src/app/app_run.c`
- `src/app/app_finish.c`
- `src/app/app_error.c`

## Parsing (ton module) — 6

- `src/parsing/parse_options.c`
- `src/parsing/parse_tokens.c`
- `src/parsing/parse_int.c`
- `src/parsing/parse_unique.c`
- `src/parsing/parse_build_a.c`
- `src/parsing/parse_arguments.c`

## Structures de piles et mémoire — 4

- `src/stack/stack_create.c`
- `src/stack/stack_free.c`
- `src/stack/stack_links.c`
- `src/stack/stack_queries.c`

## Normalisation des rangs — 1

- `src/rank/rank_normalize.c`

## Les 11 opérations et l’émission — 5

- `src/ops/ops_swap.c`
- `src/ops/ops_push.c`
- `src/ops/ops_rotate.c`
- `src/ops/ops_revrotate.c`
- `src/ops/ops_emit.c`

## Petits tris, Selection, Chunk et Radix — 5

- `src/sort/sort_small.c`
- `src/sort/sort_simple.c`
- `src/sort/sort_medium.c`
- `src/sort/sort_medium_restore.c`
- `src/sort/sort_radix.c`

## Calcul du désordre et stratégie adaptative — 2

- `src/adaptive/disorder.c`
- `src/adaptive/choose_strategy.c`

## Benchmark intégré — 2

- `src/bench/bench_counters.c`
- `src/bench/bench_report.c`

## Tests indépendants (non compilés dans push_swap) — 9

- `tests/test_operations.py`
- `tests/test_exhaustive.py`
- `tests/test_invalid.sh`
- `tests/test_bench.py`
- `tests/test_adaptive.py`
- `tests/test_normalization.c`
- `tests/test_chunk_invariants.py`
- `tests/test_radix_pass.py`
- `tests/cases/README.md`

## Outils de test externes — 2

- `tools/benchmark.py`
- `tools/reproduce_case.py`

## Documents de référence — 6

- `docs/PLAN_A_Z.md`
- `docs/CHECKLIST_DEVELOPPEMENT.md`
- `docs/GUIDE_PARSING.md`
- `docs/decisions.md`
- `docs/algorithms.md`
- `docs/evaluations.md`

## Checker bonus (facultatif, non compilé au départ) — 4

- `bonus/checker_main_bonus.c`
- `bonus/checker_read_bonus.c`
- `bonus/checker_parse_bonus.c`
- `bonus/checker_execute_bonus.c`

## Libft (réservé si vous choisissez de la réutiliser) — 1

- `libft/.gitkeep`
