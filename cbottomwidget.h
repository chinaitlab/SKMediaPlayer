#ifndef CBOTTOMWIDGET_H
#define CBOTTOMWIDGET_H

#include <QWidget>
#include "common.h"
#include "PushButton.h"

class SKMediaPlayer;
class CBottomWidget : public QWidget
{
	Q_OBJECT

public:
	CBottomWidget(QWidget *parent = 0);
	~CBottomWidget();

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
	PushButton  *m_btnList;			//�б�
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
	void sigPlaylist();

private:
	SKMediaPlayer *m_app;

};

#endif // CBOTTOMWIDGET_H
