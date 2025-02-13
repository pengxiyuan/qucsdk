﻿#ifndef YSPINBOX_H
#define YSPINBOX_H

#include <QSpinBox>

class QLineEdit;
class QLabel;

#ifdef quc
class Q_DECL_EXPORT YSpinBox : public QSpinBox
#else
class YSpinBox : public QSpinBox
#endif

{
    Q_OBJECT

    Q_PROPERTY(int btnSize READ getBtnSize WRITE setBtnSize)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)

public:
    explicit YSpinBox(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

private:
    QLineEdit *edit;        //文本框
    int btnSize;            //按钮尺寸
    QLabel *labTitle;       //标题
    QLabel *labUnit;        //单位

private slots:
    void initStyle();       //加载样式

public:
    int getBtnSize()        const;
    QString getTitle()      const;
    QString getUnit()       const;

    QSize sizeHint()        const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    //设置按钮尺寸
    void setBtnSize(int btnSize);
    //设置标题
    void setTitle(const QString &title);
    //设置单位
    void setUnit(const QString &unit);
};

#endif // YSPINBOX_H
