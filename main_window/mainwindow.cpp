#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //�������
    this->setWindowTitle("title of my mainwindow");
    //�������200*200
    this->setMaximumSize(400,400);
    //������С200*200
    this->setMinimumSize(200,200);
    //�޸Ĵ�����ʾ�ĳ�ʼλ��
    this->move(100,200);
    //����ICOͼƬ
    this->setWindowIcon(QIcon(":/ico/Iconsmind-Outline-Bear.ico"));

    newAct = new QAction(tr( "New" ), this );           // ����newAction
    newAct->setShortcut(tr("Ctrl+N" ));                 // ���ÿ�ݼ�
    newAct->setStatusTip(tr("create a new file" ));     // ����״̬����ʾ��Ϣ

    cutAct = new QAction(tr( "Cut" ), this );           // ����cutAction
    cutAct->setShortcut(tr("Ctrl+X" ));                 // ���ÿ�ݼ�
    cutAct->setStatusTip(tr("cut contents" ));          // ����״̬����ʾ��Ϣ

    copyAct = new QAction( tr( "Copy" ), this );        // ����copyAction
    copyAct->setShortcut(tr("Ctrl+C" ));                // ���ÿ�ݼ�
    copyAct->setStatusTip(tr("copy contents" ));        // ����״̬����ʾ��Ϣ

    pasteAct = new QAction(tr( "Paste" ), this );       // ����pasteAction
    pasteAct->setShortcut(tr("Ctrl+V" ));               // ���ÿ�ݼ�
    pasteAct->setStatusTip(tr("paste contents" ));      // ����״̬����ʾ��Ϣ

    aboutQtAct = new QAction(tr( "about Qt" ), this );          // ����newAction
    aboutQtAct->setStatusTip(tr("about Qt information" ));      // ����״̬����ʾ��Ϣ
    aboutQtAct->setIcon(QIcon(":/ico/Iconsmind-Outline-Bear.ico"));     // �˵�action���ͼƬ
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));    // ��һ��Qt�Դ��Ĳ�

    fileMenu = new QMenu(this);                         // �����˵���
    fileMenu = menuBar()->addMenu(tr( "File" ));        // ���Ӳ˵���˵�����
    fileMenu->addAction(newAct);                        // ���� newAction ��File�˵���
    fileMenu->addSeparator();                           // ���Ӳ˵��ָ���

    editMenu = new QMenu(this);                         // �����˵���
    editMenu = menuBar()->addMenu(tr("Edit" ));         // ���Ӳ˵���˵�����
    editMenu->addAction(cutAct);                        // ���� cutAction ��Edit�˵���
    editMenu->addAction(copyAct);                       // ���� copyAction ��Edit�˵���
    editMenu->addAction(pasteAct);                      // ���� pasteAction ��Edit�˵���
    menuBar()->addSeparator();                          // ���Ӳ˵��ָ���

    helpMenu = new QMenu(this);                         // �����˵���
    helpMenu = menuBar()->addMenu(tr("Help" ));         // ���Ӳ˵���˵�����
    helpMenu->addAction(aboutQtAct);                    // ���� aboutAction ��Edit�˵���

    fileToolBar = addToolBar(tr("New"));                // �����½�������
    fileToolBar->addAction(newAct);                     // ������������ newAction

    editToolBar = addToolBar(tr("Edit"));               // �����༭������
    editToolBar->addAction(cutAct);                     // ������������ cutAction
    editToolBar->addAction(copyAct);                    // ������������ copyAction
    editToolBar->addAction(pasteAct);                   // ������������ pasteAction
}

MainWindow::~MainWindow()
{
    delete ui;
}
