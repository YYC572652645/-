#ifndef SchoolRoolSELECT_H
#define SchoolRoolSELECT_H
#include "SchoolRoll/SchoolRoolinsert.h"
#include "MessageBox/messagedialog.h"
#include <QWidget>
#include <QProgressBar>
#include <QStatusBar>
#include <QAxObject>
#include <QFileDialog>
#include <QThread>
namespace Ui {
class SchoolRoolselect;
}

class SchoolRoolSelect : public QWidget
{
    Q_OBJECT
    friend class SchoolRoolThread;
public:
    explicit SchoolRoolSelect(QWidget *parent = 0);
    ~SchoolRoolSelect();

private:
    Ui::SchoolRoolselect *ui;
public:
    SchoolRoolDataBase *SchoolRool; //数据库对象
public:

    /********************查询学号*****************/
    void numerSelect(QString number);


    /********************查询姓名*****************/
    void nameSelect(QString name);


    /********************查询班级*****************/
    void classSelect(QString strClass);


    /********************导出Excel*****************/
    void extendExcel(QStatusBar *statusBar, float width);


    /********************导入Excel*****************/
    void importExcel(QStatusBar*statusBar,float width);


public slots:
    /********************删除数据*****************/
    void deleteData();


    /********************获取当前选中行*****************/
    void selectText(const QModelIndex &index);


 protected:

    /********************创建操作excel对象*****************/
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
    int dataBaseCount;
    int rowCount;
};

#endif // SchoolRoolSELECT_H
class SchoolRoolThread:public QThread
{
    SchoolRoolSelect *widget;
    QStatusBar*statusBar;
    int width;
    int flage;
public:
    SchoolRoolThread(SchoolRoolSelect *widget,QStatusBar*statusBar,int width,int flage);
public:
    virtual void run();
};
