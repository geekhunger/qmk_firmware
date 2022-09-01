# Mein persönliches Kinesis Advantage2 (KB600) Keymap.

Dieses Keymap ist für MacOS und Windows gedacht und hat daher zwei default Layers. Darüberhinaus gibt es ein drittes Layer, das ein Numpad enthält. Ich bin kein Freund von vielen Layern und möchte alles am besten in einem einzigen Layer unterbringen und leicht von der Homrow erreichen.

Es gibt zwei Besonderheiten.

1. Ich habe meine Verkabelung bei den FN-Tasten (1-8) verckackt. Da ich kein Elektroniker bin, konnte ich Dummie den Fehler nicht finden und hab es daher einfach in meinem Mapping softwareseitig gefixt^^
2. Mein Mapping funktioniert nur auf Computern, die deusches Layout im System eingestellt haben. (Daher ist beispielsweise im Keymap Z und Y vertausch, da es aus dem Englischen so passt.)

# Layout kompilieren und flashen

Die Firmware (inklusive keyboard schema und keyboard layout) wird kompiliert mittels `./bin/qmk compile` oder `bin/qmk compile -kb kinesis/kint36 -km herrsch`. Das Resultat ist eien .bin und eine .hex Datei im `.build/` Ordner. (Für die Tastatur brauchen wir jedoch nur die HEX, also zB '.build/kinesis_kint36_herrsch.hex`.)

Die neue Firmware muss anschließend mittels `bin/qmk flash` auf das Teensy 3.6 Board übertragen werden. Sobald der Hinweis kommt, einfach den Reset Button am Teensy Board drücken. Die Firmware wird automatisch geflasht und die Tastatur neugestartet. Fertig.