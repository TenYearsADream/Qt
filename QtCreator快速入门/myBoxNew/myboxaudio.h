/**********************��Ȩ����****************************

����Դ������www.yafeilinux.comԭ����������ѭQt��Դ���������������Э�顣

����Ȩʹ�ã������͸������ǵĴ��룬���뱣֤����Ŀ�Դ��

����Դ�����Ȩ��www.yafeilinux.com���У��벻Ҫ������ҵ��;��
**********************************************************/

#ifndef MYBOXAUDIO_H
#define MYBOXAUDIO_H
#include <Phonon>
class MyBoxAudio
{
public:
    MyBoxAudio();
    MyBoxAudio(QString musicName);
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    void setVolume(qreal volume) {boxVolume = volume;}
    void play();
private:
    static qreal boxVolume;
};

#endif // MYBOXAUDIO_H
