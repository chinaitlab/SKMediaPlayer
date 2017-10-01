#ifndef CTOPWIDGET_H
#define CTOPWIDGET_H

#include <QWidget>
#include "common.h"
#include "PushButton.h"

class CTopWidget : public QWidget
{
	Q_OBJECT

public:
	CTopWidget(QWidget *parent = 0);
	~CTopWidget();

	QLabel *GetLabelTitle() { return m_labelTitle; }
	QPushButton *GetBtnMaximize() { return m_btnMaximize; }

protected:
	bool eventFilter(QObject *, QEvent *);
	virtual void mousePressEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);
	virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void paintEvent(QPaintEvent *);

private:
	QLabel *m_labelLogo;		//��ʶ
	QLabel *m_labelTitle;		//����
	PushButton *m_btnSkin;		//����
	QPushButton *m_btnMainMenu;	//���˵�
	QPushButton *m_btnMinimize;	//��С��
	QPushButton *m_btnMaximize;	//���
	QPushButton *m_btnClose;	//�ر�
	QPushButton *m_btnSplit;	//�ָ���

private:
	void Init();
	void InitUi();

signals:
	void sigSkin();
	void sigMainMenu();
	void sigMin();
	void sigMax();
	void sigClose();

};

#endif // CTOPWIDGET_H
