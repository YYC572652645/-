/********************************************************************************
** Form generated from reading UI file 'honorselect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HONORSELECT_H
#define UI_HONORSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HonorSelect
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *HonorSelect)
    {
        if (HonorSelect->objectName().isEmpty())
            HonorSelect->setObjectName(QStringLiteral("HonorSelect"));
        HonorSelect->resize(400, 300);
        verticalLayout = new QVBoxLayout(HonorSelect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(HonorSelect);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(HonorSelect);

        QMetaObject::connectSlotsByName(HonorSelect);
    } // setupUi

    void retranslateUi(QWidget *HonorSelect)
    {
        HonorSelect->setWindowTitle(QApplication::translate("HonorSelect", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("HonorSelect", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("HonorSelect", "\346\200\247\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("HonorSelect", "\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("HonorSelect", "\344\270\223\344\270\232\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("HonorSelect", "\350\216\267\345\245\226\347\247\215\347\261\273", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("HonorSelect", "\350\216\267\345\245\226\347\272\247\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("HonorSelect", "\350\216\267\345\245\226\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("HonorSelect", "\350\216\267\345\245\226\346\227\266\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class HonorSelect: public Ui_HonorSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HONORSELECT_H
