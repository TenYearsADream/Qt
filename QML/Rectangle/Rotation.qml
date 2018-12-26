import QtQuick 2.0

Rectangle{
    width: 100;
    height: 100;
    rotation: 90;
    gradient: Gradient{
        GradientStop {
            position: 0.0;
            color: "#202020"
        }
        GradientStop{
            position: 1.0;
            color: "#A0A0A0";
        }
    }
}
