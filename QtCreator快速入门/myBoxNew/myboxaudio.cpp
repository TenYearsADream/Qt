/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/

#include "myboxaudio.h"

qreal MyBoxAudio::boxVolume = 1.0;
MyBoxAudio::MyBoxAudio()
{

}
MyBoxAudio::MyBoxAudio(QString musicName)
{
    mediaObject = new Phonon::MediaObject();
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    Phonon::createPath(mediaObject,audioOutput);
    mediaObject->setCurrentSource(Phonon::MediaSource(musicName));
}

void MyBoxAudio::play()
{
    audioOutput->setVolume(boxVolume);
    mediaObject->stop();
    mediaObject->play();
}
