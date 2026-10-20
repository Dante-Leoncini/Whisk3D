# Temps, hasard et utilitaires

| Fonction | Ce qu'elle fait |
|---|---|
| `azar() → 0..1`, `azar(min, max) → entero` | Nombres aléatoires. |
| `relojMs() → ms` | Millisecondes, pour mesurer le temps que prend une opération. |
| `perfilLua(cuadros [, etiqueta])` | Mesure quelles parties du script sont lentes (`perfilLua(0)` le désactive). |
| `lineaCrear(nombre, puntos)`, `lineaPunto(id, s)` | Une courbe lisse fermée calculée par le moteur (parcours). |

Il n'y a pas de fonction « temps écoulé depuis le début » : additionnez `dt` dans une variable.
