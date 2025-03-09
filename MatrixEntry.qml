import QtQuick
import QtQuick.Controls

TextField {
    text: "0"
    font.pointSize:14
    maximumLength:8
    implicitWidth:85
    implicitHeight:50
    onFocusChanged: {
        if (focus == true && text == "0") {
            text =""
        }
        if (focus == false && text=="") {
            text = "0"
        }
    }

    background:null
}
