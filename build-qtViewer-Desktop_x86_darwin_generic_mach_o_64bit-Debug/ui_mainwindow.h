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
#include <dscene.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionJPG;
    QAction *actionPNG;
    QAction *actionGIF;
    QAction *action;
    QAction *action_open_file;
    QAction *actionJPG_2;
    QAction *actionPNG_2;
    QAction *actionGIF_2;
    QWidget *centralwidget;
    DScene *widget_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QWidget *move_widget;
    QGridLayout *gridLayout;
    QLineEdit *movex_line;
    QLineEdit *movey_line;
    QLineEdit *movez_line;
    QLabel *movez_label;
    QLabel *move_label;
    QPushButton *move_apply;
    QLabel *movey_label;
    QLabel *movex_label;
    QSlider *movey_slider;
    QSlider *movex_slider;
    QSlider *movez_slider;
    QWidget *proection_widget;
    QGridLayout *gridLayout_6;
    QRadioButton *proection_central;
    QLabel *proection_label;
    QRadioButton *proection_parallel;
    QWidget *rotate_widget;
    QGridLayout *gridLayout_2;
    QLineEdit *rotatez_line;
    QLabel *rotatex_label;
    QLineEdit *rotatey_line;
    QLineEdit *rotatex_line;
    QSlider *rotatey_slider;
    QSlider *rotatez_slider;
    QLabel *rotate_label;
    QLabel *rotatey_labe;
    QSlider *rotatex_slider;
    QLabel *rotatez_label;
    QPushButton *rotate_apply;
    QPushButton *pushButton;
    QWidget *Edges;
    QGridLayout *gridLayout_5;
    QLabel *edges_label;
    QPushButton *pushButton_3;
    QRadioButton *edges_dashed;
    QRadioButton *edges_solid;
    QSlider *lines_sie_slider;
    QWidget *vertices_widget;
    QGridLayout *gridLayout_4;
    QRadioButton *vertices_no;
    QRadioButton *vertices_circle;
    QRadioButton *vertices_square;
    QPushButton *pushButton_2;
    QLabel *vertices_label;
    QSlider *verticles_size_slider;
    QWidget *zoom_widget;
    QGridLayout *gridLayout_3;
    QSlider *zoom_slider;
    QLineEdit *zoom_line;
    QSpacerItem *horizontalSpacer_2;
    QLabel *zoom_label;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoom_button;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QLabel *zoom_label_2;
    QPushButton *bg_color_button;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 1200);
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
        action_open_file = new QAction(MainWindow);
        action_open_file->setObjectName(QString::fromUtf8("action_open_file"));
        actionJPG_2 = new QAction(MainWindow);
        actionJPG_2->setObjectName(QString::fromUtf8("actionJPG_2"));
        actionPNG_2 = new QAction(MainWindow);
        actionPNG_2->setObjectName(QString::fromUtf8("actionPNG_2"));
        actionGIF_2 = new QAction(MainWindow);
        actionGIF_2->setObjectName(QString::fromUtf8("actionGIF_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_3 = new DScene(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(550, 30, 1081, 1131));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 19, 532, 982));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        move_widget = new QWidget(layoutWidget);
        move_widget->setObjectName(QString::fromUtf8("move_widget"));
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
        movex_line = new QLineEdit(move_widget);
        movex_line->setObjectName(QString::fromUtf8("movex_line"));

        gridLayout->addWidget(movex_line, 1, 3, 1, 1);

        movey_line = new QLineEdit(move_widget);
        movey_line->setObjectName(QString::fromUtf8("movey_line"));

        gridLayout->addWidget(movey_line, 2, 3, 1, 1);

        movez_line = new QLineEdit(move_widget);
        movez_line->setObjectName(QString::fromUtf8("movez_line"));

        gridLayout->addWidget(movez_line, 3, 3, 1, 1);

        movez_label = new QLabel(move_widget);
        movez_label->setObjectName(QString::fromUtf8("movez_label"));

        gridLayout->addWidget(movez_label, 3, 0, 1, 1);

        move_label = new QLabel(move_widget);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        move_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(move_label, 0, 0, 1, 4);

        move_apply = new QPushButton(move_widget);
        move_apply->setObjectName(QString::fromUtf8("move_apply"));
        move_apply->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: #FF6347;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(move_apply, 4, 0, 1, 4);

        movey_label = new QLabel(move_widget);
        movey_label->setObjectName(QString::fromUtf8("movey_label"));

        gridLayout->addWidget(movey_label, 2, 0, 1, 1);

        movex_label = new QLabel(move_widget);
        movex_label->setObjectName(QString::fromUtf8("movex_label"));

        gridLayout->addWidget(movex_label, 1, 0, 1, 1);

        movey_slider = new QSlider(move_widget);
        movey_slider->setObjectName(QString::fromUtf8("movey_slider"));
        movey_slider->setMinimum(-500);
        movey_slider->setMaximum(500);
        movey_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movey_slider, 2, 1, 1, 2);

        movex_slider = new QSlider(move_widget);
        movex_slider->setObjectName(QString::fromUtf8("movex_slider"));
        movex_slider->setMinimum(-500);
        movex_slider->setMaximum(500);
        movex_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movex_slider, 1, 1, 1, 2);

        movez_slider = new QSlider(move_widget);
        movez_slider->setObjectName(QString::fromUtf8("movez_slider"));
        movez_slider->setMinimum(-500);
        movez_slider->setMaximum(500);
        movez_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(movez_slider, 3, 1, 1, 2);


        gridLayout_7->addWidget(move_widget, 1, 0, 1, 2);

        proection_widget = new QWidget(layoutWidget);
        proection_widget->setObjectName(QString::fromUtf8("proection_widget"));
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


        gridLayout_7->addWidget(proection_widget, 3, 0, 1, 2);

        rotate_widget = new QWidget(layoutWidget);
        rotate_widget->setObjectName(QString::fromUtf8("rotate_widget"));
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
        rotatez_line = new QLineEdit(rotate_widget);
        rotatez_line->setObjectName(QString::fromUtf8("rotatez_line"));

        gridLayout_2->addWidget(rotatez_line, 3, 3, 1, 1);

        rotatex_label = new QLabel(rotate_widget);
        rotatex_label->setObjectName(QString::fromUtf8("rotatex_label"));

        gridLayout_2->addWidget(rotatex_label, 1, 0, 1, 2);

        rotatey_line = new QLineEdit(rotate_widget);
        rotatey_line->setObjectName(QString::fromUtf8("rotatey_line"));

        gridLayout_2->addWidget(rotatey_line, 2, 3, 1, 1);

        rotatex_line = new QLineEdit(rotate_widget);
        rotatex_line->setObjectName(QString::fromUtf8("rotatex_line"));

        gridLayout_2->addWidget(rotatex_line, 1, 3, 1, 1);

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

        rotatey_labe = new QLabel(rotate_widget);
        rotatey_labe->setObjectName(QString::fromUtf8("rotatey_labe"));

        gridLayout_2->addWidget(rotatey_labe, 2, 0, 1, 1);

        rotatex_slider = new QSlider(rotate_widget);
        rotatex_slider->setObjectName(QString::fromUtf8("rotatex_slider"));
        rotatex_slider->setMinimum(-500);
        rotatex_slider->setMaximum(500);
        rotatex_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(rotatex_slider, 1, 2, 1, 1);

        rotatez_label = new QLabel(rotate_widget);
        rotatez_label->setObjectName(QString::fromUtf8("rotatez_label"));

        gridLayout_2->addWidget(rotatez_label, 3, 0, 1, 1);

        rotate_apply = new QPushButton(rotate_widget);
        rotate_apply->setObjectName(QString::fromUtf8("rotate_apply"));
        rotate_apply->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: #FF6347;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout_2->addWidget(rotate_apply, 4, 0, 1, 4);


        gridLayout_7->addWidget(rotate_widget, 2, 0, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("QWidget {\n"
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

        gridLayout_7->addWidget(pushButton, 0, 0, 1, 2);

        Edges = new QWidget(layoutWidget);
        Edges->setObjectName(QString::fromUtf8("Edges"));
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
        edges_label = new QLabel(Edges);
        edges_label->setObjectName(QString::fromUtf8("edges_label"));
        edges_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(edges_label, 0, 0, 1, 2);

        pushButton_3 = new QPushButton(Edges);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: #FF6347;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout_5->addWidget(pushButton_3, 4, 0, 1, 2);

        edges_dashed = new QRadioButton(Edges);
        edges_dashed->setObjectName(QString::fromUtf8("edges_dashed"));

        gridLayout_5->addWidget(edges_dashed, 2, 0, 1, 2);

        edges_solid = new QRadioButton(Edges);
        edges_solid->setObjectName(QString::fromUtf8("edges_solid"));
        edges_solid->setChecked(true);

        gridLayout_5->addWidget(edges_solid, 1, 0, 1, 2);

        lines_sie_slider = new QSlider(Edges);
        lines_sie_slider->setObjectName(QString::fromUtf8("lines_sie_slider"));
        lines_sie_slider->setMinimum(1);
        lines_sie_slider->setValue(10);
        lines_sie_slider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(lines_sie_slider, 3, 0, 1, 1);


        gridLayout_7->addWidget(Edges, 6, 1, 1, 1);

        vertices_widget = new QWidget(layoutWidget);
        vertices_widget->setObjectName(QString::fromUtf8("vertices_widget"));
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
        vertices_no = new QRadioButton(vertices_widget);
        vertices_no->setObjectName(QString::fromUtf8("vertices_no"));
        vertices_no->setChecked(true);

        gridLayout_4->addWidget(vertices_no, 1, 0, 1, 2);

        vertices_circle = new QRadioButton(vertices_widget);
        vertices_circle->setObjectName(QString::fromUtf8("vertices_circle"));
        vertices_circle->setEnabled(true);
        vertices_circle->setChecked(false);

        gridLayout_4->addWidget(vertices_circle, 2, 0, 1, 2);

        vertices_square = new QRadioButton(vertices_widget);
        vertices_square->setObjectName(QString::fromUtf8("vertices_square"));
        vertices_square->setAutoFillBackground(false);
        vertices_square->setChecked(false);

        gridLayout_4->addWidget(vertices_square, 3, 0, 1, 2);

        pushButton_2 = new QPushButton(vertices_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: #FF6347;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout_4->addWidget(pushButton_2, 5, 0, 1, 2);

        vertices_label = new QLabel(vertices_widget);
        vertices_label->setObjectName(QString::fromUtf8("vertices_label"));
        vertices_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(vertices_label, 0, 0, 1, 2);

        verticles_size_slider = new QSlider(vertices_widget);
        verticles_size_slider->setObjectName(QString::fromUtf8("verticles_size_slider"));
        verticles_size_slider->setMinimum(1);
        verticles_size_slider->setValue(10);
        verticles_size_slider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(verticles_size_slider, 4, 0, 1, 1);


        gridLayout_7->addWidget(vertices_widget, 6, 0, 1, 1);

        zoom_widget = new QWidget(layoutWidget);
        zoom_widget->setObjectName(QString::fromUtf8("zoom_widget"));
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
        zoom_slider = new QSlider(zoom_widget);
        zoom_slider->setObjectName(QString::fromUtf8("zoom_slider"));
        zoom_slider->setMinimum(1);
        zoom_slider->setMaximum(100);
        zoom_slider->setValue(10);
        zoom_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(zoom_slider, 4, 0, 1, 2);

        zoom_line = new QLineEdit(zoom_widget);
        zoom_line->setObjectName(QString::fromUtf8("zoom_line"));

        gridLayout_3->addWidget(zoom_line, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        zoom_label = new QLabel(zoom_widget);
        zoom_label->setObjectName(QString::fromUtf8("zoom_label"));
        zoom_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(zoom_label, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        zoom_button = new QPushButton(zoom_widget);
        zoom_button->setObjectName(QString::fromUtf8("zoom_button"));
        zoom_button->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: #FF6347;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout_3->addWidget(zoom_button, 5, 0, 1, 3);


        gridLayout_7->addWidget(zoom_widget, 4, 0, 1, 2);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #7FFFD4;\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #2F4F4F;\n"
"    font: 12px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"    color: #191970;\n"
"}"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        zoom_label_2 = new QLabel(widget);
        zoom_label_2->setObjectName(QString::fromUtf8("zoom_label_2"));
        zoom_label_2->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(zoom_label_2, 0, 0, 1, 1);

        bg_color_button = new QPushButton(widget);
        bg_color_button->setObjectName(QString::fromUtf8("bg_color_button"));

        gridLayout_8->addWidget(bg_color_button, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget, 5, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_open_file);
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
        action_open_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        actionJPG_2->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        actionPNG_2->setText(QCoreApplication::translate("MainWindow", "PNG", nullptr));
        actionGIF_2->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        movex_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        movey_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        movez_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        movez_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        move_label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        move_apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        movey_label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        movex_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        proection_central->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        proection_label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        proection_parallel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        rotatez_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotatex_label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotatey_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotatex_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rotate_label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        rotatey_labe->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        rotatez_label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotate_apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        edges_label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202...", nullptr));
        edges_dashed->setText(QCoreApplication::translate("MainWindow", "\320\250\321\202\321\200\320\270\321\205\320\276\320\262\320\276\320\271", nullptr));
        edges_solid->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\276\320\271", nullptr));
        vertices_no->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        vertices_circle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263\320\270", nullptr));
        vertices_square->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\321\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202...", nullptr));
        vertices_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        zoom_line->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        zoom_label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        zoom_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        zoom_label_2->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        bg_color_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202...", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
