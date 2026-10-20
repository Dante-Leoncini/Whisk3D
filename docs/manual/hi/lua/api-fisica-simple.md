# सरल फ़िज़िक्स (वेग और उछाल)

| फ़ंक्शन | क्या करता है |
|---|---|
| `velocidad(obj, vx [, vy, vz])` / `velocidad(obj) → vx, vy, vz` | आप उसे एक वेग देते हैं और इंजन उसे अपने-आप चलाता है। |
| `acelerar(obj, factor [, tope])` | उसके वेग को गुणा करके उसे तेज़ करता है। |
| `caja(obj [, w, h, d])` | उसके टक्कर बॉक्स का साइज़। |
| `rebotar(obj, otro)`, `rebotarEn(obj, area [, lados])`, `rebotarDentro(obj, area)` | किसी दूसरे ऑब्जेक्ट से या किसी क्षेत्र के किनारों से उछलना (उछलने पर `true` लौटाते हैं)। |
