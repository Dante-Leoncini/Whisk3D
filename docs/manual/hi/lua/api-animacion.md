# एनिमेशन

| फ़ंक्शन | क्या करता है |
|---|---|
| `animEscena(nombre [, loop])`, `pararEscena()`, `animEscenaFrame(f)` | पूरे सीन के एनिमेशन। |
| `animObjeto(raiz, "clip" [, loop])`, `animObjetoParar`, `animObjetoTermino`, `animObjetoVelocidad` | किसी ऑब्जेक्ट और उसके चाइल्ड के एनिमेशन क्लिप। |
| `animClip(esqueleto, clip [, loop])`, `animTermino`, `animVelocidad`, `animTransicion` | किसी आर्मेचर के एनिमेशन (चलना, कूदना…) और उनके बीच का स्मूद ट्रांज़िशन। |
| `animCapa(esq, n, clip [, peso, modo])` और उससे जुड़े फ़ंक्शन | कई एनिमेशन को एक साथ लेयर (1 से 16) में मिलाना, जैसे दौड़ना + गोली चलाना। |
| `huesoPunto(esq, "hueso" [, x, y, z]) → x, y, z` | कोई बोन कहाँ है (हाथ में हथियार रखने के लिए)। |
| `animar(malla, n [, frame])` | किसी मेश का वर्टेक्स एनिमेशन बदलता है। |
