# Edit Mode (मेश)

किसी मेश पर <kbd>Tab</kbd> दबाकर इसमें जाया जाता है। ऊपरी बार के बटन के अनुसार आप **वर्टेक्स**, **एज** या **फ़ेस** पर काम करते हैं।

## चयन

| फ़ंक्शन | विवरण | शॉर्टकट |
|---|---|---|
| Select | एक वर्टेक्स, एज या फ़ेस चुनता है। | क्लिक; <kbd>Shift</kbd>+क्लिक चयन को बदलता है |
| Select Linked | पॉइंटर के नीचे जुड़ा हुआ पूरा आइलैंड। | <kbd>L</kbd> |
| Loop Select | एज या फ़ेस का एक रिंग। | <kbd>Shift+Alt</kbd>+क्लिक |
| Pick Shortest Path | सक्रिय एलिमेंट और क्लिक किए गए एलिमेंट के बीच का रास्ता चुनता है। | <kbd>Ctrl</kbd>+क्लिक |
| Shortest Path (Fill Region) | दोनों के बीच का पूरा क्षेत्र चुनता है। | <kbd>Ctrl+Shift</kbd>+क्लिक |
| All / None / Invert / Box | Object Mode की तरह, मेश के एलिमेंट पर। | <kbd>A</kbd> / <kbd>Alt+A</kbd> / <kbd>Ctrl+I</kbd> / <kbd>B</kbd> |

## मॉडलिंग

| फ़ंक्शन | विवरण | शॉर्टकट |
|---|---|---|
| Move / Rotate / Scale | चुनी हुई चीज़ों को ट्रांसफ़ॉर्म करता है। मूव चलते समय <kbd>G</kbd> दोबारा दबाने पर स्लाइड शुरू हो जाता है। | <kbd>G</kbd> / <kbd>R</kbd> / <kbd>S</kbd> |
| Shrink/Fatten | हर वर्टेक्स को उसके नॉर्मल की दिशा में खिसकाता है (फुलाता या पिचकाता है)। | <kbd>Alt+S</kbd> |
| Extrude | चुनी हुई चीज़ों से नई ज्योमेट्री निकालता है (फ़ेस अपने नॉर्मल की दिशा में निकलते हैं)। | <kbd>E</kbd> |
| Loop Cut and Slide | एज का एक रिंग काटता है। व्हील कट की संख्या बदलता है; क्लिक लागू करता है और फिर स्लाइड होता है। | <kbd>Ctrl+R</kbd> |
| New Edge/Face from Vertices | चुने हुए वर्टेक्स को एक एज या एक फ़ेस से जोड़ता है। | <kbd>F</kbd> |
| Connect Vertex Path | दो वर्टेक्स के बीच सीधी लाइन में काटता है। | <kbd>J</kbd> |
| Vertex Slide | वर्टेक्स को उनकी एज के साथ-साथ खिसकाता है। | <kbd>Shift+V</kbd> |
| Rip | चयन के साथ-साथ मेश को चीरकर अलग करता है। | <kbd>V</kbd> |
| Duplicate | चुनी हुई चीज़ों की कॉपी बनाता है और उसे पकड़े रखता है। | <kbd>Shift+D</kbd> |
| Separate | चुने हुए फ़ेस को एक नए ऑब्जेक्ट में ले जाता है। | <kbd>P</kbd> |
| Merge | वर्टेक्स को जोड़ता है: At Center, At Cursor, Collapse या By Distance। | <kbd>M</kbd> |
| Auto Merge | मूव पूरा होने पर, जो वर्टेक्स थ्रेशोल्ड से ज़्यादा पास रह गए हों, उन्हें जोड़ देता है। | Mesh मेनू |
| Delete | Vertices, Edges, Faces या Edge Loops। | <kbd>X</kbd> या <kbd>Delete</kbd> |
| Recalculate Normals / Flip | फ़ेस किस तरफ़ देखते हैं, इसे ठीक करता है, या उन्हें उलट देता है। | <kbd>Shift+N</kbd> |
| Triangulate Faces | 3 से ज़्यादा भुजाओं वाले फ़ेस को त्रिकोणों में बाँटता है। | <kbd>Ctrl+T</kbd> |
| Shade Smooth / Shade Flat | सतह पर रोशनी कैसे पड़ती है। | Face मेनू |
| Mark Sharp / Clear Sharp | ऐसी एज जो मेश के स्मूद होने पर भी सख़्त दिखती हैं। | Edge मेनू |
| Mark Seam / Clear Seam | UV अनरैप करते समय मेश कहाँ से कटेगी। | Edge या UV मेनू |
| Context menu | मौजूदा सब-मोड (वर्टेक्स, एज या फ़ेस) के ऑपरेशन, पॉइंटर की जगह पर। | <kbd>W</kbd> या दायाँ क्लिक |
| Insert Keyframe | मौजूदा फ़्रेम में मेश का आकार सेव करता है (वर्टेक्स एनिमेशन)। | <kbd>I</kbd> |

## UV मेनू

| फ़ंक्शन | विवरण | शॉर्टकट |
|---|---|---|
| Unwrap | Angle Based, Conformal या Minimum Stretch: मेश को उसकी सीम से खोलता है। | <kbd>U</kbd> |
| Smart UV Project | फ़ेस के बीच के कोणों के हिसाब से अपने-आप काटता और अनरैप करता है। | <kbd>U</kbd> |
| Lightmap Pack / Follow Active Quads | बिना एक-दूसरे पर चढ़े व्यवस्थित आइलैंड / सक्रिय फ़ेस के हिसाब से व्यवस्थित UV। | <kbd>U</kbd> |
| Cube, Cylinder, Sphere Projection, Project from View | सरल प्रोजेक्शन। | <kbd>U</kbd> |
| Reset | हर फ़ेस पूरी इमेज घेरता है। | <kbd>U</kbd> |

## कर्व (पाथ) एडिट करना

किसी कर्व पर <kbd>Tab</kbd> दबाने से आप उसके नोड ऐसे एडिट कर सकते हैं, जैसे वह पॉइंट्स की एक मेश हो: <kbd>G</kbd> मूव करता है, <kbd>E</kbd> अगला नोड जोड़ता है, <kbd>X</kbd> डिलीट करता है।
