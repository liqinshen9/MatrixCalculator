import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Backend 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    View {
        id: root
        objectName: "view"
        width: window.width
        height: window.height

        Button {
            text: "Button"
            objectName: "ButtonName"
            width:120
            height:30
            font.pointSize:12
            x:300
            y:300
            onPressed: {
                root.message("Hello!!")
            }
        }

    }
}
