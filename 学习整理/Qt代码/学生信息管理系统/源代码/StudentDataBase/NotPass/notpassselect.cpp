#include "NotPassselect.h"
#include "ui_NotPassselect.h"

NotPassSelect::NotPassSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotPassSelect)
{
    ui->setupUi(this);

    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //等宽显示
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //纵向隐藏序号
    headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    NotPass=new NotPassDataBase();
    connect(ui->tableWidget,SIGNAL(pressed(QModelIndex)),this,SLOT(selectText(QModelIndex)));

    QFont f("宋体",9);
    ui->tableWidget->horizontalHeader()->setFont(f);//表头设置字体

    rowCount=-1;
    dataBaseCount=0;
}

NotPassSelect::~NotPassSelect()
{
    delete ui;
}





/********************查询学号*****************/
void NotPassSelect::numerSelect(QString number)
{
    dataBaseCount=NotPass->selectData(number,"","");
    if(dataBaseCount==0)
    {
        ui->tableWidget->setRowCount(0);
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else if(dataBaseCount==-1)
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }

    ui->tableWidget->setRowCount(dataBaseCount);
    for(int i=0;i<dataBaseCount;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(NotPass->NotPassMessage[i].name));          //姓名
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(NotPass->NotPassMessage[i].sex));           //性别
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(NotPass->NotPassMessage[i].number));        //学号
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(NotPass->NotPassMessage[i].profess));       //班级
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassClass));  //挂科名称
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassGrade));  //挂科学分
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassPro));    //挂科性质
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassState));  //挂科状态

    }


}


/********************查询姓名*****************/
void NotPassSelect::nameSelect(QString name)
{
    dataBaseCount=NotPass->selectData("",name,"");
    if(dataBaseCount==0)
    {
        ui->tableWidget->setRowCount(0);
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else if(dataBaseCount==-1)
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }

    ui->tableWidget->setRowCount(dataBaseCount);
    for(int i=0;i<dataBaseCount;i++)
    {

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(NotPass->NotPassMessage[i].name));          //姓名
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(NotPass->NotPassMessage[i].sex));           //性别
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(NotPass->NotPassMessage[i].number));        //学号
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(NotPass->NotPassMessage[i].profess));       //班级
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassClass));  //挂科名称
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassGrade));  //挂科学分
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassPro));    //挂科性质
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassState));  //挂科状态
    }
}

/********************查询班级*****************/
void NotPassSelect::classSelect(QString strClass)
{
    dataBaseCount=NotPass->selectData("","",strClass);
    if(dataBaseCount==0)
    {
        ui->tableWidget->setRowCount(0);
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else if(dataBaseCount==-1)
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }

    ui->tableWidget->setRowCount(dataBaseCount);
    for(int i=0;i<dataBaseCount;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(NotPass->NotPassMessage[i].name));          //姓名
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(NotPass->NotPassMessage[i].sex));           //性别
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(NotPass->NotPassMessage[i].number));        //学号
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(NotPass->NotPassMessage[i].profess));       //班级
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassClass));  //挂科名称
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassGrade));  //挂科学分
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassPro));    //挂科性质
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(NotPass->NotPassMessage[i].notPassState));  //挂科状态
    }
}


/********************导出Excel*****************/
void NotPassSelect::extendExcel(QStatusBar*statusBar,float width)
{

    /******************初始化数据********************/
    QProgressBar *gressBar=new QProgressBar();//创建进度条
    statusBar->addWidget(gressBar);           //把进度条加到状态栏
    gressBar->setMinimumWidth(width); //设置进度条宽度
    int dataCount=0;
    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;


    QString fileName=QFileDialog::getSaveFileName(NULL,tr("保存文件"),".","Excel(*.xlsx *.xls)");
    if(fileName.isEmpty())
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        return;
    }


    excel=new QAxObject("Excel.Application");            //加载Excel驱动
    excel->setProperty("Visible",false);                 //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook=excel->querySubObject("ActiveWorkBook");
    workSheets=workBook->querySubObject("Sheets");       //Sheets可换做WorkSheets
    workSheet=workBook->querySubObject("Sheets(int)",1); //读取第一个工作表中的内容

    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",1,1); //循环获取单元格中数据
    cell->setProperty("Value","姓名");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,2); //循环获取单元格中数据
    cell->setProperty("Value","性别");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,3); //循环获取单元格中数据
    cell->setProperty("Value","学号");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,4); //循环获取单元格中数据
    cell->setProperty("Value","专业班级");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,5); //循环获取单元格中数据
    cell->setProperty("Value","挂科名称");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,6); //循环获取单元格中数据
    cell->setProperty("Value","挂科学分");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,7); //循环获取单元格中数据
    cell->setProperty("Value","挂科性质");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,8); //循环获取单元格中数据
    cell->setProperty("Value","挂科状态");         //写单元格值



    gressBar->setRange(0,dataBaseCount);
    /*******************************写入单元格数据***************************/
    for(int i=2;i<dataBaseCount+2;i++)
    {
        for(int j=1;j<9;j++)
        {
            cell->clear();
            cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据

            dataCount=i-2;

            switch(j)
            {
            case 1:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].name);  break;       //写单元格值
            case 2:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].sex);   break;       //写单元格值
            case 3:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].number);break;       //写单元格值
            case 4:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].profess);break;      //写单元格值
            case 5:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].notPassClass);break; //写单元格值
            case 6:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].notPassGrade);break; //写单元格值
            case 7:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].notPassPro);break;   //写单元格值
            case 8:cell->setProperty("Value",NotPass->NotPassMessage[dataCount].notPassState);break; //写单元格值
            }
        }
        gressBar->setValue(i-1);
    }


    workBook->dynamicCall("SaveAs(const Qstring&)",QDir::toNativeSeparators(fileName));//保存文件
    workBook->dynamicCall("Close(Boolen)",false);  //关闭
    excel->dynamicCall("Quit(void)");              //退出
    gressBar->deleteLater();
    statusBar->deleteLater();
    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，导出Excel成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
    MessageDialog::getInstance()->exec();
}


/********************导入Excel*****************/
void NotPassSelect::importExcel(QStatusBar*statusBar,float width)
{
    QProgressBar *gressBar=new QProgressBar();
    statusBar->addWidget(gressBar);
    gressBar->setMinimumWidth(width);


    /******************初始化数据********************/
    int Count=0;
    int dataCount=0;

    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;

    QRegExp rx;                                    //正则表达式
    rx.setPatternSyntax(QRegExp::RegExp);          //将元字符设置为统配模式下
    rx.setCaseSensitivity(Qt::CaseSensitive);      //大小写敏感
    excel=new QAxObject("Excel.Application");      //加载Excel驱动
    excel->setProperty("Visible",false);           //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");
    QString fileName=QFileDialog::getOpenFileName(this,tr("打开文件对话框"),"/","excel(*.xlsx *.xls);");//获取路径
    QFileInfo fileInfo;                    //读取文件后缀名
    fileInfo=QFileInfo(fileName);
    QString suffixName=fileInfo.suffix();  //获取文件后缀名
    if(suffixName.isEmpty())
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        return;
    }


    if(suffixName!=tr("xlsx")&&suffixName!=tr("xls"))
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，导入格式不正确！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();

        return;
    }

    if(!fileName.isEmpty())
    {
        workBooks->dynamicCall("Open(const QString &)",fileName);  //打开指定文件
        workBook=excel->querySubObject("ACtiveWorkBook");
        workSheets=workBook->querySubObject("Sheets");             //Sheets可换做WorkSheets
        int sheetCount=workSheets->property("Count").toInt();      //获取工作表数目


        if(sheetCount>0)
        {

            workSheet=workBook->querySubObject("Sheets(int)",1);        //读取第一个工作表中的内容
            QAxObject *usedRange=workSheet->querySubObject("UsedRange");//求出该表的数据的可用范围
            QAxObject *Rows=usedRange->querySubObject("Rows");          //创建行对象
            QAxObject *columns=usedRange->querySubObject("Columns");    //创建列对象
            int startRow=usedRange->property("Row").toInt();            //获取开始行
            int startColumn=usedRange->property("Column").toInt();      //获取开始列
            int rowCount=Rows->property("Count").toInt();               //获取总共多少行
            int columnCount=columns->property("Count").toInt();         //获取总共多少列

            gressBar->setRange(0,rowCount-1);
            /*******************************获取单元格中数据***************************/
            for(int i=startRow+1;i<startRow+rowCount;i++)
            {
                for(int j=startColumn;j<startColumn+columnCount;j++)
                {

                    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据
                    QVariant cellValue=cell->property("Value");                      //得到单元格值

                    if(columnCount!=5)
                    {
                        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，导入格式不正确！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                        MessageDialog::getInstance()->exec();
                        workBook->dynamicCall("Close(Boolen)",false);  //关闭
                        excel->dynamicCall("Quit(void)");              //退出
                        gressBar->deleteLater();
                        statusBar->deleteLater();
                        workBook->dynamicCall("Close(Boolen)",false);  //关闭
                        excel->dynamicCall("Quit(void)");              //退出
                        return;
                    }
                    if(Count%5==0)
                    {
                        dataCount++;
                    }
                    if(j==startColumn)
                    {
                        if(cellValue.toString().isEmpty())
                        {
                            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号为空！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                            MessageDialog::getInstance()->exec();
                            gressBar->deleteLater();
                            statusBar->deleteLater();
                            workBook->dynamicCall("Close(Boolen)",false);  //关闭
                            excel->dynamicCall("Quit(void)");              //退出
                            return;
                        }
                        else
                        {
                            rx.setPattern(QString("[1-9][0-9]{9}"));    //匹配学号10位
                            if(rx.exactMatch(cellValue.toString()))
                            {
                                NotPass->number=cellValue.toString();
                            }
                            else
                            {
                                MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                                MessageDialog::getInstance()->exec();
                                gressBar->deleteLater();
                                statusBar->deleteLater();
                                workBook->dynamicCall("Close(Boolen)",false);  //关闭
                                excel->dynamicCall("Quit(void)");              //退出
                                return;
                            }
                        }

                    }
                    else if(j==startColumn+1)
                    {
                        NotPass->notPassClass=cellValue.toString();
                    }
                    else if(j==startColumn+2)
                    {
                        NotPass->notPassGrade=cellValue.toString();
                    }
                    else if(j==startColumn+3)
                    {
                        NotPass->notPassPro=cellValue.toString();
                    }
                    else if(j==startColumn+4)
                    {
                        NotPass->notPassState=cellValue.toString();
                    }

                    Count++;
                }
                NotPass->insertData();
                gressBar->setValue(i-startRow);
            }
        }
        workBook->dynamicCall("Close(Boolen)",false);  //关闭
        excel->dynamicCall("Quit(void)");              //退出
        gressBar->deleteLater();
        statusBar->deleteLater();
    }

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，导入Excel成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
    MessageDialog::getInstance()->exec();
}


/********************删除数据*****************/
void NotPassSelect::deleteData()
{
    if(NotPass->number.isEmpty())
    {
        return;
    }
    if(NotPass->deleteData())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，删除成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
        MessageDialog::getInstance()->exec();
    }
    else
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，删除失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
    }
    if(rowCount!=-1)
    {
        ui->tableWidget->removeRow(rowCount);//移除删除的一行
    }

}


/********************获取当前选中行*****************/
void NotPassSelect::selectText(const QModelIndex &index)
{
    rowCount=index.row();

    for(int i=0;i<8;i++)
    {
        QTableWidgetItem*item=ui->tableWidget->item(index.row(),i);
        switch(i)
        {
        case 2:NotPass->number=item->text();break;
        case 4:NotPass->notPassClass=item->text();break;
        case 5:NotPass->notPassGrade=item->text();break;
        case 6:NotPass->notPassPro=item->text();break;
        case 7:NotPass->notPassState=item->text();break;
        }
    }


}


/********************线程类构造函数*****************/
NotPassThread::NotPassThread(NotPassSelect *widget, QStatusBar*statusBar, int width, int flage)
{
    this->widget=widget;
    this->statusBar=statusBar;
    this->width=width;
    this->flage=flage;
}


/********************线程函数*****************/
void NotPassThread::run()
{
    if(this->flage==1)
    {
        widget->extendExcel(this->statusBar,this->width);
    }
    else if(this->flage==2)
    {
        widget->importExcel(this->statusBar,this->width);
    }
}
