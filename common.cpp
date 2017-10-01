#include "common.h"

common::common()
{

}

common::~common()
{

}

//��ȡ��ǰ·��
QString common::GetCurrentAppPath()
{
    return QCoreApplication::applicationDirPath()+"/";
}

//��ȡ��ǰ·��
QString common::GetCurrentAppName()
{
	return QCoreApplication::applicationName();
}

//��ȡ��ǰ����ʱ������
QString common::GetLongDateTime()
{
	QDateTime time = QDateTime::currentDateTime();

	return time.toString("yyyy-MM-dd hh:mm:ss.dddd");
}

//�ļ��Ƿ����
bool common::FileExists(QString strFile)
{
    QFile tempFile(strFile);
    if (tempFile.exists())
        return true;

    return false;
}

int	common::FileLineCount(QString strFile)
{
	int count = 0;

	QFile file(strFile);
    if(!file.open(QFile::ReadOnly | QFile::Text)) 
		return 0;

	QTextStream in(&file);
	while (!in.atEnd()) 
	{
		QString line = in.readLine();
		count++;
	}

	file.close();
	return count;
}

//�ļ����Ƿ����
bool common::FolderExists(QString strFolder)
{
    QDir tempFolder(strFolder);
    if(tempFolder.exists())
        return true;

    return false;
}

//�����ļ���
bool common::CreateFolder(QString strFolder)
{
    QDir dir;
    return dir.mkdir(strFolder);
}
