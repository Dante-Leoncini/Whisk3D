# वर्टेक्स, UV और मटीरियल

| फ़ंक्शन | क्या करता है |
|---|---|
| `numVertices(m)`, `verticePos(m, i)`, `setVerticePos(m, i, x, y, z)` | वर्टेक्स को एक-एक करके पढ़ना और मूव करना। |
| `setVertices(m, {i, x, y, z, ...})` | एक साथ कई वर्टेक्स मूव करना (बहुत ज़्यादा तेज़)। |
| `grupoVertices(m, "grupo") → {índices}` | किसी ग्रुप के वर्टेक्स (इसे सिर्फ़ एक बार, `inicio` में कॉल करें)। |
| `setVerticeColor`, `setVerticesColor` | कोड से वर्टेक्स पेंट करना। |
| `setVerticeUV`, `desplazarUV(m, du, dv)`, `copiarUV` | UV को मूव करना (पानी, कन्वेयर बेल्ट…)। |
| `setTexturaB`, `setMezclaTextura`, `mezclaTextura` | किसी मटीरियल में दो टेक्सचर मिलाना। |
