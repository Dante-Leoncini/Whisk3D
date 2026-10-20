# साउंड

| फ़ंक्शन | क्या करता है |
|---|---|
| `beep(freq [, ms, vol])` | एक बीप (बिना फ़ाइल के)। |
| `sonido("sonidos/x.wav" [, vol, tono, loop, pan]) → h` | एक साउंड बजाता है; एक पहचानकर्ता लौटाता है। |
| `pararSonido(h [, fundido])`, `pararSonidos()`, `ajustarSonido(h, vol [, tono])` | साउंड रोकना या एडजस्ट करना। |
| `silenciar(bool)`, `estaMudo()` | सारी आवाज़ बंद करना। |
