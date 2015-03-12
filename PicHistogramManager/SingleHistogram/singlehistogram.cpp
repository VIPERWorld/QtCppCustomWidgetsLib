#include <iostream>
#include <math.h>
#include <assert.h>

#include "qcpxonedirslidingrect.h"
#include "singlehistogram.h"
#include "ui_singlehistogram.h"


SingleHistogram::SingleHistogram(QWidget *parent) :
    QCustomPlot(parent)
{
    // Init histograms
    initPlot();
    initBorders();

    // Todo: implement zoom in the plot
    // setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

SingleHistogram::~SingleHistogram()
{

}

void SingleHistogram::updateCoord(QCPXOneDirSlidingRect *rect, int newCoord)
{
    if (rect == leftRect) {
        leftBorderCoord = newCoord;
        rightRect->setMin(leftBorderCoord);
        emit newMinFromHist(newCoord);
    }
    else if (rect == rightRect)
    {
        rightBorderCoord = newCoord;
        leftRect->setMax(rightBorderCoord);
        emit newMaxFromHist(newCoord);
    }
    else
        assert(false);
}

int SingleHistogram::getUserInputMin()
{
    return leftRect->getXCoord();
}

int SingleHistogram::getUserInputMax()
{
    return rightRect->getXCoord();
}

void SingleHistogram::setUserInputMin(int value)
{
    leftRect->setXCoord(value);
    replot();
}

void SingleHistogram::setUserInputMax(int value)
{
    rightRect->setXCoord(value);
    replot();
}


void SingleHistogram::initPlot()
{

    // Deal with axes *******************************
    addGraph();
    xAxis->setRange(-20, 275);
    yAxis->setRange(0, 1);
    yAxis2->setVisible(true);

    for (auto axe : {xAxis, yAxis, yAxis2})
    {
        // Disable ticks
        axe->setTicks(false);
        axe->setTickLabels(false);

        // Disable grid
        axe->grid()->setVisible(false);
    }

    // Margins **************************************
    // TODO: FIXME
//        QCPAxisRect * axeRect = axisRect();
//        const QMargins * zeroMargin = new QMargins(0, 0, 0, 0);
//        //axeRect->setMargins(*zeroMargin);
//        axeRect()->setMargins(*zeroMargin);
//        delete zeroMargin;

    replot();
}

void SingleHistogram::initBorders()
{
    // Left rectangle
    leftRect  = new QCPXOneDirSlidingRect(
                this, -7000, 7000, 0, -7000, 0, 255,
                mainCoord::rightX, xAxis);
    leftBorderCoord = 0;
    initBorder(leftRect);

    // Right rectangle
    rightRect  = new QCPXOneDirSlidingRect(
                this, 255, 7000, 7000, -7000, 0, 255,
                mainCoord::leftX, xAxis);
    rightBorderCoord = 255;
    initBorder(rightRect);
}

void SingleHistogram::initBorder(QCPXOneDirSlidingRect *rect)
{
    this->addItem(rect);
    // Create fill pattern
    const QBrush * brush = new QBrush(Qt::darkGray);
    rect->setBrush(*brush);
}
