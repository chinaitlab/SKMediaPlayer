#ifndef CBOTTOMFLOATWIDGET_H
#define CBOTTOMFLOATWIDGET_H

#include <QWidget>
#include "common.h"

class SKMediaPlayer;
class CBottomFloatWidget : public QWidget
{
	Q_OBJECT

public:
	CBottomFloatWidget(QWidget *parent = 0);
	~CBottomFloatWidget();

	void SetApp(SKMediaPlayer *a) { m_app = a; }

	QLabel *GetLabelTime() { return m_labelTime; }
	QLabel *GetLabelVolume() { return m_labelVolume; }
	QPushButton *GetBtnStartStop() { return m_btnStartStop; }
	QSlider *GetSliderTime() { return m_sliderTime; }
	QSlider *GetSliderVolume() { return m_sliderVolume; }

protected:
	bool eventFilter(QObject *, QEvent *);
	virtual void mousePressEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);
	virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void paintEvent(QPaintEvent *);

private:
	QLabel *m_labelTime;			//��ǰʱ�����ʱ��
	QLabel *m_labelVolume;			//����
	QPushButton *m_btnOpen;			//��
	QPushButton *m_btnStartStop;	//��ͣ
	QPushButton *m_btnPause;		//�ر�
	QPushButton *m_btnForward;		//ǰ��
	QPushButton *m_btnRewind;		//����
	QPushButton *m_btnFullscreen;	//ȫ��
	QSlider	*m_sliderTime;			//ʱ����
	QSlider *m_sliderVolume;		//������

private:
	void Init();
	void InitUi();
	void InitSlot();

signals:
	void sigStartStop();
	void sigPause();
	void sigOpen();
	void sigForward();
	void sigRewind();
	void sigFullscreen();

private:
	SKMediaPlayer *m_app;
	
};

#endif // CBOTTOMFLOATWIDGET_H
