#ifndef PLOTSETTINGS_H
#define PLOTSETTINGS_H

class PlotSettings {
public:
    PlotSettings();

    void scroll(int dx, int dy);
    void adjust();
    double spanX() const;
    double spanY() const;

    double minX;
    double maxX;
    int numXTicks;
    double minY;
    double maxY;
    int numYTicks;

private:
    static void adjustAxis(double& min, double& max, int& numTIcks);
};

#endif // PLOTSETTINGS_H
