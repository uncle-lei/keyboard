#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QPushButton>
#include <QTimer>
#include "keyboard_global.h"
namespace Ui
{
    class Keyboard;
}

class KEYBOARDSHARED_EXPORT Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();

    void Init(int btnFontSize = 10, int labFontSize = 10);
    void bindWidget(QWidget *nowWidget); //绑定窗口


protected:
    //鼠标拖动事件
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    //输入法面板按键处理
    void btn_clicked();


    void on_btnMin_clicked();

    void on_btnMax_clicked();

private:
    Ui::Keyboard *ui;


    int deskWidth;                  //桌面宽度
    int deskHeight;                 //桌面高度
    int frmWidth;                   //窗体宽度
    int frmHeight;                  //窗体高度

    QPoint mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool mousePressed;              //鼠标是否按下

    void InitForm();                //初始化窗体数据
    void InitProperty();            //初始化属性
    void ChangeFont();              //改变字体大小
    void ShowPanel();               //显示输入法面板

    QWidget *currentWidget;         //当前焦点的对象
    QLineEdit *currentLineEdit;     //当前焦点的单行文本框
    QTextEdit *currentTextEdit;     //当前焦点的多行文本框
    QPlainTextEdit *currentPlain;   //当前焦点的富文本框
    QTextBrowser *currentBrowser;   //当前焦点的文本浏览框

    QString currentEditType;        //当前焦点控件的类型
    QString currentPosition;        //当前输入法面板位置类型
    int btnFontSize;                //当前输入法面板按钮字体大小
    int labFontSize;                //当前输入法面板标签字体大小
    void insertValue(QString value);//插入值到当前焦点控件
    void deleteValue();             //删除当前焦点控件的一个字符

    QString currentType;            //当前输入法类型
    void changeType(QString type);  //改变输入法类型
    void changeLetter(bool isUpper);//改变字母大小写


};

#endif // FRMINPUT_H
