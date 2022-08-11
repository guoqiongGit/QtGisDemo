#pragma once
#include "qgslayertreeview.h"

class QgsMapCanvas;

class QtGisLayerTreeViewMenuProvider :
    public QgsLayerTreeViewMenuProvider
{
public:
    QtGisLayerTreeViewMenuProvider(QgsLayerTreeView* layerTreeView, QgsMapCanvas* mapCanvas);

    ~QtGisLayerTreeViewMenuProvider();

    virtual QMenu* createContextMenu() override;

private:
    QgsMapCanvas* mMapCanvas;

    QgsLayerTreeView* mView;
};

