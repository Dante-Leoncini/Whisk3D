# UV Editor

यह दिखाता है कि टेक्सचर मेश पर कैसे बैठता है। एडिट करने के लिए मेश का **3D Viewport में Edit Mode** में होना ज़रूरी है; वरना एडिटर सिर्फ़ टेक्सचर दिखाता है। UV Editor का मोड अलग से चलता है: यह 3D Viewport का मोड नहीं बदलता। UV को अनरैप और प्रोजेक्ट करने वाले टूल 3D Viewport में हैं (Edit Mode, <kbd>U</kbd> कुंजी)।

## नेविगेशन और ऊपरी बार

| फ़ंक्शन | विवरण | कैसे इस्तेमाल करें |
|---|---|---|
| ज़ूम / पैन | पॉइंटर की ओर ज़ूम करता है / व्यू को खिसकाता है। | व्हील / बीच वाला बटन या ऐरो कुंजियाँ; टच: 1 उंगली पैन करती है, 2 उंगलियाँ ज़ूम |
| Mode | Object Mode, Edit Mode, Weight Paint, Edit Bones और Pose Mode (आख़िरी दो तब, जब मेश में 2D आर्मेचर हो)। | मोड बटन, <kbd>Tab</kbd> |
| Vertex / Edge / Face | Edit Mode में क्या चुना जाएगा। | बटन |
| Pivot | Cursor, Individual Origins या Median Point। | बटन |
| Cursor | Cursor to Selection, Selection to Cursor, Cursor to Center। | मेनू |
| View | Sync Selection (UV चयन वही होता है जो मेश का चयन है), Repeat Texture (टाइलिंग), Show Chrome UV, Frame Selected, Frame All। | मेनू; <kbd>Num.</kbd> |
| Texture | कौन-सा टेक्सचर दिखेगा: New Texture…, Auto (सक्रिय हिस्से वाला), या प्रोजेक्ट का कोई भी टेक्सचर। | मेनू |
| New Texture | एक इमेज बनाता है (नाम, साइज़, रंग, ट्रांसपेरेंसी; Blank, UV Grid या Color Grid), उसे प्रोजेक्ट में सेव करता है और मटीरियल को दे देता है। | Texture → New Texture… |
| Mipmap | जाँचने के लिए mipmap का कोई ख़ास लेवल दिखाता है। | Mipmap बटन |
| Edit | इमेज पर टेक्सचर पेंटिंग में जाता है और उससे बाहर आता है। | Edit बटन |
| Save (डिस्केट, हमेशा दिखता है) | Save, Save As…, Save outside the .w3d…, Save inside the .w3d, Export UV Layout… | मेनू |
| Export UV Layout | पारदर्शी बैकग्राउंड वाली एक PNG सेव करता है: अर्ध-पारदर्शी फ़ेस (जहाँ वे एक-दूसरे पर चढ़ते हैं वहाँ ज़्यादा अपारदर्शी) और अपारदर्शी लाइनें। आप नाम, फ़ोल्डर और रिज़ॉल्यूशन चुनते हैं (डिफ़ॉल्ट 512, N95 पर 256, या दिख रहे टेक्सचर का साइज़)। | Save → Export UV Layout… |
| Animation | UV लेयर के, या 2D पोज़ के कीफ़्रेम डालना, डिलीट करना या साफ़ करना। | मेनू |

## Object Mode (UV)

क्लिक से चुना जाता है कि क्या एडिट होगा: कोई 2D आर्मेचर (अगर आप किसी बोन को छूते हैं) या ज्योमेट्री। <kbd>Tab</kbd> चुनी हुई चीज़ को एडिट करने के लिए उसमें जाता है।

## Edit Mode (UV)

| फ़ंक्शन | विवरण | शॉर्टकट |
|---|---|---|
| Select | UV वर्टेक्स, एज या फ़ेस। सिंक न होने पर 3D Viewport फ़िल्टर करता है: सिर्फ़ वे फ़ेस दिखते हैं जो 3D में चुने हुए हैं। | क्लिक; <kbd>Shift</kbd>+क्लिक |
| All / None / Invert | जो दिख रहा है उस पर। | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> |
| Select Linked | पॉइंटर के नीचे वाला UV आइलैंड (<kbd>Shift</kbd> जोड़ता है)। | <kbd>L</kbd> |
| Box Select | आयत; <kbd>Shift</kbd> जोड़ता है। | <kbd>B</kbd> |
| Move / Rotate / Scale | UV को ट्रांसफ़ॉर्म करता है। <kbd>X</kbd> / <kbd>Y</kbd> एक अक्ष लॉक करते हैं; आप वैल्यू टाइप भी कर सकते हैं (1.0 = एक टाइल)। | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| 2D कर्सर रखना | जहाँ क्लिक करें, वहाँ कर्सर रख देता है। | दायाँ क्लिक |
| Insert Keyframe | UV लेयर को सक्रिय वर्टेक्स एनिमेशन में सेव करता है। | <kbd>I</kbd> |

## Weight Paint (UV)

UV मैप पर 2D बोन के वेट पेंट करता है, उन्हीं कंट्रोल के साथ जो 3D Viewport में हैं (+/−/= मोड, ग्रुप, मार्कर, फ़ॉलऑफ़, Selected only)। किसी बोन पर <kbd>Ctrl</kbd>+क्लिक करने से वह पेंटिंग के लिए चुनी जाती है।

## Edit Bones और Pose Mode (2D आर्मेचर)

| फ़ंक्शन | विवरण | शॉर्टकट |
|---|---|---|
| Add Armature 2D / Bone | मेश का 2D आर्मेचर बनाता है (उसके UV ग्रुप के साथ) या एक बोन जोड़ता है। | Add मेनू |
| Select | एक सिरा या पूरी बोन; ड्रैग करने पर वह मूव होती है। | क्लिक; <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>L</kbd> / <kbd>B</kbd> |
| Move / Rotate / Scale | Edit Bones में रेस्ट पोज़िशन बदलता है; Pose में पोज़ देता है (वेट वाले UV बोन के साथ चलते हैं)। | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Extrude / Duplicate / Delete | सिर्फ़ Edit Bones में। | <kbd>E</kbd> / <kbd>Shift+D</kbd> / <kbd>X</kbd> |
| Set Parent / Clear Parent | Keep Offset या Connected / Disconnect। | <kbd>Ctrl+P</kbd> / <kbd>Alt+P</kbd> |
| Insert Keyframe | Pose में: चैनलों का मेनू, या <kbd>Shift+I</kbd> से सब कुछ। | <kbd>I</kbd> |

## Texture Paint (UV)

**Edit** बटन से आप सीधे इमेज पर पेंट करते हैं, रंग, फ़ॉलऑफ़, रेडियस और स्ट्रेंथ के साथ। यह डिस्केट से सेव होता है।
