# कीबोर्ड, कंट्रोलर, टच और माउस

| फ़ंक्शन | क्या करता है |
|---|---|
| `tecla(nombre) → bool` | कुंजी दबी हुई है (जब तक आप उसे दबाए रखते हैं)। |
| `teclaApretada(nombre) → bool` | ठीक इसी फ़्रेम में दबाई गई (हर बार दबाने पर सिर्फ़ एक बार)। |
| `boton(nombre)`, `botonApretado(nombre)` | यही, कंट्रोलर के किसी बटन के लिए। |
| `stick(["izq"\|"der"]) → x, y` | कंट्रोलर का स्टिक, -1 से 1 तक (ऊपर -1 है)। |
| `gatillo(["izq"\|"der"]) → 0..1` | एनालॉग ट्रिगर। |
| `controles() → n`, `control([n]) → nombre, tipo` | कितने कंट्रोलर हैं और किस प्रकार के हैं (`"xbox"`, `"playstation"`, `"nintendo"`, `"generico"`)। |
| `toque() → x, y, tocando` | स्क्रीन पर उंगली (या माउस का क्लिक)। |
| `dedo([n]) → x, y, activo` | मल्टी-टच: n नंबर की उंगली (1 से 4)। |
| `apretado(obj) → bool` | इस फ़्रेम में वह 2D एलिमेंट टैप या क्लिक हुआ (बटन)। |
| `raton() → x, y, dentro` | माउस कहाँ है। |
| `capturarRaton(bool)`, `ratonRel() → dx, dy`, `ratonCapturado()` | माउस से चारों ओर देखने के लिए कैप्चर किया गया माउस (फ़र्स्ट-पर्सन गेम, सिर्फ़ PC)। |
