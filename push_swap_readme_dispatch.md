# Push_swap — Architecture & Development Documentation

> Documentation technique du projet Push_swap : architecture, répartition des fonctions, algorithmes de tri et système adaptatif.

---

# Table des matières

1. [Architecture du projet](#1-architecture-du-projet)
2. [ADPT — Système adaptatif](#2-adpt--système-adaptatif)
3. [SMP — Simple / Insertion Sort](#3-smp--simple--insertion-sort)
4. [MDM — Medium / Chunk Sort](#4-mdm--medium--chunk-sort)
5. [CMPL — Complex / Turk Algorithm](#5-cmpl--complex--turk-algorithm)
6. [CORE — Fonctions communes](#6-core--fonctions-communes)
7. [OP — Opérations Push_swap](#7-op--opérations-push_swap)
8. [Parsing et validation](#8-parsing-et-validation)
9. [Benchmark et tests](#9-benchmark-et-tests)
10. [Fonctionnement général](#10-fonctionnement-général)
11. [Conventions de développement](#11-conventions-de-développement)
12. [Ordre de développement](#12-ordre-de-développement)

---

# 1. Architecture du projet

Voici l'organisation générale des fichiers du projet.

```text
push_swap/
│
├── Makefile
├── push_swap.h
├── README.md
│
├── src/
│   │
│   ├── main.c
│   │
│   ├── parsing/
│   │   ├── parse_args.c
│   │   ├── parse_number.c
│   │   ├── parse_validate.c
│   │   └── parse_duplicates.c
│   │
│   ├── core/
│   │   ├── core_stack_init.c
│   │   ├── core_stack_utils.c
│   │   ├── core_stack_free.c
│   │   ├── core_normalize.c
│   │   ├── core_array_sort.c
│   │   └── core_error.c
│   │
│   ├── operations/
│   │   ├── op_swap.c
│   │   ├── op_push.c
│   │   ├── op_rotate.c
│   │   └── op_reverse_rotate.c
│   │
│   ├── adaptive/
│   │   ├── adpt_dispatcher.c
│   │   ├── adpt_inversions.c
│   │   ├── adpt_lis.c
│   │   ├── adpt_metrics.c
│   │   ├── adpt_cost_estimator.c
│   │   └── adpt_benchmark_data.c
│   │
│   ├── simple/
│   │   ├── smp_dispatcher.c
│   │   ├── smp_two.c
│   │   ├── smp_three.c
│   │   ├── smp_four.c
│   │   └── smp_five.c
│   │
│   ├── medium/
│   │   ├── mdm_dispatcher.c
│   │   ├── mdm_chunk.c
│   │   ├── mdm_push_to_b.c
│   │   ├── mdm_optimize_b.c
│   │   └── mdm_push_to_a.c
│   │
│   ├── complex/
│   │   ├── cmpl_dispatcher.c
│   │   ├── cmpl_positions.c
│   │   ├── cmpl_targets.c
│   │   ├── cmpl_costs.c
│   │   ├── cmpl_cheapest.c
│   │   ├── cmpl_execute.c
│   │   └── cmpl_final_align.c
│   │
│   └── benchmark/
│       ├── bench_generator.c
│       ├── bench_runner.c
│       ├── bench_counter.c
│       ├── bench_checker.c
│       └── bench_report.c
│
└── tests/
    ├── test_parsing.c
    ├── test_operations.c
    ├── test_normalization.c
    ├── test_adaptive.c
    ├── test_simple.c
    ├── test_medium.c
    └── test_complex.c
```

---

# 2. ADPT — Système adaptatif

**Préfixe : `adpt_`**

Le système adaptatif représente le cerveau du projet.

Son rôle est d'analyser la stack initiale, de calculer différents indicateurs de désordre et de sélectionner automatiquement l'algorithme qui devrait produire le moins d'opérations.

Il ne constitue pas un quatrième algorithme de tri.

Il sert uniquement à choisir entre :
- SMP : Insertion Sort.
- MDM : Chunk Sort.
- CMPL : Turk Algorithm.

## 2.1. adpt_dispatcher.c

Fichier principal du système adaptatif.

| Fonction | Description |
|---|---|
| `adpt_dispatcher()` | Lance l'analyse et organise la sélection de l'algorithme. |
| `adpt_calculate_disorder()` | Calcule un indicateur global de désordre. |
| `adpt_select_algorithm()` | Sélectionne SMP, MDM ou CMPL. |
| `adpt_execute_algorithm()` | Appelle l'algorithme sélectionné. |

## 2.2. adpt_inversions.c

Calcul des inversions dans la stack.

Une inversion correspond à deux éléments dont l'ordre ne respecte pas l'ordre croissant attendu.

| Fonction | Description |
|---|---|
| `adpt_count_inversions()` | Compte le nombre total d'inversions. |
| `adpt_calculate_inversion_ratio()` | Calcule le ratio d'inversions. |
| `adpt_is_inversion()` | Vérifie si une paire d'éléments constitue une inversion. |

Formule :

\[
D_{inv} = \frac{I}{n(n-1)/2}
\]

Avec :
- `I` : nombre d'inversions.
- `n` : nombre d'éléments.

Le résultat est compris entre 0 et 1.

## 2.3. adpt_lis.c

Calcul de la Longest Increasing Subsequence.

La LIS représente la plus longue sous-séquence croissante présente dans la stack.

| Fonction | Description |
|---|---|
| `adpt_calculate_lis()` | Calcule la longueur de la LIS. |
| `adpt_calculate_lis_ratio()` | Calcule le ratio de désordre basé sur la LIS. |
| `adpt_build_lis()` | Reconstruit la sous-séquence si nécessaire. |

Formule :

\[
D_{LIS} = 1 - \frac{LIS}{n}
\]

Le résultat est compris entre 0 et 1.

## 2.4. adpt_metrics.c

Regroupe les métriques complémentaires.

| Fonction | Description |
|---|---|
| `adpt_analyze_stack()` | Analyse la stack initiale. |
| `adpt_calculate_runs()` | Compte les séquences croissantes naturelles. |
| `adpt_calculate_displacement()` | Calcule le déplacement maximal des éléments. |
| `adpt_get_metrics()` | Retourne l'ensemble des métriques calculées. |

Les métriques complémentaires sont facultatives et pourront être ajoutées en fonction des résultats des benchmarks.

## 2.5. adpt_cost_estimator.c

Estimation du coût des trois algorithmes.

| Fonction | Description |
|---|---|
| `adpt_estimate_smp()` | Estime le nombre d'opérations de SMP. |
| `adpt_estimate_mdm()` | Estime le nombre d'opérations de MDM. |
| `adpt_estimate_cmpl()` | Estime le nombre d'opérations de CMPL. |
| `adpt_compare_costs()` | Compare les coûts estimés. |

Les estimations doivent être basées sur les résultats de benchmarks et non sur des seuils arbitraires.

## 2.6. adpt_benchmark_data.c

Gestion des données de performances.

| Fonction | Description |
|---|---|
| `adpt_load_benchmark_data()` | Charge les données de benchmarks. |
| `adpt_get_algorithm_performance()` | Récupère les performances mesurées d'un algorithme. |
| `adpt_update_estimates()` | Actualise les estimations à partir des résultats disponibles. |

---

# 3. SMP — Simple / Insertion Sort

**Préfixe : `smp_`**

Algorithme destiné aux petites stacks.

Plage initiale recommandée : **2 à 5 éléments**.

L'objectif est de produire le minimum d'opérations possible pour les petites permutations.

## 3.1. smp_dispatcher.c

| Fonction | Description |
|---|---|
| `smp_dispatcher()` | Sélectionne le tri adapté à la taille de la stack. |
| `smp_sort()` | Lance le tri simple. |

## 3.2. smp_two.c

| Fonction | Description |
|---|---|
| `smp_sort_two()` | Trie une stack contenant deux éléments. |

## 3.3. smp_three.c

| Fonction | Description |
|---|---|
| `smp_sort_three()` | Trie une stack contenant trois éléments. |
| `smp_case_012()` | Gère le cas déjà trié. |
| `smp_case_021()` | Gère le cas 0, 2, 1. |
| `smp_case_102()` | Gère le cas 1, 0, 2. |
| `smp_case_120()` | Gère le cas 1, 2, 0. |
| `smp_case_201()` | Gère le cas 2, 0, 1. |
| `smp_case_210()` | Gère le cas 2, 1, 0. |

## 3.4. smp_four.c

| Fonction | Description |
|---|---|
| `smp_sort_four()` | Trie une stack contenant quatre éléments. |
| `smp_extract_min()` | Déplace le minimum de A vers B. |
| `smp_restore_four()` | Reconstruit la stack A après le tri. |

## 3.5. smp_five.c

| Fonction | Description |
|---|---|
| `smp_sort_five()` | Trie une stack contenant cinq éléments. |
| `smp_extract_minimums()` | Extrait les deux plus petites valeurs. |
| `smp_restore_five()` | Reconstruit la stack A après le tri. |

### Objectifs SMP

- Gérer toutes les permutations de 2 à 5 éléments.
- Éviter les opérations inutiles.
- Utiliser les opérations Push_swap officielles.
- Garantir une stack A triée à la fin.
- Minimiser le nombre d'opérations.

---

# 4. MDM — Medium / Chunk Sort

**Préfixe : `mdm_`**

Algorithme destiné aux stacks de taille moyenne.

Plage initiale recommandée : **6 à 100 éléments**.

Le principe consiste à diviser les indexes en plusieurs groupes appelés chunks, puis à déplacer progressivement les éléments vers B.

## 4.1. mdm_dispatcher.c

| Fonction | Description |
|---|---|
| `mdm_dispatcher()` | Organise l'exécution du Chunk Sort. |
| `mdm_sort()` | Lance le tri. |

## 4.2. mdm_chunk.c

| Fonction | Description |
|---|---|
| `mdm_calculate_chunk_size()` | Calcule la taille des chunks. |
| `mdm_get_chunk_min()` | Récupère la borne minimale du chunk. |
| `mdm_get_chunk_max()` | Récupère la borne maximale du chunk. |
| `mdm_is_in_chunk()` | Vérifie si un élément appartient au chunk actuel. |
| `mdm_advance_chunk()` | Passe au chunk suivant. |

## 4.3. mdm_push_to_b.c

| Fonction | Description |
|---|---|
| `mdm_find_chunk_element()` | Recherche un élément appartenant au chunk actuel. |
| `mdm_find_best_position()` | Recherche le meilleur élément à déplacer. |
| `mdm_push_chunk_to_b()` | Envoie les éléments du chunk vers B. |

## 4.4. mdm_optimize_b.c

| Fonction | Description |
|---|---|
| `mdm_optimize_b()` | Optimise l'ordre des éléments dans B. |
| `mdm_rotate_b_for_push()` | Organise B pendant les insertions. |

## 4.5. mdm_push_to_a.c

| Fonction | Description |
|---|---|
| `mdm_find_max_position()` | Trouve la position du maximum dans B. |
| `mdm_push_back_to_a()` | Replace les éléments de B vers A. |
| `mdm_align_stack_a()` | Aligne le minimum en haut de A. |

### Objectifs MDM

- Déterminer automatiquement une taille de chunk adaptée.
- Minimiser les rotations inutiles.
- Optimiser l'ordre des éléments dans B.
- Réduire le nombre d'opérations `pa`.
- Garantir une stack A triée à la fin.

### Benchmarks à réaliser

Pour 100 éléments, comparer notamment :

| Configuration | Taille des chunks |
|---|---:|
| 5 chunks | 20 |
| 4 chunks | 25 |
| 10 chunks | 10 |

Ces configurations sont des points de départ, pas des valeurs obligatoires.

---

# 5. CMPL — Complex / Turk Algorithm

**Préfixe : `cmpl_`**

Algorithme destiné aux grandes stacks.

Plage initiale recommandée : **101 à 500 éléments**.

Le Turk Algorithm repose sur le calcul du coût de déplacement de chaque élément, afin de sélectionner celui qui peut être déplacé avec le moins d'opérations.

Il exploite notamment les rotations combinées `rr` et `rrr`.

## 5.1. cmpl_dispatcher.c

| Fonction | Description |
|---|---|
| `cmpl_dispatcher()` | Organise l'exécution du Turk Algorithm. |
| `cmpl_sort()` | Lance le tri complexe. |

## 5.2. cmpl_positions.c

| Fonction | Description |
|---|---|
| `cmpl_calculate_positions()` | Calcule les positions des éléments dans A et B. |
| `cmpl_get_position()` | Récupère la position d'un élément. |
| `cmpl_update_positions()` | Actualise les positions après les déplacements. |

## 5.3. cmpl_targets.c

| Fonction | Description |
|---|---|
| `cmpl_find_target_a()` | Trouve la position cible dans A. |
| `cmpl_find_target_b()` | Trouve la position cible dans B. |
| `cmpl_find_successor()` | Recherche le plus petit élément supérieur à une valeur donnée. |
| `cmpl_find_predecessor()` | Recherche le plus grand élément inférieur à une valeur donnée. |

## 5.4. cmpl_costs.c

| Fonction | Description |
|---|---|
| `cmpl_calculate_cost_a()` | Calcule le coût des rotations dans A. |
| `cmpl_calculate_cost_b()` | Calcule le coût des rotations dans B. |
| `cmpl_calculate_total_cost()` | Calcule le coût total d'un déplacement. |
| `cmpl_calculate_combined_cost()` | Prend en compte les rotations combinées RR et RRR. |

## 5.5. cmpl_cheapest.c

| Fonction | Description |
|---|---|
| `cmpl_find_cheapest_move()` | Sélectionne le déplacement le moins coûteux. |
| `cmpl_compare_moves()` | Compare les coûts des différents déplacements. |

## 5.6. cmpl_execute.c

| Fonction | Description |
|---|---|
| `cmpl_execute_move()` | Exécute le déplacement sélectionné. |
| `cmpl_rotate_stacks()` | Effectue les rotations nécessaires. |
| `cmpl_push_to_b()` | Déplace un élément sélectionné vers B. |
| `cmpl_sort_remaining_three()` | Trie les trois derniers éléments de A. |

## 5.7. cmpl_final_align.c

| Fonction | Description |
|---|---|
| `cmpl_push_back_to_a()` | Replace les éléments de B dans A. |
| `cmpl_final_align()` | Place le minimum en première position de A. |

### Objectifs CMPL

- Calculer précisément les positions.
- Déterminer les bonnes cibles d'insertion.
- Calculer les coûts de rotation.
- Exploiter les opérations combinées.
- Sélectionner systématiquement le déplacement le moins coûteux.
- Finaliser le tri avec une stack A parfaitement ordonnée.

---

# 6. CORE — Fonctions communes

**Préfixe : `core_`**

Ces fonctions sont utilisées par les trois algorithmes.

Elles doivent être développées une seule fois afin d'éviter la duplication de code.

## 6.1. core_stack_init.c

| Fonction | Description |
|---|---|
| `core_stack_new_node()` | Crée un nouveau nœud. |
| `core_stack_add_back()` | Ajoute un élément à la fin de la stack. |
| `core_stack_add_front()` | Ajoute un élément au début de la stack. |
| `core_stack_init()` | Initialise la stack A à partir des arguments. |

## 6.2. core_stack_utils.c

| Fonction | Description |
|---|---|
| `core_stack_size()` | Retourne le nombre d'éléments. |
| `core_stack_last()` | Retourne le dernier élément. |
| `core_stack_min()` | Recherche la valeur minimale. |
| `core_stack_max()` | Recherche la valeur maximale. |
| `core_stack_is_sorted()` | Vérifie si la stack est triée. |
| `core_stack_get_position()` | Recherche la position d'un élément. |

## 6.3. core_stack_free.c

| Fonction | Description |
|---|---|
| `core_stack_free()` | Libère une stack. |
| `core_stacks_free()` | Libère les stacks A et B. |

## 6.4. core_normalize.c

| Fonction | Description |
|---|---|
| `core_normalize_stack()` | Transforme les valeurs originales en indexes. |
| `core_get_rank()` | Récupère le rang d'une valeur. |
| `core_copy_stack_to_array()` | Copie les valeurs de la stack dans un tableau. |

## 6.5. core_array_sort.c

| Fonction | Description |
|---|---|
| `core_sort_array()` | Trie un tableau auxiliaire. |
| `core_binary_search()` | Recherche une valeur dans un tableau trié. |

## 6.6. core_error.c

| Fonction | Description |
|---|---|
| `core_print_error()` | Affiche le message Error sur stderr. |
| `core_cleanup()` | Libère les ressources du programme. |

---

# 7. OP — Opérations Push_swap

**Préfixe : `op_`**

Les opérations constituent la base de tous les algorithmes.

Elles doivent modifier les stacks et afficher les instructions correspondantes sur stdout.

Les fonctions internes de manipulation ne doivent pas afficher elles-mêmes les instructions.

## 7.1. op_swap.c

| Fonction | Opération | Description |
|---|---|---|
| `op_sa()` | sa | Échange les deux premiers éléments de A. |
| `op_sb()` | sb | Échange les deux premiers éléments de B. |
| `op_ss()` | ss | Effectue sa et sb simultanément. |

## 7.2. op_push.c

| Fonction | Opération | Description |
|---|---|---|
| `op_pa()` | pa | Déplace le premier élément de B vers A. |
| `op_pb()` | pb | Déplace le premier élément de A vers B. |

## 7.3. op_rotate.c

| Fonction | Opération | Description |
|---|---|---|
| `op_ra()` | ra | Déplace le premier élément de A à la fin. |
| `op_rb()` | rb | Déplace le premier élément de B à la fin. |
| `op_rr()` | rr | Effectue ra et rb simultanément. |

## 7.4. op_reverse_rotate.c

| Fonction | Opération | Description |
|---|---|---|
| `op_rra()` | rra | Déplace le dernier élément de A au début. |
| `op_rrb()` | rrb | Déplace le dernier élément de B au début. |
| `op_rrr()` | rrr | Effectue rra et rrb simultanément. |

### Objectifs OP

- Gérer les stacks vides.
- Gérer les stacks contenant un seul élément.
- Gérer les stacks contenant deux éléments.
- Ne modifier que les stacks concernées.
- Afficher uniquement des opérations Push_swap valides.
- Ne jamais afficher une opération qui n'a pas été exécutée.

---

# 8. Parsing et validation

**Préfixe : `parse_`**

Le parsing est responsable de la réception, de la conversion et de la validation des arguments.

Il doit accepter les deux formats :

```bash
./push_swap 3 2 1
```

```bash
./push_swap "3 2 1"
```

## 8.1. parse_args.c

| Fonction | Description |
|---|---|
| `parse_args()` | Récupère les arguments du programme. |
| `split_args()` | Sépare les arguments contenant plusieurs nombres. |

## 8.2. parse_number.c

| Fonction | Description |
|---|---|
| `parse_number()` | Convertit une chaîne en entier. |
| `is_valid_number()` | Vérifie le format numérique. |
| `check_int_overflow()` | Vérifie les limites INT_MIN et INT_MAX. |

## 8.3. parse_validate.c

| Fonction | Description |
|---|---|
| `parse_validate()` | Centralise les validations des arguments. |
| `parse_check_empty()` | Détecte les arguments vides ou invalides. |

## 8.4. parse_duplicates.c

| Fonction | Description |
|---|---|
| `parse_check_duplicates()` | Détecte les nombres en double. |

### Objectifs Parsing

- Accepter les nombres positifs et négatifs.
- Accepter INT_MAX et INT_MIN.
- Refuser les dépassements de capacité.
- Refuser les caractères non numériques.
- Refuser les doublons.
- Gérer les arguments vides.
- Afficher Error sur stderr en cas d'entrée invalide.
- Ne produire aucune opération en cas d'entrée invalide.

---

# 9. Benchmark et tests

**Préfixe : `bench_`**

Les benchmarks permettent de comparer objectivement les trois algorithmes et d'améliorer le système adaptatif.

## 9.1. bench_generator.c

| Fonction | Description |
|---|---|
| `bench_generate_random_array()` | Génère une permutation aléatoire. |
| `bench_generate_sorted_array()` | Génère une entrée déjà triée. |
| `bench_generate_reverse_array()` | Génère une entrée inversée. |
| `bench_generate_nearly_sorted_array()` | Génère une entrée presque triée. |

## 9.2. bench_runner.c

| Fonction | Description |
|---|---|
| `bench_run_algorithm()` | Exécute un algorithme sur une entrée de test. |
| `bench_run_all_algorithms()` | Compare les algorithmes sur une même entrée. |
| `bench_run_random_tests()` | Lance une série de tests aléatoires. |

## 9.3. bench_counter.c

| Fonction | Description |
|---|---|
| `bench_count_operations()` | Compte les opérations exécutées. |
| `bench_get_average()` | Calcule la moyenne des opérations. |
| `bench_get_worst_case()` | Identifie le pire résultat. |

## 9.4. bench_checker.c

| Fonction | Description |
|---|---|
| `bench_run_checker()` | Vérifie le résultat avec un checker indépendant. |
| `bench_validate_result()` | Vérifie que A est triée et que B est vide. |

## 9.5. bench_report.c

| Fonction | Description |
|---|---|
| `bench_save_result()` | Enregistre les résultats. |
| `bench_print_report()` | Affiche un rapport de performances. |
| `bench_compare_algorithms()` | Compare les résultats des trois algorithmes. |

### Objectifs Benchmark

Tester les trois algorithmes sur :

- Des entrées déjà triées.
- Des entrées inversées.
- Des entrées presque triées.
- Des permutations aléatoires.
- Des valeurs positives et négatives.
- Des valeurs alternant entre minimum et maximum.
- Des entrées avec une LIS importante.
- Des entrées avec beaucoup d'inversions.

Les comparaisons doivent utiliser exactement les mêmes entrées initiales et des copies indépendantes.

---

# 10. Fonctionnement général

Voici le déroulement global du programme.

```text
                    START
                      |
                      v
                 main()
                      |
                      v
                parse_args()
                      |
                      v
              parse_validate()
                      |
                      v
              core_stack_init()
                      |
                      v
            core_normalize_stack()
                      |
                      v
              adpt_dispatcher()
                      |
                      v
              adpt_analyze_stack()
                      |
              +-------+-------+
              |               |
              v               v
       Inversion ratio     LIS ratio
              |               |
              +-------+-------+
                      |
                      v
          adpt_calculate_disorder()
                      |
                      v
           adpt_select_algorithm()
                      |
             +--------+--------+
             |        |        |
             v        v        v
            SMP      MDM      CMPL
             |        |        |
             v        v        v
          Insertion Chunk     Turk
            Sort    Sort    Algorithm
             |        |        |
             +--------+--------+
                      |
                      v
                Stack A triée
                      |
                      v
               cleanup_program()
                      |
                      v
                     END
```

## 10.1. Rôle du dispatcher adaptatif

Le dispatcher est responsable de quatre étapes :

1. Analyser la stack initiale.
2. Calculer les métriques de désordre.
3. Estimer les performances des algorithmes compatibles.
4. Lancer l'algorithme sélectionné.

Exemple conceptuel :

```c
adpt_dispatcher(data)
{
    analyze_stack(data);
    calculate_disorder(data);
    select_algorithm(data);
    execute_algorithm(data);
}
```

Ce code est uniquement une représentation logique du fonctionnement, pas une implémentation C définitive.

## 10.2. Règles de sélection initiales

| Nombre d'éléments | Stratégie initiale |
|---|---|
| 0 à 1 | Aucune opération |
| 2 à 5 | SMP |
| 6 à 100 | MDM |
| 101 à 500 | CMPL |

Ces plages constituent des valeurs de départ.

Le système adaptatif pourra choisir un autre algorithme lorsqu'il sera compatible avec la taille de la stack et que les benchmarks démontreront qu'il devrait produire moins d'opérations.

**Important :** les ratios d'inversions et de LIS ne déterminent pas directement le meilleur algorithme. Ils servent à estimer les performances, en s'appuyant sur les résultats des benchmarks.

---

# 11. Conventions de développement

Tous les collaborateurs doivent respecter les mêmes conventions afin de faciliter l'intégration.

## 11.1. Préfixes obligatoires

| Préfixe | Domaine |
|---|---|
| `smp_` | Simple / Insertion Sort |
| `mdm_` | Medium / Chunk Sort |
| `cmpl_` | Complex / Turk Algorithm |
| `adpt_` | Système adaptatif |
| `core_` | Fonctions communes |
| `op_` | Opérations Push_swap |
| `parse_` | Parsing et validation |
| `bench_` | Benchmark et performances |

## 11.2. Structures communes

Les structures doivent être centralisées dans `push_swap.h`.

Exemple de base :

```c
typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

typedef struct s_metrics
{
    int     inversion_count;
    int     lis_length;
    double  inversion_ratio;
    double  lis_ratio;
}   t_metrics;

typedef struct s_data
{
    t_stack     *a;
    t_stack     *b;
    int         size;
    t_metrics   metrics;
}   t_data;
```

Ces structures pourront évoluer en fonction des besoins du projet.

## 11.3. Règles de collaboration

1. Chaque collaborateur travaille sur son domaine.
2. Chaque fichier doit respecter les préfixes définis.
3. Les prototypes publics doivent être déclarés dans `push_swap.h`.
4. Les fonctions utilisées uniquement dans un fichier doivent être déclarées `static`.
5. Les opérations Push_swap doivent être utilisées pour modifier les stacks.
6. Aucun algorithme ne doit simuler directement une opération en modifiant les listes.
7. Chaque fonction doit être testée avant intégration.
8. Les fonctions communes ne doivent pas être dupliquées.
9. Les modifications de `push_swap.h` doivent être coordonnées.
10. Chaque branche doit être compilable avant d'être fusionnée.

## 11.4. Compilation

Le projet doit compiler avec :

```bash
make
```

Options de compilation :

```bash
-Wall -Wextra -Werror
```

Commandes Makefile attendues :

```bash
make
make all
make clean
make fclean
make re
```

Vérification Norminette :

```bash
norminette
```

Vérification mémoire :

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
```

---

# 12. Ordre de développement

Voici l'ordre recommandé pour réaliser le projet.

| Phase | Travail | Priorité |
|---|---|---|
| 1 | Parsing et validation | Essentielle |
| 2 | Structures de données | Essentielle |
| 3 | Opérations Push_swap | Essentielle |
| 4 | Fonctions CORE | Essentielle |
| 5 | Normalisation | Essentielle |
| 6 | Analyseur ADPT | Haute |
| 7 | Algorithme SMP | Haute |
| 8 | Algorithme MDM | Haute |
| 9 | Algorithme CMPL | Haute |
| 10 | Dispatcher ADPT | Haute |
| 11 | Benchmarks | Haute |
| 12 | Optimisation des performances | Moyenne |
| 13 | Norminette et Valgrind | Finale |

## Répartition recommandée

| Domaine | Responsable |
|---|---|
| Parsing | Collaborateur 1 |
| CORE | Collaborateur 2 |
| OP | Collaborateur 2 |
| SMP | Collaborateur 3 |
| MDM | Collaborateur 4 |
| CMPL | Collaborateur 5 |
| ADPT | Responsable du projet |
| Benchmark | Équipe complète |

---

# Objectif final

L'objectif de Push_swap est de développer trois algorithmes de tri indépendants, puis de les connecter à un système adaptatif capable de choisir automatiquement la stratégie la plus efficace.

Le projet doit respecter les principes suivants :

- Fiabilité du parsing et des opérations.
- Structures de données propres et réutilisables.
- Normalisation des valeurs.
- Analyse précise du désordre initial.
- Trois algorithmes indépendants et fonctionnels.
- Sélection adaptative basée sur des mesures réelles.
- Minimisation du nombre d'opérations.
- Validation systématique avec un checker indépendant.
- Respect des contraintes de compilation et de Norminette.

**Objectif principal : obtenir le meilleur nombre d'opérations possible sur une grande variété d'entrées, sans sacrifier la fiabilité du programme.**

---

*Push_swap — Development Documentation*
