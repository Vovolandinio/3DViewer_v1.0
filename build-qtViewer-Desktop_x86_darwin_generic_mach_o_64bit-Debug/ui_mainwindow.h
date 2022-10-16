/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "scene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionJPG;
    QAction *actionPNG;
    QAction *actionGIF;
    QAction *action;
    QAction *action_2;
    QAction *actionJPG_2;
    QAction *actionPNG_2;
    QAction *actionGIF_2;
    QWidget *centralwidget;
    QWidget *move_widget;
    QGridLayout *gridLayout;
    QLabel *movex_label;
    QSlider *movex_slider;
    QLineEdit *movex_line;
    QLabel *movey_label;
    QLineEdit *movey_line;
    QLabel *movez_label;
    QLineEdit *movez_line;
    QSlider *movey_slider;
    QSlider *movez_slider;
    QLabel *move_label;
    QWidget *rotate_widget;
    QGridLayout *gridLayout_2;
    QLabel *rotatex_label;
    QSlider *rotatex_slider;
    QLineEdit *rotatex_line;
    QLabel *rotatey_labe;
    QLineEdit *rotatey_line;
    QLabel *rotatez_label;
    QLineEdit *rotatez_line;
    QSlider *rotatey_slider;
    QSlider *rotatez_slider;
    QLabel *rotate_label;
    QWidget *zoom_widget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QSlider *zoom_slider;
    QSpacerItem *horizontalSpacer_2;
    QLabel *zoom_label;
    QLineEdit *zoom_line;
    QWidget *vertices_widget;
    QGridLayout *gridLayout_4;
    QLabel *vertices_label;
    QLabel *vertices_red_label;
    QLabel *vertices_green_label;
    QLabel *vertices_blue_label;
    QLineEdit *vertices_red;
    QLineEdit *vertices_green;
    QLineEdit *vertices_blue;
    QLabel *vertices_color_label;
    QRadioButton *vertices_square;
    QRadioButton *vertices_circle;
    QRadioButton *vertices_no;
    QWidget *Edges;
    QGridLayout *gridLayout_5;
    QLineEdit *edges_green;
    QLabel *edges_label;
    QLabel *edges_color_label;
    QRadioButton *edges_dashed;
    QLineEdit *edges_blue;
    QLabel *edges_red_label;
    QLabel *edges_blue_label;
    QRadioButton *edges_solid;
    QLineEdit *edges_red;
    QLabel *edges_green_label;
    QPushButton *pushButton;
    Scene *widget_3;
    QWidget *proection_widget;
    QGridLayout *gridLayout_6;
    QRadioButton *proection_central;
    QLabel *proection_label;
    QRadioButton *proection_parallel;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1813, 1109);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #E0FFFF;\n"
"}"));
        actionJPG = new QAction(MainWindow);
        actionJPG->setObjectName(QString::fromUtf8("actionJPG"));
        actionPNG = new QAction(MainWindow);
        actionPNG->setObjectName(QString::fromUtf8("actionPNG"));
        actionGIF = new QAction(MainWindow);
        actionGIF->setObjectName(QString::fromUtf8("actionGIF"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionJPG_2 = new QAction(MainWindow);
        actionJPG_2->setObjectName(QString::fromUtf8("actionJPG_2"));
        actionPNG_2 = new QAction(MainWindow);
        actionPNG_2->setObjectName(QString::fromUtf8("actionPNG_2"));
        actionGIF_2 = new QAction(MainWindow);
        actionGIF_2->setObjectName(QString::fromUtf8("actionGIF_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        move_widget = new QWidget(centralwidget);
        move_widget->setObjectName(QString::fromUtf8("move_widget"));
        move_widget->setGeometry(QRect(10, 20, 531, 171));
        move_widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout = new QGridLayout(move_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        movex_label = new QLabel(move_widget);
        movex_label->setObjectName(QString::fromUtf8("movex_label"));

        gridLayout->addWidget(movex_label, 1, 0, 1, 2);

        movex_slider = new QSlider(move_widget);
        movex_slider->setObjectName(QString::fromUtf8("movex_slider"));
        movex_slider->setMinimum(-500);
        movex_slider->setMaximum(500);
        movex_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movex_slider, 1, 2, 1, 1);

        movex_line = new QLineEdit(move_widget);
        movex_line->setObjectName(QString::fromUtf8("movex_line"));

        gridLayout->addWidget(movex_line, 1, 3, 1, 1);

        movey_label = new QLabel(move_widget);
        movey_label->setObjectName(QString::fromUtf8("movey_label"));

        gridLayout->addWidget(movey_label, 2, 0, 1, 1);

        movey_line = new QLineEdit(move_widget);
        movey_line->setObjectName(QString::fromUtf8("movey_line"));

        gridLayout->addWidget(movey_line, 2, 3, 1, 1);

        movez_label = new QLabel(move_widget);
        movez_label->setObjectName(QString::fromUtf8("movez_label"));

        gridLayout->addWidget(movez_label, 3, 0, 1, 1);

        movez_line = new QLineEdit(move_widget);
        movez_line->setObjectName(QString::fromUtf8("movez_line"));

        gridLayout->addWidget(movez_line, 3, 3, 1, 1);

        movey_slider = new QSlider(move_widget);
        movey_slider->setObjectName(QString::fromUtf8("movey_slider"));
        movey_slider->setMinimum(-500);
        movey_slider->setMaximum(500);
        movey_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movey_slider, 2, 2, 1, 1);

        movez_slider = new QSlider(move_widget);
        movez_slider->setObjectName(QString::fromUtf8("movez_slider"));
        movez_slider->setMinimum(-500);
        movez_slider->setMaximum(500);
        movez_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movez_slider, 3, 2, 1, 1);

        move_label = new QLabel(move_widget);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        move_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(move_label, 0, 0, 1, 4);

        rotate_widget = new QWidget(centralwidget);
        rotate_widget->setObjectName(QString::fromUtf8("rotate_widget"));
        rotate_widget->setGeometry(QRect(10, 200, 531, 171));
        rotate_widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout_2 = new QGridLayout(rotate_widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rotatex_label = new QLabel(rotate_widget);
        rotatex_label->setObjectName(QString::fromUtf8("rotatex_label"));

        gridLayout_2->addWidget(rotatex_label, 1, 0, 1, 2);

        rotatex_slider = new QSlider(rotate_widget);
        rotatex_slider->setObjectName(QString::fromUtf8("rotatex_slider"));
        rotatex_slider->setMinimum(-500);
        rotatex_slider->setMaximum(500);
        rotatex_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(rotatex_slider, 1, 2, 1, 1);

        rotatex_line = new QLineEdit(rotate_widget);
        rotatex_line->setObjectName(QString::fromUtf8("rotatex_line"));

        gridLayout_2->addWidget(rotatex_line, 1, 3, 1, 1);

        rotatey_labe = new QLabel(rotate_widget);
        rotatey_labe->setObjectName(QString::fromUtf8("rotatey_labe"));

        gridLayout_2->addWidget(rotatey_labe, 2, 0, 1, 1);

        rotatey_line = new QLineEdit(rotate_widget);
        rotatey_line->setObjectName(QString::fromUtf8("rotatey_line"));

        gridLayout_2->addWidget(rotatey_line, 2, 3, 1, 1);

        rotatez_label = new QLabel(rotate_widget);
        rotatez_label->setObjectName(QString::fromUtf8("rotatez_label"));

        gridLayout_2->addWidget(rotatez_label, 3, 0, 1, 1);

        rotatez_line = new QLineEdit(rotate_widget);
        rotatez_line->setObjectName(QString::fromUtf8("rotatez_line"));

        gridLayout_2->addWidget(rotatez_line, 3, 3, 1, 1);

        rotatey_slider = new QSlider(rotate_widget);
        rotatey_slider->setObjectName(QString::fromUtf8("rotatey_slider"));
        rotatey_slider->setMinimum(-500);
        rotatey_slider->setMaximum(500);
        rotatey_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(rotatey_slider, 2, 2, 1, 1);

        rotatez_slider = new QSlider(rotate_widget);
        rotatez_slider->setObjectName(QString::fromUtf8("rotatez_slider"));
        rotatez_slider->setMinimum(-500);
        rotatez_slider->setMaximum(500);
        rotatez_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(rotatez_slider, 3, 2, 1, 1);

        rotate_label = new QLabel(rotate_widget);
        rotate_label->setObjectName(QString::fromUtf8("rotate_label"));
        rotate_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(rotate_label, 0, 0, 1, 4);

        zoom_widget = new QWidget(centralwidget);
        zoom_widget->setObjectName(QString::fromUtf8("zoom_widget"));
        zoom_widget->setGeometry(QRect(10, 500, 531, 111));
        zoom_widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout_3 = new QGridLayout(zoom_widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        zoom_slider = new QSlider(zoom_widget);
        zoom_slider->setObjectName(QString::fromUtf8("zoom_slider"));
        zoom_slider->setValue(10);
        zoom_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(zoom_slider, 4, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        zoom_label = new QLabel(zoom_widget);
        zoom_label->setObjectName(QString::fromUtf8("zoom_label"));
        zoom_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(zoom_label, 0, 0, 1, 3);

        zoom_line = new QLineEdit(zoom_widget);
        zoom_line->setObjectName(QString::fromUtf8("zoom_line"));

        gridLayout_3->addWidget(zoom_line, 4, 2, 1, 1);

        vertices_widget = new QWidget(centralwidget);
        vertices_widget->setObjectName(QString::fromUtf8("vertices_widget"));
        vertices_widget->setGeometry(QRect(10, 620, 531, 221));
        vertices_widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout_4 = new QGridLayout(vertices_widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        vertices_label = new QLabel(vertices_widget);
        vertices_label->setObjectName(QString::fromUtf8("vertices_label"));
        vertices_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(vertices_label, 0, 0, 1, 3);

        vertices_red_label = new QLabel(vertices_widget);
        vertices_red_label->setObjectName(QString::fromUtf8("vertices_red_label"));
        vertices_red_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(vertices_red_label, 5, 0, 1, 1);

        vertices_green_label = new QLabel(vertices_widget);
        vertices_green_label->setObjectName(QString::fromUtf8("vertices_green_label"));
        vertices_green_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(vertices_green_label, 5, 1, 1, 1);

        vertices_blue_label = new QLabel(vertices_widget);
        vertices_blue_label->setObjectName(QString::fromUtf8("vertices_blue_label"));
        vertices_blue_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(vertices_blue_label, 5, 2, 1, 1);

        vertices_red = new QLineEdit(vertices_widget);
        vertices_red->setObjectName(QString::fromUtf8("vertices_red"));

        gridLayout_4->addWidget(vertices_red, 6, 0, 1, 1);

        vertices_green = new QLineEdit(vertices_widget);
        vertices_green->setObjectName(QString::fromUtf8("vertices_green"));

        gridLayout_4->addWidget(vertices_green, 6, 1, 1, 1);

        vertices_blue = new QLineEdit(vertices_widget);
        vertices_blue->setObjectName(QString::fromUtf8("vertices_blue"));

        gridLayout_4->addWidget(vertices_blue, 6, 2, 1, 1);

        vertices_color_label = new QLabel(vertices_widget);
        vertices_color_label->setObjectName(QString::fromUtf8("vertices_color_label"));

        gridLayout_4->addWidget(vertices_color_label, 4, 0, 1, 3);

        vertices_square = new QRadioButton(vertices_widget);
        vertices_square->setObjectName(QString::fromUtf8("vertices_square"));
        vertices_square->setAutoFillBackground(false);
        vertices_square->setChecked(false);

        gridLayout_4->addWidget(vertices_square, 3, 0, 1, 2);

        vertices_circle = new QRadioButton(vertices_widget);
        vertices_circle->setObjectName(QString::fromUtf8("vertices_circle"));
        vertices_circle->setEnabled(true);
        vertices_circle->setChecked(true);

        gridLayout_4->addWidget(vertices_circle, 2, 0, 1, 2);

        vertices_no = new QRadioButton(vertices_widget);
        vertices_no->setObjectName(QString::fromUtf8("vertices_no"));

        gridLayout_4->addWidget(vertices_no, 1, 0, 1, 2);

        Edges = new QWidget(centralwidget);
        Edges->setObjectName(QString::fromUtf8("Edges"));
        Edges->setGeometry(QRect(10, 850, 531, 221));
        Edges->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout_5 = new QGridLayout(Edges);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        edges_green = new QLineEdit(Edges);
        edges_green->setObjectName(QString::fromUtf8("edges_green"));

        gridLayout_5->addWidget(edges_green, 5, 1, 1, 1);

        edges_label = new QLabel(Edges);
        edges_label->setObjectName(QString::fromUtf8("edges_label"));
        edges_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(edges_label, 0, 0, 1, 3);

        edges_color_label = new QLabel(Edges);
        edges_color_label->setObjectName(QString::fromUtf8("edges_color_label"));

        gridLayout_5->addWidget(edges_color_label, 3, 0, 1, 3);

        edges_dashed = new QRadioButton(Edges);
        edges_dashed->setObjectName(QString::fromUtf8("edges_dashed"));

        gridLayout_5->addWidget(edges_dashed, 2, 0, 1, 2);

        edges_blue = new QLineEdit(Edges);
        edges_blue->setObjectName(QString::fromUtf8("edges_blue"));

        gridLayout_5->addWidget(edges_blue, 5, 2, 1, 1);

        edges_red_label = new QLabel(Edges);
        edges_red_label->setObjectName(QString::fromUtf8("edges_red_label"));
        edges_red_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(edges_red_label, 4, 0, 1, 1);

        edges_blue_label = new QLabel(Edges);
        edges_blue_label->setObjectName(QString::fromUtf8("edges_blue_label"));
        edges_blue_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(edges_blue_label, 4, 2, 1, 1);

        edges_solid = new QRadioButton(Edges);
        edges_solid->setObjectName(QString::fromUtf8("edges_solid"));
        edges_solid->setChecked(true);

        gridLayout_5->addWidget(edges_solid, 1, 0, 1, 2);

        edges_red = new QLineEdit(Edges);
        edges_red->setObjectName(QString::fromUtf8("edges_red"));

        gridLayout_5->addWidget(edges_red, 5, 0, 1, 1);

        edges_green_label = new QLabel(Edges);
        edges_green_label->setObjectName(QString::fromUtf8("edges_green_label"));
        edges_green_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(edges_green_label, 4, 1, 1, 1);

        pushButton = new QPushButton(Edges);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 6, 2, 1, 1);

        widget_3 = new Scene(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(550, 20, 1251, 1051));
        proection_widget = new QWidget(centralwidget);
        proection_widget->setObjectName(QString::fromUtf8("proection_widget"));
        proection_widget->setGeometry(QRect(10, 380, 531, 111));
        proection_widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}\n"
""));
        gridLayout_6 = new QGridLayout(proection_widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        proection_central = new QRadioButton(proection_widget);
        proection_central->setObjectName(QString::fromUtf8("proection_central"));

        gridLayout_6->addWidget(proection_central, 2, 0, 1, 2);

        proection_label = new QLabel(proection_widget);
        proection_label->setObjectName(QString::fromUtf8("proection_label"));
        proection_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(proection_label, 0, 0, 1, 2);

        proection_parallel = new QRadioButton(proection_widget);
        proection_parallel->setObjectName(QString::fromUtf8("proection_parallel"));
        proection_parallel->setChecked(true);

        gridLayout_6->addWidget(proection_parallel, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1813, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_2);
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(actionJPG_2);
        menu_2->addAction(actionPNG_2);
        menu_2->addAction(actionGIF_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionJPG->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        actionPNG->setText(QCoreApplication::translate("MainWindow", "PNG", nullptr));
        actionGIF->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        actionJPG_2->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        actionPNG_2->setText(QCoreApplication::translate("MainWindow", "PNG", nullptr));
        actionGIF_2->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        movex_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        movex_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        movey_label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        movey_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        movez_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        movez_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        move_label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        rotatex_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotatex_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotatey_labe->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        rotatey_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotatez_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotatez_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotate_label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        zoom_label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        zoom_line->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        vertices_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        vertices_red_label->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        vertices_green_label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        vertices_blue_label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        vertices_red->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        vertices_green->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        vertices_blue->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        vertices_color_label->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        vertices_square->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\321\213", nullptr));
        vertices_circle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263\320\270", nullptr));
        vertices_no->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        edges_green->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        edges_label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270", nullptr));
        edges_color_label->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        edges_dashed->setText(QCoreApplication::translate("MainWindow", "\320\250\321\202\321\200\320\270\321\205\320\276\320\262\320\276\320\271", nullptr));
        edges_blue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        edges_red_label->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        edges_blue_label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        edges_solid->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\276\320\271", nullptr));
        edges_red->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        edges_green_label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\272\320\275\320\276\320\277\320\260\321\207\320\272\320\260", nullptr));
        proection_central->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        proection_label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        proection_parallel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
