CHARACTER_CIFRADO_E_NORMAL = {
    "`":"`",  "1":"`",  "2":"1",  "3":"2",  "4":"3",  "5":"4",  "6":"5",  "7":"6",  "8":"7",  "9":"8",  "0":"9",  "-":"0",  "=":"-",      
    "Q":"Q",  "W":"Q",  "E":"W",  "R":"E",  "T":"R",  "Y":"T",  "U":"Y",  "I":"U",  "O":"I",  "P":"O",  "[":"P",  "]":"[",  "\\":"]",
    "A":"A",  "S":"A",  "D":"S",  "F":"D",  "G":"F",  "H":"G",  "J":"H",  "K":"J",  "L":"K",  ";":"L",  "\'":";",
    "Z":"Z",  "X":"Z",  "C":"X",  "V":"C",  "B":"V",  "N":"B",  "M":"N",  ",":"M",  ".":",",  "/":".",
    " ":" "
}

def ex1196(textoCifrado):
    textoDecifrado = ""

    for i in range(0, len(textoCifrado)):
        if textoCifrado[i] in CHARACTER_CIFRADO_E_NORMAL:
            textoDecifrado += CHARACTER_CIFRADO_E_NORMAL[textoCifrado[i]]
        else:
            textoDecifrado += textoCifrado[i]
    print(textoDecifrado)

while(True):
    try:
        ex1196(input())
    except EOFError:
        break