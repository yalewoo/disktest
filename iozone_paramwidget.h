#ifndef IOZONE_PARAMWIDGET_H
#define IOZONE_PARAMWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSettings>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include <cmath>


#define FILESYS_TYPE_RAMFS 0
#define FILESYS_TYPE_OBFS 1
#define FILESYS_TYPE_PMFS 2

struct iozoneParamStruct{
    /*设置参数*/
    int iFileSize;
    bool bFlaga;
    bool bFlags;
    bool bFlagi0;
    bool bFlagi1;
    bool bFlagi2;
    bool *pbFlagRun;
    QString qsFileName;
    QString qsDevDir;
    QString qsMntDir;
    QString qsFsType;/* 文件系统类型 */
};

class iozoneParamWidget : public QWidget
{
    Q_OBJECT
public:
    iozoneParamWidget(QWidget *parent = 0);
    struct iozoneParamStruct * getParamData(int);

    void setRunFlag(bool);/* 向iozoneWidget类提供设置运行状态接口 */
    bool getRunFlag(void) { return bFlagRun; }
    int getTotalTimes(void) { return iTotalTimes; }

public slots:
    void onFileSizeChanged(int);
    void onConfigDirClicked(void);

private:
    QLabel labelFileSize;
    QSlider sliderFileSize;
    QSettings *qsetConfig; /* 配置信息 */
    QLineEdit lineConfigDir;
    QPushButton btnConfigDir;

    int iFileSize;
    /* iTotalTimes: 需要进行测试的次数(以iozone中不同reclen来计,主要用来控制进度条) */
    int iTotalTimes;
    bool bFlaga;
    bool bFlags;
    bool bFlagi0;
    bool bFlagi1;
    bool bFlagi2;
    bool bFlagRun; /* 正在执行 点击start时变true thread中iozoneMain执行完后变false */
    QString qsRamfsFileName;
    QString qsRamfsDevDir;/* 设备路径 */
    QString qsRamfsMntDir;/* 挂载路径 */
    QString qsRamfsFsType;/* 文件系统类型 */
    QString qsObfsFileName;
    QString qsObfsDevDir;
    QString qsObfsMntDir;
    QString qsObfsFsType;
    QString qsPmfsFileName;
    QString qsPmfsDevDir;
    QString qsPmfsMntDir;
    QString qsPmfsFsType;
    QString qsConfigDir; //配置文件的路径
};

#endif // IOZONE_PARAMWIDGET_H

