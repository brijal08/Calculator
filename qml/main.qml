import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id:root
    visible: true
    minimumWidth:385
    minimumHeight:421
    title: qsTr("Calculator")
    color: "#fdfdfd"

    Rectangle {
        id: textrect
        width: root.width/1.1
        height: root.height/4
        color: "#00FFFFFF"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: recttext
            text: qsTr("0")
            font.weight: Font.Medium
            verticalAlignment: Text.AlignBottom
            horizontalAlignment: Text.AlignRight
            font.pointSize: (textrect.height+textrect.width)/16
            anchors.bottom: textrect.bottom
            anchors.right: textrect.right
            wrapMode: Text.WordWrap
        }
    }

    Grid{
        id:gridlayout
        spacing: 10
        columns: 4
        rows: 4
        anchors.top: textrect.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        padding: 10
        property var ids:["7","8","9","","4","5","6","-","1","2","3","+","","0","","="]
        Repeater{
            model: gridlayout.ids
            CalculatorButton
            {
                str_id: modelData
                str_bgcolor: ((modelData === "-") || (modelData === "+") || (modelData === "+") || (modelData === "") || (modelData === "=")) ? "#eeeeee" : "#f6f6ff"
                str_hoverbgcolor: "#f5e3e3"
                str_clickbgcolor: "#d3d0d0"
                width: root.width/4.6
                height: root.height/6.3
                i_fontsize: ((root.width/6)+(root.height/8))/5
                b_enable: (str_id === "") ? false : true
                onButtonclicked: recttext.text = ((str_id === "+") && (recttext.text === "0")) ? "0" :
                                                                                                 ((str_id === "-") && (recttext.text === "0")) ? "-" :
                                                                                                                                                 (str_id === "=") ? caluculatorresult.resolveequestion(recttext.text) : recttext.text + str_id
            }
        }
    }
}
