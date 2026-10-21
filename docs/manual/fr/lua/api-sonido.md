# Son

| Fonction | Ce qu'elle fait |
|---|---|
| `beep(freq [, ms, vol])` | Un bip (sans fichier). |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | Joue un son ; renvoie un identifiant. |
| `sonido("sonidos/x.wav", {vol, tono, loop, pan, ataque, decaimiento, sostenido, caida, liberacion, duracion, reverb}) → h` | La même chose avec des noms, plus l'enveloppe (attaque, déclin, maintien de 0 à 1, `caida` : le maintien baisse de 60 dB en autant de secondes, relâchement, et `duracion` : la note se relâche seule après autant de secondes) et la part du son envoyée à la réverbération (0 à 1). |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | Arrêter ou ajuster des sons. |
| `soltarSonido(h)` | Relâche la note : l'enveloppe passe à son relâchement. |
| `reverb(sala, amortiguacion, nivel)` | La réverbération générale : taille de la salle, amortissement et niveau (de 0 à 1 ; niveau 0 l'éteint). |
| `silenciar(bool)`, `estaMudo()` | Silence général. |
