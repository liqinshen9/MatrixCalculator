import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Backend 1.0
import Paint 1.0

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

        Text {//cannot be edited
            id: prompt //name within qml
            text: "Dimensions: " //the text in Text
            font.pointSize:14
            x:30
            y:30
        }

        TextField {//can be edited
            objectName: "n_dimension"
            text: "2"
            x:150
            y:30
            width:40
            height:30
            font.pointSize:14
            maximumLength:2
            background:Rectangle {color:"#f5f5f5"}
        }
        Text {
            text: "X"
            font.pointSize:14
            x:200
            y:30
        }
        TextField {
            objectName: "m_dimension"
            text: "2"
            x:220
            y:30
            width:40
            height:30
            font.pointSize:14
            maximumLength:2
            background: Rectangle {color:"#f5f5f5"}
        }

        Button {
            text: "Apply"
            width:50
            height:30
            font.pointSize:12
            x:280
            y:30
            onPressed: {
                root.message("apply_dimensions")
            }
        }

        Button {
            text: "Toggle Scalars"
            width:120
            height:30
            font.pointSize:12
            x:340
            y:30
            onPressed: {
                root.message("toggle_scalars")
            }
        }

        MatrixBackground {
            id:matrixbg
            x:100
            y:120
            width:200
            height:200
        }

        Button {
            text: "Row Reduce"
            width:150
            height:50
            font.pointSize:14
            x:347
            y:350
            onPressed: {
                root.message("row_reduce")
            }
        }

        Button {
            text:"Solve"
            width:100
            height:50
            font.pointSize:14
            x:500
            y:350
            onPressed: {
                root.message("solve")
            }
        }


    }
}
