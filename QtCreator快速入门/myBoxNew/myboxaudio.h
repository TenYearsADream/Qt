/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
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
