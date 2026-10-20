# Lumières et caméra

| Fonction | Ce qu'elle fait |
|---|---|
| `color(luz) → r, g, b`, `setColor(luz, r, g, b)` | La couleur d'une lumière. |
| `energia(luz) → e`, `setEnergia(luz, e)` | Sa luminosité, de 0 à 1 (pour la faire scintiller ou s'éteindre progressivement). |
| `setCamaraActiva(cam)` | Change la caméra depuis laquelle on voit le jeu. |
| `lenteDe(cam) → fov, cerca, lejos`, `setLente(cam [, fov, cerca, lejos])` | Angle de vue et distances de découpe. |
| `camaraXZ() → fx, fz, rx, rz` | La direction dans laquelle la caméra regarde sur le sol (pour déplacer le personnage selon la caméra). |
| `pantallaDe(obj) → x, y, delante` | L'endroit où un objet 3D apparaît à l'écran (pour placer une étiquette 2D au-dessus). |
| `setRiel(cam, curva [, offset])`, `setRielNodo`, `setMiradaRiel`, `rielDe` | Faire suivre une courbe (rail) à la caméra. |
| `resolucion() → ancho, alto` | Taille réelle de l'image 3D en pixels. |
