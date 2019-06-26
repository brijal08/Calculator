import QtQuick 2.0

Item {
    id:calculatorbutton
    property string str_id
    property string str_bgcolor
    property string str_hoverbgcolor
    property string str_clickbgcolor
    property int i_fontsize
    property bool b_enable: false

    signal buttonclicked
    signal buttonclicke(int value, string xyz)

    Rectangle {
        id: rect
        width: parent.width
        height: parent.height
        color: calculatorbutton.str_bgcolor
        radius: 5
        Text {
            id: recttext
            text: qsTr(calculatorbutton.str_id)
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: calculatorbutton.i_fontsize
            anchors.centerIn: rect
        }
        MouseArea {
            anchors.fill: rect
            hoverEnabled: calculatorbutton.b_enable
            onEntered: {
                rect.scale = 1.1
                rect.color = calculatorbutton.str_hoverbgcolor
            }
            onExited: {
                rect.scale = 1
                rect.color = calculatorbutton.str_bgcolor
            }
            onPressed :{
                rect.scale = calculatorbutton.b_enable ? 0.9 : 1
                rect.color = calculatorbutton.b_enable ? calculatorbutton.str_clickbgcolor : calculatorbutton.str_bgcolor
            }
            onReleased: {
                rect.scale = calculatorbutton.b_enable ? 1.1 : 1
                rect.color = calculatorbutton.b_enable ? calculatorbutton.str_hoverbgcolor : calculatorbutton.str_bgcolor
                calculatorbutton.b_enable ? buttonclicked() : console.log("empty string")
            }
        }
    }
}
