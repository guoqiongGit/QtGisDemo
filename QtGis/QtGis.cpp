#include "QtGis.h"
#include <QTabWidget>
#include <QProgressBar>
#include <QGridLayout>
#include <QListWidget>
#include <QGroupBox>
#include "QtGisLayerTreeViewMenuProvider.h"

#include "qgsmapcanvas.h"
#include "qgsapplication.h"
#include "qgsstatusbar.h"
#include "qgstaskmanagerwidget.h"
#include "qgsdoublespinbox.h"
#include "qgsdockwidget.h"
#include "QgsLayerTreeView.h"
#include "QgsLayerTreeModel.h"
#include "QgsLayerTreeMapCanvasBridge.h"
#include "QgsLayerTreeRegistryBridge.h"
#include "QgsLayerTree.h"
#include "QgsLayerTreeLayer.h"
#include "QgsLayerTreeViewDefaultActions.h"
#include "QgsLayerTreeUtils.h"

#include "QGISFiles/qgsStatusBarCoordinatesWidget.h"
#include "QGISFiles/qgsstatusbarscalewidget.h"
#include "QGISFiles/qgsstatusbarmagnifierwidget.h"

QtGis* QtGis::sInstance = nullptr;
QtGis::QtGis(QWidget *parent)
    : DemoRibbonWindow(parent)
{
    sInstance = this;
	//设置软件title
    setWindowTitle(QStringLiteral("QtGis"));
	//创建地图画布
    createMapCanvas();
	//创建QAction
    createActions();
	//创建菜单
    createMenuFile();
	//创建快速访问按钮
    createQuickAccessBar();
	//创建RibbonPage并添加QAction
    createRibbonBar();

	QgsProject::instance()->setCrs(QgsCoordinateReferenceSystem("EPSG:4326"));
	createDockWidget();
	createLayerTreeView();
	setAcceptDrops(true);

}

QtGis::~QtGis()
{
}

void QtGis::dragEnterEvent(QDragEnterEvent* event)
{
}

void QtGis::dropEvent(QDropEvent* event)
{
}

void QtGis::createMapCanvas()
{
	//创建一个QTabWidget
    mCenterTabWidget = new QTabWidget(this);
	//创建一个画布
    mMapCanvas = new QgsMapCanvas();
    mMapCanvas->setObjectName("mapCanvas");
	//设置画布背景色、选中色、缓存、更新间隔等属性
    mMapCanvas->setPreviewJobsEnabled(true);
    mMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mMapCanvas->setSelectionColor(QColor(0, 255, 255));
    mMapCanvas->setProject(QgsProject::instance());
    mMapCanvas->setParallelRenderingEnabled(true);
    mMapCanvas->setCachingEnabled(true);
    mMapCanvas->setMapUpdateInterval(250);

    // set project linked to main canvas
    mMapCanvas->setProject(QgsProject::instance());
	//将画布添加在创建的QTabWidget控件mCenterTabWidget中
    mCenterTabWidget->addTab(mMapCanvas, "Map View");
    mCenterTabWidget->tabBar()->setTabButton(mCenterTabWidget->indexOf(mMapCanvas), QTabBar::RightSide, nullptr) ;
	//设置该QTabWidget控件mCenterTabWidget展示在窗体的中间
    setCentralWidget(mCenterTabWidget);
    mMapCanvas->setFocus();
}

void QtGis::createActions()
{
    mFileNew = new QAction(DemoRibbonWindow::createIcon(Image_New),tr("New"));
    mFileNew->setToolTip(QStringLiteral("New File"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileNew()));

    mFileOpen = new QAction(DemoRibbonWindow::createIcon(Image_Open),tr("Open"));
    mFileOpen->setToolTip(QStringLiteral("Open File"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileOpen()));

    mFileSave = new QAction(DemoRibbonWindow::createIcon(Image_Save),tr("Save"));
    mFileSave->setToolTip(QStringLiteral("Save File"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileSave()));

    mFileSaveAs = new QAction(DemoRibbonWindow::createIcon(Image_SaveAs), tr("Save As"));
    mFileSaveAs->setToolTip(QStringLiteral("Save File As"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileSaveAs()));

    mFileClose = new QAction(DemoRibbonWindow::createIcon(Image_Close), tr("Close"));
    mFileClose->setToolTip(QStringLiteral("Close File"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileClose()));

    mFileExit = new QAction(DemoRibbonWindow::createIcon(Image_Exit), tr("Exit"));
    connect(mFileSaveAs, SIGNAL(triggered()), this, SLOT(slot_fileExit()));

    mAddRasterLayer = new QAction(DemoRibbonWindow::createIcon(Add_RasterLayer), tr("Add Raster Layer"));
    connect(mAddRasterLayer, SIGNAL(triggered()), this, SLOT(slot_addRaterLayer()));

    mAddVectorLayer = new QAction(DemoRibbonWindow::createIcon(Add_VectorLayer), tr("Add Vector Layer"));
    connect(mAddVectorLayer, SIGNAL(triggered()), this, SLOT(slot_addVectorLayer()));
    
}

void QtGis::createMenuFile()
{
    QIcon iconLogo;
    iconLogo.addPixmap(QPixmap(QStringLiteral(":/QtGis/images/qtitanlogo32x32.png")));
	//添加Project菜单
    QAction* actionFile = ribbonBar()->addSystemButton(iconLogo, tr("&Project"));
    ribbonBar()->systemButton()->setToolButtonStyle(Qt::ToolButtonTextOnly);
    actionFile->setToolTip(tr("Click here to see everything you can do with your document"));
    RibbonSystemMenu* systemMenu = qobject_cast<RibbonSystemMenu*>(actionFile->menu());
	//在菜单下添加相应的按钮
    systemMenu->addAction(mFileNew);
    systemMenu->addAction(mFileOpen);
    systemMenu->addAction(mFileSave);
    systemMenu->addAction(mFileSaveAs);
    systemMenu->addAction(mFileClose);
    systemMenu->addAction(mFileExit);
	//在菜单下最近打开的工程列表控件
    RibbonPageSystemRecentFileList* pageRecentFile = systemMenu->addPageRecentFile(QStringLiteral("Recent Maps"));
	//设置最多展示已打开的9个工程
    pageRecentFile->setSize(9);
	//绑定槽函数
    connect(pageRecentFile, SIGNAL(openRecentFile(const QString&)), this, SLOT(openRecentFile(const QString&)));
    connect(this, SIGNAL(updateRecentFileActions(const QStringList&)), pageRecentFile, SLOT(updateRecentFileActions(const QStringList&)));
}

void QtGis::createQuickAccessBar()
{
    RibbonQuickAccessBar* quickAccessBar = ribbonBar()->quickAccessBar();
    QAction* action = quickAccessBar->actionCustomizeButton();
    action->setToolTip(tr("Customize Quick Access Bar"));

    QAction* smallButton = quickAccessBar->addAction(DemoRibbonWindow::createIcon(Image_Open), QStringLiteral("Open Project"));
    smallButton->setToolTip(QStringLiteral("Open Project"));
    connect(smallButton, SIGNAL(triggered()), this, SLOT(slot_fileOpen()));

    smallButton = quickAccessBar->addAction(DemoRibbonWindow::createIcon(Image_Save), QStringLiteral("Save Project"));
    smallButton->setToolTip(QStringLiteral("Save Project"));
    connect(smallButton, SIGNAL(triggered()), this, SLOT(slot_fileSave()));

    quickAccessBar->setVisible(true);
}

void QtGis::createRibbonBar()
{
	//创建page Layer
    RibbonPage* pageFile = ribbonBar()->addPage(tr("&Layer"));
	//创建分组 Layer
    RibbonGroup* layerGroup = pageFile->addGroup(QStringLiteral("Layer"));
	//在分组 Layer下添加按钮
    layerGroup->addAction(mAddRasterLayer, Qt::ToolButtonTextUnderIcon);
    layerGroup->addAction(mAddVectorLayer, Qt::ToolButtonTextUnderIcon);

    ribbonBar()->setFrameThemeEnabled();
}

void QtGis::createStatusBar()
{
	QFont statusBarFont = font();
	int fontSize = statusBarFont.pointSize();
	fontSize = std::max(fontSize - 1, 8);
	statusBarFont.setPointSize(fontSize);
	statusBar()->setFont(statusBarFont);

	mStatusBar = new QgsStatusBar();
	// mStatusBar->setParentStatusBar(QMainWindow::statusBar());
	mStatusBar->setFont(statusBarFont);
	statusBar()->addPermanentWidget(mStatusBar, 10);

	// Add a panel to the status bar for the scale, coords and progress
  // And also rendering suppression checkbox
	mProgressBar = new QProgressBar(mStatusBar);
	mProgressBar->setObjectName(QStringLiteral("mProgressBar"));
	mProgressBar->setMaximumWidth(100);
	mProgressBar->setMaximumHeight(18);
	mProgressBar->hide();
	mStatusBar->addPermanentWidget(mProgressBar, 1);

	//建立画布与状态栏进度条之间的信号槽
	connect(mMapCanvas, &QgsMapCanvas::renderStarting, this, &QtGis::canvasRefreshStarted);
	connect(mMapCanvas, &QgsMapCanvas::mapCanvasRefreshed, this, &QtGis::canvasRefreshFinished);

	mTaskManagerWidget = new QgsTaskManagerStatusBarWidget(QgsApplication::taskManager(), mStatusBar);
	mTaskManagerWidget->setFont(statusBarFont);
	mStatusBar->addPermanentWidget(mTaskManagerWidget, 0);

	//coords status bar widget
	mCoordsEdit = new QgsStatusBarCoordinatesWidget(mStatusBar);
	mCoordsEdit->setObjectName(QStringLiteral("mCoordsEdit"));
	mCoordsEdit->setMapCanvas(mMapCanvas);
	mCoordsEdit->setFont(statusBarFont);
	mStatusBar->addPermanentWidget(mCoordsEdit, 0);

	mScaleWidget = new QgsStatusBarScaleWidget(mMapCanvas, mStatusBar);
	mScaleWidget->setObjectName(QStringLiteral("mScaleWidget"));
	mScaleWidget->setFont(statusBarFont);
	mStatusBar->addPermanentWidget(mScaleWidget, 0);

	// zoom widget
	mMagnifierWidget = new QgsStatusBarMagnifierWidget(mStatusBar);
	mMagnifierWidget->setObjectName(QStringLiteral("mMagnifierWidget"));
	mMagnifierWidget->setFont(statusBarFont);
	connect(mMapCanvas, &QgsMapCanvas::magnificationChanged, mMagnifierWidget, &QgsStatusBarMagnifierWidget::updateMagnification);
	connect(mMagnifierWidget, &QgsStatusBarMagnifierWidget::magnificationChanged, mMapCanvas, [=](double factor) { mMapCanvas->setMagnificationFactor(factor); });
	connect(mMagnifierWidget, &QgsStatusBarMagnifierWidget::scaleLockChanged, mMapCanvas, &QgsMapCanvas::setScaleLocked);
	connect(mMagnifierWidget, &QgsStatusBarMagnifierWidget::scaleLockChanged, mScaleWidget, &QgsStatusBarScaleWidget::setLocked);
	mMagnifierWidget->updateMagnification(QSettings().value(QStringLiteral("/qgis/magnifier_factor_default"), 1.0).toDouble());
	mStatusBar->addPermanentWidget(mMagnifierWidget, 0);

	// add a widget to show/set current rotation
	mRotationLabel = new QLabel(QString(), mStatusBar);
	mRotationLabel->setObjectName(QStringLiteral("mRotationLabel"));
	mRotationLabel->setFont(statusBarFont);
	mRotationLabel->setMinimumWidth(10);
	//mRotationLabel->setMaximumHeight( 20 );
	mRotationLabel->setMargin(3);
	mRotationLabel->setAlignment(Qt::AlignCenter);
	mRotationLabel->setFrameStyle(QFrame::NoFrame);
	mRotationLabel->setText(tr("Rotation"));
	mRotationLabel->setToolTip(tr("Current clockwise map rotation in degrees"));
	mStatusBar->addPermanentWidget(mRotationLabel, 0);

	mRotationEdit = new QgsDoubleSpinBox(mStatusBar);
	mRotationEdit->setObjectName(QStringLiteral("mRotationEdit"));
	mRotationEdit->setClearValue(0.0);
	mRotationEdit->setKeyboardTracking(false);
	mRotationEdit->setMaximumWidth(120);
	mRotationEdit->setDecimals(1);
	mRotationEdit->setRange(-360.0, 360.0);
	mRotationEdit->setWrapping(true);
	mRotationEdit->setSingleStep(5.0);
	mRotationEdit->setFont(statusBarFont);
	mRotationEdit->setSuffix(tr("degree"));
	mRotationEdit->setToolTip(tr("Current clockwise map rotation in degrees"));
	mStatusBar->addPermanentWidget(mRotationEdit, 0);
	connect(mRotationEdit, static_cast <void (QgsDoubleSpinBox::*)(double)> (&QgsDoubleSpinBox::valueChanged), this, &QtGis::userRotation);

	showRotation();


	mOnTheFlyProjectionStatusButton = new QToolButton(mStatusBar);
	mOnTheFlyProjectionStatusButton->setAutoRaise(true);
	mOnTheFlyProjectionStatusButton->setFont(statusBarFont);
	mOnTheFlyProjectionStatusButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	mOnTheFlyProjectionStatusButton->setObjectName(QStringLiteral("mOntheFlyProjectionStatusButton"));

	mOnTheFlyProjectionStatusButton->setMaximumHeight(mScaleWidget->height());
	mOnTheFlyProjectionStatusButton->setIcon(QgsApplication::getThemeIcon(QStringLiteral("mIconProjectionEnabled.svg")));
	connect(QgsProject::instance(), &QgsProject::crsChanged, this, &QtGis::projectCrsChanged);
	mStatusBar->addPermanentWidget(mOnTheFlyProjectionStatusButton, 0);
	mStatusBar->showMessage(tr("Ready"));



}

void QtGis::createDockWidget()
{
	//新建图层QgsDockWidget
	mLayerMapDock = new QgsDockWidget(this);
	mLayerMapDock->setWindowTitle(tr("Layer Maps"));
	mLayerMapDock->setObjectName(QStringLiteral("LayerMaps"));
	//将图层QgsDockWidget 添加在左侧展示
	addDockWidget(Qt::LeftDockWidgetArea, mLayerMapDock);

	mAttributeDock = new QgsDockWidget(this);
	mAttributeDock->setWindowTitle(tr("Object Attribute"));
	mAttributeDock->setObjectName(QStringLiteral("ObjectAttribute"));
	addDockWidget(Qt::RightDockWidgetArea, mAttributeDock);

}

void QtGis::createLayerTreeView()
{
	//新建图层树形控件
	mLayerTreeView = new QgsLayerTreeView(this);
	mLayerTreeView->setObjectName(QStringLiteral("theLayerTreeView"));

	//创建QgsLayerTreeModel 实例,并允许用户通过点选复选框手动隐藏/显示图层
	QgsLayerTreeModel* model = new QgsLayerTreeModel(QgsProject::instance()->layerTreeRoot(), this);
	model->setFlag(QgsLayerTreeModel::AllowNodeChangeVisibility);
	model->setFlag(QgsLayerTreeModel::AllowNodeReorder);
	model->setFlag(QgsLayerTreeModel::AllowNodeRename);
	model->setFlag(QgsLayerTreeModel::ShowLegendAsTree);
	model->setFlag(QgsLayerTreeModel::UseEmbeddedWidgets);
	model->setFlag(QgsLayerTreeModel::UseTextFormatting);
	model->setAutoCollapseLegendNodes(10);

	//将View视图与Model数据绑定
	mLayerTreeView->setModel(model);

	//将工程实例中的图层根节点与画布绑定，实现与地图画布控件的数据交互
	mLayerTreeCanvasBridge = new QgsLayerTreeMapCanvasBridge(QgsProject::instance()->layerTreeRoot(), mMapCanvas, this);

	//添加图层组
	QAction* addGroup = new QAction(tr("Add Group"), this);
	addGroup->setIcon(createIcon(Add_Group));
	addGroup->setToolTip(tr("Add Group"));
	connect(addGroup, &QAction::triggered, mLayerTreeView->defaultActions(), &QgsLayerTreeViewDefaultActions::addGroup);
	//展开所有图层组
	QAction* actionExpandAll = new QAction(tr("Expand All"), this);
	actionExpandAll->setIcon(createIcon(Expand_All));
	actionExpandAll->setToolTip(tr("Expand All"));
	connect(actionExpandAll, &QAction::triggered, mLayerTreeView, &QgsLayerTreeView::expandAllNodes);
	//折叠所有图层组
	QAction* actionCollapseAll = new QAction(tr("Collapse All"), this);
	actionCollapseAll->setIcon(createIcon(Collapse_All));
	actionCollapseAll->setToolTip(tr("Collapse All"));
	connect(actionCollapseAll, &QAction::triggered, mLayerTreeView, &QgsLayerTreeView::collapseAllNodes);

	QToolBar* toolbar = new QToolBar(this);
	toolbar->setIconSize(QSize(16, 16));
	toolbar->addAction(addGroup);
	toolbar->addAction(actionExpandAll);
	toolbar->addAction(actionCollapseAll);

	QVBoxLayout* vboxLayout = new QVBoxLayout;
	vboxLayout->setContentsMargins(0, 0, 0, 0);
	vboxLayout->setSpacing(0);
	vboxLayout->addWidget(toolbar);
	vboxLayout->addWidget(mLayerTreeView);

	QWidget* w = new QWidget;
	w->setLayout(vboxLayout);

	//设置点击右键出现菜单项
	mLayerTreeView->setMenuProvider(new QtGisLayerTreeViewMenuProvider(mLayerTreeView, mMapCanvas));

	//将View添加到左侧的Dock控件中展示
	mLayerMapDock->setWidget(w);

	connect(mLayerTreeView, &QgsLayerTreeView::currentLayerChanged, this, &QtGis::onActiveLayerChanged);
	connect(QgsProject::instance()->layerTreeRegistryBridge(), &QgsLayerTreeRegistryBridge::addedLayersToLayerTree, this, &QtGis::autoSelectAddedLayer);
}

QList<QgsMapCanvas*> QtGis::mapCanvases()
{
	auto canvases = findChildren< QgsMapCanvas* >();
	canvases.erase(std::remove_if(canvases.begin(), canvases.end(),
		[](QgsMapCanvas* canvas)
		{
			return !canvas || canvas->property("browser_canvas").toBool();
		}), canvases.end());
	return canvases;
}

void QtGis::freezeCanvases(bool frozen)
{
	const auto canvases = mapCanvases();
	for (QgsMapCanvas* canvas : canvases)
	{
		canvas->freeze(frozen);
	}
}

QgsMapCanvas* QtGis::mapCanvas()
{
	return mMapCanvas;
}

void QtGis::refreshMapCanvas(bool redrawAllLayers)
{
	const auto canvases = mapCanvases();
	for (QgsMapCanvas* canvas : canvases)
	{
		//stop any current rendering
		canvas->stopRendering();
		if (redrawAllLayers)
			canvas->refreshAllLayers();
		else
			canvas->refresh();
	}
}

void QtGis::markDirty()
{
	QgsProject::instance()->setDirty(true);
}

void QtGis::onActiveLayerChanged(QgsMapLayer* layer)
{
	const QList< QgsMapCanvas* > canvases = mapCanvases();
	for (QgsMapCanvas* canvas : canvases)
		canvas->setCurrentLayer(layer);
	//TODO emit activeLayerChanged
}

void QtGis::autoSelectAddedLayer(QList<QgsMapLayer*> layers)
{
	if (!layers.isEmpty()) {
		QgsLayerTreeLayer* nodeLayer = QgsProject::instance()->layerTreeRoot()->findLayer(layers[0]->id());
		if (!nodeLayer)
			return;
		auto index = mLayerTreeView->layerTreeModel()->node2index(nodeLayer);
		mLayerTreeView->setCurrentIndex(index);
	}
}

void QtGis::updateNewLayerInsertionPoint()
{
	QgsLayerTreeGroup* insertGroup = mLayerTreeView->layerTreeModel()->rootGroup();
	QModelIndex current = mLayerTreeView->currentIndex();
	int index = 0;
	QgsLayerTreeRegistryBridge::InsertionPoint insertionPoint = QgsLayerTreeRegistryBridge::InsertionPoint(insertGroup, index);;

	if (current.isValid())
	{
		index = current.row();

		QgsLayerTreeNode* currentNode = mLayerTreeView->currentNode();
		if (currentNode)
		{
			// if the insertion point is actually a group, insert new layers into the group
			if (QgsLayerTree::isGroup(currentNode))
			{
				// if the group is embedded go to the first non-embedded group, at worst the top level item
				QgsLayerTreeGroup* insertGroup = QgsLayerTreeUtils::firstGroupWithoutCustomProperty(QgsLayerTree::toGroup(currentNode), QStringLiteral("embedded"));

				insertionPoint = QgsLayerTreeRegistryBridge::InsertionPoint(insertGroup, 0);
			}
			else {
				// otherwise just set the insertion point in front of the current node
				QgsLayerTreeNode* parentNode = currentNode->parent();
				if (QgsLayerTree::isGroup(parentNode))
				{
					// if the group is embedded go to the first non-embedded group, at worst the top level item
					QgsLayerTreeGroup* parentGroup = QgsLayerTree::toGroup(parentNode);
					insertGroup = QgsLayerTreeUtils::firstGroupWithoutCustomProperty(parentGroup, QStringLiteral("embedded"));
					if (parentGroup != insertGroup)
						index = 0;
				}
				insertionPoint = QgsLayerTreeRegistryBridge::InsertionPoint(insertGroup, index);
			}
		}
	}
	QgsProject::instance()->layerTreeRegistryBridge()->setLayerInsertionPoint(insertionPoint);
}

void QtGis::slot_fileNew()
{
}

void QtGis::slot_fileOpen()
{
}

void QtGis::slot_fileSave()
{
}

void QtGis::slot_fileClose()
{
}

void QtGis::slot_fileExit()
{
}

void QtGis::openRecentFile(const QString& file)
{
}

void QtGis::updateRecentFileActions(const QStringList&)
{
}


void QtGis::projectCrsChanged()
{
}

void QtGis::canvasRefreshStarted()
{
}

void QtGis::canvasRefreshFinished()
{
}

void QtGis::userRotation()
{
}

void QtGis::showRotation()
{
}

void QtGis::slot_fileSaveAs()
{
}
