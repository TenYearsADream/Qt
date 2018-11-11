#include <cmath>
#include "plotsettings.h"

PlotSettings::PlotSettings()
{
    minX = 0.0;
    maxX = 10.0;
    numXTicks = 5;

    minY = 0.0;
    maxY = 10.0;
    numYTicks = 5;
}

void PlotSettings::scroll(int dx, int dy)
{
    double stepX = spanX() / numXTicks;
    minX += dx * stepX;
    maxX += dx * stepX;

    double stepY = spanY() / numYTicks;
    minY += dy * stepY;
    maxY += dy * stepY;
}

void PlotSettings::adjust()
{
    adjustAxis(minX, maxX, numXTicks);
    adjustAxis(minY, maxY, numYTicks);
}

double PlotSettings::spanX() const
{
    return maxX - minX;
}

double PlotSettings::spanY() const
{
    return maxY - minY;
}

void PlotSettings::adjustAxis(double& min, double& max, int& numTIcks)
{
    const int MinTicks = 4;
    double grossStep = (max - min) / MinTicks;
    double step = std::pow(10.0, std::floor(std::log10(grossStep)));

    if (5 * step < grossStep) {
        step *= 5;
    } else if (2 * step < grossStep) {
        step *= 2;
    }

    numTIcks = static_cast<int>(std::ceil(max / step) - std::floor(min / step));
    if (numTIcks < MinTicks) {
        numTIcks = MinTicks;
    }
    min = std::floor(min / step) * step;
    max = std::ceil(max / step) * step;
}
