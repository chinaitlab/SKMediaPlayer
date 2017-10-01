#ifndef CSIMPLEPARAMWIDGET_H
#define CSIMPLEPARAMWIDGET_H

#include <QWidget>
#include "common.h"

class SKMediaPlayer;
class CSimpleParamWidget : public QWidget
{
	Q_OBJECT

public:
	CSimpleParamWidget(QWidget *parent = 0);
	~CSimpleParamWidget();

	void SetApp(SKMediaPlayer *a) { m_app = a; }

	QLabel *GetLabelTime() { return m_labelTime; }
	QLabel *GetLabelVolume() { return m_labelVolume; }

private:
	QLabel *m_labelTime;	//��ǰӰ��ʱ��
	QLabel *m_labelVolume;	//����

private:
	void Init();
	void InitUi();
	void InitSlot();

private:
	SKMediaPlayer *m_app;
	
};

#endif // CSIMPLEPARAMWIDGET_H
