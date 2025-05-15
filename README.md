# Reverse Polish Notation Automaton

This program evaluates strings and determines whether they are in valid [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation). A very dumbed down deterministic [pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton) (PDA) is being used to validate these inputs. Each calculation step (with `--step-mode`) and the result of the evaluation by the automaton are displayed.

The following test words are being used with their expected outputs:

| Input                                           | Output              |
| ----------------------------------------------- | ------------------- |
| `3 9 + 4 2 + 8 2 + 4 9 + * * +`                 | Valid (Result: 792) |
| `2 3 + 1 2 + 3 2 7 + 2 5 2 4 + + 6 * + + + + +` | Valid (Result: 88)  |
| `6 4 + *`                                       | Invalid             |
| `2 * 9 + 7 * 3 *`                               | Invalid             |

# Quick start

**Assumption:** Compiled to `/main`

Normal mode (only shows results):\
`./main < test-words.txt`

Step mode (also shows each calculation step):\
`./main --step-mode < test-words.txt`

# Why?

This was an assignment from university (Zürcher Hochschule für Angewandte Wissenschaften).
