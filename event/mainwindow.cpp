#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    textEdit = new QTextEdit(this);
    textEdit->setText(tr("this is a mouse evetn test program."));
    textEdit->setGeometry(QRect(50,50,300,200));

    // [1] ���������ù��
    QCursor cursor;                        // ����������
    cursor.setShape(Qt::OpenHandCursor);   // ���ù����״
    setCursor(cursor);                     // ʹ�ù��

    // ������ʱ��
    timerId1 = startTimer(1000);    // ��ʱ 1s
    timerId2 = startTimer(2000);    // ��ʱ 2s
    timerId3 = startTimer(3000);    // ��ʱ 3s
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [2]��갴���¼�
void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        QCursor cursor;                              // ����������
        cursor.setShape(Qt::ClosedHandCursor);       // ���ù����״
        QApplication::setOverrideCursor(cursor);     // �����ʱ�ı���״
        offset = event->globalPos() - pos();         // ��ȡָ��λ�úʹ���λ�õĲ�ֵ
    } else if (event->button() == Qt::RightButton){
        QCursor cursor;                               // ����������
        cursor.setShape(Qt::WaitCursor);              // ���ù����״
        QApplication::setOverrideCursor(cursor);      // �����ʱ�ı���״
    }
}
// [3]����ƶ��¼�
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    // ����ƶ�ʱ���������а��µļ���button()�����޷�ȷ���ĸ���������
    // ����ʹ��buttons()��Qt::LeftButton���а�λ��ķ����ж�����Ƿ���
    if (event->buttons() & Qt::LeftButton){
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);//ʹ����굱ǰλ�ü�ȥ��ֵ�����Ǵ���Ӧ���ƶ���λ��
    }
}
// [4]����ͷ��¼�
void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();  // �ָ����ָ����״
}
// [5]���˫���¼�
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){         //���������������
        if(windowState() != Qt::WindowFullScreen)   //������ڲ���ȫ����ʾ
              setWindowState(Qt::WindowFullScreen);   //��������Ϊȫ��
        else setWindowState(Qt::WindowNoState);     //����ָ���ǰ�Ĵ�С
    }
}
// [6]�����¼�
void MainWindow::wheelEvent(QWheelEvent *event){
    if (event->delta() >0){
        this->textEdit->zoomIn();
    } else {
        this->textEdit->zoomOut();
    }
}

// [7]���̰����¼�
void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->modifiers() == Qt::ControlModifier){ // Ctrl �����£�
        if (event->key() == Qt::Key_G && windowState() != Qt::WindowFullScreen)              // G �����£�
            setWindowState(Qt::WindowFullScreen);   //��������Ϊȫ��
        if (event->key() == Qt::Key_B && windowState() == Qt::WindowFullScreen)              // B �����£�
            setWindowState(Qt::WindowNoState);      // ���ڻָ���ǰ�Ĵ�С
    }
}

// [8]�����ͷ��¼�
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    Q_UNUSED(event);  // ��Q_UNUSED����һ��event���������ᾯ����ʾeventδʹ��
    // �����ͷź󣬲���Ҫ��ʲô��������˴���Ϊ��
}

// [9]��ʱ���¼�
void MainWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timerId1){
        this->textEdit->insertPlainText(tr("timer 1 event happen\n"));
        killTimer(timerId1); //�رն�ʱ��1
    } else if (event->timerId() == timerId2){
        this->textEdit->insertPlainText(tr("timer 2 event happen\n"));
        killTimer(timerId2); //�رն�ʱ��2
    } else {
        this->textEdit->insertPlainText(tr("timer 3 event happen\n"));
        killTimer(timerId3); //�رն�ʱ��3
    }
}