#include "QtGisLayerTreeViewMenuProvider.h"
#include "qmenu.h"

#include "QgsLayerTreeView.h"
#include "QgsMapCanvas.h"
#include "QgsLayerTreeNode.h"
#include "QgsLayerTree.h"
#include "QgsVectorLayer.h"
#include "QgsLayerTreeViewDefaultActions.h"

QtGisLayerTreeViewMenuProvider::QtGisLayerTreeViewMenuProvider(QgsLayerTreeView* layerTreeView, QgsMapCanvas* mapCanvas)
	:QgsLayerTreeViewMenuProvider()
	, mMapCanvas(mapCanvas)
	, mView(layerTreeView)
{
}

QtGisLayerTreeViewMenuProvider::~QtGisLayerTreeViewMenuProvider()
{
}

QMenu* QtGisLayerTreeViewMenuProvider::createContextMenu()
{
	QMenu* menu = new QMenu;
	QModelIndex index = mView->currentIndex();
	if (!index.isValid()) return nullptr;
	QgsLayerTreeNode* node = mView->index2node(index);
	if (QgsLayerTree::isGroup(node)) {
		menu->addAction(mView->defaultActions()->actionRemoveGroupOrLayer(menu));
		menu->addAction(mView->defaultActions()->actionRenameGroupOrLayer(menu));
	}
	else if(QgsLayerTree::isLayer(node)){
		QgsMapLayer* layer = QgsLayerTree::toLayer(node)->layer();
		if (layer) {
			menu->addAction(mView->defaultActions()->actionZoomToLayer(mMapCanvas,menu));
			menu->addAction(mView->defaultActions()->actionRemoveGroupOrLayer(menu));
			menu->addAction(mView->defaultActions()->actionRenameGroupOrLayer(menu));
		}
		QgsVectorLayer* vLayer = qobject_cast<QgsVectorLayer*>(layer);
		if (vLayer) {
			menu->addAction(mView->defaultActions()->actionShowFeatureCount(menu));
		}
	}

	return menu;
}
