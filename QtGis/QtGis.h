#pragma once

#include <QtWidgets/QMainWindow>
#include "DemoRibbonWindow.h"

class QToolButton;
class QTabWidgte;

class QgsMapCanvas;
class QgsDoubleSpinBox;
class QgsStatusBar;
class QProgressBar;
class QgsTaskManagerStatusBarWidget;
class QgsStatusBarCoordinatesWidget;
class QgsStatusBarScaleWidget;
class QgsStatusBarMagnifierWidget;
class QgsDockWidget;
class QgsLayerTreeView;
class QgsLayerTreeMapCanvasBridge;

class QtGis : public DemoRibbonWindow
{
    Q_OBJECT

public:
    QtGis(QWidget *parent = Q_NULLPTR);

    ~QtGis();

    static QtGis* Instance() { return sInstance; }

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;

    void dropEvent(QDropEvent* event) override;
private:
    void createMapCanvas();
    void createActions();
    void createMenuFile();
    void createQuickAccessBar();
    void createRibbonBar();
    void createStatusBar();
    void createDockWidget();
    void createLayerTreeView();

    QList<QgsMapCanvas*> mapCanvases();

    /**
    * Freezes all map canvases (or thaws them if the \a frozen argument is false).
    */
    void freezeCanvases(bool frozen = true);

    QgsMapCanvas* mapCanvas();

private slots:
    void slot_fileSaveAs();
    void slot_fileNew();
    void slot_fileOpen();
    void slot_fileSave();
    void slot_fileClose();
    void slot_fileExit();
    void openRecentFile(const QString& file);
    void updateRecentFileActions(const QStringList&);
    void projectCrsChanged();

    //����ˢ��
      /**
     * @brief slot--������ʼˢ��
    */
    void canvasRefreshStarted();
    /**
     * @brief slot--����ֹͣˢ��
    */
    void canvasRefreshFinished();
    /**
     * @brief ���û�����ת
    */
    void userRotation();
    /**
    * @brief ����״̬���еĵ�ͼ��ת�Ƕ�
    */
    void showRotation();

    /**
     * @brief ˢ�»���
    */
    void refreshMapCanvas(bool redrawAllLayers = false);

    void markDirty();


public slots:
    void slot_addRaterLayer();

    void slot_addVectorLayer();


public:
    bool addRaterLayer(const QStringList&);

    bool addVectorLayer(const QStringList&);

private:

    static QtGis* sInstance;

    //! ��ͼ����
    QgsMapCanvas* mMapCanvas = nullptr;
    //�м�tab�ؼ�
    QTabWidget* mCenterTabWidget = nullptr;
    //״̬��
    QgsStatusBar* mStatusBar = nullptr;
    QProgressBar* mProgressBar = nullptr;
    QgsTaskManagerStatusBarWidget* mTaskManagerWidget = nullptr;
    QgsStatusBarCoordinatesWidget* mCoordsEdit = nullptr;
    QgsStatusBarScaleWidget* mScaleWidget = nullptr;
    QgsStatusBarMagnifierWidget* mMagnifierWidget = nullptr;
    QLabel* mRotationLabel = nullptr;
    QgsDoubleSpinBox* mRotationEdit = nullptr;
    QToolButton* mOnTheFlyProjectionStatusButton = nullptr;

    //Dock
    QgsDockWidget* mAttributeDock = nullptr;
    QgsDockWidget* mLayerMapDock = nullptr;
    QgsLayerTreeView* mLayerTreeView = nullptr;
    QgsLayerTreeMapCanvasBridge* mLayerTreeCanvasBridge = nullptr;

    //Actions Project
    QAction* mFileNew = nullptr;
    QAction* mFileOpen = nullptr;
    QAction* mFileSave = nullptr;
    QAction* mFileSaveAs = nullptr;
    QAction* mFileClose = nullptr;
    QAction* mFileExit = nullptr;

    //Actions Layer
    QAction* mAddRasterLayer = nullptr;
    QAction* mAddVectorLayer = nullptr;

    QString mRasterFileFilter;
    QString mVectorFileFilter;

    class QgsCanvasRefreshBlocker
    {
    public:

        QgsCanvasRefreshBlocker()
        {
            if (QtGis::Instance()->mFreezeCount++ == 0)
            {
                // going from unfrozen to frozen, so freeze canvases
                QtGis::Instance()->freezeCanvases(true);
            }
        }
        QgsCanvasRefreshBlocker(const QgsCanvasRefreshBlocker& other) = delete;
        QgsCanvasRefreshBlocker& operator=(const QgsCanvasRefreshBlocker& other) = delete;

        void release()
        {
            if (mReleased)
                return;

            mReleased = true;
            if (--QtGis::Instance()->mFreezeCount == 0)
            {
                // going from frozen to unfrozen, so unfreeze canvases
                QtGis::Instance()->freezeCanvases(false);
                QtGis::Instance()->refreshMapCanvas();
            }
        }

        ~QgsCanvasRefreshBlocker()
        {
            if (!mReleased)
                release();
        }

    private:

        bool mReleased = false;
    };
    int mFreezeCount = 0;
    friend class QgsCanvasRefreshBlocker;
};
