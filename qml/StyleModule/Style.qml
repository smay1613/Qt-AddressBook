pragma Singleton
import QtQuick 2.0

QtObject {
    property bool isDarkTheme: true
    readonly property color primaryColor: isDarkTheme ? "#BB86FC" : "#6200EE"
    readonly property color primaryVariantColor: "#3700B3"
    readonly property color secondaryColor: "#03DAC6"
    readonly property color secondaryVariant: isDarkTheme ? "#018786" : secondaryColor
    readonly property color backgroundColor: isDarkTheme ? "#121212" : "#FFFFFF"
    readonly property color errorColor: isDarkTheme ? "#CF6679" : "#B00020"
    readonly property color textColor: isDarkTheme ? "#FFFFFF" : "#000000"
    readonly property color themeDefaultColor: isDarkTheme ? "#000000" : "#FFFFFF"
    readonly property color themeInvertedColor: isDarkTheme ? "#FFFFFF" : "#000000"

    readonly property real defaultOpacity: 1
    readonly property real emphasisOpacity: 0.87
    readonly property real secondaryOpacity: 0.6
    readonly property real disabledOpacity: 0.38

    readonly property int defaultOffset: 15
    readonly property int mediumOffset: 10
    readonly property int tinyOffset: 5

    readonly property int bigSpacing: 20
    readonly property int mediumSpacing: 10
    readonly property int smallSpacing: 7
}
