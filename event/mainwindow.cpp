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

    // [1] 创建并设置光标
    QCursor cursor;                        // 创建光标对象
    cursor.setShape(Qt::OpenHandCursor);   // 设置光标形状
    setCursor(cursor);                     // 使用光标

    // 启动定时器
    timerId1 = startTimer(1000);    // 定时 1s
    timerId2 = startTimer(2000);    // 定时 2s
    timerId3 = startTimer(3000);    // 定时 3s
}

MainWindow::~MainWindow()
{
    delete ui;
}

// [2]鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        QCursor cursor;                              // 创建光标对象
        cursor.setShape(Qt::ClosedHandCursor);       // 设置光标形状
        QApplication::setOverrideCursor(cursor);     // 鼠标暂时改变形状
        offset = event->globalPos() - pos();         // 获取指针位置和窗口位置的差值
    } else if (event->button() == Qt::RightButton){
        QCursor cursor;                               // 创建光标对象
        cursor.setShape(Qt::WaitCursor);              // 设置光标形状
        QApplication::setOverrideCursor(cursor);      // 鼠标暂时改变形状
    }
}
// [3]鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    // 鼠标移动时，会检测所有按下的键，button()函数无法确定哪个键被按下
    // 所以使用buttons()和Qt::LeftButton进行按位与的方法判断左键是否按下
    if (event->buttons() & Qt::LeftButton){
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);//使用鼠标当前位置减去差值，就是窗口应该移动的位置
    }
}
// [4]鼠标释放事件
void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();  // 恢复鼠标指针形状
}
// [5]鼠标双击事件
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){         //如果是鼠标左键按下
        if(windowState() != Qt::WindowFullScreen)   //如果现在不是全屏显示
              setWindowState(Qt::WindowFullScreen);   //窗口设置为全屏
        else setWindowState(Qt::WindowNoState);     //否则恢复以前的大小
    }
}
// [6]滚轮事件
void MainWindow::wheelEvent(QWheelEvent *event){
    if (event->delta() >0){
        this->textEdit->zoomIn();
    } else {
        this->textEdit->zoomOut();
    }
}

// [7]键盘按下事件
void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->modifiers() == Qt::ControlModifier){ // Ctrl 键按下？
        if (event->key() == Qt::Key_G && windowState() != Qt::WindowFullScreen)              // G 键按下？
            setWindowState(Qt::WindowFullScreen);   //窗口设置为全屏
        if (event->key() == Qt::Key_B && windowState() == Qt::WindowFullScreen)              // B 键按下？
            setWindowState(Qt::WindowNoState);      // 窗口恢复以前的大小
    }
}

// [8]键盘释放事件
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    Q_UNUSED(event);  // 用Q_UNUSED处理一下event，否则程序会警告提示event未使用
    // 键盘释放后，不需要有什么操作，因此代码为空
}

// [9]定时器事件
void MainWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timerId1){
        this->textEdit->insertPlainText(tr("timer 1 event happen\n"));
        killTimer(timerId1); //关闭定时器1
    } else if (event->timerId() == timerId2){
        this->textEdit->insertPlainText(tr("timer 2 event happen\n"));
        killTimer(timerId2); //关闭定时器2
    } else {
        this->textEdit->insertPlainText(tr("timer 3 event happen\n"));
        killTimer(timerId3); //关闭定时器3
    }
}